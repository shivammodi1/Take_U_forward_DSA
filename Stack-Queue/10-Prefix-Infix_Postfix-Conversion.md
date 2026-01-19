// Operator -> It is a just a symbol that represents a specific mathematical or logical operation.
// Operand -> It is a value or variable on which the operator performs the operation.
// example: In the expression "a + b", '+' is the operator and 'a' and 'b' are operands.

- Infix Expression -> An expression where the operator is placed between the operands.
// example: A + B

- Prefix Expression -> An expression where the operator is placed before the operands.
// example: +AB

- Postfix Expression -> An expression where the operator is placed after the operands.
// example: AB+

# 1. Infix to Postfix Conversion
example: Infix Expression: a + b * ( c ^ d - e )
         Postfix Expression: abcd^e-*+

| Scanned | Action                          | Stack   | Postfix   |
| ------- | ------------------------------- | ------- | --------- |
| a       | Operand → output                | empty   | a         |
| +       | Push                            | +       | a         |
| b       | Operand → output                | +       | ab        |
| *       | Higher precedence than + → push | + *     | ab        |
| (       | Push                            | + * (   | ab        |
| c       | Operand → output                | + * (   | abc       |
| ^       | Push                            | + * ( ^ | abc       |
| d       | Operand → output                | + * ( ^ | abcd      |
| -       | Lower than ^ → pop ^            | + * (   | abcd^     |
|         | Push -                          | + * ( - | abcd^     |
| e       | Operand → output                | + * ( - | abcd^e    |
| )       | Pop till ( and push -           | + *     | abcd^e-   |
| end     | Pop all and push remaining      | empty   | abcd^e-*+ |
|         |   operators in stack            |         |           |

# 2. Postfix to Infix Conversion
example: Postfix Expression: abcd^e-*+
         Infix Expression: a + b * ( c ^ d - e )