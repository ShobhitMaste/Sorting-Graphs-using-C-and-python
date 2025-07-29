import pandas as pd
import matplotlib.pyplot as plt

# Load CSV
df = pd.read_csv('./sorted_output_csv/result.csv')

# Convert microseconds to milliseconds
for algo in ['Selection', 'Insertion', 'Merge', 'Quick', 'GNU']:
    df[algo] = df[algo] / 1000.0

# Unique input sizes
input_sizes = df['InputSize'].unique()

for size in input_sizes:
    subset = df[df['InputSize'] == size]

    # Set bar width and labels
    algorithms = ['Selection', 'Insertion', 'Merge', 'Quick', 'GNU']
    x = range(len(algorithms))

    plt.figure(figsize=(10, 6))
    for _, row in subset.iterrows():
        times = [row[algo] for algo in algorithms]
        plt.plot(algorithms, times, marker='o', label=row['Type'])

    plt.title(f"Sorting Time Comparison - Input Size {size}")
    plt.xlabel("Sorting Algorithms")
    plt.ylabel("Time (ms)")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(f"graph_{size}.png")
    plt.show()
