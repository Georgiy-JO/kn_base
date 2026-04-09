# Postfix notation

## Theory
There are different ways of writing arithmetical expressions:
- **Infix notation** - operations between the operands: 25 + 7 * (5 + 55 * 42 * (7 + 3) - 8) / 9
- **Prefix notation** (Polish notation) - operations before the operands: sin(x)
- **Postfix notation** (Reverse Polish notation) - operations after the operands: 25 7 5 55 42 7 3 + * * + 8 - * 9 / +

## Postfix notation calculation
The simplest way to work with postfix notation is using a [stack](/General/Data_structures/Stanard_data_structures.md#stack).

### Logic:
Go through the string of Reverse Polish notation from left to right:
- if there is a number, *push* it in **stack**;
- if there is an operator:
  - *pop* two last elements from the **stack** and preform the operation with those;
  - *push* the result into **stack**;
- continue...  

![ScShot_1](/General/Algorithms/media/postfix_1.png "Calculating postfix notation with stack") 

## Getting postfix notation
### From infix to postfix
To transform infix notation to postfix notation use following algorithm:
- create an operation **stack**;
- go through the string of infix notation from left to right:
  - if it is an operand, put is straight into resulting postfix notation string;
  - if it is an operation:
    - *pop* all the operations with higher or equal priority from the operation **stack** and put them into the resulting postfix notation string,
    - *push* this operation into the operation **stack**;
  - opening bracket goes into the operation **stack**;
  - closing bracket *pops* all operations from the operation **stack** and puts them into the resulting postfix notation string until the opening bracket is found and deletes the opening bracket;
  - at the end *pop* all the operations left in the operation **stack** and put them into the resulting postfix notation string.


