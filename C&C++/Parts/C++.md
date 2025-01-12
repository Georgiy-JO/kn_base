# C++
- Created in year 1985.
- Developed by Bjarne Stroustrup.
- [Object-oriented programming](/General/Dictionaty.md#object-oriented-programming) (OOP) language.
  - The main principals of OOP are realized via [`class`](#object-and-class)
- Evolution of C.
  - Plenty of C elements, functions, etc. works here...

## Contents
- [Libraries](#libraries)
- [General (+ Situations and examples)](#general--situations-and-examples)
  - [Tips](#tips)
  - [**Lvalue** and **Rvalue**     (//❗❗)](#lvalue-and-rvalue-----)
  - [PCH  (//❗❗)](#pch--)
  - [For each loop](#for-each-loop)
  - [Ternary operator](#ternary-operator)
  - [Random numbers](#random-numbers)
  - [Matrices (2D array)](#matrices-2d-array)
  - [Recursion](#recursion)
  - [Macros](#macros)
- [Datatype +](#datatype-)
  - [Element initialization](#element-initialization)
    - [Copy initializes](#copy-initializes)
    - [Functional notation (Direct initialization)](#functional-notation-direct-initialization)
    - [Braced initialization (List Initialization)](#braced-initialization-list-initialization)
    - [Value initialization](#value-initialization)
    - [Declaration (no initialization)](#declaration-no-initialization)
    - [Auto initialization (❗***HINT***)](#auto-initialization-hint)
  - [References](#references)
    - [Constant references](#constant-references)
  - [Pointers](#pointers)
  - [Smart pointers (❗***HINT***)](#smart-pointers-hint)
    - [`std::unique_ptr`](#stdunique_ptr)
    - [`std::shared_ptr`](#stdshared_ptr)
  - [Extra data types](#extra-data-types)
  - [Strings](#strings)
    - [String built-in methods](#string-built-in-methods)
  - [Type Casting (Type Conversion)](#type-casting-type-conversion)
    - [Implicit Type Conversion (Automatic Conversion)](#implicit-type-conversion-automatic-conversion)
    - [Explicit Type Conversion (Type Casting)](#explicit-type-conversion-type-casting)
    - [Type Casting - C-style Casting](#type-casting---c-style-casting)
    - [Type Casting - `const_cast`](#type-casting---const_cast)
    - [Type Casting - `reinterpret_cast`](#type-casting---reinterpret_cast)
    - [Type Casting - `static_cast`](#type-casting---static_cast)
    - [Type Casting - `dynamic_cast`](#type-casting---dynamic_cast)
  - [Typedef and Using](#typedef-and-using)
    - [(❗***HINT***)](#hint)
- [Instruments](#instruments)
  - [Namespaces](#namespaces)
      - [(❗***HINT***) #1](#hint-1)
      - [(❗***HINT***) #2](#hint-2)
      - [(❗***HINT***) #3](#hint-3)
      - [(❗***HINT***) #4](#hint-4)
  - [Dynamic memory](#dynamic-memory)
      - [(❗***HINT***) new + initialization](#hint-new--initialization)
  - [Enumerations](#enumerations)
  - [Scoped enumeration(enum class)](#scoped-enumerationenum-class)
  - [Exceptions (Error handling)](#exceptions-error-handling)
      - [(❗***HINT***)](#hint-1)
  - [`constexpr`](#constexpr)
  - [Comments](#comments)
    - [Comments standards](#comments-standards)
- [Input - Output](#input---output)
  - [Input](#input)
    - [Standard input](#standard-input)
    - [Getline](#getline)
    - [(❗***HINT***)](#hint-2)
  - [Output](#output)
  - [Manipulators](#manipulators)
- [Files](#files)
- [Function](#function)
  - [Library functions](#library-functions)
      - [(❗***HINT***)](#hint-3)
    - [Fill()](#fill)
    - [std::terminate()](#stdterminate)
    - [std::abort()](#stdabort)
  - [Tips](#tips-1)
  - [Passing data to function (❗***HINT***)](#passing-data-to-function-hint)
  - [Functions default input](#functions-default-input)
    - [(❗***HINT***) (Fun default)](#hint-fun-default)
  - [Function template](#function-template)
      - [(❗***HINT***) `auto`](#hint-auto)
  - [Inline Functions (❗***HINT***)](#inline-functions-hint)
  - [Lambda Functions (❗***HINT***)](#lambda-functions--hint)
  - [Pointer to a function (//❗❗)](#pointer-to-a-function-)
- [Structure](#structure)
  - [Summery](#summery)
- [Object and Class](#object-and-class)
  - [General](#general)
  - [Constructor](#constructor)
      - [(❗***HINT***)](#hint-4)
      - [(❗***HINT***)](#hint-5)
      - [(❗***HINT***)](#hint-6)
  - [Destructor](#destructor)
  - [Overloaded constructors](#overloaded-constructors)
  - [Constant methods](#constant-methods)
  - [Overloading operators](#overloading-operators)
    - [Addition operator `+` (❗***HINT***)](#addition-operator--hint)
    - [Index operator `[]`](#index-operator-)
    - [Operator `()`](#operator-)
  - [Functors](#functors)
  - [Friend classes and functions](#friend-classes-and-functions)
  - [Inheritance](#inheritance)
    - [Protected constructor and destructor (❗***HINT***) (//❗❗)](#protected-constructor-and-destructor-hint-)
  - [Virtual method](#virtual-method)
    - [`override` and `final`](#override-and-final)
  - [**Abstract method** (Pure Virtual Functions)](#abstract-method-pure-virtual-functions)
  - [Abstract Classes](#abstract-classes)
  - [Interface](#interface)
  - [Multiple inheritance](#multiple-inheritance)
    - [Diamond inheritance (virtual classes declaration)](#diamond-inheritance--virtual-classes-declaration)
  - [Static attributes and Static methods](#static-attributes-and-static-methods)
    - [Static attributes](#static-attributes)
    - [Static method](#static-method)
  - [Methods outsource (❗***HINT***)](#methods-outsource-hint)
  - [Class template](#class-template)
    - [More info (//❗❗)](#more-info---)
- [Standard Template Library](#standard-template-library)
  - [STL containers](#stl-containers)
    - [Main Categories of STL Containers  (❗***HINT***)](#main-categories-of-stl-containers--hint)
  - [STL algorithms](#stl-algorithms)
    - [Common STL Algorithms](#common-stl-algorithms)
- [Multithreading (//❗❗)](#multithreading---)
- [Links](#links)

## Libraries 

| C++          | Description                                                        |
| ------------ | ------------------------------------------------------------------ |
| \<iostream>  | input/output                                                       |
| \<cmath>     | math functions                                                     |
| \<ctime>     | time related functions                                             |
| \<iomanip>   | facilities for manipulating the input and output format of streams |
| \<memory>    | [smart pointers](#smart-pointers-hint)                             |
| \<vector>    | dynamic array ([STL-c.](#sequence-containers))                     |
| \<map>       | pair data ([STL-c.](#associative-containers))                      |
| \<algorithm> | [STL algorithms](#stl-algorithms)                                  |
| \<stdexcept> | standard errors list                                               |
| \<string>    | extra for strings                                                  |
| \<fstream>   | to work with [files](#files)                                       |

## General (+ Situations and examples)

### Tips
- Assigning double value to an int variable truncates it
    ```C++
    int a = 3.7; // a is 3
    int a = 5.5; // a is 5
    int a = -5.5; // a is 5
    ```
- `const` keyword is used to declare a constant variable, it can be used with functions to prevent modification of the function's parameters (secure the data).
    ```C++
    void printer (const std::string &data_1, const int &data_2){...}
    ```
- `sizeof` operator returns the size of a variable or data type in bytes, it can be used with arrays to get the total size of the array in bytes
- If a function is described after the `main` function, it must be declared before it.
- If local and global variable share a same name, function will use the local version, unless you use `::` before the variable name:
    ```C++
    int a = 5;
    int main(){
        int a = 10;
        std::cout << a << std::endl; // prints 10
        std::cout << ::a << std::endl; // prints 5
    }
    ```
- ways to pass an array into a function (both actually receive a pointer):
    - 1:
    ```C++ 
    void fun1(){
        //...
        fun2(array);
    }
    void fun2(double passed_array[]){/*...*/ }
    ```
    - 2:
    ```C++ 
    void fun1(){
        //...
        fun2(array);
    }
    void fun2(double* passed_array){/*...*/ }
    ```
- `nullptr` - *NULL* pointer;
- `__cplusplus` - defined (exist) for g++ compiller.

### **Lvalue** and **Rvalue**     (//❗❗)
In C++, the terms **lvalue** and **rvalue** refer to different categories of expressions that determine how values are stored and manipulated in memory. 
  
#### Lvalue
An **lvalue** (locator value / left value) refers to an object that occupies some identifiable location in memory (i.e., it has an address). Lvalues can appear on the left-hand side of an assignment.
- Characteristics:
  - Can be assigned to.
  - Has a persistent state (lifetime).
  - Can be modified (if not declared as const).
- Examples:
    ```C++
    int x = 10;  // 'x' is an lvalue
    x = 20;      // You can assign a new value to 'x'

    int* p = &x; // You can take the address of 'x'
    ```

#### Rvalue
An **rvalue** (read value / right value) refers to a temporary object that does not have a persistent memory address. Rvalues typically represent temporary values that are created during expressions and cannot be assigned to.
- Characteristics:
  - Cannot be assigned to (they do not have a memory location).
  - Usually represent temporary objects or literals.
  - Can be moved from (in the context of move semantics).
- Examples:
    ```C++
    int y = 5;      // '5' is an rvalue
    int z = x + y;  // 'x + y' is an rvalue (temporary result)

    // You cannot do this:
    // 5 = x;       // Error: cannot assign to an rvalue
    ```

#### Lvalue and Rvalue References
With C++11, the concepts of **lvalue** and **rvalue** references were introduced to facilitate move semantics and perfect forwarding.
- **Lvalue Reference**: Denoted by &, it allows you to bind to lvalues.
    ```C++
    int a = 10;
    int& lref = a; // lref is an lvalue reference to 'a'
    ```
- **Rvalue Reference**: Denoted by &&, it allows you to bind to rvalues. This is particularly useful for implementing **move semantics**.
    ```C++
    int&& rref = 20; // rref is an rvalue reference to the temporary value '20'
    ```

#### Move Semantics
**Move semantics** allow the resources of temporary objects (rvalues) to be "moved" rather than copied, which can lead to performance improvements. This is particularly useful for classes that manage dynamic resources (like memory, file handles, etc.).
- Examples:
    ```C++
    #include <iostream>
    #include <vector>

    class MyClass {
    public:
        MyClass(std::vector<int> data) : data_(std::move(data)) {
            std::cout << "Constructor called\n";
        }

        // Move constructor
        MyClass(MyClass&& other) noexcept : data_(std::move(other.data_)) {
            std::cout << "Move constructor called\n";
        }

        // Copy constructor
        MyClass(const MyClass& other) : data_(other.data_) {
            std::cout << "Copy constructor called\n";
        }

    private:
        std::vector<int> data_;
    };

    int main() {
        MyClass obj1(std::vector<int>{1, 2, 3}); // Constructor called
        MyClass obj2(std::move(obj1));            // Move constructor called
        return 0;
    }
    ```

#### More info
1) [Click](https://youtu.be/5hY0PMgqSiA?si=uN-1btg452_tiKji)
2) [Click](https://youtu.be/Jw3uUe-NuLE?si=7sxuEW7EPnRVVGMi)

### PCH  (//❗❗)
**Precompiled headers (PCH)** are a feature used in C and C++ programming to speed up the compilation process. They allow the compiler to store the results of parsing and processing header files so that they do not need to be reprocessed every time a source file is compiled. This can significantly reduce compilation times, especially in large projects with many dependencies.

#### How Precompiled Headers Work
- **Creation of Precompiled Header**: A precompiled header is created by compiling a specific header file (or a set of header files) into a binary format. This typically includes standard libraries and frequently used headers that do not change often.
- **Using Precompiled Header**: When compiling source files, the compiler can use the precompiled header instead of reprocessing the original header files. This means that the compiler can skip the parsing and processing steps for those headers, leading to faster compilation.
- **File Format**: The precompiled header is usually stored in a binary format that is specific to the compiler being used. This means that precompiled headers are not portable between different compilers.

#### Benefits of Precompiled Headers
- **Reduced Compilation Time**.
- **Improved Build Performance**: In large projects, where many source files depend on the same set of headers, using precompiled headers can lead to a more efficient build process.
- **Simplified Dependency Management**: Precompiled headers can help manage dependencies more effectively, as changes to header files will only require recompilation of the affected source files rather than all files that include those headers.

#### Drawbacks of Precompiled Headers
- **Complexity**: Setting up precompiled headers can add complexity to the build process. Developers need to ensure that the precompiled header is updated whenever the included headers change.
- **Portability Issues**: Precompiled headers are often specific to a particular compiler and may not be portable across different compilers or even different versions of the same compiler.

#### Examples of Using Precompiled Headers
- **Create a Precompiled Header File**: Create a header file, typically named **pch.h**, that includes the headers you want to precompile.
    ```C++
    // pch.h
    #ifndef PCH_H
    #define PCH_H

    #include <iostream>
    #include <vector>
    #include <string>

    // Add other frequently used headers here

    #endif // PCH_H
    ```
- **Compile the Precompiled Header**: Use your compiler's options to compile this header file into a precompiled header. 
  - For example, in GCC:
    ```bash
    g++ -o pch.pch -x c++-header pch.h
    ```
- **Use the Precompiled Header in Your Source Files**: In your source files, include the precompiled header at the top.
    ```C++
    // main.cpp
    #include "pch.h"
    int main() {
        std::cout << "Hello, World!" << std::endl;
        return 0;
    }
    ```
- **Compile Your Source Files**: When compiling your source files, ensure that the compiler knows to use the precompiled header.

### For each loop
A cycle structure that ease going through an iterable data set.
- Does not work if the amount of elements is not preset or is unknown.
- Does not work with elements themselves, just create a copy (can be bypassed by using [references](#references)).

#### Syntax
```C++
for( <datatype> <name_single_element> : <anme_of_dataset>){...}
```

#### Examples
- **#1**
    ```C++
    std::string numbers[]={"one", "two", "three", "four", "five"};
    for( std::string number : numbers){
        std::cout << number<< std::endl;
    }
    double decimals[]={1.0, 2, 3, 4, 5};
    for (double dec: decimals){
        std::cout << dec << std::endl;
    }
    ```
- **#2**
```C++
int arr[]={1,2,3,4,5};

for(int i : arr)
    i*=2;
for(int i : arr)
    std::cout << i << ' ';  //1 2 3 4 5
std::cout << std::endl;
//with references
for(int &i : arr)
    i*=2;
for(int i : arr)
    std::cout << i << ' ';  //2 4 6 8 10
std::cout << std::endl;
```

### Ternary operator
The ternary operator is a shorthand way to write a simple if-else statement. 

```C++
if(x=='Y')
    std::cout << "YES";
else
    std::cout << "NO";
//or
std::cout << (x=='Y' ? "YES" : "NO");
//or
x=='Y'?std::cout << "YES":std::cout <<"NO";
```

### Random numbers
(actually are pseudo-random)

#### C style
1. Include \<ctime>.
2. Use `srand(time(NULL))` to seed the random number generator.
3. Use `x = rand()` to generate a random number (from 0 to 32767).
    - Use `y = rand()%n` to generate a random number between 0 and n-1.

#### C++ style
```C++
#include <iostream>
#include <random>
#include <chrono> // Для инициализации seed

int main() {
    // Инициализация генератора случайных чисел с помощью seed на основе текущего времени
    auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::mt19937 mt(seed);

    // Создание распределений
    std::uniform_int_distribution<int> int_dist(1, 10);         // Равномерное распределение для целых чисел
    std::uniform_real_distribution<double> real_dist(0.0, 1.0); // Равномерное распределение для вещественных чисел

    // Генерация случайных чисел
    int random_int = int_dist(mt);     // Случайное целое число [1, 10]
    double random_double = real_dist(mt); // Случайное вещественное число [0.0, 1.0]

    // Вывод результатов
    std::cout << "Случайное целое число [1, 10]: " << random_int << "\n";
    std::cout << "Случайное вещественное число [0.0, 1.0]: " << random_double << "\n";

    return 0;
}
```

### Matrices (2D array)
- The number of columns must be set with number:
    ```C++
    int matrix[][3] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};
    ```
- The number of rows can be calculated:
    ```C++
    int rows = sizeof(matrix)/sizeof(matrix[0]);
    ```
- The number of columns can be calculated:
    ```C++
    int columns = sizeof(matrix[0])/sizeof(matrix[0][0]);
    ```


### Recursion 
A programming technique there a function that invokes (calls) itself from within.
- The function calls itself until it reaches a base case that stops the recursion.
- The recursion can be used to solve problems that have a recursive recitative structure (good for sorting or searching algorithms, for working with tree-like structures).
- In comparison with iterative algorithms:
    - pros: less and cleaner coding;
    - cons: uses more memory and is slower.


### Macros
Macros is a feature provided by the preprocessor, which is a tool that processes your source code before it is compiled. Macros allow you to define code snippets that can be reused throughout your program, and they can be used for a variety of purposes, such as defining constants, creating inline functions, or conditionally compiling code.

#### Example
```C++
//Object-like Macros
#define PI 3.14159
//Function-like Macros
#define SQUARE(x) ((x) * (x))
int main(){
    //...
    double area = PI * radius * radius;
    //...
    int square = SQUARE(5);// Expands to ((5) * (5))
}
```

## Datatype +

### Element initialization
C++ allows different ways of initialization of an element.
#### Copy initializes 
C style.
```C++
double x=-5.44;
std::string str ="Hello"; 
int arr[] = {1, 2, 3, 4, 5};
```

#### Functional notation (Direct initialization)
Better use this one for C++;
- Does not check the data type it initialize.
```C++
double x(-5.44);
std::string str("Hello");
int y(2+4*5);           //22

int notInt(5.4);        //5
```

#### Braced initialization (List Initialization)
Best for C++ lists, vectors, arrays, etc.
- Does check the data type it initialize
```C++
double x{-5.44};
std::string str{"Hello"};
int arr[]{1, 2, 3, 4, 5};
chat ch{'b'};
int y{2+4*5};           //22

int notInt(5.4);        //error
```

#### Value initialization
Initialization with default value (most times **0**).
```C++
int x{}; // Value initializes x to 0
std::string str{}; // Value initializes str to an empty string
```
#### Declaration (no initialization)
No initialization (value most times will just keep the memory garbage).
```C++
int x;
std::string str;
```
- Better use initialization with set values, than this one.

#### Auto initialization (❗***HINT***)
C++ can automatically decide what type to use.
- From C++11
- `auto`
    ```C++
    auto x = 5.44;                  //double
    auto y = 5.44f;                 //float
    auto str{"Hello"};              //std::string
    auto arr = {1, 2, 3, 4, 5};     //int[]
    auto ch('f');                   //char
    auto z((short)10+100000UL);     //unsigned long
    auto k{5*6+x};                  //double 

    const int v=5;
    int* p=nullptr;
    const int* i=nullptr;
    auto q = p;                     //int*
    auto q1 = *p;                   //int
    auto q2 = &p;                   //int**
    auto r=v;                       //int
    const auto r1=v;                //const int
    auto j = i;                     //const int*
    auto j2 = *i;                   //int
    auto j3 = &i;                   //const int**
    ```
- To force the type completely: `decltype(<variable>)`.
    ```C++
    const int v=5;
    const int* i=nullptr;
    decltype(v) r;                  //const int
    decltype(i) j;                  //const int*
    ```
- `auto` and `decltype` work not only for initialization.

#### [Examples of initialization](#hint-new--initialization)


### References
(Ссылки)
**Reference** is an alias for another variable (another name for an existing variable). 
  - It must be **initialized** when it is declared and **cannot** be changed to refer to another variable later.
  - Using **reference** instead of copying values into a function if faster.
```C++
int x = 5;
int& lnk_x = x;          // y is a reference to x
cout<< x <<endl;     //5
cout<< lnk_x <<endl;     //5

int a=10;
int* ptr_a=&a;
int ar[]={1,2,3};
int& ref_a=a;           //ok
int& &ref_ptr_a=*ptr_a; //ok
int& ref_ar=ar[0];      //ok
int& ref=10;            //error
int& &ref_ptr_a=ptr_a;  //error
```
#### Constant references
- **Constant reference** is a reference that does allow seeing data, but does not allow to change it.
```C++
    int a=5;
    const int& lnk_a=a;
    cout << lnk_a <<endl;
    a=10;
    cout << lnk_a <<endl;
    lnk_a=5;                //error    

    const int b=5;
    const int& lnk_b=b;     //ok
    int& lnk_b_1=b;         //error 
```

### Pointers
Pointers are variables that hold the memory address of another variable.
- The `&`- *address-of operator* is used to get the memory address of a variable, it can be used to pass variables to functions by reference.
- The `*` operator is used to get the value of the variable at the memory address or the value of a variable that a pointer is pointing.
- The `NULL` constant is used to represent a null pointer.
- To assign a `NULL` constant to a pointer or check if a pointer is `NULL`: ```std::string *pStr=nullptr;```
- Pointers' names are usually created by adding '**p**' to a variable name (like "**pName**").

#### Examples
```C++
std::string str="rock";                              //string
std::string strs[]={"Rock", "Jazz", "Classics"};     //array of strings
std::string *pStr=&str;                              //pointer to a string 
std::string *pStrs[]={(strs+0),(strs+1),(strs+2)};   //array of pointers
std::string *pStrs2=strs;                            //pointer to an array
```

### Smart pointers (❗***HINT***)
Smart pointers in C++ are objects that manage dynamic memory and automatically release it when the pointer is no longer needed. This helps prevent memory leaks and simplifies resource management. The C++ Standard Library provides several types (classes) of smart pointers, with `std::unique_ptr` and `std::shared_ptr` being the most common.  
- Working with smart pointers requires `#include <memory>`
- `std::unique_ptr` and `std::shared_ptr` can't be mixed (they are different classes).

#### `std::unique_ptr`
`std::unique_ptr` is a smart pointer that provides unique ownership of an object. This means that only one `std::unique_ptr` can point to the that memory at a time. When a `std::unique_ptr` goes out of scope or is initialized with another pointer, the object is automatically released.
- `std::make_unique` is a utility function (from C++14) that simplifies the creation of `std::unique_ptr`. Using `std::make_unique` is preferred over using `new` directly because it helps prevent memory leaks and makes the code safer and cleaner (requires `#include <memory>` too).
  - Syntax:
    ```C++
    std::unique_ptr<T> <pointer_name> {make_unique<T>(Args&&... args)}
    ```
    - Where `T` is the type of the object you want to create, and `Args` are the arguments that will be forwarded to the constructor of `T`.
- Methods of `unique_ptr`:
  - `get()` - return a raw pointer to the allocated memory.
  - `release()` - return a raw pointer to the allocated memory and disconnect smart pointer from it (does not free it).
  - `reset()` - reset the smart pointer to point to a new object or to nothing and free the allocated memory.
  - `swap()` - swap the addresses of 2 smart pointers.
  - etc.

#### `std::shared_ptr`
`std::shared_ptr` is a smart pointer that provides shared ownership of an object. The object will be released when the last `std::shared_ptr` pointing to it is destroyed or reset.
- `std::make_shared` is a utility function in C++ that simplifies the creation of `std::shared_ptr`(requires `#include <memory>` too). 
  - Syntax:
    ```C++
    std::shared_ptr<T> <ptr_name> = make_shared<T>(Args&&... args);
    ```
    - Where `T` is the type of the object you want to create, and `Args` are the arguments that will be forwarded to the constructor of `T`.
- Methods of `shared_ptr`:
  - `get()` - return a raw pointer to the allocated memory.
  - `reset()` - reset the smart pointer to point to a new object or to nothing and free the allocated memory.
  - `swap()` - swap the addresses of 2 smart pointers.
  - `use_count()` - return the number of `shared_ptr` objects pointing to the same memory space (will not count raw pointers).
  - `unique()` - return **true** if only one pointer reference the memory, **false** - if 2 and more.
  - etc.
- Memory control for `std::shared_ptr` be like:  
    ![Memory_ctrl_shared_ptr_1](/C&C++/media/shared_ptr_1.png "Two point to one")  
    ![Memory_ctrl_shared_ptr_2](/C&C++/media/shared_ptr_2.png "Each point to different")  
    ![Memory_ctrl_shared_ptr_3](/C&C++/media/shared_ptr_3.png "When not a single one is pointing, it gets deleted") 
- Memory control for `std::shared_ptr` for class be like:   
    ![Memory_ctrl_shared_ptr_4](/C&C++/media/shared_ptr_4.png "Two point to one")  


#### Examples `unique_ptr`
- **#1**: smart pointers:`unique_ptr`: general
    ```C++
    #include <iostream>
    #include <memory>
    int main(){
        std::unique_ptr<int> ptr;           //creating of unique smart pointer for int value, the pointer's value will be NULL
        std::shared_ptr<int> ptr2 {};       //creating of shared smart pointer for int value, the pointer's value will be NULL
        std::shared_ptr<int> ptr3 {nullptr};//creating of shared smart pointer for int value, the pointer's value will be NULL
        std::shared_ptr<int> ptr4 {std::make_unique<int>(55)};  //creating and initializing a pointer with value

        ptr=std::make_unique<int>(10);      //allocation memory for the pointer and writing 10 there

        (*ptr)++;                           
        std::cout << *ptr << std::endl;     //output: 11  
        //...                               //can work with smart pointer the same way as with raw ones
        ptr=std::make_unique<int>(11);      //will free the previos memory and allocate new 
        ptr2=ptr;                           //error
        return 0;
    }
    ```
- **#2**: smart pointers: `unique_ptr`: methods
    ```C++
    #include <iostream>
    #include <memory>
    int main(){
        std::unique_ptr<int> ptr {std::make_unique<int>(55)};
        std::unique_ptr<int> ptr2 {std::make_unique<int>(155)};

        int* p =ptr.get();
        std::cout << *p << std::endl;       //output: 55

        int* p2 = ptr.release();
        std::cout << *p2 << std::endl;      //output: 55
        std::cout << ptr.get() << std::endl;//output: 0
        delete p2;

        ptr = std::make_unique<int>(55);
        ptr.reset();
        std::cout << ptr.get() << std::endl;//output: 0
        ptr.reset(new int(143));            //does not allow `make_unique`
        std::cout << *ptr << std::endl;     //output: 143
        
        std::swap(ptr, ptr2);
        std::cout << *ptr << std::endl;     //output: 155
        std::cout << *ptr2 << std::endl;    //output: 143

        return 0;
    }
    ```
- **#3**: smart pointers: `unique_ptr`:arrays
    ```C++
    int main(){
        unsigned total (10);
        std::unique_ptr<int[]> ar {std::make_unique<int[]>(total)};
        auto ar2 {std::make_unique<int[]>(3)};
        std::unique_ptr<int[]> ar3 {nullptr};

        for (int i=0;i<total;i++){
            ar[i]=i*i;
        }
        for(int i=0;i<total;i++){
            std::cout << ar[i] << " ";
        }
        std::cout << std::endl;
        
        return 0;
    }
    ```
#### Examples `shared_ptr`
- **#4**: smart pointers:`shared_ptr`: general
```C++
#include <iostream>
#include <memory>
int main(){
    std::shared_ptr<int> ptr;
    std::shared_ptr<int> ptr2{};
    std::shared_ptr<int> ptr3{nullptr};
    std::shared_ptr<int> ptr4{ptr};     //ptr and ptr4 refference the same memory
    std::shared_ptr<int> ptr5 = ptr2;   //ptr2 and ptr5 refference the same memory
    std::shared_ptr<int> ptr6 {std::make_shared<int>(55)};
    std::shared_ptr<int> ptr7 = std::make_shared<int>(55);

    ptr3=ptr6;           //ptr3 not has the same address as ptr6
    *ptr7=10;
    std::cout << ptr7 <<" "<< *ptr7 << std::endl;     //will autput address and value
    // can act like a usual raw pointer, except address arithmetic:
    ptr7+=10;                   //error
    auto res= ptr3-ptr4;        //error

    std::unique_ptr<int> ptr8; 
    ptr8=ptr7;                  //error

    return 0;
}
```
- **#5**:smart pointers:`shared_ptr`: methods
```C++
int main(){
    std::shared_ptr<int> ptr{std::make_shared<int>(55)};
    std::shared_ptr<int> ptr2{ptr};

    ptr2.reset(new int[5]{1,2,3});
    int* ar=ptr2.get();             //that is needed because shared_ptr can't work will arrays usual way

    for(int i=0;i<5;i++){
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;            
    ptr2[3]=8;                      //error: because shared_ptr can't work will arrays usual way 

    ptr2.swap(ptr);
    std::cout << *ptr2 <<' '<<ptr.use_count()<< std::endl;  //output: 55 1
    std::cout << ptr.unique() << std::endl;                 //output: 1

    ptr=ptr2;
    std::cout << *ptr2 <<' '<<ptr.use_count()<< std::endl;  //output: 55 2
    std::cout << ptr.unique() << std::endl;                 //output: 0   
    return 0;
}
```
- proper work with arrays for shared_ptr will be available from C++20

### Extra data types 
Some extra data types.

| Type       | Description                                     | Inc in                         | Size                                 |
| ---------- | ----------------------------------------------- | ------------------------------ | ------------------------------------ |
| `bool`     | can be `true`(1) or `false`(0)                  | exists by default              | 1 byte                               |
| `wchar_t`  | expended char (for Unicode)                     | exists by default              | 2 byte - Windows <br> 4 byte - Linux |
| `char8_t`  | 8-bit Unicode character (for Unicode (UTF-16))  | exists by default (from C++20) | 1 byte                               |
| `char16_t` | 16-bit Unicode character (for Unicode (UTF-16)) | exists by default              | 2 byte                               |
| `char32_t` | 32-bit Unicode character (for Unicode (UTF-32)) | exists by default              | 4 byte                               |

#### Example
```C++
wchar_t x;
char y;
y='Я';              //out of range error
x ='Я';             // error
x = L'Я';           // L is used for wide character list
cout<<x<<endl;      //1071 - code of symbol 
char line[]="Привет"
cout<<line<<endl;   // prints "Привет"
y=line[0];
cout<<y<<endl;      // undefind character
```
- Code of the symbol depend on the coding system of out file (UTF-8, etc.).
- `wchar_t` is useful for UTF-8 etc.
- `char` is alright for Windows-1251, ASCII etc.

### Strings
A string is an object (of `string` class) that represents a sequence of text. Strings are provided from the standard namespace. String is a reference datatype (it actually stores a pointer to the place where the data is located). Strings are dynamically allocated. Strings still have **'\0'** at the end. Strings can be read using [`cin`](#input) or [`getline()`](#getline).
```C++
std::string name = "Jack";
std::string address = "My_street 55, flat 25";
```

* Strings can be summarized:
    ```C++
    std::string name = "Jack";
    std::string second_name = "ONeill";
    std::string full_name = name + " " + second_name;
    ```
* String part can be called like an array element.
    ```C++
    std::string str="hello world";
    std::cout << str[3] << std::endl;       //l
    str[4]='a';
    std::cout << str << std::endl;          //hella world
    ```
* Strings can be easily replaced/swapped/etc:
    ```C++
    std::string name1 = "Jack";
    std::string name2 = "ONeill";
    std::string tmp;
    tmp = name1;
    name1 = name2;
    name2 = tmp;
    ```
* There are [methods](#string-built-in-methods) to make work with strings simpler.

#### String built-in methods
Include:
- length
- emptiness 
- clean
- append
- get a char
- insert string
- find char
- erase part
- size
- capacity
- data
- [etc](https://cplusplus.com/reference/string/string/)

**String length, size, capacity**
- `capacity` - how much place was allocated';
- `size` - how much place is used;
- `length` - how much place is used (same as `size`).
```C++
std::string full_name="Jack O'Neill";
cout<<"The length of the string is: "<<full_name.length()<<endl;    //12
cout<<"The size of the string is: "<<full_name.size()<<endl;        //12
cout<<"The capacity of the string is: "<<full_name.capacity()<<endl;//15
```

**String empty**
```C++
if (full_name.empty()) {
    std::cout << "The string is empty." << std::endl;
}
```

**String clear**
```C++
full_name="Jack";
std::cout << full_name << std::endl; //Jack
full_name.clear();
std::cout << full_name<< std::endl; // 
```

**String append**
```C++
full_name = "Jack ";
std::string surname = "Oneill";
full_name.append(surname); 
```

**Convert to char string**
- The `c_str()` method of `std::string` returns a pointer to a null-terminated character array representing the string's content.
```C++ 
std::string surname {"Oneill"};
const char* surname2=surname.c_str();
```


**String get char**
```C++
std::string full_name = "Jack";
std::cout<< full_name.at(0); //J
```

**String insert string**
```C++
std::string full_name = "Jack";
full_name.insert(0,"@");    //@Jack
full_name.insert(1,"@");    //J@ack
full_name.insert(1,"Ro");   //JRoack
```

**String find char**
```C++
std::string full_name = "Jack";
size_t pos = full_name.find('a'); // 1
```

**String erase part**
```C++
std::string full_name = "Jack";
std::cout << full_name.erase(1,2)<< std::endl;  //Jk
std::cout << full_name.erase(1,3)<< std::endl;  //J
```
- In `.erase(<begin_index>,<end_index>)` *<begin_index>* in inclusive, *<end_index>* is not.

**Data**
- `data` return the C-kind string from object string.
```C++
std::string full_name = "Jack";
char* cstr = full_name.data();
printf("%s\n",cstr);
```

### Type Casting (Type Conversion)

#### Implicit Type Conversion (Automatic Conversion)
Implicit conversion is allowed when the destination type is larger than the source type.
```C++
int a = 10;
float b = a; // Implicit conversion from int to float
```

#### Explicit Type Conversion (Type Casting) 
The programmer explicitly defines the conversion using a cast operator.
There are several types of explicit type conversion in c++:
- [**C-style Casting**]
- **`static_cast`**;
  - **`std::static_pointer_cast`**;
- **`dynamic_cast`**;
  - **`std::dynamic_pointer_cast`**;
- **`const_cast`**;
- **`reinterpret_cast`**;

#### Type Casting - C-style Casting
```C++
int a = (int)3.14; // C-style explicit cast
```

#### Type Casting - `const_cast`
Used to add or remove the `const`(and `volatile`) qualifier from a variable.
- Can be used for **links** and **pointers**.
- Logically it is not very safe operator, better not to use it, unless it is really needed. 
```C++
int a;
conts int* ptr_a=&a; 
int * ptr=const_cast<int*>(ptr_a);              // Removes constness
const int* ptr_cnst=const_cast<const int*>(&a); // Adds constness
const int& const_lnk_a=a;
int& lnk_a=const_cast<int &>(const_lnk_a);      // Removes constness
int d=const_cast<int>(a);                       //ERROR
```

#### Type Casting - `reinterpret_cast`
Casting from one type to another with some checking by the compiler.
- Can be used for **links** and **pointers**.
  - Including pointers and links to user types (structures, etc.).
- Works similar with *C-style Casting*.
```C++
int a=10;
int * ptr_a=&a;
char ptr_ch=reinterpret_cast<char*>(ptr_a);// Reinterprets int pointer as char pointer
char lnk_a=reinterpret_cast<char&>(a);
void ptr_ch=reinterpret_cast<void*>(&a);
```

#### Type Casting - `static_cast`
Casting with taking into account lines of inheritance of structures and classes during the compilation.
- Used for safe conversions between related types.
- Similar to `reinterpret_cast`, but has more strict rules.
- `std::static_pointer_cast` - analog for [smart pointers](#smart-pointers-hint).
```C++
struct point2D{
    int x,y;
};
struct point3D{
    int x,y,z;
};
struct point4D:point2D{
    int x,y,z,i;
};
int main(){
char ch{0};
short sh{0};
int i{0};
double d{0};
point2D* ptr_2d=new point2D;

char* ptr_ch {&ch};
short* ptr_sh {&sh};
int* ptr_i {&i};
double* ptr_d {&d};

ch=static_cast<char>(sh) ;      //ok
ch=reinterpret_cast<char>(sh);  //error

d=static_cast<double>(i);       //ok
d=reinterpret_cast<double>(i);  //error

sh=static_cast<short>(ptr_i);    //error
sh=reinterpret_cast<short>(ptr_i);  //ok

ptr_d=static_cast<double*>(ptr_ch);       //error
ptr_d=reinterpret_cast<double*>(ptr_ch);  //ok

point3D* ptr_3d=static_cast<point3D*>(ptr_2d);       //error
point3D* ptr_3d=reinterpret_cast<point3D*>(ptr_2d);  //ok

point4D* ptr_4d=static_cast<point4D*>(ptr_2d);       //ok
point4D* ptr_4d=reinterpret_cast<point4D*>(ptr_2d);  //ok
return 0;
}
```

#### Type Casting - `dynamic_cast`
Casting with taking into account lines of inheritance of structures and classes during program execution.
- Allows checking if an object has the class we are interested in.
  - If we use `dynamic_cast` on wrong pointer, it returns `nullptr`,
  - If we use `dynamic_cast` on correct pointer, it returns the pointer to the object.
  - If we use `dynamic_cast` on wrong reference, it returns `bad_cast` ([*](https://en.cppreference.com/w/cpp/types/bad_cast));
  - If we use `dynamic_cast` on correct reference, it returns the reference to the object.
- The only casting that works during program execution.
- Can be used for **reference** and **pointers**.
- To define the class it uses virtual table of methods for classes, so if there is no virtual methods in classes, `dynamic_cast` can't be used.
- Uses *RTTI* technology - slows down the program - better not be used.
- `std::dynamic_pointer_cast` - analog for [smart pointers](#smart-pointers-hint).
```C++
class Thing{
    public:
        virtual void print() const{};
};
class Ball:public Thing{
    int radius;
    public:
        virtual void print() const override{ puts("Ball");}
};
class Mouse: public Thing{
    public:
        virtual void print() const override{ puts("Mouse");}
};
class Cart{
    public:
        void add_thing(const Thing& th){
            th.print();
            const Ball* ptr_ball=dynamic_cast<const Ball*>(&th);    
            // if `th` is a Ball object link ptr_ball=&th
            // if `th` is some other `Thing` ptr_ball=nullptr
            if(ptr_ball!=nullptr){
                puts("It's a ball!")
                //do somethinf
            }
        }
}
```





### Typedef and Using
`typedef` is a keyword in C++ that allows you to give a new name or alias to an existing type. This can make your code more readable and easier to understand.
* Usually the new datatype has **_t** at the end of the name.
* New datatype can be used the same way as old datatype, and old datatype can be used at the same time as new datatype.

####  (❗***HINT***)
`typedef` is usually replaced by `using` (using works better with templates).

```C++
typedef std::string text_t;
int main(){
    text_t name = "Jack";
    //...

using text_t = std::string;
int main(){
    text_t name = "Jack";
    //...
```


## Instruments

### Namespaces
Namespace is a declarative region that provides a scope to the identifiers (such as variables, functions, classes, etc.) inside it. Namespaces are used to organize code and prevent name conflicts, especially in large projects or when using libraries that may have overlapping names.
- `::` - symbol of opening a namespace.
- Using `::` without setting the namespace before activate the standard **global namespace**.
    ```C++
    int global=5;
    int global_2=10;
    int main(){
        int global_2=15;
        std::cout<<::gloabal<<std::endl;    //5
        std::cout<<gloabal<<std::endl;      //5
        std::cout<<::global_2<<std::endl;   //10
        std::cout<<global_2<<std::endl;     //15
    }
- **Global namespace** is a default namespace of the program for those global variables, structures, etc. that do not have any namespace set.
- `using` - allows to use the names from the namespace without prefixing them with the namespace name.

#### Standard namespace
In C++, `std` is the **standard namespace** that contains all the standard library functions, classes, and objects. The C++ Standard Library provides a rich set of functionalities, including input/output operations, data structures, algorithms, and more, which are essential for C++ programming.

* **Standard Library Headers**: To use components from the `std` namespace, you need to include the appropriate headers. For example:
    - `#include <iostream>` for input/output streams.
    - `#include <vector>` for the vector container.
    - `#include <algorithm>` for algorithms like `std::sort`.

#### Key Features of Namespaces
**Avoiding Name Conflicts**: Namespaces allow you to define functions, classes, and variables with the same name in different contexts without causing conflicts. For example, you can have two functions named print() in different namespaces.

**Organizing Code**: Namespaces help in logically grouping related code together, making it easier to manage and understand.
**Nested Namespaces**: You can define namespaces within other namespaces, allowing for a hierarchical organization of code.
**Using Directives**: You can use the using directive to bring names from a namespace into the current scope, which can simplify code but may also lead to name conflicts if not used carefully.

#### Examples
```C++
namespace first {
    int x = 5;
}
namespace Second {
    int x = 9;
}
// Example 1
int main(){
    int x=0;
    std::cout << "Global x: " << x << std::endl;                    //0
    std::cout << "First namespace x: " << first::x << std::endl;    //5
    std::cout << "Second namespace x: " << Second::x << std::endl;  //9
    return 0;
}

// Example 2
int main(){
    using namespace first;
    std::cout << "First namespace x: " << x << std::endl;           //5
    std::cout << "Second namespace x: " << Second::x << std::endl;  //9
    return 0;
}
```

####  (❗***HINT***) #1
Namespace can be added to later in a program:
```C++
namespace first {
    int x = 5;
}
namespace Second {
    int x = 9;
}
namespace first {
    std::string line = "myLine";
}
```
- This adjusted namespace is seen as one by the program.
- This parts of a namespace can be in different files (example: `std`).
- 
####  (❗***HINT***) #2
`using` with **namespaces** allows cutting down some repetitions in code by importing elements for a particular namespace. Can be used inside a function (so it will be active for the function) or outside it for global effect. But the standard namespace is so huge so using it straight would cause too much intersection. 
* Syntaxes:   
  1) `using namespace <name_of_namespace>;`
  2) `using <name_of_namespace>::<element>;`
* Wrong way to use:
    ```C++
    using namespace std;

    string name = "Jack";               //std::string name = "Jack";
    cout << "My name is  " << name;     //std::cout << "My name is  " << name;
    ```
* Better way:
    ```C++
    using std::cout;
    using std:: string;

    string name = "Jack";               //std::string name = "Jack";
    cout << "My name is  " << name;     //std::cout << "My name is  " << name;    
    ```
####  (❗***HINT***) #3
Namespaces can be nested:
```C++
namespace first {
    namespace second {
        int x = 5;
    }
}
int main(){
    std::cout << first::second::x << std::endl;  //5
}
```
####  (❗***HINT***) #4
Namespaces name can be removed from calling by `inline`:
```C++
namespace first {
    inline namespace second {
        int x = 5;
    }
}
int main(){
    std::cout << first::x << std::endl;          //5
    std::cout << first::second::x << std::endl;  //5
}
```


### Dynamic memory  
Memory that is allocated after the program is already compiled and running. 
- This memory is allocated in the heap, which is a big segment of the memory assigned to the program.  
![Memory](/C&C++/media/program_memory.png "Memory of a program")
- The `new` operator is used to allocate memory dynamically - allocates memory and calls the [constructor](#constructor) (if it exists).
  - Use `new` to allocate memory for one object.
  - Use `new[]` to allocate memory for an array of objects.
- The `delete` operator is used to free the memory - frees memory and calls [destructor](#destructor) (if it exists).
  - Use `delete` when you want to deallocate memory that was allocated for a single object using `new`.
  - Use `delete[]` when you want to deallocate memory that was allocated for an array of objects using `new[]`.
- Pointers that do not manage the lifetime of the objects they point to (regular pointers) are called raw pointers.
- After using `delete` it is a good practice to assign to the pointer `nullptr`, this way in case you call `delete` again no error will happen. 

#### Example
- ***#1***
    ```C++
    using namespace std;

    int **matrix=nullptr;
    int rows=0, columns=0;

    cin>>rows;
    cin>>columns;

    matrix = new int*[rows];
    for (int i=0;i<rows;i++){
        matrix[i]=new int[columns];
    }

    for (int i=0;i<rows;i++){
        for (int j=0;j<columns;j++){
            cin>>matrix[i][j];
        }
    }

    for (int i=0;i<rows;i++){
        for (int j=0;j<columns;j++){
            cout<<matrix[i][j]<<" ";
        }
    cout<<endl;
    }

    for (int i=0;i<rows;i++){
        delete [] matrix[i];
    }
    delete [] matrix;

    return 0;
    ```
- ***#2***
    ```C++
    int main() {
        int* arr = new int[5];  // Allocate memory for an array of 5 numbers
        delete[] arr;           // Deallocate memory for the array of numbers
        int* pointer = new int;
        delete pointer;
        return 0;
    }
    ```
- ***#3***: constructor + memory allocation
    ```C++
    struct point{
        private:
            int x;
            int y;\
        public:
        point(){
            x=0;
            y=0;
            std::cout<<"Constructor called"<<std::endl;
        }
        point(int x, int y){
            this->x=x;
            this->y=y;
            std::cout<<"Constructor called"<<std::endl;
        }
        ~point(){
            std::cout<<"Destructor called"<<std::endl;
        }
    };
    int main(){
        point* p = new point(1,2);
        delete p;
        return 0;
    }
    ```
##### (❗***HINT***) new + initialization
- ***#4***: different approach 
    ```C++
    struct volume {
        int length, height, depth;
    };
    int main() {
        volume* v_1 = new volume;           //memory garbage in variables     
        volume* v_2 {new volume};           //same as one before
        volume* v_3 = new volume();         //variables are initiated with zeros 
        volume* v_4 = new volume{1, 2, 3};  //variables are initiated with values 
        volume* v_5 {new volume{1, 2, 3}};  //same as one before
        delete v_1;
        delete v_2;
        delete v_3;
        delete v_4;
        delete v_5;
        v_1=nullptr;
        v_2=nullptr;
        v_3=nullptr;
        v_4=nullptr;
        v_5=nullptr;

        int* p1 = new int;                  //not initialized (memory garbage)
        double* p2 {new double()};          //initialized with 0
        short* p3 {new short{-5}};          //initialized with -5
        unsigned p4 {new unsigned(11)};     //initialized with 11 
        delete p1;
        delete p2;
        delete p3;
        delete p4;
        p1=nullptr;
        p2=nullptr;
        p3=nullptr;
        p4=nullptr;

        int* ar_1 {new int[7]{}};           //0 0 0 0 0 0 0
        int* ar_2 {new int[4]()};           //0 0 0 0
        int* ar_3 {new int[5]{1, 2, 3}};    //1 2 3 0 0
        delete[] ar_1;
        delete[] ar_2;
        delete[] ar_3;
        ar_1=nullptr;
        ar_2=nullptr;
        ar_3=nullptr;

        return 0;
    }
    ```



### Enumerations
Enumerations are a way to define a set of named values. It is a user-defined datatype that consists of paired named-integer constants. 
- Enumerations can be created with `enum` keyword.
- Enumerations are great for sets of options.
- Enumerations can be put inside a class.

#### Example
```C++
enum Day {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
enum Nums {One=1, Two=2, Three=3, MinusOne=-1};
int main(){
    using std::cout, std::endl;
    Day today = Sunday;
    switch(today){
        case Sunday: cout<<"It's Sunday"<<endl; 
            break;
        case Monday: cout<<"It's Monday"<<endl; 
            break;
        case Tuesday: cout<<"It's Tuesday"<<endl; 
            break;
        case Wednesday: cout<<"It's Wednesday"<<endl; 
            break;
        case Thursday: cout<<"It's Thursday"<<endl; 
            break;
        case Friday: cout<<"It's Friday"<<endl; 
            break;
        case Saturday: cout<<"It's Saturday"<<endl; 
            break;
    }

    int x=Tuesday;
    //...
}
```
- If the numbers for *enum*s are not set, the list will start from **0** and go with *+1* step;
- Enumerations can be used just like number constants assigning those to any variable (that can be assigned to *int*).
- Enumerations can be used like a datatype.

### Scoped enumeration(enum class)
`enum class` (also known as a scoped enumeration) provides a way to define enumerations with better type safety and scoping compared to traditional enumerations (`enum`).

#### Key Characteristics
- **Scoped**: The enumerators (the named constants defined in the enumeration) are scoped within the enumeration type. This means that you must qualify the enumerators with the enumeration name to access them, which helps avoid name collisions.
    ```C++
    enum class Color {
        Red,
        Green,
        Blue
    };
    enum class TrafficLight {
        Red,
        Yellow,
        Green
    };
    Color myColor = Color::Red; // Scoped access // No conflict with TrafficLight::Red
    ```

- **Strongly Typed**: `enum class` provides better type safety. The enumerators are not implicitly converted to integers, which helps prevent accidental misuse.
    ```C++
    enum class Color {
        Red,
        Green,
        Blue
    };
    int value = Color::Red; // Error: cannot convert 'Color' to 'int'
    ```

- **Underlying Type**: You can specify the underlying type of the enumeration, which determines the storage size. By default, the underlying type is int, but you can change it to other integral types (like char, short, long, etc.).
    ```C++
    enum class Color : unsigned char {
        Red,
        Green,
        Blue
    };
    ```

### Exceptions (Error handling)
Exceptions in C++ are a powerful mechanism for error handling that allows developers to manage errors and exceptional situations in a more structured and maintainable way compared to traditional error handling methods (return codes, etc).

#### Key Concepts of Exceptions
- **Separation of Error Handling from Regular Code**: using exceptions allows you to separate error handling logic from the main logic of your program. This leads to cleaner and more readable code.
- **Throwing Exceptions**: when an error occurs, you can "throw" an exception using the `throw` keyword. This interrupts the normal flow of the program and transfers control to the nearest exception handler with an error message.
- **Catching Exceptions**: you can "catch" exceptions using the `try` and `catch` blocks. This allows you to define how to handle specific types of exceptions.
  - Syntax:
    ```C++
    try {
        // Code that might throw an exception
    } catch (/*type of exception*/) {
        // Code of exceptions handling
    }
    ```
    - `try{...}` - defines the program bloc that can result in program failure or error;
    - code inside the `catch(){...}` block will be executed if program runs into the failure;
    - if you want to catch any and all exceptions, write `...` in the type of exception place;
    - types of exceptions must be carefully written: [rules](#throw---catch-types-rules)
- **Stack Unwinding**: when an exception is thrown, the program unwinds the stack, meaning that destructors for all objects created in the current scope are called. This helps in resource management and prevents memory leaks.
- **Standard Exception Classes**: C++ provides a hierarchy of standard exception classes in the `<stdexcept>` header, such as `std::runtime_error`, `std::logic_error`, and others, which can be used to represent different types of errors.

#### Throw - Catch types rules
- `T` - type;
- `A` - base class or structure;
- `B` - derived class or struct.  

| `throw <insert>` | `catch(<insert>)`                                       |
| ---------------- | ------------------------------------------------------- |
| `T` / `const T`  | `T` / `T&` / `const T` / `const T&`                     |
| `T*`             | `T*` / `const T*`                                       |
| `const T*`       | `const T*`                                              |
| `A` / `const A`  | `A` / `A&` / `const A` / `const A&`                     |
| `B` / `const B`  | `B` / `B&` / `const B` / `const B&` / `A&` / `const A&` |
| `A*`             | `A*` / `const A*`                                       |
| `const A*`       | `const A*`                                              |
| `B*`             | `B*` / `const B*` / `A*` / `const A*`                   |
| `const B*`       | `const B*` / `const A*`                                 |
- Examples:
  - `throw (int)` => `catch(int/int&/const int/const int&)`;
  - `throw (int)` <> `catch(long/etc.)`;
  - `throw (const int*)` => `catch(const int*)`;
  - `throw (const int*)` <> `catch(int*)`;
  - `throw (int*)` => `catch(const int*)`;
  - `throw (int*)` => `catch(int*)`.

#### Execution steps
1. When a function meets `throw` it immediately stops execution.
2. The function that called the function that threw the exception is called.  
3. The chain of functions unwinds to the next function.
4. 
   1. Does not meet error handling / error handling does not meet the error kind `trow` sent:
      1. Repeat step 3 and 4 if possible, if not:
      2. Run `std::terminate()` - printing automatic error message.
      3. Run `std::abort()` - stopping the program.
   2. Does meet error handling (`trow` was located in `try` block, there is `catch` after):
      1. Does not execute anything else inside try - go straight to `catch` that meets the `trow` parameter.
      2. Execute code inside the `catch` (only one `catch` can be executed).
         - By just writing `throw` in `catch` section the error can be `thown` to upwards the stack of functions to more general one.
      3. If the code continues after the catch, program goes on with the execution.

#### Examples of Using Exceptions
- ***#1*** 
    ```C++
    int perimetr_tr(int a, int b, int c){
        try{
            if(a<0 ||b<0 ||c<0)
                throw -1;
        }
        catch(int e){
            cout<<"Error: negative length"<<endl;
            return e;
        }
        if(a>b+c||c>b+a||b>a+c)
            throw "Error: a,b,c do not form a triangle.";
        try{
            if(a>15)
                throw 5.5;
        }
        catch(double e){
            throw;
        }
        return a+b+c;
    }

    int main(){
        try{
        int p=perimetr_tr(25,20,24);
        }
        catch(const char* e){
            cout<<e<<endl;
        }
        catch (double){
            cout<<"Error: first side is bigger than 15"<<endl;
        }
        catch(...){
            cout<<"Error: unknown error"<<endl;
        }
        cout<< "continuing...."<<endl;
        return 0;
    }
    ```

#### Exception class
There built-in methods of exception creation.
- `std::exception` is the base class for all standard exceptions in C++. It is defined in the <exception> header and provides a common interface for handling errors and exceptional conditions in C++ programs.
Furthermore, you can write your own class for that:
- ***#1*** 
    ```C++
    class Exception{
        public:
            static int count_create;
            static int count_delete;
            Exception(){count_create++;}
            Exception(const Exception& ){count_create++;}
            ~Exception(){count_delete++;}
    };
    int Exception::count_create = 0;
    int Exception::count_delete = 0;

    void loadData (const char* path, int& x){
        std::ifstream ifs;

        try{
            ifs.open(path);
            if(!ifs.is_open())
                throw Exception();

        ifs>>x;
        ifs.close();
        }
        catch(const Exception& e){
            ifs.close();
            throw;
        }
    }
    int main(){
        int data{0};
        try{
            loadData("123.txt",data);
            cout<<data<<endl;
        }
        catch(const Exception& ex){
            cout<<"Errors created: " << ex.count_create <<endl;
            cout<<"Errors deleted: " << ex.count_delete <<endl;
        }
        return 0;
    }
    ```
#####  (❗***HINT***)
- ***#2*** 
```C++
class CardError : public std::exception{
    std::string msg;
    public:
        CardError(const char* error): msg(error){}
        CardError(const CardError& other): msg(other.msg){}
        const char* what() const noexcept override {return msg.c_str();}
};
class CardLengthError:public CardError{
    public:
    CardLengthError(const char* error="Card number length is not right!"): CardError(error){}
};
class CardFormatError:public CardError{
    public:
    CardFormatError(const char* error="Incorrect format!"): CardError(error){}
};
class CardNumberError:public CardError{
    public:
    CardNumberError(const char* error="Incorrect number!"): CardError(error){}
};

class BankCard{
private:
    const int num_length{19};
    std::string num;
    void verify(const std::string& card) const{
        if(card.length() != num_length)
            throw CardLengthError();

        const char* p = card.c_str();
        for( int i=0;i<num_length;i++){
            if((i==4||i==9||i==14)){
                if(p[i]!='-')
                    throw CardFormatError();
            }
            else if (p[i]<'0' || p[i]>'9')
                throw CardNumberError("Only numbers are allowed!"); 
        }
    }
public:
    void set_number(const std::string& card){
        verify(card);
        num=card;
    }
    const std::string& get_number()const {return num;}
};

int main(){
    BankCard card;
    try{
        card.set_number("1245-5678-9012-3456");
    }
    catch(const CardError& e){
        cout << e.what() << endl;
    }
    catch(const std::exception& e){
        cout << "An error occurred: " << e.what() << endl;
    }
    return 0;
}  
```
- `noexcept`: This specifier indicates that the function is not expected to throw any exceptions. This can help with performance optimizations and is important for certain contexts, such as when using standard containers.
- The `c_str()` method of std::string returns a pointer to a null-terminated character array representing the string's content.


### `constexpr`
`constexpr` is a keyword introduced in C++11 that allows to define variables, functions, and constructors that can be evaluated at compile time. This feature is particularly useful for improving performance and enabling certain optimizations by allowing the compiler to perform calculations during compilation rather than at runtime.

#### Key Features of constexpr
- **Compile-Time Evaluation**: functions and variables declared with `constexpr` can be evaluated at compile time, which can lead to faster execution since the results are computed before the program runs.
- **Constant Expressions**: A `constexpr` function must produce a constant expression when given constant expressions as arguments. This means that the function can be used in contexts that require compile-time constants, such as array sizes or template parameters.
- **Usage in Various Contexts**: `constexpr` can be applied to variables, functions, and constructors. This allows for a wide range of applications, from defining constant values to creating complex compile-time computations.

#### Examples Usage of `constexpr`
```C++
#include <iostream>

// A constexpr function to calculate the factorial of a number
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    //Example of a `constexpr` Variable
    constexpr int value = 5;   
    //Example of a `constexpr` Function
    constexpr int result = factorial(value); // Evaluated at compile time
    std::cout << "Factorial of 5 is: " << result << std::endl; // Output: 120
    return 0;
}
```

### Comments
- **Single-Line Comments**: Comments that span a single line are preceded by `//`.
- **Multi-Line Comments**: Comments that span multiple lines are enclosed within `/* */`.
- **Block Comments**: Comments that are used to document a block of code are typically placed above the block (function / class / logically difficult part of the program).
- **Title comment**: header comment that describes the purpose of the file at the top of a file.

#### Comments standards
Tools like Doxygen (which is a popular documentation generator for C++ and other programming languages) use documentation conventions to simplify the auto-generation of documentation. Each function has a comment block before it that contain the description of it, the comments in the comment block are structured by tag system. 
- Tag list:
  - `@brief`: Brief description of the function, class, or other code element.
  - `@param`: Description of a function parameter.
  - `@return`: Description of the return value of a function.
  - `@throws`: Description of exceptions thrown by a function.
  - `@note`: Additional information about the code element.
  - `@warning`: Warning about the code element.
  - `@see`: Reference to other code elements.
  - `@example`: Example of how to use the code element.
  - `@author`: Author of the code element.
  - `@date`: Date of creation or modification of the code element.
  - `@version`: Version of the code element.
  - `@copyright`: Copyright information about the code element.
  - `@license`: License under which the code element is released.
  - `@link`: Link to external resources.
  - `@details`: Detailed description of the code element.
- Example:
    ```C++
    /**
    * @brief Calculates the area of a rectangle.
    *
    * This function takes the width and height of a rectangle
    * and returns the area. It assumes that both width and height
    * are non-negative values.
    *
    * @param width The width of the rectangle.
    * @param height The height of the rectangle.
    * @return The area of the rectangle.
    */
    double CalculateArea(double width, double height) {
        return width * height;
    }
    ```

## Input - Output

### Input

#### Standard input
- Each read works until *new line break* or *space* etc.
- `cin` - object of **istream** class from `std` namespace that works with input of data.
```C++
std::string name;
int age;
std::cin >> name;
std::cin >> age;
//or 
std::cin >> name >> age;
```

#### Getline
Reads until *new line break* or set character.
```C++
std::string full_name;
std::getline(std::cin, name);

std::string string2;
std::getline(std::cin, string2, ','); //read until comma
```

####  (❗***HINT***)
If we use `getline` after `cin` we could read `\n` instead of the line we want to, this happens because *new line break* is still in the buffer. This can be avoided several ways, for example:
- 1:
    ```C++
    std::cin >> age;
    std::cin.ignore(); // ignore the rest of the line
    std::getline(std::cin, name);
    ```
- 2:
    ```C++
    std::cin >> age;
    std::getline(std::cin >> std::ws, name);
    ```


### Output
```C++
// printing text 
std::cout << "Text";
// line breaks
std::cout << "Text_2" << '\n';
std::cout << "Text" << std::endl;
// printing variable
int x=5;
std::cout << x;
std::cout << "Room number " << x ;
// printing single character
std::cout << 'A';
```
- `std` - [standard namespace](#standard-namespace)
- `cout` - **c**haracter **out**put - an object from the `std` namespace in **ostream** class that works with outputs.
- `endl` - does the same thing as `\n`, furthermore flashes the output buffer, but `\n` if better in the terms of performance. 
- Operator `<<` is overloaded for each and every variable type inside the `cout`, so we don't need to specify the type of data we print.

#### Precision output
* requires \<iomanip>
```C++
double balance = 123.45;
std::cout << "You have: " << std::setprecision(8) << std::fixed << balance << std::endl;
```
- `std::setprecision(8)` - sets the decimal precision of floating-point numbers to 8 digits (sets for decimal part), will round numbers mathematically if needed.
- `std::fixed` - sets the floating-point format to fixed-point notation (will add zeros at the end of the decimal part if needed for the set precision).
- `std::setw(12)` - set the whole length of the output, will not cut output if it is longer, but will add spaces in front if it is shorter.
    
### Manipulators
In C++, manipulators are special functions or objects that are used to modify the behavior of input and output streams. They allow you to change the formatting and presentation of data when it is sent to or read from streams, such as `std::cout` for [output](#output) and `std::cin` for [input](#input).
- Manipulators can change various aspects of stream formatting, such as precision, width, alignment, fill characters, etc.
- Manipulators can be chained together using the **insertion operator** (`<<`) for output streams or the **extraction operator** (`>>`) for input streams.
- Most manipulators are defined in the `<iomanip>` header, while some are defined in `<iostream>` and other headers.


#### Some more manipulators

| Manipulator                                      | Use                                                                                                                                                    | Library     |
| ------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------ | ----------- |
| `std::endl`                                      | Inserts a newline character into the output stream and flushes the stream.                                                                             | \<iostream> |
| `std::fixed`                                     | Sets the floating-point format to fixed-point notation.                                                                                                | \<iomanip>  |
| `std::scientific`                                | Sets the floating-point format to scientific notation (e+).                                                                                            | \<iomanip>  |
| `std::setprecision(n)`                           | Sets the precision of floating-point numbers to n.                                                                                                     |             |
| `std::setw(n)`                                   | Sets the minimum field width for the next output operation to n. If the output is shorter than this width, it will be padded (default is with spaces). | \<iomanip>  |
| `std::setfill`                                   | Sets the fill character used when padding output to the specified width                                                                                | \<iomanip>  |
| `std::left` <br>`std::right` <br>`std::internal` | Control the alignment of output within a specified width                                                                                               | \<iomanip>  |

#### Example: 
```C++
#include <iostream>
#include <iomanip>

int main() {
    double pi = 3.14159265358979;

    std::cout << "Default: " << pi << std::endl;
    //Default: 3.14159

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Fixed (2 decimal places): " << pi << std::endl;
    //Fixed (2 decimal places): 3.14

    std::cout << std::setw(10) << std::setfill('*') << 42 << std::endl;
    //********42

    std::cout << std::left << std::setw(10) << "Left" << std::endl;
    //Left******
    std::cout << std::right << std::setw(10) << std::setfill(' ') << "Right" << std::endl;
    //     Right

    return 0;
}
```

## Files
In C++ there are following classes that make working with files easier (to work with those `#include <fstream>`):
- `ifstream`: for reading data from file;
- `ofstream`: for writing data to file;
- `fstream`: for both reading and writing data to file;
- `wifstream`: for reading data from file for type `wchar_t`;
- `wofstream`: for writing data to file for type `wchar_t`;
- `wfstream`: for both reading and writing data to file for type `wchar_t`.

### This classes methods:
| Method                | Description                                                                       | Example        |
| --------------------- | --------------------------------------------------------------------------------- | -------------- |
| `open("<file_name>")` | to open file (`ofstream` and `fstream` will create new files if there aren't any) | [#1](#1-files) |
| `close()`             | to close file                                                                     | [#1](#1-files) |
| `is_open()`           | to check if file is open                                                          | [#1](#1-files) |
| `eof()`               | return **true** when we get to the end of the file                                | [#4](#4-files) |
| `write(...)`          | straight writing data to file (byte to byte)                                      | [#5](#5-files) |
| `read(...)`           | straight reading of data from file to memory (byte to byte)                       | [#5](#5-files) |
- `write((char*)<pointer_to_beginning_of_data>,<size_of_data_to_write>)`
- Writing data to file in binary form is the straight copying the memory. It takes less space.
- `read((char*)<pointer_to_place_to_save>,<size_of_data_to_read>)` / `read((char*)<pointer_to_variable>,<size_of_data_to_read>)`
- `read()` can detect the end of file.

### File access modes
There are several modes of opening files. The particular mode can be chosen while opening file. To choose the mode following flags (variables) are used, these variables are part of class `ios`. 

| Flag          | Description                                              | For objects from class                    |
| ------------- | -------------------------------------------------------- | ----------------------------------------- |
| `ios::in`     | only to read from file                                   | `ifstream` <br> `fstream`                 |
| `ios::out`    | only to write to file <br> previous data will be deleted | `ofstream` <br> `fstream`                 |
| `ios::app`    | to write to file <br> previous data will not be deleted  | `ifstream` <br>`ofstream` <br> `fstream`  |
| `ios::ate`    | to open file and set the position to the end of file     | `ifstream` <br> `ofstream` <br> `fstream` |
| `ios::binary` | to open file in binary mode                              | `ifstream` <br> `ofstream` <br> `fstream` |
- These are more of those.
- The flags can be mixed.
- Examples [#2](#2-files), [#3](#3-files)

### Input and Output of data
Works the same way as for `cin`, `cout`, but with our new objects.
- Examples [#4](#4-files)

### Examples
#### #1 files
```C++
#include <fstream>
#include <iostream>
int main(){
    std::ofstream ofs;
    ofs.open("output.txt");
    std::ifstream ifs;
    ifs.open("input.txt");
    if(!ifs.is_open())
        cout << "Unable to open input file"<<endl;
    else{
        ifs.close();
    }
    ofs.close();
    return 0;
}
```
Or opening could be done via constructor.
```C++
int main(){
    std::ofstream ofs("output.txt");
    std::ifstream ifs("input.txt");
    //...
}
```
#### #2 files
```C++
using std::ios;
int main(){
    std::ofstream ofs("output.txt");
    std::ifstream ifs("input.txt", ios::app);   //will create a file  this time
    cout<<ifs.is_open()<<endl;                  //true
    //...
}
```
#### #3 files
```C++
std::ifstream ifs("input.txt", ios::app| ios::binary);   //will open in binary format
```
#### #4 files
```C++
#include <iostream>
#include <fstream>
using std::cout, std::endl, std::ios;

int main(){

    //-----output to file-----
    std::ofstream ofs("output.txt");
    if(ofs.is_open()){
        ofs << "Hello, world!" << endl;
        ofs << -55.5 << ' ' << 1000 << endl;
        ofs << "This is a test." << endl;
        ofs.close();
    }
    //-----input from file-----
    int data_3{};
    double data_2{};
    std::string data_1{}, data_4{};
    std::ifstream ifs("output.txt");
    if(ifs.is_open()){
        getline(ifs,data_1);
        ifs >> data_2 >> data_3;
        while(data_4.length()==0 && !ifs.eof())         //otherwise it will read '\n'
            getline(ifs,data_4);
        ifs.close();
    }
    cout <<data_1<<endl<<data_2<<endl<<data_3<<endl<<data_4<<endl;
    return 0;
} 
```

#### #5 files
```C++
//-----write to file in binary form-----
double arr_in[]{55, -5.5, -9999.99, -7.77777, 5, 0};
std::ofstream ofs("output.txt", ios::binary | ios::out);
if(ofs.is_open()){
    ofs.write((char*)arr_in, sizeof(arr_in));
    ofs.close();
}
//-----read from file in binary form-----
double arr_out[sizeof(arr_in)/sizeof(arr_in[0])]{};
std::ifstream ifs("output.txt", ios::binary | ios::in);
if(ifs.is_open()){
    ifs.read((char*)arr_out, sizeof(arr_in));
    ifs.close();
}
//-----print the array-----
for(double& x:arr_out){
    cout << x << " ";
}
cout << endl;
return 0;
```

#### #6 file
- Writing a structure to file binary way: [/C&C++/materials/CPP/example_2.cpp](/C&C++/materials/CPP/example_2.cpp)


## Function 

### Library functions
| function          | description                                        | header/library |
| ----------------- | -------------------------------------------------- | -------------- |
| `z=std::max(x,y)` | returns maximum                                    | \<iostream>    |
| `z=std::min(x,y)` | returns minimum                                    | \<iostream>    |
| `z=abs(x)`        | returns absolute value                             | \<cmath>       |
| `z=pow(x,y)`      | returns x to the power of y                        | \<cmath>       |
| `z=sqrt(x)`       | returns square root of x                           | \<cmath>       |
| `z=ceil(x)`       | returns the smallest integer >= x <br> (round up)  | \<cmath>       |
| `z=floor(x)`      | returns the largest integer <= x <br> (round down) | \<cmath>       |
| `z=round(x)`      | returns the nearest integer to x                   | \<cmath>       |
| `m =toupper(c)`   | return the uppercase version of c                  | \<iostream>    |

#####  (❗***HINT***)
Function lists:
- [CMATH](https://cplusplus.com/reference/cmath/)

#### Fill()
- fills a range with a value.
- Syntax
    ```C++
    std::fill( <beginning_of_range>, <end_of_range>, <value> );
    ```
    - Fills with values including beginning and excluding the end.
- Example
    ```C++
    int length =50;
    string n[length];
    fill( &n[0], &n[length/2], "pizza");
    fill( n + length/2, n + length, "sushi");
    ```

#### std::terminate()
Print the message that tells that the function was terminated - automatic error message.

#### std::abort()
Terminates the program immediately.


### Tips
C++ does support **overloaded functions**:
* There can be several functions with the same name, if their parameters list differs.
* The compiler will choose the correct function based on the parameters passed. It is done during compilation.
* Function's **signature** (name + parameters list) MUST be unique.
* This is an instance of static polymorphism. 

```C++
int summ(int x, int y) { return x+y; }
//will work for summ(int, int), summ(short, short)
//but will not work for summ(long, long)
double summ(double x, double y) { return x+y; }     
//will work for summ(double, double), summ(float, float)
```

### Passing data to function (❗***HINT***)
- **Pass by value**: The function receives a copy of the original variable;
- **Pass by [reference](#references)**: The function receives the original variable;
- **Pass by [pointer](#pointers)**: The function receives the memory address of the original variable;
Example:
```C++
void swap (int x, int y){
    int temp = x;
    x = y;
    y = temp;
}
void swap2 (int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}
void swap3 (int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    using namespace std;
    int x=5, y=10;
    cout<< x <<" "<<y<<endl;    //5 10
    swap(x,y);                  //pass values (creates capies inside a function)
    cout<< x <<" "<<y<<endl;    //5 10
    swap2(x,y);                 //pass values by refference (actually work with original addresses)
    cout<< x <<" "<<y<<endl;    //10 5
    swap3(&x,&y);               //pass values by pointer (pass addresses and work with addresses)
    cout<< x <<" "<<y<<endl;    //5 10
    return 0;
}
```
- Same pattern can work with **strings**.


### Functions default input
```C++
void fun (int x=55, std::string str="hello!", double y = -54.4){
    cout << x <<';'<< str <<';'<< y <<endl;
}
int main(){
    fun();  //55;hello!;-54.4
    fun(10);                //10;hello!;-54.4
    fun(10, "world");       //10;world;-54.4
    fun(10, "world", 100);  //10;world;100
    fun("world");           //error
    return 0;
}
```

- Not all parameters in function must have defaults if others have defaults. But in this case not preset parameters go first!
    ```C++
    void fun (char* str0, int x=55, std::string str="hello!", double y = -54.4){
        cout << str0 <<';'<<x <<';'<< str <<';'<< y <<endl;
    }
    void fun ( int x=55, char* str0, std::string str="hello!", double y = -54.4){       //ERROR
        //...
    }
    int main(){
        fun();                  // error
        fun("line");            //line;10;hello!;-54.4
        return 0;
    }
    ```
####  (❗***HINT***) (Fun default)
Having some default parameters in function is useful for functions that's parameters works like settings (change the way function act).
```C++
double round_my(double x, int radix=0){
    double p=pow(10,radix);
    return round(x*p)/p;
}
```

### Function template
A function template is a function that can work with different data types. This allows us to generate as many overloaded functions with different datatype as we need easily and without writing same code again and again. 
- Compiler will decide what type to put instead of type we set in template base on where and how we call the function (base on parameters).
- If a template is not used, it will not be transformed into machine code.
- **Function template instantiation** - the process of creating a specific function from a function template by substituting the template parameters with actual types.
- To force setting the type that we want, use `<\*type*\>` when calling the function, before arguments. Furthermore, it is useful if you have different arguments and the template has a type announced as output.
- Type parameters can be modified with `const`, pointers, links.
- Templates can be overloaded just like usual functions.
- Instead of `typename` can use keyword `class`.

#### Example
- ***#1***: general + explicit type decision
    ```C++
    //instead of 
    int max (int x, int y){
        return (x>y)?x:y;
    }
    double max (double x, double y){
        return (x>y)?x:y;
    }
    char max (char x, char y){
        return (x>y)?x:y;   
    }
    //this one will work if we have 2 similar datatypes
    template <typename T>
    T max (T x, T y){
        return (x>y)?x:y;
    }
    int main(){
        // explicit type decision
        short i=max<short>(5,55);       //short max<short>(short x, short y)
        return 0;
    }
    ```

#####  (❗***HINT***) `auto`
- ***#2***: different types +`auto`
    These will work if we have 2 different datatypes.
    ```C++
    template <typename T>
    T max (T x, T y){
        return (x>y)?x:y;
    }
    // this will work if we have 2 different data types.
    template <typename T, typename U>
    auto max2 (T x, U y){
        return (x>y)?x:y;
    }
    int main(){
        //this one will work if we have 2 different datatypes too
        int k=max<int>(5,5.666);
    }
    ```
    - `auto` make the compiler deduce that the result type should be.
  
  
- ***#3***: add `const`, links and pointers
    ```C++
    template <typename T>
    T max3 (const T& x, const T& y){
        return (x>y)?x:y;
    }

    template <typename T> void swap(T* x, T* y){
        T temp=*x;
        *x=*y;
        *y=temp;
    }
    ```

- ***#4***: preset datatype
    ```C++
    template <typename TO=double, typename T1, typename T2>
    TO mult ( T1 x, T2 y){
        return x*y;
    }

    template <int calc_t=1, typename T1, typename T2>
    auto get_rec(T1 width,T2 height){
        if (calc_t==1)
            return width*height;
        else
            return 2*(width+height);
    }

    //automatically set the number of elements
    template <typename T, size_t N>
    T ar_sum(const T(&ar)[N]){
        T res=0;
        for(size_t i=0;i<N;i++)
            res+=ar[i];
        return res;
    }

    int main(){
        int res_1= mult(5,6.5);         //double mult<double, int, double>(int x, double y)
        double res_2=mult(5,6);         //double mult<double, int, int>(int x, int y)
        // explicit defining type can replace the preset one
        short res_3=mult<short>(2,3);   //short mult<short, int, int>(int x, int y)
        short res_4=mult<int>(2.5,3.9); //int mult<int, double, double>(double x, double y)

        double r_1 = get_rec(5, 6.5);
        int r_2=get_rec<2>(5,6);
        cout<<r_1<<' '<<r_2<<endl;      //output: 32.5 22

        double data[]={0.5,3.2,7.8,3,10.4,5.6};
        int marks[]{3,4,5,5,4,5,4,2,3};
        auto s= ar_sum(data);           //double ar_sum<double, 6UL>(const double (&ar)[6])
        auto s2=ar_sum(marks);          //int ar_sum<int, 9UL>(const int (&ar)[9])
        cout<<"Summs: "<<s<<" "<<s2<<endl; //30.5 35

        return 0;
    }
    ```

- ***#5***: overloaded templates
    ```C++
    template <typename T>
    T add (T a, T b){ return a+b}
    template <typename T>
    T add (T* a, T* b){ return *a+*b}
    template <typename T1, typename T2>
    auto add (T1 a, T2 b){ return a+b}
    void add (std::string& dest, const std::string& src){
        dest+=src;S
    }
    ```
    - Usual functions have a priority over templates, so they will be checked if they fit type first. To make compiler use template over existing function add `<>` to the function call.

### Inline Functions (❗***HINT***)
Inline functions are a feature of C++ that allows you to define functions that are expanded in-line.
- `inline` keyword is used to suggest to the compiler that it should attempt to expand the function's code inline at the point of call, rather than generating a traditional function call. 
- This can reduce the overhead associated with function calls, especially for small, frequently called functions.

#### Key Points about `inline`:
- **Function Definition**: When you define a function as inline, you are suggesting to the compiler that it should replace calls to the function with the function's body. This can lead to performance improvements by eliminating the overhead of a function call.
    ```C++
    inline int add(int a, int b) {
        return a + b;
    }
    ```
- **Multiple Definitions**: An inline function can be defined in multiple translation units (source files) without violating the One Definition Rule (ODR). This is useful for defining functions in header files.
- **Compiler Discretion**: The inline keyword is merely a suggestion to the compiler. The compiler may choose to ignore it and generate a regular function call if it deems it more efficient.
- **Use Cases**: inline is typically used for small, frequently called functions, such as accessory methods or simple mathematical operations.


### Lambda Functions  (❗***HINT***)
**Lambda Functions** (or simply **lambdas**, or **anonymous functions**) allows defining anonymous functions (functions without a name) directly in your code (in any fitting place of program). They are particularly useful for short, simple operations that are used only once or a few times, such as in algorithms or as callbacks.
- From C++11

#### Key Features of Lambda Functions
- **Syntax**: The basic syntax of a lambda function is as follows:
    ```C++
    [capture](parameters) -> return_type {
        // function body
    }
    ```
    - **Capture**: This part specifies which variables from the surrounding scope are accessible inside the lambda. You can capture by value or by reference.
    - **Parameters**: This is where you define the input parameters for the lambda, similar to a regular function.
    - **Return Type**: This is optional; if omitted, the compiler will deduce the return type.
    - **Function Body**: This contains the code that will be executed when the lambda is called.
- **Capture Modes**: Lambda functions can't use local variables from function it is in. Capturing variables allow using local variables inside lambda function. There are several mods of capturing, those can be set with a special parameter in capture element (example 6), the parameters can be combined, mixed, used for particular variables or all variables local for the function lambda function is it:
    - **By Value**: `[x]`: captures x by value (a constant copy inside lambda function).
      - Using `mutable` make this copy modifiable.
      - Can capture several variables separated by comma.
      - If the passing variable is a pointer the original value can be changes from inside of lambda function.
    - **By Reference**: `[&x]`: captures x by reference (not copying), lambda function will be able to modify variables from outside.
    - **All by Value**: `[=]`: captures all variables used in the lambda by value (use those as constants inside lambda function).
      - Use `mutable` to make those passed variables modifiable (not constant), but still those changes will be local inside lambda function.
    - **All by Reference**: `[&]`: captures all variables used in the lambda by reference.
- **Use Cases**: Lambda functions are often used in:
  - Standard algorithms (like `std::sort`, `std::for_each`, etc.);
  - Event handling and callbacks;
  - As temporary functions for short-lived operations;
  - Can be put inside another function's parameters (example 4).
  
#### Example
- **#1** 
```C++
int main(){
        [](int a, int b){ return a + b; }(5,5);
        std::cout << [](int a, int b){ return a + b; }(5,5) << std::endl;   //10
        [](int a, int b){ return a + b; };                                  //nothing
        return 0;
    }
```
- **#2**
    ```C++
    int main(){
        auto add = [](int a, int b){ return a + b; };
        std::cout << add(5, 7) << std::endl;            //12
        auto s =add;    //same as s{add}
        std::cout << s(15, 17) << std::endl;            //32
        auto k {[](const char* msg,double&x){
            std::cout << msg << std::endl;
            x++;
        }};
        double x = 0;
        k("Hello",x);                                   //Hello
        std::cout << x << std::endl;                    //1
        auto k2 {[](const char* msg,double x){
            std::cout << msg << std::endl;
            return ++x;
        }};
        x=k("world",x);                                 //world
        std::cout << x << std::endl;                    //2
        return 0;
    }
    ```
    - **add**: is an object of the function.
    - **s**: is another object of the function.
- **#3**
    ```C++
    int main(){
        auto summ { [](int a, int b){return a+b;}};             //will return int
        auto summ2 { [](int a, int b) -> double {return a+b;}};  //will return double
        auto summ3 { [](auto a, auto b){return a+b;}};           //from C++14
        auto summ4 { [](auto a, auto b) -> auto {return a+b;}};  //type of return depend on type of input
        std::cout << summ4(5,7) << std::endl;                    //12 -- int
        std::cout << summ4(5.5,7.7) << std::endl                 //13.2 -- double
        std::string res = summ4(std::string("Hello "), std::string("world!"));
        std::cout << res << std::endl;                            //Hello world! -- string
    }
    ```
- **#4**
    ```C++
    void show_ar(const int* ar, size_t length, bool (*filter_func)(int)=nullptr){
        for(int i=0;i<length;i++){
            if(filter_func!=nullptr){
                if (filter_func(ar[i]))
                    cout <<ar[i]<<' ';
            }
            else
                cout <<ar[i]<<' ';
        }
    }
    int main(){
        int data[]{1,2,3,4,5,6,7,8,9,10};
        show_ar(data,sizeof(data)/sizeof(*data));   //will print all data
        cout<<endl;
        show_ar(data,sizeof(data)/sizeof(*data),[](int x){return x%2==0?true:false;});  //print only even numbers
        cout<<endl;
        return 0;
    }
    ```
- **#5**: [/C&C++/materials/CPP/lambda_fun_ex.cpp](/C&C++/materials/CPP/lambda_fun_ex.cpp)
- **#6**
    ```C++
    int main(){
        int a(5), b(10),c(15);
        double data[]{1.2,3.4,6.7,8.5};

        auto r1=[=](){
            cout <<c<<endl; //OK
            c++;            //ERROR
            return a+b;     //OK
        };
        r1();

        auto r2=[=]() mutable{
            c++;            //OK
            cout <<c<<endl; //OK    //16
            return a+b;     //OK
        };
        r2();
        cout <<c<<endl;             //15

        auto r3=[c,data](){
            cout <<c<<endl; //OK
            cout << a<<endl;//ERROR
            return data[0]; //OK
        };
        r3();

        auto r4=[&a](){
            cout <<a<<endl; //OK    //5
            a++;
            c++;            //ERROR
            cout << a<<endl;//OK    //6
        };
        r4();
        cout << a<<endl;//OK    //6

        auto r5=[&](){
            a++;            //OK
            c++;            //OK
        };
        r5();

        int* ptr_b=&b;
        auto r6=[ptr_b](){
            cout <<*ptr_b<<endl;//OK    //10
            (*ptr_b)++;         //OK
            *ptr_b++;           //ERROR
            cout <<*ptr_b<<endl;//OK    //11
        };
        r6();
        cout <<*ptr_b<<endl;//OK    //11

        auto r7=[ptr_b]()mutable{
            (*ptr_b)++;         //OK
            *ptr_b++;           //OK
        };
        r7();

        // Mixing the way of capture
        auto r8=[ptr_b, &a, c, &data]()mutable{
            //...
        };
        // Capture all by value, but `a` and `b` by reference
        auto r9=[=, &a,&b]()mutable{
            //...
        };
        // Capture all by reference, but `data` and `c` by value
        auto r10=[&, data,c]()mutable{
            //...
        };

        return 0;
    }
    ```


### Pointer to a function (//❗❗)
......

## Structure
A structure is a collection of variables of different data types that can be used together as a single unit.
- Structures can be created with `struct` keyword.
- Variables in structure are called *"members"*.
- *Members* can be accessed with "*class member access operator*":
    - `.` for variables;
    - `->` for pointers.

### Examples 
```C++
struct person {
    std::string name;
    int age;
    double rating =0.0;
};
void data_crean (person *p){
    p->name.clear();
    p->age = 0;
    p->rating = 0.0;
}
void printer(person p){
    std::cout << "Name: " << p.name << std::endl;
    std::cout << "Age: " << p.age << std::endl;
    std::cout << "Rating: " << p.rating << std::endl;
}
void update_rating(person &p){
    p.rating+=0.5;
}
int main(){
    using std::cout, std::endl;

    person first_per;
    first_per.name = "John";
    first_per.age = 25;
    first_per.rating = 4.5;

    printer (first_per);
    update_rating(first_per);
    printer (first_per);
    data_crean(&first_per);
    printer (first_per);

    return 0;
} 
```
- `p->rating = 0.0;` sets a default value for the member.

### Methods in structures
In C++ structures has methods, they act mostly the same way as the ones from classes.
```C++
struct vec {
    double x, y;
    double length(){return sqrt(x*x+y*y);}
};
using std::cout, std::endl;
int main(){
    vec v{1}, v2{5,10};
    v.y=5;
    cout << v.length() << endl;
    cout << v2.length() << endl;
    return 0;
}
```
- Function if structure knows where to find variables for calculation, because when you call the function structure passes in it `this->` pointer to the right variables. 
   - `double length(){return sqrt(x*x+y*y);}` == `double length(){return sqrt(this->x*this->x+this->y*this->y);}`
   - `this` pointer has the same type as structure and can be used everywhere in the structure, accept `stqtic` methods.

### Access modifiers in structures
Access modifiers in structures works the same way as those in [classes](#object-and-class). The difference is that for classes default state is `private` and for structure fields `public`.

### Constructors and Destructors in structures
Constructors in structures work almost the same way as those in [classes](#object-and-class). If we do not specify a constructor, compiler will add several standard constructors to the structure, if we add at least one constructor ourselves, no default constructors will be added.
Same works with destructors.

### Summery
Structures and [classes](#object-and-class) are pretty close in C++.

![StructVsClass](/C&C++/media/STRUCTvsCLASS.png "structure vs class")


## Object and Class

### General 

![OOP_1](/C&C++/media/oop_1.png "example of OOP based on real world")

#### Class
- A class is a blueprint or template for creating objects;
- It defines the structure and behavior of objects;
- It contains data members (variables) and member functions;
- Classes are abstract concepts, not physical entities;
- They are defined using the `class` keyword;
- No memory is allocated when a class is defined;
- **Classes** are **namespaces** for theirs **methods** and **attributes**.

#### Object
- An object is an instance of a class;
- It represents a concrete entity with specific values for data members;
- Objects contain actual data stored in memory;
- They are created from classes using [constructors](#constructor);
- Objects are physical entities that exist at runtime;
- Memory is allocated when an object is created;
- The **attributes** of an **object** are stored in memory allocated for this object, but the **methods** are located there in the general **class** memory.

#### Summary
Object is a collection of **attributes** and **methods**. **Attributes** are characteristics of an object, **methods** are functions that object can preform. **Object** is an instance of a data when **class** is the definition of an object.
- Objects can be created from a user-defined data type **class**, that acts like a blueprint for an object.
- **Class** [**encapsulates**](/General/Dictionaty.md) data (*attributes*) and functions (*methods*) that operate on that data into a single unit. 
- **Classes** are a fundamental part of *object-oriented programming* (**OOP**) in C++, allowing for the modeling of real-world entities and promoting code reusability, modularity, and [**abstraction**](/General/Dictionaty.md).
- For **methods** class can be seen as a namespace (*example 6*). **Methods** are connected to the class itself, due to that it can access private members of any object of that class (*example 3*).
- **Attributes** are elements of an object and get memory only when the object is created (except [`static` **attributes**](#static-properties)).
- **Objects** are instances of a class, they have their own memory space and can be used independently.

#### Methods
In C++, methods are functions that are associated with a class or an object. They define the behavior of the objects created from that class. Methods are often referred to as member functions because they are defined within a class and can access the class's data members.
- Methods can have access specifiers (access modifiers*) that determine their visibility.
- **Method Types**:
    - ***Instance Methods***: These methods operate on instances of the class and can access instance variables.
    - ***Static Methods***: These methods belong to the class itself rather than any particular object. They cannot access instance variables directly but can access static variables.
- **Const Methods**: A method can be declared as `const`, indicating that it does not modify any member variables of the class.
- **Overloading**: C++ allows method overloading, which means you can have multiple methods with the same name but different parameter lists.
- Syntax of Methods:
    - Defining a Class with Methods: [Class examples](#class-examples):#4
    - Using Methods: [Class examples](#class-examples):#4
    - Method Overloading: [Class examples](#class-examples):#5
- Special method kinds:
  - [Constructor](#constructor)
  - [Destructor](#destructor)
  - Static methods
  - [Virtual methods](#abstract-methods-virtual-functions)
- When a method is called by an object the object passes `this` pointer to the method of a class - that is the way class methods knows which value to use, even thought they are stored separately with the objects of the class.  
    ![Scheme_object→class](/C&C++/media/ObjectToClass.png "Scheme how class let the method knows what data to use")

#### Access modifiers
**Access modifiers** are keywords used in object-oriented programming to set the accessibility or visibility of **methods**, **Attributes** and other members of **class** or **structure**. They control how and where these members can be accessed from other parts of the program. 
- The main purpose of access modifiers is to implement **encapsulation**, which is a fundamental principle of object-oriented design.
- **Access modifiers** work at the class level, not object level (*example 3*).
- **Attributes** and **methods** have ***access modifiers***:
    - `public`: can be accessed from anywhere.
    - `private`: can only be accessed within the class.
    - `protected`: can be accessed within the class and its derived classes.
  - **Access modifiers** are set for a class not an object (this protection is at the class level).
    - See [example #3](#class-examples).
- Related methods:
  - `getter` - function that makes a private attribute READABLE.
  - `setter` - function that makes a private attribute WRITABLE.
  - **getter**s and **setter**s are used due to that fact that it is a good practice to keep as many of the class **attributes** `private` as possible.

#### Object lifeline
1. Allocating memory for the object;
2. Initializing the object;
   - Constructor initialization has higher priority than default values of attributes (if it does not exist (or called) the defaults are used).
   - If there are other objects as attributes of the class their *1) initialisation* and *2) call of constructor* will be executed at this step.
3. Calling constructor;
4. Using the object;
5. Calling destructor;
6. Deleting variables of the object;
   - Destructors of attribute objects will be called here.
7. Freeing memory.

#### Class examples
- **#1**
    ```C++
    #include <iostream>

    class Human{
        public:
            std::string name;
            std::string occupation;
            int age;
            bool isAlive=true;

            void eat(){
                std::cout<<"Human is eating"<<std::endl;
            }
            void sleep(){
                std::cout<<"Human is sleeping"<<std::endl;
            }
            void drink(){
                std::cout<<"Human is drinking"<<std::endl;
            }
    };
    int main(){
        using std::cout, std::endl;

        Human human1;
        Human human2;

        human1.name="John";
        human1.occupation="Pilot";
        human1.age=30;
        human2.name="Jeffrey";
        human2.occupation="Comander";
        human2.age=45;

        cout<<"Name: "<<human1.name<<endl;
        cout<<"Occupation: "<<human1.occupation<<endl;
        cout<<"Age: "<<human1.age<<endl;
        cout<<"Is Alive: "<<human1.isAlive<<endl;

        cout<<"Name: "<<human2.name<<endl;
        cout<<"Occupation: "<<human2.occupation<<endl;
        cout<<"Age: "<<human2.age<<endl;

        human1.eat();
        human2.sleep();
        human1.drink();
        return 0;
    } 
    ```
  - If there is setting a value in class description it sets a default value for this attribute.
- **#2**
    ```C++
    class Stove{
        private:
            double temperature=0;
        public: 
            std::string colour="Black";
            double getTemperature (){
                return temperature;
            }
            void setTemperature(double temp){
                if(temp<=0)
                    temperature=0;
                else if (temp>=10)
                    temperature=10;
                else
                    temperature=temp;
            }
        Stove(double temperature, std::string colour){
            setTemperature(temperature);
            this->colour=colour;
        }
    };
    int main(){
        using std::cout, std::endl;
        Stove stove(5,"blue");
        stove.colour="red";                                         //ok
        stove.temperature=1000;                                     //error
        stove.setTemperature(1000);                                 //ok
        cout << "Stove temperature:"<<stove.getTemperature()<<endl; //ok
        return 0;
    } 
    ```
- **#3**
    ```C++
    #include <iostream>
    #include <math.h>
    class Point2D {
    private:
        int x, y;
    public:
        void set_coords(int a, int b)
            {x = a; y = b;}
        double length_to(const Point2D& pt)
        {
            return sqrt((x - pt.x) * (x - pt.x) + (y - pt.y) * (y - pt.y));
        }
    };

    int main()
    {
        Point2D pt, endp;
        pt.set_coords(1, 2);
        endp.set_coords(10, 20);
        double len = pt.length_to(endp);
        std::cout << len << std::endl;
        return 0;
    }
    ```
    - In function `length_to` we can access private elements of another object because **access modifiers** are parameters of class itself not an object.
- **#4**
    ```C++
    #include <iostream>
    using namespace std;

    class MyClass {
    private:
        int value; // Private data member

    public:
        // Constructor
        MyClass(int v) : value(v) {}
        // Instance method
        void display() {
            cout << "Value: " << value << endl;
        }
        // Static method
        static void staticMethod() {
            cout << "This is a static method." << endl;
        }
        // Const method
        void constMethod() const {
            cout << "This is a const method." << endl;
        }
    };

    int main() {
        MyClass obj(10); // Create an object of MyClass
        obj.display();   // Call the instance method
        MyClass::staticMethod(); // Call the static method
        obj.constMethod(); // Call the const method

        return 0;
    }

    ```
- **#5**
    ```C++
    class Calculator {
    public:
        // Overloaded methods for addition
        int add(int a, int b) {
            return a + b;
        }

        double add(double a, double b) {
            return a + b;
        }

        int add(int a, int b, int c) {
            return a + b + c;
        }
    };
    int main() {
        Calculator calc;
        cout << "Sum of 2 integers: " << calc.add(5, 10) << endl; // Calls int version
        cout << "Sum of 2 doubles: " << calc.add(5.5, 10.5) << endl; // Calls double version
        cout << "Sum of 3 integers: " << calc.add(1, 2, 3) << endl; // Calls 3-parameter version
        return 0;
    }
    ```
- **#6** classes as namespace
    ```C++
    class whatever {
        public:
            int x=5;                //default value set
            static int y;
            int getX() { return x;}
            static void printer (){
                std::cout << "Hello, world!" << std::endl;
            }
    };

    // Definition and initialization of the static variable
    int whatever::y = 0; // You can initialize it to any value, here it's initialized to 0

    int main() {
        whatever::printer();                        // Correctly calls the static method
        // whatever::getX();                           //error: not static method is object related
        std::cout << whatever().getX() << std::endl;// Creates a temporary object and calls getX()

        whatever::y = 5;                            // Set the static variable
        std::cout << whatever::y << std::endl;      // Outputs: 5
        return 0;
    }
    ```
    - Any public element can be potentially called via `::` from a class, but it makes sense mostly only for static methods and attributes.


### Constructor
It is a special method, that is automatically called when an object is instantiated (useful to assign values to attributes as arguments). 
- There always is a **constructor** that is automatically called: in C++ if you don't define any *constructor*, the compiler provides a set of *constructors* (and operators): *Default constructor*, *Copy constructor*, *Copy assignment operator*, *Destructor*, *Move constructor* and *Move assignment operator*.
- **Constructor** can be manually set.
- A **constructor** is a member function with the same name as the class.
- If any constructor is set no default constructor will compiler create.
- Constructor may have any list of parameters.
- Constructor never returns anything.
    ```C++
        Student s2;         // would not work
    ```
- Syntax:
    ```C++
    Constructor(<input_values>): <initialisation> { <setting_values_and_other_code>}
    ```
    - *example 4*
  
#### **Default constructor**
Constructor that can be executed without any parameters. This constructor will be used in case array of objects is created and if an object was created with no parameters. If there will be no parameters described in the constructor, the variables will get default values. If there are no default values, variables will keep memory garbage.
- If any constructor is not set, compiler will create default constructor automatically. It will initialize attributes with either default values (if there is any) or keep memory garbage in variables.
- If you added *copy constructor* or *move constructor*, but you want to keep **default constructor** created by compiler, add line:
  ```C++
  class myClass{
    public:
        myClass()=default;
    //...
    }
  ```
- If you forcefully stop compiler from creating **default constructor** (this will work for **copy constructor** and **move constructor** too, but if we use it on any of these two, it will delete *default constructor* too, so to keep it, while not creating other compiler-made constructores use `myClass()=default`), add line:
  ```C++
  class myClass{
    public:
        myClass()=delete;
    //...
    }
  ```
  
#### **Converting constructor**
Constructor that can be called with a single argument of a different type than the class itself. This allows for implicit or explicit conversion from that type to the class type. Converting constructors are useful for creating objects from other types without requiring an explicit cast.
- *example 5*
- `explicit` before a single argument constructor will stop it from being converting constructor, but still keep the ability of creating objects with one variable.
  - Without `explicit`:
      ```C++
      MyClass c1(2,3);                                        //OK
      MyClass c2(2);  // initialization with one parameter    //OK
      MyClass c3 = 2; // implicit conversion                  //OK
      c2.add(4.2);                                            //OK
      ```
  - With `explicit`:
      ```C++
      MyClass c1(2,3);                                        //OK
      MyClass c2(2);  // initialization with one parameter    //OK
      MyClass c3 = 2; // implicit conversion                  //ERROR
      c2.add(4.2);                                            //ERROR
      ```

#### **Copy constructor** 
This is the constructor that is called when one object was defined with another:
```C++
myClass obj;
myClass obj2(obj); // calls copy constructor
```
- Copy constructor as a parameter has a link to an object from the same class.
- If a copy constructor is not specified, compiler will add one automatically. *BUT* this automatic copy constructor *MUST* be rewritten in case you work with dynamic memory (if object has dynamically allocated memory in it), because in this case we get 2 objects pointing to one memory space, that may result in issue when destructor for these objects will be called (memory will be deleted 2 times).
    ```C++
    {
    myClass obj;
    myClass obj2(obj); // calls copy constructor
    }   //end of block => 2 destructors will be called => ERROR
    ```
    - *example 6*
  
#### **Delegating constructor** 
Constructor that delegate actions to another constructor - call another constructor to execute actions.
- *example 6*

#### Examples (constructor)
- ***#1***: (`this->` pointer)
  - with `this->`:
    ```C++
    class Student{
        public:
            std::string name;
            int age;
            double mark;
        
        Student(std::string name, int age, double mark){
            this->name= name;
            this->age = age;
            this->mark = mark;
        }
    };
    int main(){
        using std::cout, std::endl;
        Student s1("John", 20, 85.5);
        cout << "Name: " << s1.name << endl<< "Age: "<<s1.age<<endl << "Mark: "<<s1.mark<<"%"<<endl;
        return 0;
    } 
    ```
  - without `this->`:
    ```C++
    class Student{
        public:
            std::string name;
            int age;
            double mark;
        
        Student(std::string n, int a, double m){
            name= n;
            age = a;
            mark = m;
        }
    };
    int main(){
        using std::cout, std::endl;
        Student s1("John", 20, 85.5);
        cout << "Name: " << s1.name << endl<< "Age: "<<s1.age<<endl << "Mark: "<<s1.mark<<"%"<<endl;
        return 0;
    } 
    ```
  - If in the constructor declaration the names of variables are the same `this->` pointer is needed to address to attributes. Otherwise, you can just use attributes names and `this->` pointer will be added automatically on execution.
  
##### (❗***HINT***)
- ***#2***: fast use of class   
  - Class (or structure) can be used for calculations, this way the object itself won't be created. 
    ```C++
    class point{
        double x, y;
        public:
        point(double x, double y){
            this->x = x;
            this->y = y;
        }
        double distance(){
            return sqrt(x*x + y*y);
        }
    };
    int main(){
        double length=point(5,10).distance();
        cout << length << endl;
        return 0;
    }
    ```
- ***#3***: list initialization #1
    ```C++
    class point{
        double x, y;
        public:
            //default constrictor
            point():x(0),y(0) //order matters! - same as in declaration list
                {}
            //other constructor (reload of constructor)
            point(double x1, double y1): x(x1), y(y1){}
            double getX(){
                return x;
            }
            double getY(){ return y;}
    };
    int main() {
        std::unique_ptr<point> p1(new point(22,25));
        std::unique_ptr<point> p2{new point(-55,0)};
        point p3;
        point p4(3,5);
        std::cout << p1->getX() << " " << p1->getY() << std::endl;  //22 25
        std::cout << p2->getX() << " " << p2->getY() << std::endl;  //-55 0
        std::cout << p3.getX() << " " << p3.getY() << std::endl;    //0 0
        std::cout << p4.getX() << " " << p4.getY() << std::endl;    //3 5
        return 0;
    }
    ```
- ***#4***: list initialization #2
    ```C++
    class point{
        const unsigned any;
        double x, y;
        public:
            point(unsigned any1, double x1, double y1): any(any1), x(x1), y(y1){    //ok
                any=any1;           //error: constants can only be initialized, can't be just set value to
                x=x1;               //ok
                y=y1;               //ok
            }
    };
    ```
##### (❗***HINT***)
- ***#5***: converting constructor + use of `this`
    ```C++
    class Complex{
        double real{0}, imag{0};
        public:
        Complex(): real(0.0), imag(0.0){};
        Complex(double real1):real(real1), imag(0.0){}
        Complex(double real1, double imag1): real(real1), imag(imag1){}
        double getReal(){
            return real;
        }
        double getImag(){
            return imag;
        }
        void get_data(double& real, double& imag){
            real = this->real;
            imag = this->imag;
        }
        const Complex& add(const Complex& other){
            real += other.real;
            imag += other.imag;
            return *this;
        }
    };
    int main() {
        Complex C1;
        Complex C2= 3.0;
        Complex C3(3.5, 4.1);
        std::cout << C1.getReal() << " " << C1.getImag() << std::endl;//0 0 
        std::cout << C2.getReal() << " " << C2.getImag() << std::endl;//3 0
        std::cout << C3.getReal() << " " << C3.getImag() << std::endl;//3.5 4.1
        C3.add(C2);
        double real, imag;
        C3.get_data(real, imag);
        std::cout << real << " " << imag << std::endl;//6.5 4.1

        C3.add(4.5);            //(*)
        C3.get_data(real, imag);
        std::cout << real << " " << imag << std::endl;//11 4.1

        return 0;
    }
    ```
  - (\*) - create a temple object and calculate with it. That is possible due to existence of single element constructor (converting constructor).
##### (❗***HINT***)
- ***#6***: copy constructor
    ```C++
    #include <iostream>
    #include <memory>

    class PointMD{      //multidementional point
        size_t total{0};
        double* coords{nullptr};
        public:
        PointMD() : total(0), coords(nullptr){}
        PointMD(size_t n) : total(n), coords(new double[n]{0}){
            std::cout << "Created"<<std::endl;
        }
        PointMD(size_t n, double* data):PointMD(n){         //calling one constructor from athother
            set_coords(n,data);
        }
        //copy constructor
        // PointMD(const PointMD& other) : total(other.total){
        //     coords = new double[total];
        //     set_coords(total,other.coords);
        //     std::cout << "Copied"<<std::endl;
        // }
        //copy constructor #2
        PointMD(const PointMD& other) : PointMD(other.total,other.coords){  //calling another constructure to avoid code copies
        }
        ~PointMD(){
            delete[] coords;
            std::cout << "Freed"<<std::endl;
        }

        void set_coords(size_t n, double* data){
            for(size_t i=0;i<total;i++){
                coords[i] = (i<n)?data[i]:0;
            }
        }
        const size_t get_total(){ return total;}
        const double* get_coords(){ return coords;}
        const double get_coord(size_t i){return coords[i];}

        //rewriting the copy assignment operator
        const PointMD& operator=(const PointMD& other)
        {
            std::cout << "Assigned"<<std::endl;
            if(this != &other){
                delete [] coords;
                total = other.total;
                coords = new double[total];
                set_coords(total, other.coords);
            }
            return *this;
        }
    };

    int main() {
        PointMD pt(5);                          //output: Created

        double ar[]{1,2,3,4,5};
        pt.set_coords(5,ar);

        for(size_t i=0;i<pt.get_total();i++){   //output: 1 2 3 4 5
            std::cout<<pt.get_coord(i)<<" ";
        }
        std::cout<<std::endl;

        for(size_t i=0;i<pt.get_total();i++){   //output: 1 2 3 4 5
            std::cout<<pt.get_coords()[i]<<" ";
        }
        std::cout<<std::endl;

        PointMD pt2{pt};                        //output: Copied

        PointMD pt3;
        //this is not initialization, copy constructor is not active 
        //bypass: rewriting copy assignment operator
        pt3=pt;                                 //output: Assigned                                 

        PointMD pt4{5,ar};                      //output: Created
        for(size_t i=0;i<pt4.get_total();i++){  //output: 1 2 3 4 5
        std::cout<<pt4.get_coord(i)<<" ";
        }
        std::cout<<std::endl;

        return 0;
    }                                           //output: Freed     Freed     Freed     Freed
    ```


### Destructor
In C++, a **destructor** is a special member function that is **automatically** called when an object goes out of scope or is **explicitly deleted**. The primary purpose of a destructor is to perform cleanup operations, such as releasing resources that the object may have acquired during its lifetime. This can include deallocating memory, closing file handles, or releasing network connections.
- A destructor has the same name as the class but is preceded by a **tilde (~)**. For example, if you have a class named `MyClass`, the destructor would be named `~MyClass`.
- Destructors do not take any parameters and do not return a value.
- Destructors are called automatically when an object goes out of scope (for stack-allocated objects) or when delete is called on a dynamically allocated object.
- A class can have only one destructor. It **can't** be overloaded.
- If a class is intended to be a base class, it is a good practice to declare its destructor as virtual. This ensures that the destructor of the derived class is called when an object is deleted through a base class pointer.

#### Example
```C++
#include <iostream>

class MyClass {
private:
    int* data; // Pointer to dynamically allocated memory

public:
    // Constructor
    MyClass(int size) {
        data = new int[size]; // Allocate memory
        std::cout << "Constructor: Memory allocated for " << size << " integers." << std::endl;
    }
    // Destructor
    ~MyClass() {
        delete[] data; // Deallocate memory
        std::cout << "Destructor: Memory deallocated." << std::endl;
    }
};

int main() {
    {
        MyClass obj(5); // The constructor is called, and memory is allocated
    } // obj goes out of scope here, and the destructor is called

    //Danger!!!
    MyClass obj(5);
    MyClass obj2{obj};  //points to the same memory
    //destructor will be called 2 time  for the same memory, that leads to an error!

    return 0;
}
```
- This kind of issue (double call of destructor, when one object is connected to the same memory) can be bypassed by writing a [**copy constructor**](#constructor).


### Overloaded constructors 
With the same logic as overloaded functions **overloaded constructors** allow to have different constructors with the same name, but different parameters.

#### Example
```C++
class Pizza{
    public:
        std::string topping1;
        std::string topping2="NON";
        std::string topping3="NON";

    Pizza(){}
    Pizza(std::string t1){
        topping1= t1;
    }
    Pizza(std::string t1, std::string t2){
        topping1= t1;
        topping2= t2;
    }
    Pizza(std::string t1, std::string t2, std::string t3){
        topping1= t1;
        topping2= t2;
        topping3= t3;
    }
    void ingredients(){
        std::cout << "Topping 1: " << topping1 << std::endl;
        if(topping2!="NON"){
            std::cout << "Topping 2: " << topping2 << std::endl;
            }
        if(topping3!="NON"){
            std::cout << "Topping 3: " << topping3 << std::endl;
        }
    }
};

int main(){
    using std::cout, std::endl;
    Pizza p1("peppirony");
    Pizza p2("peppirony", "mushroom", "olive");
    p1.ingredients();
    cout << endl;
    p2.ingredients();
   return 0;
} 
```

### Constant methods
A constant method is a member function of a class that is declared with the `const` keyword at the end of its declaration. This indicates that the method does not modify the state of the object on which it is called. Constant methods are useful for providing read-only access to the object's data members and ensuring that the object's state remains unchanged.
- Inside a constant method, you cannot modify any non-static member variables of the class. Attempting to do so will result in a compilation error.
- This is useful to fix the issue, when you can't call a method of an object passed as constant reference.
- Only constant methods can be called from a constant method.
- Constant methods can't return not-constant pointers of references.
- If you need to set a variable, so it will be changeable inside a constant method, use `mutable`:
    ```C++
    class myClass{
        int x;
        public:
            mutable unsigned  count_call;
        int get_X ()  const{
            count_call++;
            return x;
        }
    };
    ```
    - Better not to use it.

#### Example
```C++
class Pizza{
    private:
        name
    public:
        std::string getName() const {
            return name; // Allowed: reading member variable
        }
};
```

### Overloading operators 
Operator overloading is the process of defining the behavior of operators when they are used with objects of a class. This is done by declaring a member function with name `operator<symbol>`. The function takes the operands as parameters and performs the desired operation.

#### Copy assignment operator `=`
The copy assignment operator is used to assign the contents of one object to another. 
Usually for classes copy assignment operator is set automatically, and it copies byte by byte all elements from one object to another. But rewriting it is useful and needed if you work with dynamic memory inside objects.

```C++
class PointMD{      //multidementional point
    size_t total{0};
    double* coords{nullptr};
    public:
    PointMD() : total(0), coords(nullptr){}
    PointMD(size_t n) : total(n), coords(new double[n]{0}){ }
    PointMD(size_t n, double* data):PointMD(n){ 
        set_coords(n,data);
    }
    PointMD(const PointMD& other) : PointMD(other.total,other.coords){  }

    ~PointMD(){
        delete[] coords;
    }

    void set_coords(size_t n, double* data){
        for(size_t i=0;i<total;i++){
            coords[i] = (i<n)?data[i]:0;
        }
    }

    //rewriting the copy assignment operator
    const PointMD& operator=(const PointMD& other)
    {
        if(this != &other){
            delete [] coords;
            total = other.total;
            coords = new double[total];
            set_coords(total, other.coords);
        }
        return *this;
    }
};

int main() {
    PointMD pt(5);
    PointMD pt3;
    
    pt3=pt;                                

    return 0;
}
```

#### Addition operator `+` (❗***HINT***)
The addition operator is used to add two objects together.
- ***#1***: addition operator overloading example
    ```C++
    class myclock{
    unsigned long sec;
    public:
    myclock(unsigned long days, unsigned long hours, unsigned long minutes, unsigned long seconds)
    : sec (days * 24 * 60 * 60 + hours * 60 * 60 + minutes *60 + seconds) {  }
    myclock (unsigned long tm): sec(tm){ }              //converting constructor
    void getTime (unsigned long& days , unsigned long& hours, unsigned long& minutes, unsigned long& seconds);
        myclock operator + (const myclock& right) const{
            return myclock(this->sec+right.sec);
        }

    };

    void myclock::getTime(unsigned long& days , unsigned long& hours, unsigned long& minutes, unsigned long& seconds){
        seconds=sec%60;
        minutes=(sec/60)%60;
        hours=(sec/(60*60))%24;
        days = sec / (24 * 60 * 60);
    }
    using std::endl, std::cout;
    int main(){
        myclock set1(2,3,55,5), set2(5,1,0,0);
        unsigned long days, hours, minutes, seconds;
        set1.getTime(days,hours, minutes, seconds);
        cout << "Time is: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." <<endl;
        set2.getTime(days,hours, minutes, seconds);
        cout << "Time is: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." <<endl;
        myclock set3=set1+set2;                         //same as set1.operator+(set2)
        set3.getTime(days,hours, minutes, seconds);
        cout << "Time is: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." <<endl;
        set3=set3+50;
        set3.getTime(days,hours, minutes, seconds);
        cout << "Time is: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." <<endl;
        set3=set3+50;                                   //ERROR: how to fix it?!  => example #4
        set3=set3+myclock(1,20,30,5);
        set3.getTime(days,hours, minutes, seconds);
        cout << "Time is: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." <<endl;
        return 0;
    } 
    ```
- ***#2***: addition operator overloading example: another approach 
    ```C++
    class myclock{
    unsigned long sec;
    public:
    myclock(unsigned long days, unsigned long hours, unsigned long minutes, unsigned long seconds)
    : sec (days * 24 * 60 * 60 + hours * 60 * 60 + minutes *60 + seconds) {  }
    myclock (unsigned long tm): sec(tm){ }              //converting constructor
    void getTime (unsigned long& days , unsigned long& hours, unsigned long& minutes, unsigned long& seconds);
        unsigned long operator + (const myclock& right) const{
            return this->sec+right.sec;
        }

    };
    void myclock::getTime(unsigned long& days , unsigned long& hours, unsigned long& minutes, unsigned long& seconds){
        seconds=sec%60;
        minutes=(sec/60)%60;
        hours=(sec/(60*60))%24;
        days = sec / (24 * 60 * 60);
    }
    using std::endl, std::cout;
    int main(){
        myclock set1(2,3,55,5), set2(5,1,0,0);
        unsigned long days, hours, minutes, seconds;
        set1.getTime(days,hours, minutes, seconds);
        cout << "Time is: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." <<endl;
        set2.getTime(days,hours, minutes, seconds);
        cout << "Time is: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." <<endl;
        myclock set3=set1+set2;
        set3.getTime(days,hours, minutes, seconds);
        cout << "Time is: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." <<endl;
        return 0;
    } 
    ```
    - That kind of interpretation is possible due to [**converting constructor**](#converting-constructor).
- ***#3***: addition operator overloading example: fixing the order in operations problem
    ```C++
    class myclock{
        unsigned long sec;
        public:
        myclock(unsigned long days, unsigned long hours, unsigned long minutes, unsigned long seconds)
        : sec (days * 24 * 60 * 60 + hours * 60 * 60 + minutes *60 + seconds) {  }
        myclock (unsigned long tm): sec(tm){ }
        void getTime (unsigned long& days , unsigned long& hours, unsigned long& minutes, unsigned long& seconds) const;
        unsigned long getTime() const{return sec;}
    };

    unsigned long operator + (const myclock& left, const myclock& right){
            return left.getTime() + right.getTime();
        }

    void myclock::getTime(unsigned long& days , unsigned long& hours, unsigned long& minutes, unsigned long& seconds) const{
        seconds=sec%60;
        minutes=(sec/60)%60;
        hours=(sec/(60*60))%24;
        days = sec / (24 * 60 * 60);
    }
    using std::endl, std::cout;
    int main(){
        myclock set1(2,3,55,5);
        unsigned long days, hours, minutes, seconds;

        myclock set3=set1+600;
        set3.getTime(days,hours, minutes, seconds);
        cout << "Time is: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." <<endl;
        set3=7000+set1;
        set3.getTime(days,hours, minutes, seconds);
        cout << "Time is: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." <<endl;
        set3=7000+500;
        set3.getTime(days,hours, minutes, seconds);
        cout << "Time is: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." <<endl;
        return 0;
    } 
    ```
#### Index operator `[]`
Operator to ease work with arrays of data inside object.
- The task is hardened by the fact that index operator should work differently based on if we are reading or writing data. Due to that solution involves creating another class within the main one.

```C++
class DArray{      //dynamic array 
    enum {
        max_length = 50,
        resize_factor=2,
        start_length=8,
        error_val=999
    };

    size_t length{0};
    size_t capacity{0};
    int* data{nullptr};

    class Item{
        DArray* current{nullptr};
        int index {-1};
        public:
            Item(DArray* p, int i):current(p), index(i){}
            //will work when something is written into array
            int operator = (int right);
            //will work when something is read from array     
            operator int () const;    //operator of class transformation to int
    };

    void _resize_array(int new_size);


    public:
        DArray() : length(0), capacity(start_length), data(new int[capacity]){}
        DArray(const DArray& other) : length(other.length), capacity(other.capacity), data(new int[capacity]){ 
            for(size_t i=0; i<length; ++i)
                data[i]=other.data[i];
        }
        ~DArray(){delete[] data;}

        int size() const {return length;}
        int capacity_ar() const { return capacity;}
        const int* get_data()const {return data;}
        void push_in(int value);

        const DArray& operator=(const DArray& other);

        Item operator [](int index){
            return Item(this,index);
        }
};

void DArray::push_in(int value){
    if(length>=capacity)
        _resize_array(capacity*resize_factor);

    if(length <capacity)
        data[length++]=value;
}
void DArray::_resize_array(int new_size){
    if(new_size>capacity){
        while (new_size>=capacity){
            capacity*=resize_factor;
            if(capacity>=max_length){
                capacity=max_length;
                break;
            }
        }
        int* new_data = new int[capacity];
        for(size_t i=0; i<length; ++i)
            new_data[i]=data[i];
        
        delete [] data;
        data = new_data;
    }
}
const DArray& DArray::operator=(const DArray& other)
{
    if(this != &other){
        delete [] data;
        length=other.length;
        capacity=other.capacity;
        data=new int[capacity];
        for(size_t i=0; i<length; ++i)
            data[i]=other.data[i];
    }
    return *this;
};

int DArray::Item::operator = (int right){
    if (index>=max_length || index<0)
        return right;
    if( index>=current->capacity)
        current->_resize_array(index+1);
    for (size_t i =current->length;i<index;i++ )
        current->data[i]=0;
    current->data[index]=right;
    if(index>=current->length)
        current->length=index+1;
    return right;           //this is needed to constructions like: a=b=c; - will work
}
DArray::Item::operator int () const{
    if (index>=current->length || index<0)
        return error_val;
    return current->data[index];
}

int main(){
    DArray ar1;
    for(int i=0; i<10;i++)
        ar1.push_in((i+1)*M_PI);

    ar1[25]=777;
    int v=ar1[25];

    cout<<v<<endl;
    for(int i=0; i<26;i++)
        cout<<ar1[i]<<" ";
    cout<<endl;
    cout<<ar1[255]<<endl;       //error code

    return 0;
} 
```

#### Operations: `+=`, `*=`, `%=`, etc  (//❗❗)
- Guide: [Click](https://youtu.be/EdHgDl52aNU?si=uKE0OiCSzNLgskdz)
- File: <!-- [/C&C++/materials/CPP/dynamic_array.cpp](/C&C++/materials/CPP/dynamic_array.cpp) -not ready -->

#### Operations: `++`, `--`               (//❗❗)
Increment and decrement operators.
- Guide: [Click](https://youtu.be/zd4nAiRt18Y?si=T9XccOm91frAkZZV)
- File: <!-- [/C&C++/materials/CPP/dynamic_array.cpp](/C&C++/materials/CPP/dynamic_array.cpp) -not ready -->
  
#### Operator `()`
See [Functors](#functors)

### Functors
Functors (or functional objects) are objects that can be called as if they were functions. They allow you to use an object-oriented approach to create callable entities, which can be particularly useful in various contexts.

#### Examples: functors
```C++
class Counter{ 
    double start{0.0};
    double step{0.0};
    double count{start};
    public:
        Counter(double start=0.0, double step=1.0): start(start), step(step),count(start){}
        operator double() const {return count;}
        double operator()(){
            double temp = count;
            count += step;
            return temp;
        }    
};

int main(){
    Counter c1, c2(0.0,0.5);
    double r1=c2;
    c2();
    double r2 = c2();           //objects of class counter can be called like fuctions
    c2();
    c2();
    c2();
    double r3=c2;
    cout  << r1 << " " << r2 << " " << r3 << endl;  //0 0.5 2.5
    return 0;
} 
```

### Friend classes and functions
To bypass access prohibitions (`privare`), outside functions can be announced inside a class as friendly (marked with word `friend`), in this case private variables and methods will be accessible inside this function.
The same can be done for a class.
- **!** This instrument is considered damaging to the readability of the program, use it with caution. Better find another way.
- Friendliness can be written inside `private` or `public` section - it does not matter.

#### Example: friend classes and functions
```C++
class myclass{
    int x, y;
    friend class myOtherClass;
    public:
        int fun1(){ return x+y;}
        friend int fun3(myclass& obj);
        int fun4();
        int getX(){return x;}
        int getY(){return y;}
        myclass(int x, int y){
            this->x = x;
            this->y = y;
        }
};
int fun2(myclass& obj){ 
    // return obj.x+obj.y;              //error of access
    return obj.getX()+obj.getY();
}
int fun3(myclass& obj){
    return obj.x+obj.y;
}
int myclass::fun4(){
    return x+y;
}
class myOtherClass{
    public:
        static void printFun (const myclass& obj) {
            cout << "x = " << obj.x << endl;
            cout << "y = " << obj.y << endl;
        }
};
```

### Inheritance
Inheritance is a principle of *OOP* that allows a new class (subclass/derived class/**child class**) to inherit *attributes* and *methods* from an existing class (superclass/base class/**parent class**). 
- This method helps to reuse similar code found within multiple classes.
- Which elements to inherit: `private` aren't inherited, `protected` are inherited,`public` are inherited.
- Pointer of child class can be assigned to a parent pointer, in this case via parent pointer we can access any attributes (data) of the child object that where declared in parent class and any method that where declared in parent class, but can't access the elements that where declared in the child class and data those store.

#### Overriding class elements
**Override methods**: If method in child class has the same signature are one in parent it will override it so if called via child object child's method will be called.
  - But if we set parent class as namespace it will call method from there:
    ```C++
    class parent{
        public:
        void method(){        cout << "Parent method" << endl;    };
    };
    class child:public parent{
        public:
        void method(){        cout << "Child method" << endl;    };
    };
    int main(){
        child c;
        parent p = c; //p is a parent object
        p.method(); //calls parent's method
        c.method(); //calls child's method
        c.parent::method(); //calls parent's method
        return 0;
    }
    ```
**Override attributes**: is possible, but is mostly used only for constants (due to the fact that it damage readability of code). In this case both the parent class and child class attributes are getting memory storage and methods from each class affect attributes from that class.  
  ![Overriding_class_elements](/C&C++/media/override_clas_elements.png "The way overrided elements are stored in memory")

#### Inheritance types
Description will be based at:
```C++
class Shape{
    //...
};
class Circle : public Shape{            //public inheritance
    //...
};
```

- **PUBLIC**
  - It establishes an "IS-A" relationship: By using public, we're stating that a Circle is indeed a type of Shape. This aligns with the Liskov substitution principle in object-oriented design.
  - It preserves access to public members: Any public members of the Shape class will remain public in the Circle class, allowing them to be accessed directly from Circle objects. Circle can add its own private members, maintaining encapsulation.
  - It allows for [polymorphism](/General/Dictionaty.md): Objects of the Circle class can be treated as Shape objects wherever a Shape is expected, enabling polymorphic behavior.
  - It maintains the public interface: Any public functions or variables in Shape will remain accessible through Circle objects, preserving the intended interface.
- **PRIVATE**
  - Makes the inherited members private in the derived class. Only accessible within the derived class.
- **PROTECTED**
  - Makes the inherited members protected in the derived class. Accessible within the derived class and its subclasses.
- *The default inheritance type*. 
  - If no access specifier is used, private inheritance is assumed by default. Makes all inherited members private in the derived class.

#### Constructor-destructor order
- The order:
  1) Constructor of base class;
  2) Constructor of derived class;
  3) Destructor of derived class;
  4) Destructor of base class.
- Issues:
  - If there is no default constructor (with no arguments) in the base class - the compiler return an error. To fix that in constructor of the child class you should call constructor of the base class that dies exist.
    ```C++
    class parent{
        public:
        parent(int a){cout << "Parent constructor" << endl;}
    };
    class child : public parent{
        x{0};
        public:
        child():parent(0):x{0}{...}
    };
    ```

#### Protected constructor and destructor (❗***HINT***) (//❗❗)
- Put constructor of a parent class into `protrcted` section to avoid creating objects of parent class, while be able to use this constructor from the child class to create objects of the child class. Parent class will be usable only from inheritance classes.
- Put destructor of a class into `protected` section to avoid creating objects of this class in stack - this way objects can only be created in heap. To free memory in this case it is possible to create a special method in class that will delete object - free memory (this method will be able to call `protected` destructor and everything will work fine).
- More info: [Click](https://youtu.be/bTvoVPmPUgg?si=_Dg0M0n-nQQ8F53z)

#### Examples
- **#1**
    ```C++
    class Animal{
        public:
            bool alive =true;
        void eat(){
            std::cout<<"Eating"<<std::endl;
        }
    };
    class Dog:public Animal{
        bool nameteg=true;
        public:
        void bark(){
            std::cout<<"Barking"<<std::endl;
        }
        void stayAtHome(){
            std::cout<<"Staying near house"<<std::endl;
        }
    };
    class Cat:public Animal{
        bool bed=true;
        public:
        void meow(){
            std::cout<<"Meowing"<<std::endl;
        }
        void stayAtHome(){
            std::cout<<"Staying in house"<<std::endl;
        }
    };
    int main(){
        using std::cout, std::endl;
        Dog Guffy;
        Cat Tom;
        Guffy.eat();
        cout<<"Guffy is alive: "<<Guffy.alive<<endl;
        Guffy.bark();
        Guffy.stayAtHome();
        Tom.eat();
        cout<<"Tom is alive: "<<Tom.alive<<endl;
        Tom.meow();
        Tom.stayAtHome();
        Tom.bark();                                 //error
        Dog* newDoggo;
        Animal* newPet = newDoggo;                  // through this pointer can access `alive` but can't access `nameteg`
        return 0;
    } 
    ```
- **#2**
Check [/C&C++/materials/CPP/example_1.cpp](/C&C++/materials/CPP/example_1.cpp)


### Virtual method 
An **virtual method** (**virtual function**) is a member function in a base class that you expect to override in derived classes. 
- When a function is declared as virtual, C++ uses a mechanism called **dynamic binding** (or late binding) to resolve which function to call at runtime. This is typically implemented using a "vtable" (**virtual table**), which is a table of function pointers.
- To make function virtual use keyword `virtual`.
- When you use a base class pointer or reference to call a **virtual function**, C++ determines which function to invoke at runtime based on the actual object type, not the type of the pointer/reference:
    ```C++ 
    class Animal{
        public:
        virtual void eat(){cout<<"Animal eats"<<endl;} // Virtual method
    };
    class Dog:public Animal{
        public:
        void eat(){cout<<"Dog eats"<<endl;}
    };
    int main(){
        Dog doggo;
        Animal* animal = &doggo; // base class pointer
        Animal* animal2{new Animal};
        animal->eat();  // Output: Dog eats
        animal2->eat(); // Output: Animal eats
        doggo.eat();    // Output: Dog eats
        return 0;
    }
    ```
  - Schemes of memory control:  
    - [for parent pointing to child](/C&C++/media/virtual_method_1.png)
    - [for parent pointing to parent](/C&C++/media/virtual_method_2.png)
  - Letting a program decide at runtime which method to invoke is an example of dynamic (or run-time) [***polymorphism***](/General/Dictionaty.md).
- Using virtual method allows you to treat objects of derived classes as objects of the base class. This is particularly useful in scenarios where you want to write code that can work with objects of different types through a common interface.
- The class that inherit and re-define a virtual method is called "polymorphic class".
- ❗If a class has a virtual method, its destructor (even if it does nothing) should be set virtual too! It is important, because otherwise in situations like assigning to a parent class object of child class, wrong destructor will be called. If parent destructor is set virtual, both destructors get into virtual table and **both** will be called, when cleaning child object. 

#### `override` and `final`
- **`override`**: keyword is used to indicate that a function is intended to override a virtual function. It works like a flag for the compiler.
  - If function is `const`, `override` goes after the `const`.
  - `override` should be used at all methods that overrides virtual methods.
- **`final`** keyword can be used to prevent a function from being overridden in derived classes. It works like a flag for the compiler.
  - If function is `const`, `final` goes after the `const`. 
  - If function has `override`, `final` goes after the`override`.

#### Examples virtual method
- **#1**
    ```C++
    class Base {
    public:
        virtual void show() {
            std::cout << "Base class show function called." << std::endl;
        }
    };
    class Derived : public Base {
    public:
        void show() override { // Override the base class function
            std::cout << "Derived class show function called." << std::endl;
        }
    };
    class Derived_2 : public Base {
    public:
        void show() override { // Override the base class function
            std::cout << "Derived #2 class show function called." << std::endl;
        }
    };

    void display(Base* b) {
        b->show(); // Calls the appropriate show() function based on the actual object type
    }
    int main() {
        Base b;
        Derived d;
        Derived_2 d2;

        display(&b); // Output: Base class show function called.
        display(&d); // Output: Derived class show function called.
        display(&d2); // Output: Derived #2 class show function called.

        return 0;
    }
    ```
- **#2**
  Check out [/C&C++/materials/CPP/example_1.cpp](/C&C++/materials/CPP/example_1.cpp)


### **Abstract method** (Pure Virtual Functions)
A **pure virtual function** is a virtual function that has no implementation in the base class. This makes the class abstract, meaning you cannot instantiate it directly. Derived classes must provide an implementation for the **pure virtual function**.
- **`= 0`** is used to declare a pure virtual function.
- This approach allows us to get error at the compilation step if we try to use method that are not set in child object, that can save as from wrong actions of the program. 

#### Examples abstract method
- **#1**
    ```C++
    class AbstractBase {
    public:
        virtual void show() = 0; // Pure virtual function
    };

    class DerivedClass : public AbstractBase {
    public:
        void show() override {
            std::cout << "Derived class show function called." << std::endl;
        }
    };
    int main(){
        DerivedClass ob1;
        ob1.show(); // Output: Derived class show function called.
        AbstractBase ob2;
        //ob2.show(); // Error: Cannot instantiate abstract class
        AbstractBase* ob3=&ob1;
        ob3->show(); // Output: Derived class show function called.
        return 0;
    }
    ```
- **#2**
    ```C++
    class figure{
        protected:
            double x0{0},y0{0},x1{0},y1{0};
        public:
            virtual void printer()const=0;
    };
    class circle:public figure{
        public:
            void printer() const override final {
                cout<<"Circle: "<<x0<<" "<<y0<<" "<<x1<<" "<<y1<< endl;
            }
    };
    class line:public figure{
        public:
            void printer() const override final {
                cout<<"Line: "<<x0<<" "<<y0<<" "<<x1<<" "<<y1<< endl;
            }
    };
    class rectangle:public figure{
        public:
            void printer() const override final {
                cout<<"Rectangle: "<<x0<<" "<<y0<<" "<<x1<<" "<<y1<< endl;
            }
    };

    int main(){
        int ammo=4;
        figure* list[ammo]{nullptr};
        list[0]=new circle();
        list[1]=new line();
        list[2]=new rectangle();
        list[3]=new circle();
        for (int i=0;i<ammo;i++)
            list[i]->printer();
        for (int i=0;i<ammo;i++)
            delete list[i];
        return 0;
    }
    ```



### Abstract Classes
**Abstract Classes** are classes that cannot be instantiated on their own (object of this class can't be created) and are meant to be subclassed. They can contain both abstract methods and concrete methods (which have an implementation), but should contain at least one [pure virtual function](#pure-virtual-functions).  
- Using Abstract classes supports [polymorphism](/General/Dictionaty.md).
- Sometimes, it's useful to declare an interface without providing any implementation details. This can be achieved using forward declarations:
    ```C++
    class InterfaceForwardDeclaration;

    class ConcreteClass : public InterfaceForwardDeclaration {
        // Implementation
    };
    ```

### Interface
An **interface** is a contract or specification that defines a set of methods or behaviors that a class must implement. 
- **Interfaces** define a contract that classes must adhere to.
- Classes that implement an interface must provide concrete implementations for all of its methods. 
- The most common way to create interfaces in C++ is through [**abstract classes**](#abstract-classes). In C# and some other languages *interfaces* exist as a separate instrument.
- **Interfaces'** main purposes are:
  - To achieve abstraction by defining a common interface for a group of unrelated classes;
  - To enable [polymorphism](/General/Dictionaty.md) and loose coupling between different parts of a program;
  - To define a contract or protocol that classes must follow.
- **Interfaces'** characteristics:
  - An interface typically contains only method signatures, without implementations;
  - It does not include data members or variables;
  - Methods in an interface are implicitly public and abstract;
  - Interfaces can have static and constant variables.
  
#### Interface (Pure Virtual Class) vs Abstract Class

| Feature               | Interface (Pure Virtual Class)                                                                               | Abstract Class                                                                                                                                         |
| --------------------- | ------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Description           | In C++, an interface is typically defined using a class that contains only pure virtual functions (methods). | An abstract class in C++ is a class that contains at least one virtual function. It can also contain concrete (non-pure) methods and member variables. |
| Instantiation         | Cannot be instantiated                                                                                       | Cannot be instantiated                                                                                                                                 |
| Method Implementation | Only pure virtual methods                                                                                    | Can have both pure virtual and concrete methods                                                                                                        |
| Member Variables      | Cannot have member variables                                                                                 | Can have member variables                                                                                                                              |
| Constructors          | No constructors                                                                                              | Can have constructors                                                                                                                                  |
| Use Case              | Define a contract for unrelated classes                                                                      | Provide a common base for related classes                                                                                                              |

### Multiple inheritance
Multiple inheritance is a feature in object-oriented programming where a class can inherit properties and methods from more than one parent class. 
- **Multiple inheritance** allows a class to inherit behavior from multiple base classes.
- It is dangerous because can lead to error from interfering the parent classes, but can be useful in some situations.
- Multiple inheritance can be achieved by writing parent classes with inheritance mod for each separated by comma in the child class declaration line.
- In case of multiple inheritance constructors of base classes are called in the same order as classes was written in child class declaration and then child class' constructor will be called. Destructors will have the backwards order.
- Memory scheme:
    ![Multyple_inheritance](/C&C++/media/multiple_inheritance.png)
- Example: 
  - [/C&C++/materials/CPP/multiple_inheritance.cpp](/C&C++/materials/CPP/multiple_inheritance.cpp)

#### Diamond inheritance  (virtual classes declaration)
Specific scenario in multiple inheritance where a class inherits from two classes that both derive from a common base class. This creates a diamond-shaped structure in the class hierarchy, leading to potential ambiguity in method resolution.
- Issue:
    ```C++
    class Base {
    public:
        void fun() { cout << "Base" << endl; }
    };

    class Parent1 : public Base {
    public:
        void fun() { cout << "Parent1" << endl; }
    };

    class Parent2 : public Base {
    public:
        void fun() { cout << "Parent2" << endl; }
    };

    class Child : public Parent1, public Parent2 {
        // Ambiguity arises here
    };
    ```
    - Multiple call of "base" constructor.
    - Overlap of "fun" method interpretation - for Child objects method is unusable.
- To fix this issue add `virtual` in both ("Parent1" an "Parent2") classes declaration.
    ```C++
    class Base {
    public:
        void fun() { cout << "Base" << endl; }
    };

    class Parent1 : virtual public Base {
    public:
        void fun() { cout << "Parent1" << endl; }
    };

    class Parent2 : virtual public Base {
    public:
        void fun() { cout << "Parent2" << endl; }
    };

    class Child : public Parent1, public Parent2 {
        // Ambiguity arises here
    };
    ```
    - Fixed.
- More info: [click](https://youtu.be/bTvoVPmPUgg?si=od3nNRksLT36oFCy)


### Static attributes and Static methods
#### Static attributes  
Static member variables (**attributes**) belong to the class itself rather than to any specific object. They are shared among all instances of the class. Static attributes are not created or kept in objects, but each object of the class have reference to it in it.  
#### Static method  
Static methods are **methods** that belong to the class itself rather than to any specific object. They are shared among all instances of the class. Static methods are not created or kept in objects, but each object of the class can call it.  Basically it is just a function in the class namespace.
#### Examples of static methods and static attributes  
```C++
class Car {
    private:
        static int carCount; // Static property
    public:
        Car() {
            carCount++; // Increment car count when a new car is created
        }
        static int getCarCount() { return carCount; }   
};
class Trucks:public Car{
    //...
};

int Car::carCount = 0; // Initialize static member - can be initialized even if it private
int main(){
    Trucks BFT, SFT, AFT;
    std::cout << Car::getCarCount() << std::endl; // Output: 3
    std::cout << SFT.getCarCount() << std::endl; // Output: 3
    std::cout << Car::carCount << std::endl;     // Error: would work if it was public
}
```

### Methods outsource (❗***HINT***)
Methods can be defined outside the class definition. This is useful for several reasons:
- It allows you to separate the interface from the implementation.
- It makes it easier to reuse and read code.
- It can improve performance by reducing the size of the compiled code.
- It can make it easier to test and debug code.
- It can stop class from growing too big
It is possible because of:
- Each class can be seen as a namespace, and namespace rules can apple to it.
- Methods just like functions can be announced in one place and described in another.
The idea is: 
- to keep inside the class attributes, short methods and long methods' declaration;
- to keep outside the class long methods and methods that are not used often.
- **!!** Usually definition of elements are kept in separate *.cpp* file, while the class is described in **.h* file.
Terms:
- declarations of methods inside class are called **prototypes**.
Syntax:
- Inside class: **prototype** : `<data_type> <name_of_element>(<input>);`
- Outside class: **definition** : `<data_type> <class_name>::<name_of_element>(<input>){<definition>}`

#### Examples method outsource
```C++
```C++
#include <iostream>
#include <memory>

class PointMD{      //multidementional point
    size_t total{0};
    double* coords{nullptr};
public:
    PointMD() : total(0), coords(nullptr){}
    PointMD(size_t n) : total(n), coords(new double[n]{0}){    }
    PointMD(size_t n, double* data):PointMD(n){   set_coords(n,data);  }
    PointMD(const PointMD& other) : PointMD(other.total,other.coords){    }
    ~PointMD(){  delete[] coords;   }

    void set_coords(size_t n, double* data);        //prototype
    const size_t get_total(){ return total;}
    const double* get_coords(){ return coords;}
    const double get_coord(size_t i){return coords[i];}
    const PointMD& operator=(const PointMD& other);        //prototype
};

void PointMD::set_coords(size_t n, double* data){
    for(size_t i=0;i<total;i++){
        coords[i] = (i<n)?data[i]:0;
    }
}

const PointMD& PointMD::operator=(const PointMD& other)
{
    std::cout << "Assigned"<<std::endl;
    if(this != &other){
        delete [] coords;
        total = other.total;
        coords = new double[total];
        set_coords(total, other.coords);
    }
    return *this;
}
```

### Class template   
Similarly to [function template](#function-template) it is possible to create class and structure templates in C++.
- Syntax: 
    ```C++
    template </*parameters*/>
    class /*class name*/ {
        /*class body*/
    };
    ```
- Instead of `typename` can use keyword `class`.
- - **Class template instantiation** - the process of creating a specific function from a function template by substituting the template parameters with actual types.

#### Examples: Class templates
- ***#1***
    ```C++
    template <typename T> 
    class Point {
        T x{}, y{};
        static T counter_obj;
    public:
        Point(T a, T b):x(a),x(b){ }
        T get_x(){return x};
        T get_y(){return y};
        void set_xy(T a, T b){
            x=a;
            y=b;
        }
        void reallyLongFunc (T a, T b);
    };
    template <typename T> 
    void Point<T>::reallyLongFunc (T a, T b){
        //....
    }
    template <typename T> 
    T Point<T>::counter_obj=0;

    int main(){
        Point<int> pt_i(1,2);
        Point<double> pt_d(1.1,2.2);

        Point pt_d(1.1,2.2);        // will deside type from constructor base on arguments(double) -- works from C++17
    }
    ```
#### [More info](https://youtu.be/5YcZMDKygOs?si=DKBKCLwGq9F9cooj)   (//❗❗)


## Standard Template Library

### STL containers 
**Standard Template Library containers** are template classes provided by the C++ Standard Library that are used for storing and managing collections of objects. They offer convenient and efficient ways to work with data, including adding, removing, searching, and sorting elements.

#### Main Categories of STL Containers  (❗***HINT***)
- **Sequence Containers**: These containers store elements in a specific order. Elements can be accessed by index, and their order is preserved.
  - Examples:
    - **`std::array`**: A fixed-size array that can be used when the size in set - ***array***.
    - **`std::vector`**: A dynamic array that can change its size. It provides fast access to elements by index (`#include <vector>`) - ***dynamic arrays***.
    - **`std::deque`**: A double-ended queue that allows adding and removing elements from both the front and the back - ***queue***.
    - **`std::list`**: A ***doubly linked list*** that allows efficient insertion and deletion of elements at any position in the list, but does not provide fast access by index.
  
- **Associative Containers**: These containers store elements as pairs of "key-value". They provide fast access to elements by key.
  - Examples:
    - **`std::set`**: A container that stores unique elements in a sorted order.
    - **`std::map`**: A container that stores pairs of "key-value", where keys are unique and sorted (`#include <map>`).
    - **`std::multiset`** and **`std::multimap`**: Similar to set and map, but allow duplicates.

- **Unordered Associative Containers**: These containers do not store elements as "key-value" pairs and do not guarantee order.
  - Examples:
    - **`std::unordered_set`**: A container that stores unique elements without guaranteeing order.
    - **`std::unordered_map`**: A container that stores "key-value" pairs without guaranteeing order.

#### Examples of using STL Containers

- `std::vector`
    ```C++
    #include <iostream>
    #include <vector>

    int main() {
        std::vector<int> numbers; // Create a vector

        // Add elements
        numbers.push_back(10);
        numbers.push_back(20);
        numbers.push_back(30);

        // Output elements
        for (int num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        return 0;
    }
    ```

- `std::map`
    ```C++
    #include <iostream>
    #include <map>

    int main() {
        std::map<std::string, int> ageMap; // Create an associative container
        // Add "key-value" pairs
        ageMap["Alice"] = 30;
        ageMap["Bob"] = 25;

        // Output values by key
        std::cout << "Alice's age: " << ageMap["Alice"] << std::endl;
        std::cout << "Bob's age: " << ageMap["Bob"] << std::endl;
        return 0;
    }
    ```

### STL algorithms 
Standard Template Library Algorithms are a collection of functions provided by the C++ Standard Library that operate on containers. These algorithms are designed to work with the various STL containers (like vector, list, set, map, etc.) and provide a wide range of functionalities, including searching, sorting, modifying, and manipulating data.

#### Key Features of STL Algorithms
- **Generic Programming**: STL algorithms are designed to work with any container that supports the required operations, provide a uniform interface for accessing elements in different types of containers.
- **Efficiency**: Many STL algorithms are optimized for performance and can handle large datasets efficiently.
- **Flexibility**: Algorithms can be customized using function objects (functors) or lambda expressions, allowing for greater flexibility in how they operate on data.
- **Composability**: Algorithms can be combined to create complex operations by chaining them together.

#### Common STL Algorithms
Here are some commonly used STL algorithms:
- **Sorting Algorithms**:
  - `std::sort`: Sorts the elements in a range.
  - `std::stable_sort`: Sorts the elements while preserving the relative order of equivalent elements.
- **Searching Algorithms**:
  - `std::find`: Searches for a specific value in a range.
  - `std::binary_search`: Checks if a value exists in a sorted range.
- **Modification Algorithms**:
  - `std::copy`: Copies elements from one range to another.
  - `std::transform`: Applies a function to a range of elements and stores the result in another range.
- **Set Operations**:
  - `std::set_union`: Computes the union of two sorted ranges.
  - `std::set_intersection`: Computes the intersection of two sorted ranges.
- **Numeric Algorithms**:
  - `std::accumulate`: Computes the sum of a range of elements.
  - `std::inner_product`: Computes the inner product of two ranges.
- **Other Useful Algorithms**:
  - `std::for_each`: Applies a function to each element in a range.
  - `std::reverse`: Reverses the order of elements in a range.

#### Examples
- Example of Using `std::sort` and `std::for_each`:
    ```C++
    #include <iostream>
    #include <vector>
    #include <algorithm> // For std::sort and std::for_each

    int main() {
        std::vector<int> numbers = {5, 3, 8, 1, 2};

        // Sort the numbers
        std::sort(numbers.begin(), numbers.end());

        // Print the sorted numbers
        std::for_each(numbers.begin(), numbers.end(), [](int num) {
            std::cout << num << " ";
        });
        std::cout << std::endl;

        return 0;
    }
    ```
- Example of Using `std::find`
    ```C++
    #include <iostream>
    #include <vector>
    #include <algorithm> // For std::find

    int main() {
        std::vector<int> numbers = {5, 3, 8, 1, 2};

        // Find a specific number
        auto it = std::find(numbers.begin(), numbers.end(), 3);
        if (it != numbers.end()) {
            std::cout << "Found: " << *it << std::endl;
        } else {
            std::cout << "Not found." << std::endl;
        }

        return 0;
    }
    ```

## Multithreading   (//❗❗)
std::thread, std::async


## Links
[6 hours basic tutorial (EN)](https://youtu.be/-TkoO8Z07hI?si=vifWswvQmeKroSGu)
[Beginning of series of tutorial videos about basics of C++ (RU)](https://youtu.be/QYZbN2g-Dxc?si=AofHPo_lEbHv93qC)
[Beginning of series of tutorial videos about OOP with C++ (RU)](https://youtu.be/RKMyJKXXpKM?si=5yCHTqHpgMCdhmfm)
[C++ official documentation](https://cplusplus.com/)
