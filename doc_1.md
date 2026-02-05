<<<<<<< HEAD
# Program 1 — Parentheses Balance Checker ✅

## Purpose
Check whether a mathematical expression contains balanced brackets of types '()', '[]', and '{}'.

## Description
The program reads a single-line expression from standard input and uses a stack to verify that every closing bracket matches the most recent unmatched opening bracket. It ignores non-bracket characters and reports whether the expression is "Balanced" or "Not Balanced".

## Example input/output
- Input: 'a+ (b-c)'
  - Output: 'Balanced'
- Input: 'm+ [a-b*(c+ d*{m)]'
  - Output: 'Not Balanced'
- Input: 'a+ (b-c) *(d'
  - Output: 'Not Balanced'

## Algorithm (brief)
- Scan the expression from left to right.
- Push opening brackets '(', '[', '{' onto a stack.
- For each closing bracket ')', ']', '}': if the stack is empty or the top element does not match the closing bracket, the expression is unbalanced; otherwise pop the top.
- After scanning, if the stack is empty the expression is balanced.

## Complexity
- Time: O(n) — single pass over the input string.
- Space: O(n) — worst-case stack usage when all characters are openings.

## Notes
- The program reads one line and treats everything other than brackets as irrelevant for the balance check.
- If the input line is longer than the buffer, behavior will be limited by the buffer size.

## Sample Output

a+(b-c)*(d -> Not Balanced
m+[a-b*(c+d*{m)] -> Not Balanced
a+(b-c) -> Balanced


=======
# Program 1 — Parentheses Balance Checker ✅

## Purpose
Check whether a mathematical expression contains balanced brackets of types '()', '[]', and '{}'.

## Description
The program reads a single-line expression from standard input and uses a stack to verify that every closing bracket matches the most recent unmatched opening bracket. It ignores non-bracket characters and reports whether the expression is "Balanced" or "Not Balanced".

## Example input/output
- Input: 'a+ (b-c)'
  - Output: 'Balanced'
- Input: 'm+ [a-b*(c+ d*{m)]'
  - Output: 'Not Balanced'
- Input: 'a+ (b-c) *(d'
  - Output: 'Not Balanced'

## Algorithm (brief)
- Scan the expression from left to right.
- Push opening brackets '(', '[', '{' onto a stack.
- For each closing bracket ')', ']', '}': if the stack is empty or the top element does not match the closing bracket, the expression is unbalanced; otherwise pop the top.
- After scanning, if the stack is empty the expression is balanced.

## Complexity
- Time: O(n) — single pass over the input string.
- Space: O(n) — worst-case stack usage when all characters are openings.

## Notes
- The program reads one line and treats everything other than brackets as irrelevant for the balance check.
- If the input line is longer than the buffer, behavior will be limited by the buffer size.

## Sample Output

a+(b-c)*(d -> Not Balanced
m+[a-b*(c+d*{m)] -> Not Balanced
a+(b-c) -> Balanced


>>>>>>> b75faef5eb984d79887d3d59a5aa983c6f730d56
