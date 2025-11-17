OUT_DIR="inputs"    # Output directory for input text files
SEED=5204           # Seed for reproducible randomness

mkdir -p "$OUT_DIR"


# p02255 - Insertion Sort  
INPUT="$OUT_DIR/p02255.txt"
NUM_INT=100     # Number of integers to create
MAX_INT=1000000    # Maximum value for integers, default max

if [ ! -f "$P02255" ]; then
    echo "$NUM_INT" > "$INPUT"
    awk -v seed="$SEED" -v n="$NUM_INT" -v max="$MAX_INT" 'BEGIN { srand(seed); for(i=1;i<=n;i++) print int(rand()*max) }' >> "$INPUT"
    echo "'$INPUT' generated with seed: '$SEED'."
else
    echo "'$INPUT' already exists. Skipping generation."
fi


# p02259 - Bubble Sort 
INPUT="$OUT_DIR/p02259.txt"
NUM_INT=100     # Number of integers to create
MAX_INT=1000000    # Maximum value for integers, default max

if [ ! -f "$P02259" ]; then
    echo "$NUM_INT" > "$INPUT"
    awk -v seed="$SEED" -v n="$NUM_INT" -v max="$MAX_INT" 'BEGIN { srand(seed); for(i=1;i<=n;i++) print int(rand()*max) }' >> "$INPUT"
    echo "'$INPUT' generated with seed: '$SEED'."
else
    echo "'$INPUT' already exists. Skipping generation."
fi


# p02260 - Selection Sort
INPUT="$OUT_DIR/p02260.txt"
NUM_INT=100     # Number of integers to create
MAX_INT=1000000    # Maximum value for integers, default max

if [ ! -f "$P02260" ]; then
    echo "$NUM_INT" > "$INPUT"
    awk -v seed="$SEED" -v n="$NUM_INT" -v max="$MAX_INT" 'BEGIN { srand(seed); for(i=1;i<=n;i++) print int(rand()*max) }' >> "$INPUT"
    echo "'$INPUT' generated with seed: '$SEED'."
else
    echo "'$INPUT' already exists. Skipping generation."
fi


# p02261 - Stable Sort
INPUT="$OUT_DIR/p02261.txt"
NUM_INT=36     # Number of cards to create
MAX_INT=1000000    # Maximum value for integers, default max

if [ ! -f "$P02261" ]; then
    echo "$NUM_INT" > "$INPUT"
    awk -v seed="$SEED" -v n="$NUM_INT" -v max="$MAX_INT" 'BEGIN { srand(seed); for(i=1;i<=n;i++) print int(rand()*max) }' >> "$INPUT"
    echo "'$INPUT' generated with seed: '$SEED'."
else
    echo "'$INPUT' already exists. Skipping generation."
fi


# p02262 - Shell Sort
INPUT="$OUT_DIR/p02262.txt" # Has an additional constraint regarding arrays, how to tackle?
NUM_INT=1000000    # Number of integers to create
MAX_INT=1000000    # Maximum value for integers

if [ ! -f "$P02262" ]; then
    echo "$NUM_INT" > "$INPUT"
    awk -v seed="$SEED" -v n="$NUM_INT" -v max="$MAX_INT" 'BEGIN { srand(seed); for(i=1;i<=n;i++) print int(rand()*max) }' >> "$INPUT"
    echo "'$INPUT' generated with seed: '$SEED'."
else
    echo "'$INPUT' already exists. Skipping generation."
fi


# p02272 - Merge Sort
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


# p02275 - Counting Sort
INPUT="$OUT_DIR/p02275.txt" #Had to change the max integer for this one since the constraint was larger than the default, also have to add the array constraint
NUM_INT=2000000     # Number of integers to create
MAX_INT=2000000    # Maximum value for integers

if [ ! -f "$P02275" ]; then
    echo "$NUM_INT" > "$INPUT"
    awk -v seed="$SEED" -v n="$NUM_INT" -v max="$MAX_INT" 'BEGIN { srand(seed); for(i=1;i<=n;i++) print int(rand()*max) }' >> "$INPUT"
    echo "'$INPUT' generated with seed: '$SEED'."
else
    echo "'$INPUT' already exists. Skipping generation."
fi


# p02277 - Quick Sort
INPUT="$OUT_DIR/p02277.txt" # Have to add array constraint / way to avoid same input for cards
NUM_INT=100000     # Number of integers to create
MAX_INT=1000000    # Maximum value for integers

if [ ! -f "$P02277" ]; then
    echo "$NUM_INT" > "$INPUT"
    awk -v seed="$SEED" -v n="$NUM_INT" -v max="$MAX_INT" 'BEGIN { srand(seed); for(i=1;i<=n;i++) print int(rand()*max) }' >> "$INPUT"
    echo "'$INPUT' generated with seed: '$SEED'."
else
    echo "'$INPUT' already exists. Skipping generation."
fi


# p02278 - Minimum Cost Sort
INPUT="$OUT_DIR/p02278.txt" # Have to add array constraint / making sure arrays aren't the same
NUM_INT=1000     # Number of integers to create
MAX_INT=1000000    # Maximum value for integers

if [ ! -f "$P02278" ]; then
    echo "$NUM_INT" > "$INPUT"
    awk -v seed="$SEED" -v n="$NUM_INT" -v max="$MAX_INT" 'BEGIN { srand(seed); for(i=1;i<=n;i++) print int(rand()*max) }' >> "$INPUT"
    echo "'$INPUT' generated with seed: '$SEED'."
else
    echo "'$INPUT' already exists. Skipping generation."
fi