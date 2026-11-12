# DAA Lab

This repository contains C++ implementations of common Design and Analysis of Algorithms (DAA) problems and techniques covered in the S5 curriculum.

It is organized by algorithmic topic and includes programs for sorting, trees, graphs, dynamic programming, greedy algorithms, divide-and-conquer strategies, and backtracking.

## Repository Structure

- `backtracking/`
  - `NQueens.cpp` - Solution to the N-Queens problem using backtracking
- `divide_and_conquer/`
  - `IntegerMultiplication.cpp` - Integer multiplication using divide and conquer
- `dynamic_programming/`
  - `LongestCommonSubsequence.cpp` - LCS problem implementation
  - `SequenceAlignment.cpp` - Sequence alignment using dynamic programming
  - `knapsack.cpp` - 0/1 knapsack problem
- `graphs/`
  - `minimum_spanning_tree/`
    - `KruskalsAlgorithm.cpp`
    - `PrimsAlgorithm.cpp`
  - `shortest_path/`
    - `BellmanFord.cpp`
    - `Dijkstra.cpp`
    - `FloydWarshall.cpp`
  - `traversal/`
    - `BFS.cpp`
    - `DFS.cpp`
- `greedy/`
  - `fractional_knapsack.cpp`
  - `huffman.cpp`
- `sorting/`
  - `HeapSort.cpp`
  - `InsertionSort.cpp`
  - `MergeSort.cpp`
  - `QuickSort.cpp`
- `trees/`
  - `BinarySearchTree.cpp`
  - `BinaryTree.cpp`
  - `InOrderTraversal.cpp`
  - `PostOrderTraversal.cpp`
  - `PreOrderTraversal.cpp`

## Topics Covered

- Sorting algorithms
- Tree operations and traversals
- Graph traversal and shortest path algorithms
- Minimum spanning tree algorithms
- Dynamic programming problems
- Divide and conquer techniques
- Greedy strategy problems
- Backtracking problems

## How to Run

Each file is a standalone C++ program. You can compile and run any file using:

```bash
g++ sorting/QuickSort.cpp -o quicksort
./quicksort
```

Or for another file:

```bash
g++ graphs/shortest_path/Dijkstra.cpp -o dijkstra
./dijkstra
```

## Requirements

- C++ compiler such as `g++`
- Terminal or command prompt

## Purpose

This repository is intended for learning and practicing algorithm design and analysis through practical C++ implementations.

## License

This project is provided for educational use.
