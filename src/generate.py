import json
import numpy as np
import traceback #added to catch error
from openai import OpenAI
from numpy.typing import NDArray

# Set `OPENAI_API_KEY` environment variable
client = OpenAI()

# Global variables
TOP_K = 3
DB_DIR = "embedded"
MODEL ="gpt-5-mini"
EMBED_MODEL = "text-embedding-3-small"

# Typedefs
Entry = dict[str, str | dict[str, str]]
Vector = NDArray[np.float64]
Score = tuple[float, Entry]

# Vector database to be loaded in to main()
VECTORS: Vector | None = None
METADATA: list[Entry] | None = None


def load_db() -> tuple[Vector, list[Entry]]:
    # Load vector database (2D NumPy array)
    vectors: Vector = np.load(f"{DB_DIR}/vectors.npy")

    # Load metadata into a list
    metadata: list[Entry] = []
    with open(f"{DB_DIR}/metadata.jsonl") as f:
        for line in f:
            metadata.append(json.loads(line))

    return vectors, metadata


def embed_query(query: str) -> Vector:
    # Create embedding of the query with OpenAI model
    emb = client.embeddings.create(
        model=EMBED_MODEL,
        input=query
    )
    return np.array(emb.data[0].embedding)


def cosine_similarity(a: Vector, b: Vector) -> float:
    return np.dot(a, b) / (np.linalg.norm(a) * np.linalg.norm(b))


def query_vector_db(text_query: str, top_k: int = 5) -> list[Score]:
    # Added to give a better description of an error with the nothing in the database
    if VECTORS is None or METADATA is None:
        raise RuntimeError("Vector DB not loaded")
    # Embed the query
    q_vec: Vector = embed_query(text_query)

    # Perform cosine similarity between q_vec and vec_db
    scores: list[Score] = []
    for idx, vec in enumerate(VECTORS):
        score = cosine_similarity(q_vec, vec)
        scores.append((score, METADATA[idx]))

    # Sort the scores in descending order by score
    scores.sort(key = lambda x: x[0], reverse = True)

    return scores[:top_k]


def build_prompt(prompt: str, retrieved: list[Score]) -> str:
    # Add the entries as context
    context: list[str] = []
    for idx, entry in enumerate(retrieved):
        md: Entry = entry[1]
        context.append(
            "\n".join([
                f"## Retrieved Optimal Implementation #{idx}",
                f"### Algorithm: {md['algorithm']}",
                f"### C Code:\n```c\n{md['code']}\n```"
            ])
        )

    # Join the context with the prompt
    return "\n".join([
        "# Task:"
        "You are a systems-level code optimizer.",
        "",
        f"The user wants: '{prompt.strip()}'",
        "",
        "Use the retrieved optimized implementations to inspire a new solution.",
        "Do not copy them directly; adapt them to the user's requirements.",
        "Focus on cache efficiency and architecture-aware tuning.",
        "",
        "Now generate an optimized C implementation with the following retrieved optimized implementations:"
        f"{"\n".join(context)}",
    ])


def main() -> None:
    # Load the vector database
    global VECTORS, METADATA #Added this as an issue was faced where these variables weren't updating globally causing issues
    VECTORS, METADATA = load_db()

    # print("Loaded VECTORS shape:", VECTORS.shape)
    # print("Loaded METADATA entries:", len(METADATA)) # Added these two print statments just to check
    # Obtain user prompt
    # user_prompt = "Generate a efficient merge sort implementation for a modern Intel CPU."
    user_prompt = input("Enter your optimization request: ") # Added this and commented out the other user prompt, can comment this and uncomment the other if needed
    try:
        # Query RAG system and build prompt
        retrieved: list[Score] = query_vector_db(user_prompt, top_k=TOP_K)
        prompt: str = build_prompt(user_prompt, retrieved)

        # Generate a response with the new prompt
        response = client.responses.create(
            model=MODEL,
            input=prompt
        )
        print(response.output_text)
    except Exception as e:
        print(f"Error: {e}")
        traceback.print_exc() # added to catch error

if __name__ == "__main__":
    main()
