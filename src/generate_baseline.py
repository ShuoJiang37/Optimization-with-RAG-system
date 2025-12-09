from openai import OpenAI

MODEL = "gpt-5-mini"

client = OpenAI()

def main() -> None:
    user_prompt = input("Enter optimization request (no RAG baseline): ")

    # Call the model directly, no retrieval, no extra context
    response = client.responses.create(
        model=MODEL,
        input=user_prompt
    )

    print(response.output_text)

if __name__ == "__main__":
    main()
