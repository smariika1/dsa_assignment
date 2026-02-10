# Q5: How can we implement the undirected graph using adjacency matrix? Write a function that implement the BFS and DFS technique to traverse through the graph. Demonstrate the use of your program with example graph.

An undirected graph can be implemented using an adjacency matrix by storing a symmetric 2D array in which the entry at row *i* and column *j* is 1 if there is an edge between vertices *i* and *j*, and 0 otherwise.

## Data Structure
- **Graph**: Adjacency matrix (V×V array)
  - adj[i][j] = 1 if edge exists
  - Undirected: adj[i][j] = adj[j][i]

## Key Functions
1. **BFS**: Level-by-level traversal using queue
2. **DFS**: Depth-first traversal using recursion

## BFS Algorithm
1. Mark start as visited, enqueue
2. While queue not empty:
   - Dequeue vertex
   - Enqueue all unvisited neighbors

## DFS Algorithm
1. Mark current as visited
2. Recursively visit all unvisited neighbors

## Output
```
Adjacency Matrix:
   0 1 2 3 4 5 
0: 0 1 1 0 0 0 
1: 1 0 0 1 0 0 
2: 1 0 0 1 1 0 
3: 0 1 1 0 0 1 
4: 0 0 1 0 0 1 
5: 0 0 0 1 1 0 

BFS from 0: 0 1 2 3 4 5 
DFS from 0: 0 1 3 2 4 5 
```

## Complexity
- BFS/DFS: O(V²) with adjacency matrix
