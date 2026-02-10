# Q3: Write and Implement the reverse traversal algorithm in the the linked list. Write main() to demonstrate the use of the function.

## Data Structure
- **Node**: Contains data and next pointer

## Key Functions
1. **printReverseRecursive**: Uses recursion stack to reverse
2. **printReverseStack**: Uses explicit array stack

## Algorithm (Recursive)
1. Recursively reach end of list
2. Print while backtracking

## Algorithm (Stack)
1. Push all elements to stack
2. Pop and print

## Output
```
Forward: 10 20 30 40 50 
Reverse (Recursive): 50 40 30 20 10 
Reverse (Stack): 50 40 30 20 10 
```

## Complexity
- Both methods: O(n) time, O(n) space