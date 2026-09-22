# Eulerian Tour Algorithms

Informatics ITS Graph Theory Class - Group 2

## Members

| No. | Name | NRP |
|---:|---|---|
| 1 | Ahmad Farras Favian Al Efasi | 5025251005 |
| 2 | Daniel Pedrosaputra | 5025251171 |

---

## Problem Description

This repository contains implementations of three algorithms for solving the CSES Mail Delivery problem:

1. Fleury's Algorithm
2. Hierholzer's Algorithm
3. Left-Hand Rule Algorithm

The objective is to find an Eulerian circuit that starts at vertex 1, uses every edge exactly once, and returns to vertex 1.

## Algorithms Introduction

### Fleury's Algorithm

Fleury's Algorithm selects unused edges while avoiding bridges whenever another edge is available.

Time Complexity: O(E^2)

### Hierholzer's Algorithm

Hierholzer's Algorithm constructs an Eulerian circuit by following unused edges and combining cycles.

Time Complexity: O(E)

### Left-Hand Rule Algorithm

The Left-Hand Rule follows unused edges according to a fixed local edge ordering.

Time Complexity: O(E)

## Requirements

- C++17 compatible compiler

## How to Run

Compile one of the programs using a C++ compiler.

For Fleury's Algorithm:

```bash
g++ -std=c++17 fleury.cpp -o fleury
./fleury
```

For Hierholzer's Algorithm:

```bash
g++ -std=c++17 hierholzer.cpp -o hierholzer
./hierholzer
```

For Left-Hand Rule Algorithm:

```bash
g++ -std=c++17 left_hand_rule.cpp -o left_hand_rule
./left_hand_rule
```

## Sample Input

```text
6 8
1 2
1 3
2 3
2 4
2 6
3 5
3 6
4 5
```

## Sample Output

```text
1 2 3 5 4 2 6 3 1
```

The exact Eulerian circuit may differ depending on the order in which edges are selected.

## AI Tools Usage

AI tools used:
- ChatGPT
- Claude

Claude was used to assist with understanding the assignment.
ChatGPT was used during for generating the C++ implementations, testing the sample case, and preparing the README.

Prompt:
1. "Explain to me what I should do for the assignment (Refurbished W3 Eulerian Tour.pdf)."
2. "Give me an example of another algorithm that suits beside fleury’s and hierholzer’s."
3. "Make a readme file for the repository based on this report."
4. "help me make the c++ solution for the algorithms."

