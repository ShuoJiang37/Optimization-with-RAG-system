import os
import json
import numpy as np
from openai import OpenAI

INPUTS_FOLDER = "./inputs"
EMBEDDED_FOLDER = "./embedded"
DIMENSION = 1024
TOP_K = 5

client = OpenAI()

def embed_input_files():
    embedded_queries = []

    print("Embedding input files from:", INPUTS_FOLDER)

    for filename in os.listdir(INPUTS_FOLDER):
        full_path = os.path.join(INPUTS_FOLDER, filename)

        if not os.path.isfile(full_path):
            continue

        print("Embedding:", filename)

        with open(full_path, "r", encoding="utf-8", errors="replace") as f:
            code = f.read()

        try:
            response = client.embeddings.create(
                model="text-embedding-3-small",
                input=code,
            )
        except Exception as e:
            print("Error embedding", filename, "-", e)
            continue

        vec = response.data[0].embedding
        embedded_queries.append({
            "file": filename,
            "embedding": np.array(vec)
        })

    print("\nComplete embedding input files. Total:", len(embedded_queries))
    return embedded_queries

def load_stored_embeddings():
    stored_vectors = []

    print("Loading stored embeddings from:", EMBEDDED_FOLDER)

    for root, dirs, files in os.walk(EMBEDDED_FOLDER):
        for name in files:
            if not name.endswith(".json"):
                continue

            full_path = os.path.join(root, name)

            with open(full_path, "r", encoding="utf-8") as f:
                data = json.load(f)

            stored_vectors.append({
                "file": data["file"],
                "path": data["path"],
                "embedding": np.array(data["embedding"])
            })

    print("Loaded:", len(stored_vectors), "embedded files.")
    return stored_vectors

def cosine_similarity(a, b):
    a = np.array(a)
    b = np.array(b)

    norm_a = np.linalg.norm(a)
    norm_b = np.linalg.norm(b)

    if norm_a == 0 or norm_b == 0:
        return 0.0

    return np.dot(a, b) / (norm_a * norm_b)

def find_top_matches(query_embedding, stored_vectors, top_k=TOP_K):
    results = []

    for item in stored_vectors:
        sim = cosine_similarity(query_embedding, item["embedding"])
        results.append((sim, item["file"], item["path"]))

    results.sort(reverse=True, key=lambda x: x[0])
    return results[:top_k]

if __name__ == "__main__":
    queries = embed_input_files()
    stored_vectors = load_stored_embeddings()

    for q in queries:
        print("\nSearching for matches for:", q["file"])
        top = find_top_matches(q["embedding"], stored_vectors)

        for score, file, path in top:
            print(f"{score:.4f} | {file} | {path}")
