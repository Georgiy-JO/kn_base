# Standard data structures
Data can be structures in many ways. Some ways are better for one situation others for another. Some can be used in different algorithm solutions.

## Stack
- **LIFO** - Last in - First out - the element that was added last will be the first to be taken.
  - Other elements can't be accessed or taken.
- Standard ways: ```stack.push(x)```(adds new element to the end of the *stack*), ```stack.pop()```(removes last element of the *stack*), ```x=stack.top()```(returns last element of the *stack*).

### Example 
- **C++**: ```std::stack```.
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
- **FIFO** - First in - First out - the element that was added first will be the first to be taken.
- Standard ways: ```queue.push(x)```(adds new element to the end of the *queue*), ```queue.pop()```(removes first element of the *queue*), ```x=stack.front()```(returns first element of the *queue*).

### Example 
- **C++**: ```std::queue```.
- **Python**: ```from queue import Queue```.


## Deque
Double ended queue.
- Elements can be added and removed from both ends.
- Standard ways: ```deque.push_back(x)```(adds new element to the end of the *deque*), ```deque.push_front(x)```(adds new element to the beginning of the *deque*), ```deque.pop_back()```(removes last element of the *deque*), ```deque.pop_front()```(removes first element of the *deque*), ```x=deque.back()```(returns last element of the *deque*), ```x=deque.front()```(returns first element of the *deque*).

### Example 
- **C++**: ```std::deque```.
- **Python**: ```from collections import deque```.

### Usage examples
#### Minimum in window
- Input: array of ``n`` numbers.
- Task: for every element window length ``k`` find the smallest element in it.
- Main idea: go through the array from left to right, use *deque* to keep all the candidates to the minimum for future windows.
- Logic:
  - Creating a *deque* of candidates to the minimum:
    - if new element is smaller than the last element of the *deque*:
      - remove the last element from the *deque* (repeat until all larger elements are removed);
    - **push** the new element to the *deque* (we do it anyway);
    - if the element that is removed because we moved the window is the first element of the *deque*:
      - remove the first element from the *deque*;
  - As the result we will have the growing sequence in the *deque*, so the smallest element of the window is the first element of the *deque*.
  - move the window and repeat.
- Output: the smallest elements for all windows.

## Set
**Unordered collection** of **unique** elements. No duplicates allowed.
- Fast membership testing (`in` operation), insertion, and deletion (average O(1) time).
- Does not maintain insertion order (except in ordered variants like `std::set`).
- Standard ways: ```set.insert(x)``` (adds element if not present), ```set.erase(x)``` / ```set.remove(x)``` (removes element), ```set.count(x)``` / ```x in set``` (checks existence).

### Example 
- **C++**: ```std::unordered_set``` (hash-based) or ```std::set``` (ordered).
- **Python**: ```set``` (built-in).

## Dictionary
**Key-value** pairs (also called map or associative array).
- Keys must be unique and hashable. Values can be duplicated.
- Fast lookup, insertion, and deletion by key (average O(1)).
- Maintains insertion order in modern implementations (Python 3.7+, C++17+ `std::unordered_map` does not guarantee order).
- Standard ways: ```dict[key] = value``` (insert/update), ```dict[key]``` / ```dict.get(key)``` (access), ```del dict[key]``` / ```dict.erase(key)``` (remove), ``dict.count(key)`` / ```key in dict``` (check).

### Example 
- **C++**: ```std::unordered_map``` (hash-based) or ```std::map``` (ordered).
- **Python**: ```dict``` (built-in).

## Array
**Contiguous** collection of elements of the same type, accessed by **index**.
- Fixed size in many languages (or dynamic like vectors).
- Fast random access (O(1) by index), good cache locality.
- Standard ways: ```arr[index]``` (access/assign), ```arr.push_back(x)``` (dynamic resize in vectors), ```arr.size()``` (get length).

### Example 
- **C++**: ```std::vector<T>``` (dynamic) or raw ```T arr[N]``` (fixed).
- **Python**: ```list``` (dynamic array) or ```array.array``` (for primitive types).
