from openai import OpenAI

# Set `OPENAI_API_KEY` environment variable
client = OpenAI()

MODEL = "gpt-5.1"


def main() -> None:
    user_prompt = input("Enter optimization request (no RAG baseline): ")

    # Call the model directly with no retrieval
    response = client.responses.create(
        model=MODEL,
        input=user_prompt
    )

    print(response.output_text)


if __name__ == "__main__":
    main()
