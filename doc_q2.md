# Q2: Write a program to convert an infix mathematical expression to postfix and evaluate it.

## Data Structures
- **CharStack**: For operators during conversion
- **IntStack**: For operands during evaluation

## Key Functions
1. **infixToPostfix**: Converts infix to postfix using operator precedence
2. **evaluate**: Evaluates postfix expression using stack

## Algorithm (Conversion)
1. Scan infix left to right
2. Operand → add to postfix
3. Operator → pop higher/equal precedence, then push
4. '(' → push, ')' → pop until '('

## Algorithm (Evaluation)
1. Scan postfix left to right
2. Operand → push to stack
3. Operator → pop two operands, compute, push result

## Output
```
Infix:   3 + 5 * 2
Postfix: 3 5 2 * + 
Result:  13

Infix:   ( 3 + 5 ) * 2
Postfix: 3 5 + 2 * 
Result:  16
```

## Complexity
- Conversion: O(n), Evaluation: O(n)
