# Q6: Given the array of the data (unsorted), Write a program to build the min and max heap.

## Data Structure
- **Heap**: Complete binary tree stored in array
- Min Heap: Parent < Children
- Max Heap: Parent > Children

## Key Functions
1. **minHeapify**: Maintain min heap property at index i
2. **maxHeapify**: Maintain max heap property at index i
3. **buildMinHeap/buildMaxHeap**: Convert array to heap

## Build Heap Algorithm
1. Start from last non-leaf node (n/2 - 1)
2. Heapify each node going backwards to root
3. Time: O(n)

## Heapify Algorithm
1. Compare node with children
2. Swap with smallest/largest child if needed
3. Recursively heapify affected subtree

## Output
```
Original: 12 11 13 5 6 7 
Min Heap: 5 6 7 12 11 13 
Max Heap: 13 11 12 5 6 7 
```

## Complexity
- Build: O(n), Heapify: O(log n)
