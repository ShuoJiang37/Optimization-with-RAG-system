import os
import json
import numpy as np
from openai import OpenAI
from typing import Iterator

# Set `OPENAI_API_KEY` environment variable
client = OpenAI()

# Global variables
ROOT = "filtered"
DATASET = "dataset"
OUTPUT_DIR = "embedded"
EMBED_MODEL = "text-embedding-3-small"

# Typedefs
Entry = dict[str, str | dict[str, str]]


def read_machine_metadata(metadata_path: str) -> dict[str, str]:
    # Read in metadata from a file of k:v pairs seperated by newlines
    machine_md: dict[str, str] = {}
    with open(metadata_path, "r") as f:
        for line in f:
            if ":" in line:
                key, val = line.split(":", 1)
                machine_md[key.strip().lower()] = val.strip()

    return machine_md


def walk_filtered_directory() -> Iterator[Entry]:
    # Iterate through ever machine in dataset
    for machine in os.listdir(ROOT):
        # Get directory path for the machine
        machine_path = os.path.join(ROOT, machine)
        if not os.path.isdir(machine_path):
            continue
        # Iterate through every algorithm tested on the machine
        for file in os.listdir(machine_path):
            name, ext = os.path.splitext(file)
            if ext.lower() != ".txt":
                continue

            # Check if it is a metadata file
            if name.lower() == "metadata":
                metadata_path = os.path.join(machine_path, file)
                # Get the metadata of the machine
                machine_md: dict[str, str] = read_machine_metadata(metadata_path)

            # Check if it is an algorithm file
            if ":" not in name:
                continue

            # Iterate through every implementation
            problem, algorithm = name.split(":", 1)
            with open(os.path.join(machine_path, file), "r") as f:
                for impl in f:
                    # Verify source code exists in dataset
                    impl_path = os.path.join(DATASET, problem, impl.strip())
                    print(impl_path)
                    if not os.path.exists(impl_path):
                        print("here")
                        continue

                    # Read the source code
                    with open(impl_path, "r") as src:
                        code_text = src.read()

                    # Return RAG Vector Schema
                    yield {
                        "machine": machine,
                        "machine_metadata": machine_md,
                        "algorithm": algorithm,
                        "code": code_text
                    }


def build_embedding_text(machine_md: dict[str, str], algorithm: str, code_text: str) -> str:
    # Join the dictionary as an unordered list
    machine_str = "\n".join([f"{k}: {v}" for k, v in machine_md.items()])
    return "\n".join([
        f"Machine Architecture:\n{machine_str}",
        f"Algorithm:\n{algorithm}",
        f"C Code:\n{code_text}"
    ])


def embed_text(text: str) -> list[float]:
    # Create an embedding using OpenAI model
    emb = client.embeddings.create(
        model=EMBED_MODEL,
        input=text
    )
    return emb.data[0].embedding


def main() -> None:
    # Check if filtered and dataset directory exists
    if not os.path.isdir(ROOT) or not os.path.isdir(DATASET):
        print("Filtered dataset directory does not exist")
        return

    # Create output directory if it doesn't exist
    os.makedirs(OUTPUT_DIR, exist_ok=True)

    vectors: list[list[float]] = []
    metadata_entries: list[Entry] = []

    print("Scanning dataset...")

    # Work through the filtered dataset
    for idx, entry in enumerate(walk_filtered_directory()):
        print(f"Embedding #{idx}: {entry['algorithm']} on {entry['machine']}")

        # Convert the entry and metadata into a string
        emb_text = build_embedding_text(
            entry["machine_metadata"],
            entry["algorithm"],
            entry["code"]
        )

        # Generate an vector embedding
        try:
            vector: list[float] = embed_text(emb_text)
        except Exception as e:
            print(f"Error ({entry['algorithm']} on {entry['machine']}): {e}")
            continue

        # Append embedding and metadata to list
        vectors.append(vector)
        metadata_entries.append(entry)

    print("Saving vector DB to filesystem...")

    # Save vector embeddings as NumPy arrays
    vectors_np = np.array(vectors)
    np.save(os.path.join(OUTPUT_DIR, "vectors.npy"), vectors_np)

    # Save metadata as a json
    with open(os.path.join(OUTPUT_DIR, "metadata.jsonl"), "w") as f:
        for md in metadata_entries:
            f.write(json.dumps(md) + "\n")

    # Save count as a json
    with open(os.path.join(OUTPUT_DIR, "info.json"), "w") as f:
        json.dump({"count": len(vectors)}, f, indent=4)

    print("Vector DB stored in:", OUTPUT_DIR)


if __name__ == "__main__":
    main()
