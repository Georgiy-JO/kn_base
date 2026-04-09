# Standard data structures
Data can be structures in many ways. Some ways are better for one situation others for another. Some can be used in different algorithm solutions.

## Stack
- **FIFO** - First in - First out - the element that was added last will be the first to be taken.
  - Other elements can't be accessed or taken.
- Standard ways: ```stack.push(x)```(adds new element to the end of the stack), ```stack.pop()```(removes last element of the stack), ```x=stack.top()```(returns last element of the stack).

### Example 
- **C++**: ```std::stack```
- **Python**: ```list``` is used instead of stack.

### Usage examples
#### [Postfix notation](/General/Algorithms/parts/Postfix_notation.md)
#### Monotonic stack (stack of records)
- Input: array of ``n`` numbers.
- Task: for every element find one what is smaller than in from all the elements righter than it.
- Main idea: create and use monotonic *stack*.
- Logic:
  - create a *stack* of pairs (element + index);
  - go through the array from left to right:
    - if the element is smaller than **top** of the *stack*:
      - remove top element from the *stack* (the new element is the one we were looking for) - index of new element is the answer for the element from the *stack*;
      - repeat until the **top** element of the *stack* is smaller than the current element;
      - **push** the current element to the *stack*.
    - if the element is bigger than **top** of the *stack*:
      - **push** the current element to the *stack*.
  - in the end we will have stack that goes from smallest to the largest - these elements don't have a smaller one to the right;
- Output: pairs of (element + index) and elements without an answer in the stack.


## Queue
- **LIFO** - Last in - First out - the element that was added first will be the first to be taken.



## Deque

## Dictionary

## Array
