OUT_DIR="inputs"    # Output directory for input text files
SEED=5204           # Seed for reproducible randomness

mkdir -p "$OUT_DIR"

# p02272
INPUT="$OUT_DIR/p02272.txt"
NUM_INT=500000     # Number of integers to create
MAX_INT=1000000    # Maximum value for integers

if [ ! -f "$P02272" ]; then
    echo "$NUM_INT" > "$INPUT"
    awk -v seed="$SEED" -v n="$NUM_INT" -v max="$MAX_INT" 'BEGIN { srand(seed); for(i=1;i<=n;i++) print int(rand()*max) }' >> "$INPUT"
    echo "'$INPUT' generated with seed: '$SEED'."
else
    echo "'$INPUT' already exists. Skipping generation."
fi

# 
INPUT="$OUT_DIR/p02272.txt"
NUM_INT=500000     # Number of integers to create
MAX_INT=1000000    # Maximum value for integers

if [ ! -f "$P02272" ]; then
    echo "$NUM_INT" > "$INPUT"
    awk -v seed="$SEED" -v n="$NUM_INT" -v max="$MAX_INT" 'BEGIN { srand(seed); for(i=1;i<=n;i++) print int(rand()*max) }' >> "$INPUT"
    echo "'$INPUT' generated with seed: '$SEED'."
else
    echo "'$INPUT' already exists. Skipping generation."
fi