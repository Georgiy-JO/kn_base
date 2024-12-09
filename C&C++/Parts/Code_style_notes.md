# Style of a code

## Contents:
- [Style of a code](#style-of-a-code)
  - [Contents:](#contents)
  - [General](#general)
    - [Key Aspects of Code Style](#key-aspects-of-code-style)
    - [Benefits of a Consistent Code Style](#benefits-of-a-consistent-code-style)
  - [Code Style Guides](#code-style-guides)
    - [Example of C++ code style + guidelines](#example-of-c-code-style--guidelines)
      - [General rules:](#general-rules)
      - [Specific rules:](#specific-rules)
  - [Links](#links)


## General
Code style refers to a set of guidelines and conventions for writing code in a consistent and readable manner. It encompasses various aspects of programming, including formatting, naming conventions, and the organization of code. Adhering to a particular code style helps improve the maintainability, readability, and overall quality of the code, making it easier for developers to collaborate and understand each other's work.

### Key Aspects of Code Style
- **Indentation**: Consistent use of spaces or tabs for indentation helps to visually separate code blocks and makes the structure of the code clear. 
- **Naming Conventions**: Guidelines for naming variables, functions, classes, and other identifiers. Common conventions include:
  - **Camel Case**: myVariableName
  - **Snake Case**: my_variable_name
  - **Pascal Case**: MyClassName
  - **Choosing meaningful names** that convey the purpose of the variable or function enhances code readability.
- **Commenting**: Writing clear and concise comments to explain complex logic, describe the purpose of functions, or provide context for certain code sections. Comments should enhance understanding without being overly verbose.
- **Line Length**: Guidelines on the maximum length of a line of code (often 80 or 120 characters) to avoid horizontal scrolling and improve readability.
- **Whitespace**: Consistent use of whitespace around operators, after commas, and between code blocks can help improve readability. 
- **Function and Class Structure**: Guidelines on how to structure functions and classes, including the order of methods:
  -  constructor first, 
  -  followed by public methods, 
  -  then private methods.
- **Functions**: A well-designed function has the following characteristics:
  - Completely fulfills a clearly defined task;
  - Doesn't take on too much work;
  - Not linked to other functions without purpose;
  - Stores data as compressed as possible;
  - Helps recognize and separate program structure;
  - Helps get rid of excess that would otherwise be present in the program.
- **Error Handling**: Consistent practices for handling errors, such as using exceptions or error codes, and ensuring that error handling is clear and effective.
- **File Organization**: Guidelines on how to organize files and directories in a project, including naming conventions for files and the structure of modules and packages.
  
### Benefits of a Consistent Code Style
- **Readability**: Code that follows a consistent style is easier to read and understand, which is essential for collaboration among multiple developers.
- **Maintainability**: Consistent code is easier to maintain and update, as developers can quickly grasp the structure and purpose of the code.
- **Reduced Errors**: A well-defined code style can help prevent common programming errors and improve code quality.
- **Easier Onboarding**: New team members can more easily understand and contribute to the codebase when a consistent style is followed.
  
## Code Style Guides
Many programming languages and frameworks have established style guides that provide recommendations for code style. Some well-known style guides include:
- Python: PEP 8 (Python Enhancement Proposal 8);
- JavaScript: Airbnb JavaScript Style Guide, Google JavaScript Style Guide;
- Java: Google Java Style Guide;
- [C/C++: Google Style Guide](https://google.github.io/styleguide/cppguide.html);
- C#: Microsoft C# Coding Conventions;
- Ruby: Ruby Style Guide.

### Example of C++ code style + guidelines 
#### General rules:
- Global:
  - follow Google C++ guidelines (can be checked with `clang-format`);
  - avoid memory leaking situations;
  - use `const` where it's possible;
  - cover as many code as you can with tests;
  - program must be rational in terms of memory usage and the speed of the execution; 
  - global variables should be only constants or not used at all;
  - follow [SOLID](/General/Dictionaty.md)
  - **No magic numbers** - use named constants instead of magic numbers;
  - **no goto**;
  - `namespace`s must be used for logical code organization;
  - use `template` where it's possible;
- Levels and blocks of code:
  - code must be separated into [layers and abstractions](Dictionaty.md), if it is needed - code must be separated into functions and files according to logic and goals;
  - use logical file structure;
  - repeating code parts must be moved to a separate functions;
- Functions
  - any function (except `main`) should not contain more than 40-50 lines of code;
  - inserted code blocks should not consist of 4 or more insertions:
    ```C++
    for(...){
      for(...){
        for(...){
          if(){
            //...
          }
        }
      }
    }
    ```
    - in this case it is better to separate those into different functions;
  - void “chained” calls, where multiple functions call each other in a chain without returning a value in `main` (main should be a short description of the entire program);
- Naming:
  - use meaningful variable names;
  - use meaningful function names;
  - use meaningful class names;
  - variable and function naming must follow the Google standards;
- Comments
  - use meaningful comments - focus not on **what** does this code block do, but on **what** does it do it **for**;
  - use **title comment** - place a header comment that describes the purpose of the file at the top of each file;
  - use comments before classes and functions - describe the meaning of those, what kind of data receive, what do output;
  - comment hard parts of a code inside functions;
  - comments must follow the comment standard of the organization:
    - [Example](/C&C++/Parts/C++.md#comments-standards);
  - `//` is much more common;
- Classes and objects:
  - Encapsulation. Separate your objects by making all data fields in your class `private`, use getter and setter functions to work with those;
  - Always place declarations of classes and their parts in their own files, **ClassName.h** and always wrap `.h` class declaration files into a `#ifndef/#define/#endif` preprocessor block to avoid multiple declarations of the same class;
  - **(SRP)**: each class should solve only one task, separate functionality into separate classes if needed;
  - hierarchy must exist but must mot be overwhelmed:
    - child classes must complement and change the act of parent class;
    - child classes must not repeat the functionality of parent class, child classes must be needed and support polymorphism (do not create too complex hierarchy if it is not needed);
    - support polymorphism:
      - interfaces/abstract classes must be fully used and described in children classes; 
      - check that interface implementation can be easily swapped without damaging not related code (including code that uses it) - **the Dependency Inversion Principle**;
      - pure virtual functions should be used to create abstract parent classes if they are needed;
  - use [abstraction](/General/Dictionaty.md#abstraction) principles is classes - classes should hide the implementation and have clear interaction interface;
  - constructors and destructors must exist if reserves use and logic requires (ex. destructor if class has dynamic allocation of memory);
  - `const` should be used for methods that does not change the object (except static variables);
- Error handling:
  - code must include border cases and error handling;

#### Specific rules:
- naming style examples:
  - `class Employee`;
  - `int employee_count`;
  - `void CalculateSalary()`;
- better use **smart pointers** when working with dynamic memory;
- use **[STL containers](/C&C++/Parts/C++.md#stl-containers)** as much as possible if it fits the goal;
- use **[STL algorithms](/C&C++/Parts/C++.md#stl-algorithms)** when you work with *STL containers*;
- use `constexpr` where it's possible;
- [Comment standard](/C&C++/Parts/C++.md#comments-standards):
    ```C++
    /**
    * @brief умножает число на два.
    *
    * @param a — число для умножения.
    * @return — результат умножения.
    */
    int MultiplyByTwo(int a);
    ```
- use `nullptr` instead of `NULL` or "0" for pointers;
- use `enum class` instead of `enum`;
- use `auto` and other modern C++ features;
- better use `constexpr` and `inline` instead of macros; 
- when necessary, it is preferable to use multithreading with the standard library;
- use [**PCH**](/C&C++/Parts/C++.md#pch)
- use [lambda functions](/C&C++/Parts/C++.md#lambda-functions)
- [exceptions](/C&C++/Parts/C++.md#exceptions-error-handling) must be used for error handling.





## Links
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [Stanford C++ code style guide in RUS](https://tproger.ru/translations/stanford-cpp-style-guide)