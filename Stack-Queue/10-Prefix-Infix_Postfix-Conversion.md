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
| Step | Scanned Symbol | Action        | Operand 1 | Operand 2           | Expression Formed          | Stack (Bottom → Top)          |
| ---: | -------------- | ------------- | --------- | ------------------- | -------------------------- | ----------------------------- |
|    1 | a              | Push operand  | –         | –                   | –                          | a                             |
|    2 | b              | Push operand  | –         | –                   | –                          | a , b                         |
|    3 | c              | Push operand  | –         | –                   | –                          | a , b , c                     |
|    4 | d              | Push operand  | –         | –                   | –                          | a , b , c , d                 |
|    5 | ^              | Pop & combine | c         | d                   | (c ^ d)                    | a , b , (c ^ d)               |
|    6 | e              | Push operand  | –         | –                   | –                          | a , b , (c ^ d) , e           |
|    7 | -              | Pop & combine | (c ^ d)   | e                   | ((c ^ d) - e)              | a , b , ((c ^ d) - e)         |
|    8 | *              | Pop & combine | b         | ((c ^ d) - e)       | (b * ((c ^ d) - e))        | a , (b * ((c ^ d) - e))       |
|    9 | +              | Pop & combine | a         | (b * ((c ^ d) - e)) | (a + (b * ((c ^ d) - e)))  | (a + (b * ((c ^ d) - e)))     |
|   10 | END            | Final Answer  | –         | –                   | **Final Infix Expression** | **(a + (b * ((c ^ d) - e)))** |

# 3. Prefix to Infix Conversion
example: Prefix Expression: +a*b-^cd e
         Infix Expression: a + b * ( c ^ d - e )

- Now in this start from right to left (backward direction) 
- same as postfix to infix conversion just the direction is changed.

| Step | Scanned Symbol | Action        | Operand 1 | Operand 2           | Expression Formed         | Stack (Bottom → Top)          |
| ---: | -------------- | ------------- | --------- | ------------------- | ------------------------- | ----------------------------- |
|    1 | e              | Push operand  | –         | –                   | –                         | e                             |
|    2 | d              | Push operand  | –         | –                   | –                         | e , d                         |
|    3 | c              | Push operand  | –         | –                   | –                         | e , d , c                     |
|    4 | ^              | Pop & combine | c         | d                   | (c ^ d)                   | e , (c ^ d)                   |
|    5 | -              | Pop & combine | (c ^ d)   | e                   | ((c ^ d) - e)             | ((c ^ d) - e)                 |
|    6 | b              | Push operand  | –         | –                   | –                         | ((c ^ d) - e) , b             |
|    7 | *              | Pop & combine | b         | ((c ^ d) - e)       | (b * ((c ^ d) - e))       | (b * ((c ^ d) - e))           |
|    8 | a              | Push operand  | –         | –                   | –                         | (b * ((c ^ d) - e)) , a       |
|    9 | +              | Pop & combine | a         | (b * ((c ^ d) - e)) | (a + (b * ((c ^ d) - e))) | (a + (b * ((c ^ d) - e)))     |
|   10 | END            | Final Answer  | –         | –                   | **Final Infix**           | **(a + (b * ((c ^ d) - e)))** |
