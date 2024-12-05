# C++
- Created in year 1985.
- Developed by Bjarne Stroustrup.
- [Object-oriented programming](/General/Dictionaty.md#object-oriented-programming) (OOP) language.
  - The main principals of OOP are realized via [`class`](#object-and-class)
- Evolution of C.

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



## Code situations and examples

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
- `NULL` = `nullptr`;
- `__cplusplus` - defined (exist) for g++ compiller.

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

#### Value Initialization
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

####  ❗***HINT***
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
    

### Data types 
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

####  ❗***HINT*** #1
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
####  ❗***HINT*** #2
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
####  ❗***HINT*** #3
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
####  ❗***HINT*** #4
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

### Typedef and Using
`typedef` is a keyword in C++ that allows you to give a new name or alias to an existing type. This can make your code more readable and easier to understand.
* Usually the new datatype has **_t** at the end of the name.
* New datatype can be used the same way as old datatype, and old datatype can be used at the same time as new datatype.

####  ❗***HINT***
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
1. Include \<ctime>.
2. Use `srand(time(NULL))` to seed the random number generator.
3. Use `x = rand()` to generate a random number (from 0 to 32767).
    - Use `y = rand()%n` to generate a random number between 0 and n-1.

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

### Dynamic memory  
Memory that is allocated after the program is already compiled and running. 
- This memory is allocated in the heap, which is a big segment of the memory assigned to the program.  
![Memory](/C&C++/media/program_memory.png "Memory of a program")
- The `new` keyword is used to allocate memory dynamically.
- The `delete` keyword is used to free the memory.
  - Use `delete` when you want to deallocate memory that was allocated for a single object using `new`.
  - Use `delete[]` when you want to deallocate memory that was allocated for an array of objects using `new[]`.
- Pointers that do not manage the lifetime of the objects they point to (regular pointers) are called raw pointers.

#### Example
- **#1**
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
        delete matrix[i];
    }
    delete matrix;

    return 0;
    ```
- **#2**
    ```C++
    int main() {
        int* arr = new int[5]; // Allocate memory for an array of 5 numbers
        delete[] arr; // Deallocate memory for the array of numbers
        int* pointer = new int;
        delete pointer;
        return 0;
    }
    ```
    
### Smart pointers (❗***HINT***)
Smart pointers in C++ are objects that manage dynamic memory and automatically release it when the pointer is no longer needed. This helps prevent memory leaks and simplifies resource management. The C++ Standard Library provides several types of smart pointers, with `std::unique_ptr` and `std::shared_ptr` being the most common.
  - `std::unique_ptr` is a smart pointer that provides unique ownership of an object. This means that only one s`td::unique_ptr` can own a given object at any time. When a `std::unique_ptr` goes out of scope or is initialized with another pointer, the object is automatically released.
  - `std::shared_ptr` is a smart pointer that provides shared ownership of an object. The object will be released when the last `std::shared_ptr` pointing to it is destroyed or reset.
- Working with smart pointers requires `#include <memory>`

#### Examples
- **#1 `std::unique_ptr`**
    ```C++
    #include <iostream>
    #include <memory> // For std::unique_ptr

    int main() {
        // Create a unique pointer to an array of 10 integers
        std::unique_ptr<int[]> array(new int[10]);

        // Initialize the array
        for (int i = 0; i < 10; ++i) {
            array[i] = i * 10;
        }

        // Output the values of the array
        for (int i = 0; i < 10; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

        // The pointer automatically releases memory when it goes out of scope
        return 0;
    }
    ```
- **#1 `std::shared_ptr`**
    ```C++
    #include <iostream>
    #include <memory> // For std::shared_ptr

    void useSharedPtr(std::shared_ptr<int> ptr) {
        std::cout << "Value: " << *ptr << std::endl;
    }

    int main() {
        // Create a shared pointer
        std::shared_ptr<int> sharedPtr1(new int(42));

        // Create a second pointer that points to the same object
        std::shared_ptr<int> sharedPtr2 = sharedPtr1;

        std::cout << "Shared Pointer 1 Value: " << *sharedPtr1 << std::endl;
        std::cout << "Shared Pointer 2 Value: " << *sharedPtr2 << std::endl;

        // Pass shared_ptr to a function
        useSharedPtr(sharedPtr1);

        // The object will be released when both pointers go out of scope
        return 0;
    }
    ```
    - `new int(42)`: This part allocates memory for a single integer on the heap and initializes it with the value 42.

#### Example

### Recursion 
A programming technique there a function that invokes (calls) itself from within.
- The function calls itself until it reaches a base case that stops the recursion.
- The recursion can be used to solve problems that have a recursive recitative structure (good for sorting or searching algorithms, for working with tree-like structures).
- In comparison with iterative algorithms:
    - pros: less and cleaner coding;
    - cons: uses more memory and is slower.

### Function templates
A function template is a function that can work with different data types. This allows us to generate as many overloaded functions with different datatype as we need. 

#### Example
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
//this one will work if we have 2 different datatypes too
template <typename T, typename U>
auto max (T x, U y){
    return (x>y)?x:y;
}
```
####  ❗***HINT*** `auto`
- `auto` make the compiler deduce that the result type should be.

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
####  ❗***HINT*** (Fun default)
Having some default parameters in function is useful for functions that's parameters works like settings (change the way function act).
```C++
double round_my(double x, int radix=0){
    double p=pow(10,radix);
    return round(x*p)/p;
}
```

### Structure
A structure is a collection of variables of different data types that can be used together as a single unit.
- Structures can be created with `struct` keyword.
- Variables in structure are called *"members"*.
- *Members* can be accessed with "*class member access operator*":
    - `.` for variables;
    - `->` for pointers.

#### Example 
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

### Enumerations
Enumerations are a way to define a set of named values. It is a user-defined datatype that consists of paired named-integer constants. 
- Enumerations can be created with `enum` keyword.
- Enumerations are great for sets of options.

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

### Exceptions (error handling)
Exceptions in C++ are a powerful mechanism for error handling that allows developers to manage errors and exceptional situations in a more structured and maintainable way compared to traditional error handling methods (return codes, etc).

#### Key Concepts of Exceptions
- **Separation of Error Handling from Regular Code**: using exceptions allows you to separate error handling logic from the main logic of your program. This leads to cleaner and more readable code.
- **Throwing Exceptions**: when an error occurs, you can "throw" an exception using the `throw` keyword. This interrupts the normal flow of the program and transfers control to the nearest exception handler.
- **Catching Exceptions**: you can "catch" exceptions using the `try` and `catch` blocks. This allows you to define how to handle specific types of exceptions.
- **Stack Unwinding**: when an exception is thrown, the program unwinds the stack, meaning that destructors for all objects created in the current scope are called. This helps in resource management and prevents memory leaks.
- **Standard Exception Classes**: C++ provides a hierarchy of standard exception classes in the `<stdexcept>` header, such as `std::runtime_error`, `std::logic_error`, and others, which can be used to represent different types of errors.

#### Example of Using Exceptions
```C++
#include <iostream>
#include <stdexcept> // For std::runtime_error

// Function that may throw an exception
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw std::runtime_error("Division by zero error");
    }
    return numerator / denominator;
}

int main() {
    try {
        double result = divide(10.0, 0.0); // This will throw an exception
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl; // Handle the exception
    }

    return 0;
}
```

### `constexpr`
`constexpr` is a keyword introduced in C++11 that allows to define variables, functions, and constructors that can be evaluated at compile time. This feature is particularly useful for improving performance and enabling certain optimizations by allowing the compiler to perform calculations during compilation rather than at runtime.

#### Key Features of constexpr
- **Compile-Time Evaluation**: functions and variables declared with `constexpr` can be evaluated at compile time, which can lead to faster execution since the results are computed before the program runs.
- **Constant Expressions**: A `constexpr` function must produce a constant expression when given constant expressions as arguments. This means that the function can be used in contexts that require compile-time constants, such as array sizes or template parameters.
- **Usage in Various Contexts**: `constexpr` can be applied to variables, functions, and constructors. This allows for a wide range of applications, from defining constant values to creating complex compile-time computations.

#### Example Usage of `constexpr`
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


### PCH
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

#### Example of Using Precompiled Headers
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

### Lambda Functions  (❗***HINT***)
**Lambda Functions** (or simply **lambdas**, or **anonymous functions**) allows defining anonymous [functions](#functions) (functions without a name) directly in your code (in any fitting place of program). They are particularly useful for short, simple operations that are used only once or a few times, such as in algorithms or as callbacks.
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
    - 
- **Capture Modes**: You can capture variables in different ways:
    - **By Value**: [x] captures x by value (a copy).
    - **By Reference**: [&x] captures x by reference (no copy).
    - **All by Value**: [=] captures all variables used in the lambda by value.
    - **All by Reference**: [&] captures all variables used in the lambda by reference.
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


- **#**: [/C&C++/materials/CPP/lambda_fun_ex.cpp](/C&C++/materials/CPP/lambda_fun_ex.cpp)



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


## Functions 

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

####  ❗***HINT***
Function lists:
- [CMATH](https://cplusplus.com/reference/cmath/)

### Fill()
- fills a range with a value.
#### Syntax
```C++
std::fill( <beginning_of_range>, <end_of_range>, <value> );
```
- Fills with values including beginning and excluding the end.
#### Example
```C++
int length =50;
string n[length];
fill( &n[0], &n[length/2], "pizza");
fill( n + length/2, n + length, "sushi");
```

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

## Manipulators
In C++, manipulators are special functions or objects that are used to modify the behavior of input and output streams. They allow you to change the formatting and presentation of data when it is sent to or read from streams, such as `std::cout` for [output](#output) and `std::cin` for [input](#input).
- Manipulators can change various aspects of stream formatting, such as precision, width, alignment, fill characters, etc.
- Manipulators can be chained together using the **insertion operator** (`<<`) for output streams or the **extraction operator** (`>>`) for input streams.
- Most manipulators are defined in the `<iomanip>` header, while some are defined in `<iostream>` and other headers.

### Some manipulators


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

## Object and Class

### General 

![OOP_1](media/oop_1.png "example of OOP based on real world")

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
Object is a collection of attributes and methods. **Attributes** are characteristics of an object, **methods** are functions that object can preform. **Object** is an instance of a data when **class** is the definition of an object.
- Objects can be created from a user-defined data type **class**, that acts like a blueprint for an object.
- **Class** [**encapsulates**](/General/Dictionaty.md) data (*attributes*) and functions (*methods*) that operate on that data into a single unit. 
- **Classes** are a fundamental part of *object-oriented programming* (**OOP**) in C++, allowing for the modeling of real-world entities and promoting code reusability, modularity, and [**abstraction**](/General/Dictionaty.md).
- **Access modifiers** are keywords used in object-oriented programming to set the accessibility or visibility of **classes**, **methods**, **Attributes** and other members. They control how and where these members can be accessed from other parts of the program. 
  - The main purpose of access modifiers is to implement **encapsulation**, which is a fundamental principle of object-oriented design.
  - **Attributes** and **methods** have ***access modifiers***:
      - `public`: can be accessed from anywhere.
      - `private`: can only be accessed within the class.
      - `protected`: can be accessed within the class and its derived classes.
    - **Access modifiers** are set for a class not an object (this protection is at the class level).
      - See example #3.
  - Related functions:
    - `getter` - function that makes a private attribute READABLE.
    - `setter` - function that makes a private attribute WRITABLE.
    - **getter**s and **setter**s are used due to that fact that it is a good practice to keep as many of the class **attributes** `private` as possible.

#### Methods
In C++, methods are functions that are associated with a class or an object. They define the behavior of the objects created from that class. 
#### Key Concepts of Methods in C++
- **Member Functions**: Methods are often referred to as member functions because they are defined within a class and can access the class's data members.
- **Access Specifiers**: Methods can have access specifiers that determine their visibility:
    - ***public***: Accessible from outside the class.
    - ***private***: Accessible only from within the class.
    - ***protected***: Accessible from within the class and by derived classes.
- **Method Types**:
    - ***Instance Methods***: These methods operate on instances of the class and can access instance variables.
    - ***Static Methods***: These methods belong to the class itself rather than any particular object. They cannot access instance variables directly but can access static variables.
- **Const Methods**: A method can be declared as `const`, indicating that it does not modify any member variables of the class.
- **Overloading**: C++ allows method overloading, which means you can have multiple methods with the same name but different parameter lists.
- Syntax of Methods:
    - Defining a Class with Methods: [Class examples](#class-examples):#4
    - Using Methods: [Class examples](#class-examples):#4
    - Method Overloading: [Class examples](#class-examples):#5

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
-  **#4**
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

### Constructor
It is a special method, that is automatically called when an object is instantiated (useful to assign values to attributes as arguments). 
- There is a **constructor** that is automatically called.  In C++ if you don't define any *constructor*, the compiler provides a default *constructor* that initializes the object with default values.
- **Constructor** can be manually set.
- A **constructor** is a member function with the same name as the class.
- If a constructor is set you can't just create new object simple way.
    ```C++
        Student s2;         // would not work
    ```

#### Examples
- ***#1***
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
- ***#2***
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
- If in the constructor declaration the names of variables are the same `this->` keyword is needed to address to attributes. Otherwise, you can just use attributes names.

### Destructor
In C++, a **destructor** is a special member function that is automatically called when an object goes out of scope or is explicitly deleted. The primary purpose of a destructor is to perform cleanup operations, such as releasing resources that the object may have acquired during its lifetime. This can include deallocating memory, closing file handles, or releasing network connections.
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

    return 0;
}
```


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

### Inheritance
Inheritance is a principle of *OOP* that allows a new class (subclass/derived class/**child class**) to inherit *attributes* and *methods* from an existing class (superclass/base class/**parent class**). 
- This method helps to reuse similar code found within multiple classes.

#### Inheritance types
Description will be based at:
```C++
class Shape{
    //...
};
class Circle : public Shape{
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
        public:
        void bark(){
            std::cout<<"Barking"<<std::endl;
        }
        void stayAtHome(){
            std::cout<<"Staying near house"<<std::endl;
        }
    };
    class Cat:public Animal{
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
        return 0;
    } 
    ```
- **#2**
Check [/C&C++/materials/CPP/example_1.cpp](/C&C++/materials/CPP/example_1.cpp)


### Interface
An **interface** is a contract or specification that defines a set of methods or behaviors that a class must implement. 
- **Interfaces** define a contract that classes must adhere to.
- Classes that implement an interface must provide concrete implementations for all of its methods. 
- The most common way to create interfaces in C++ is through [**abstract classes**](#abstract-classes). 
- **Interfaces'** main purposes are:
  - To achieve abstraction by defining a common interface for a group of unrelated classes;
  - To enable [polymorphism](/General/Dictionaty.md) and loose coupling between different parts of a program;
  - To define a contract or protocol that classes must follow.
- Its characteristics:
  - An interface typically contains only method signatures, without implementations;
  - It does not include data members or variables;
  - Methods in an interface are implicitly public and abstract;
  - Interfaces can have static and constant variables.
  

### Abstract Classes
**Abstract Classes** are classes that cannot be instantiated on their own and are meant to be subclassed. They can contain both abstract methods (which must be implemented by subclasses) and concrete methods (which have an implementation). But typically it contains at least one [pure virtual function](#pure-virtual-functions).  Using Abstract classes supports [polymorphism](/General/Dictionaty.md).
- Sometimes, it's useful to declare an interface without providing any implementation details. This can be achieved using forward declarations:
    ```C++
    class InterfaceForwardDeclaration;

    class ConcreteClass : public InterfaceForwardDeclaration {
        // Implementation
    };
    ```

| Feature| Interface (Pure Virtual Class)   | Abstract Class |
| ---|--- | ---|
| Description| In C++, an interface is typically defined using a class that contains only pure virtual functions (methods).  | An abstract class in C++ is a class that contains at least one virtual function. It can also contain concrete (non-pure) methods and member variables. |
|Instantiation| Cannot be instantiated | Cannot be instantiated |
| Method Implementation| Only pure virtual methods | Can have both pure virtual and concrete methods | 
| Member Variables | Cannot have member variables | Can have member variables |
| Constructors | No constructors | Can have constructors | 
| Use Case | Define a contract for unrelated classes | Provide a common base for related classes |
- In C++, interfaces are typically implemented using pure virtual classes, while abstract classes can contain both pure virtual and concrete methods.

### Abstract methods (**Virtual functions**)
An **abstract method** or a **virtual function** is a member function in a base class that you expect to override in derived classes. When you use a base class pointer or reference to call a **virtual function**, C++ determines which function to invoke at runtime based on the actual object type, not the type of the pointer/reference. **Interfaces** define a contract that children classes must adhere to.
-  An interface can only contain method signatures (no implementation) and constants. Classes that implement an interface must provide concrete implementations for all of its methods.
- Using **virtual function** allows for dynamic (or run-time) [***polymorphism***](/General/Dictionaty.md), enabling a program to decide at runtime which method to invoke based on the type of the object being referenced, rather than the type of the reference itself. 
- This allows you to treat objects of derived classes as objects of the base class. This is particularly useful in scenarios where you want to write code that can work with objects of different types through a common interface.
- To create a virtual function use keyword `virtual`.

#### Examples
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
    - **`override`** keyword is used to indicate that a function is intended to override a virtual function.
      - If function is `const`, `override` goes after the `const`.
    - **`final`** keyword can be used to prevent a function from being overridden in derived classes.
    - When a function is declared as virtual, C++ uses a mechanism called **dynamic binding** (or late binding) to resolve which function to call at runtime. This is typically implemented using a "vtable" (virtual table), which is a table of function pointers.
- **#2**
  Check [/C&C++/materials/CPP/example_1.cpp](/C&C++/materials/CPP/example_1.cpp)

#### Pure Virtual Functions
A **pure virtual function** is a virtual function that has no implementation in the base class and is declared by assigning 0 to it. This makes the class abstract, meaning you cannot instantiate it directly. Derived classes must provide an implementation for the **pure virtual function**.
```C++
class AbstractBase {
public:
    virtual void show() = 0; // Pure virtual function
};

class ConcreteDerived : public AbstractBase {
public:
    void show() override {
        std::cout << "ConcreteDerived class show function called." << std::endl;
    }
};
```

### Static [Properties](/General/Dictionaty.md)
Static member variables (**attributes**) belong to the class itself rather than to any specific object. They are shared among all instances of the class.
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

int Car::carCount = 0; // Initialize static member
int main(){
    Trucks BFT, SFT, AFT;
    std::cout << SFT.getCarCount() << std::endl; // Output: 3
}
```

### Templates
Templates are a way to write generic code that can work with different data types. They work with classes the same way they work with functions;

#### Example 
```C++
template <typename T>
class Stack {
    private:
        std::vector<T> elements;
    public:
        void push(T const& element);
        T pop();
};
```

## STL containers 
**Standard Template Library containers** are template classes provided by the C++ Standard Library that are used for storing and managing collections of objects. They offer convenient and efficient ways to work with data, including adding, removing, searching, and sorting elements.

### Main Categories of STL Containers  (❗***HINT***)
#### Sequence Containers
These containers store elements in a specific order. Elements can be accessed by index, and their order is preserved.
- Examples:
    - **`std::array`**: A fixed-size array that can be used when the size in set - ***array***.
    - **`std::vector`**: A dynamic array that can change its size. It provides fast access to elements by index (`#include <vector>`) - ***dynamic arrays***.
    - **`std::deque`**: A double-ended queue that allows adding and removing elements from both the front and the back - ***queue***.
    - **`std::list`**: A ***doubly linked list*** that allows efficient insertion and deletion of elements at any position in the list, but does not provide fast access by index.
  
#### Associative Containers
These containers store elements as pairs of "key-value". They provide fast access to elements by key.
- Examples:
    - **`std::set`**: A container that stores unique elements in a sorted order.
    - **`std::map`**: A container that stores pairs of "key-value", where keys are unique and sorted (`#include <map>`).
    - **`std::multiset`** and **`std::multimap`**: Similar to set and map, but allow duplicates.

#### Unordered Associative Containers
These containers do not store elements as "key-value" pairs and do not guarantee order.
- Examples:
    - **`std::unordered_set`**: A container that stores unique elements without guaranteeing order.
    - **`std::unordered_map`**: A container that stores "key-value" pairs without guaranteeing order.

### Examples of using STL Containers

#### `std::vector`
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

#### `std::map`
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

## STL algorithms 
Standard Template Library Algorithms are a collection of functions provided by the C++ Standard Library that operate on containers. These algorithms are designed to work with the various STL containers (like vector, list, set, map, etc.) and provide a wide range of functionalities, including searching, sorting, modifying, and manipulating data.

### Key Features of STL Algorithms
- **Generic Programming**: STL algorithms are designed to work with any container that supports the required operations, provide a uniform interface for accessing elements in different types of containers.
- **Efficiency**: Many STL algorithms are optimized for performance and can handle large datasets efficiently.
- **Flexibility**: Algorithms can be customized using function objects (functors) or lambda expressions, allowing for greater flexibility in how they operate on data.
- **Composability**: Algorithms can be combined to create complex operations by chaining them together.

### Common STL Algorithms
Here are some commonly used STL algorithms:
#### Sorting Algorithms:
- `std::sort`: Sorts the elements in a range.
- `std::stable_sort`: Sorts the elements while preserving the relative order of equivalent elements.
#### Searching Algorithms:
- `std::find`: Searches for a specific value in a range.
- `std::binary_search`: Checks if a value exists in a sorted range.
#### Modification Algorithms:
- `std::copy`: Copies elements from one range to another.
- `std::transform`: Applies a function to a range of elements and stores the result in another range.
#### Set Operations:
- `std::set_union`: Computes the union of two sorted ranges.
- `std::set_intersection`: Computes the intersection of two sorted ranges.
#### Numeric Algorithms:
- `std::accumulate`: Computes the sum of a range of elements.
- `std::inner_product`: Computes the inner product of two ranges.
#### Other Useful Algorithms:
- `std::for_each`: Applies a function to each element in a range.
- `std::reverse`: Reverses the order of elements in a range.

### Examples
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

## Multithreading   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
std::thread, std::async


## Links
[6 hours basic tutorial (EN)](https://youtu.be/-TkoO8Z07hI?si=vifWswvQmeKroSGu)
[Beginning of series of tutorial videos about basics of C++ (RU)](https://youtu.be/QYZbN2g-Dxc?si=AofHPo_lEbHv93qC)
[Beginning of series of tutorial videos about OOP with C++ (RU)](https://youtu.be/RKMyJKXXpKM?si=5yCHTqHpgMCdhmfm)
[C++ official documentation](https://cplusplus.com/)
