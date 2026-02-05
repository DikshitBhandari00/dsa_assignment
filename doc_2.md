<<<<<<< HEAD
# Program 2 — Infix to Postfix Conversion and Evaluation

## Summary
This program converts an arithmetic expression from infix notation to postfix (Reverse Polish Notation) and evaluates the postfix expression. It uses stacks: one for operators during conversion and one for operands during evaluation.


## Supported features (current implementation)
- Operators: '+', '-', '*', '/'
- Parentheses: '(' and ')'
- Single-digit non-negative integer operands (0–9)
- No whitespace is allowed in the input (input is read using 'scanf("%s", ...)')
- Integer arithmetic (division is integer division)

Example:
```
Enter expression: (2+3)*4
Postfix: 23+4*
Result: 20
```

## Algorithm (brief)
1. Infix to postfix: scan input left to right.
   - If token is an operand, append to postfix.
   - If token is '(' push it to operator stack.
   - If token is ')', pop operators to postfix until matching '('.
   - For operators, pop higher-or-equal precedence operators before pushing the current one.
2. Evaluate postfix: scan postfix and use a stack of integer operands; on operator pop two operands, apply operator, push result.

Time complexity: O(n) where n is expression length. Space complexity: O(n) for stacks.

## Known limitations and edge cases
- Only single-digit operands are supported. Multi-digit numbers and negative/unary numbers are not supported.
- Input cannot contain whitespace; expressions with spaces will not parse correctly.
- No checks for malformed expressions (e.g., unbalanced parentheses, invalid characters) beyond normal stack behavior — such cases may lead to undefined or incorrect behavior.
- No explicit handling of division-by-zero — the program will crash or produce undefined behavior if division by zero occurs.
- No input-length validation beyond buffer sizes in the source (arrays of size 100).




=======
# Program 2 — Infix to Postfix Conversion and Evaluation

## Summary
This program converts an arithmetic expression from infix notation to postfix (Reverse Polish Notation) and evaluates the postfix expression. It uses stacks: one for operators during conversion and one for operands during evaluation.


## Supported features (current implementation)
- Operators: '+', '-', '*', '/'
- Parentheses: '(' and ')'
- Single-digit non-negative integer operands (0–9)
- No whitespace is allowed in the input (input is read using 'scanf("%s", ...)')
- Integer arithmetic (division is integer division)

Example:
```
Enter expression: (2+3)*4
Postfix: 23+4*
Result: 20
```

## Algorithm (brief)
1. Infix to postfix: scan input left to right.
   - If token is an operand, append to postfix.
   - If token is '(' push it to operator stack.
   - If token is ')', pop operators to postfix until matching '('.
   - For operators, pop higher-or-equal precedence operators before pushing the current one.
2. Evaluate postfix: scan postfix and use a stack of integer operands; on operator pop two operands, apply operator, push result.

Time complexity: O(n) where n is expression length. Space complexity: O(n) for stacks.

## Known limitations and edge cases
- Only single-digit operands are supported. Multi-digit numbers and negative/unary numbers are not supported.
- Input cannot contain whitespace; expressions with spaces will not parse correctly.
- No checks for malformed expressions (e.g., unbalanced parentheses, invalid characters) beyond normal stack behavior — such cases may lead to undefined or incorrect behavior.
- No explicit handling of division-by-zero — the program will crash or produce undefined behavior if division by zero occurs.
- No input-length validation beyond buffer sizes in the source (arrays of size 100).




>>>>>>> b75faef5eb984d79887d3d59a5aa983c6f730d56
