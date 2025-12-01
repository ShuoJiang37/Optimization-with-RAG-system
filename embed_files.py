from openai import OpenAI
import os
import json

SOURCE = "./dataset/"
DESTINATION = "./embedded/"

print("Embedding files from:", SOURCE)
print("Saving embeddings to:", DESTINATION)

client = OpenAI()

for root, dirs, file_list in os.walk(SOURCE):
    for filename in file_list:
        if not filename.lower().endswith(".c"):
            continue
        
        full_path = os.path.join(root, filename)
        rel_path = os.path.relpath(full_path, SOURCE)
        file_out_dir = os.path.join(DESTINATION, os.path.dirname(rel_path))
        file_out_path = os.path.join(file_out_dir, filename + ".json")

        os.makedirs(file_out_dir, exist_ok=True)

        print("Embedding:", rel_path)

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

        embedding = response.data[0].embedding

        with open(file_out_path, "w", encoding="utf-8") as f:
            json.dump({
                "file": filename,
                "path": rel_path,
                "embedding": embedding
            }, f)

print("All embeddings saved to:", DESTINATION)
