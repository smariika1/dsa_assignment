# Q1: Write a program to check if any given mathematical expression has balanced number of parentheses or not? 

## Data Structures
- **Stack**: Array-based with top pointer for storing opening brackets.

## Key Functions
1. **push/pop**: Standard stack operations - O(1)
2. **isBalanced**: Main algorithm using stack
   - Push opening brackets
   - Pop and match closing brackets
   - Return true if stack empty at end

## Algorithm
1. Scan expression left to right
2. Opening bracket → push to stack
3. Closing bracket → pop and check match
4. Final: stack must be empty

## Output
```
Expression: a + (b - c) * (d
Result: NOT BALANCED

Expression: m + [a - b * (c + d * {m)]
Result: NOT BALANCED

Expression: a + (b - c)
Result: BALANCED
```

## Complexity
- Time: O(n), Space: O(n)
