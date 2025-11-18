from openai import OpenAI
import pandas as pd
import os 

source = "./data/filtered"
destination = "./data/embedded/"
dimension = 256

files = os.listdir(source)

print("Embedding files from: ", source)
print("Reducing embedding dimensionality to: ", dimension)

client = OpenAI()
output_rows = []

for file_name in files:
    full_path = os.path.join(source, file_name)
    print("Embedding: ", full_path)

    with open(full_path, "r") as f:
        code = f.read()

    try:
        response = client.embeddings.create(
            model="text-embedding-3-small",
            input=code,
            dimensions=dimension
        )
    except Exception as e:
        print("Error: ", file_name, "-", e)
        continue  

    embedding = response.data[0].embedding

    output_rows.append({
        "file": file_name,
        "embedding": embedding
    })

df = pd.DataFrame(output_rows)
df.to_csv(f"{destination}c_files_embedded.csv", index=False)

print(f"Results have been saved to {destination}c_files_embedded.csv")