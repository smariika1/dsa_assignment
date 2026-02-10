# Q7: Given a weighted graph, implement Dijkstra’s algorithm to find the shortest path from a source node to all other nodes.

## Data Structure
- Adjacency matrix for weighted graph
- Distance array and visited array

## Key Functions
1. **minDistance**: Finds unvisited vertex with minimum distance
2. **dijkstra**: Computes shortest paths from source

## Algorithm
1. Initialize all distances as infinity, source as 0
2. Repeat V times:
   - Pick minimum distance unvisited vertex
   - Mark it visited
   - Update distances of neighbors

## Output
```
Shortest distances from vertex 0:
To 0: 0
To 1: 4
To 2: 12
To 3: 19
To 4: 28
To 5: 16
```

## Complexity
- Time: O(V²), Space: O(V)