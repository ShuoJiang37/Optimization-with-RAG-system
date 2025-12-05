import os
import json
import numpy as np
from openai import OpenAI
from typing import Dict, Iterator

# Set `OPENAI_API_KEY` environment variable
client = OpenAI()

ROOT = "filtered"
OUTPUT_DIR = "embedded"
EMBED_MODEL = "text-embedding-3-small"

def walk_filtered_directory() -> Iterator[Dict[str, str]]:
    # Iterate through ever machine in dataset
    for machine in os.listdir(ROOT):
        # Get directory path for the machine
        machine_path = os.path.join(ROOT, machine)
        if not os.path.isdir(machine_path):
            continue

        # Get the metadata of the machine
        metadata_path = os.path.join(path, "metadata.txt")
        if os.path.exists(metadata_path):
            continue

        machine_md = {}
        with open(metadata_path, "r") as f:
            for line in f:
                if ":" in line:
                    key, val = line.split(":", 1)
                    machine_md[key.strip().lower()] = val.strip()

        # Iterate through every algorithm tested on the machine
        for algorithm in os.listdir(machine_path):
            # Get directory path for each algorithm
            algorithm_path = os.path.join(machine_path, algorithm)
            if not os.path.isdir(algorithm_path):
                continue

            # Iterate through every submission
            for file in os.listdir(algorithm_path):
                if file.endswith(".c"):
                    with open(os.path.join(algorithm_path, file), "r") as f:
                        code_text = f.read()

                    # Return RAG Vector Schema
                    yield {
                        "machine": machine,
                        "machine_metadata": machine_md,
                        "algorithm": algorithm,
                        "filename": file,
                        "code": code_text
                    }


def build_embedding_text(machine_md: str, algorithm: str, code_text: str) -> str:
    # Join the dictionary seperated by newlines
    machine_str = "\n".join([f"{k}: {v}" for k, v in machine_md.items()])
    return f"Machine Architecture: {machine_str}\nAlgorithm: {algorithm}\nC Code: {code_text} """


def embed_text(text: str) -> []:
    # Create an embedding using OpenAI model
    # emb = client.embeddings.create(
    #     model=EMBED_MODEL,
    #     input=text
    # )
    # return emb.data[0].embedding
    pass


def main():

    # Check if filtered dataset directory exists
    if not os.path.isdir(ROOT):
        print("Filtered dataset directory does not exist")
        return

    # Create output directory if it doesn't exist
    os.makedirs(OUTPUT_DIR, exist_ok=True)

    vectors = []
    metadata_entries = []

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
            vector = embed_text(emb_text)
        except Exception as e:
            print(f"Error embedding {entry['algorithm']} on {entry['machine']}")
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

    # Save id map as a json
    with open(os.path.join(OUTPUT_DIR, "id_map.json"), "w") as f:
        json.dump({"count": len(vectors)}, f, indent=4)

    print("Vector DB stored in:", OUTPUT_DIR)


if __name__ == "__main__":
    main()
