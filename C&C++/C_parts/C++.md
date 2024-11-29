# C++
- Created in year 1985.
- Developed by Bjarne Stroustrup.
- Object-oriented programming (OOP) language.
- Evolution of C.

## Libraries 

| C++         | Description    |
| ----------- | -------------- |
| \<iostream> | input/output   |
| \<cmath>    | math functions |
| \<ctime>    | time related functions  |
| \<iomanip>  | facilities for manipulating the input and output format of streams |
<!-- | \<algorithm>| algorithms     | -->
<!-- | \<vector>   | dynamic array  | -->
<!-- | \<string>   | string        | -->


## Code situations and examples

### Tips
- Assigning double value to an int variable truncates it
    ```C++
    int a = 3.7; // a is 3
    int a = 5.5; // a is 5
    int a = -5.5; // a is 5
    ```
- `bool` datatype exists by default (can be `true` or `false`).
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



### Input

#### Standard input
Each read works until *new line break* or *space* etc.
```C++
std::string name;
int age;
std::cin >> name;
std::cin >> age;
//or 
std::cin >> name >> age;
```

#### Getline
Reads until *new line break*.
```C++
std::string full_name;
std::getline(std::cin, name);
```

####  ❗***HINT***
If we use `getline` after `cin` we could read `\n` instead of the line we want to, this happens because *new line break*is still in the buffer. This can be avoided several ways, for example:
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
- `cout` - **c**haracter **out**put.
- `endl` - does the same thing as `\n`, furthermore flashes the output buffer, but `\n` if better in the terms of performance. 

#### Precision output
* requires \<iomanip>
```C++
double balance = 123.45;
std::cout << "You have: " << std::setprecision(8) << std::fixed << balance << std::endl;
```
- `std::setprecision(8)` - sets the decimal precision of floating-point numbers to 8 digits (sets for decimal part), will round numbers mathematically if needed.
- `std::fixed` - sets the floating-point format to fixed-point notation (will add zeros at the end of the decimal part if needed for the set precision).
- `std::setw(12)` - set the whole length of the output, will not cut output if it is longer, but will add spaces in front if it is shorter.
    

### Strings
String is an object that represents a sequence of text. Strings are provided from the standard namespace. String is a reference datatype (it actually stores a pointer to the place where the data is located).
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
    ```
* There are [methods](#string-methods) to make work with strings simpler.
* Strings can be easily replaced/swapped/etc:
    ```C++
    std::string name1 = "Jack";
    std::string name2 = "ONeill";
    std::string tmp;
    tmp = name1;
    name1 = name2;
    name2 = tmp;
    ```



### Namespaces
Namespace is a declarative region that provides a scope to the identifiers (such as variables, functions, classes, etc.) inside it. Namespaces are used to organize code and prevent name conflicts, especially in large projects or when using libraries that may have overlapping names.

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

####  ❗***HINT***
`using namespace` allows cutting down some repetitions. But the standard namespace is so huge so using it straight would cause too much intersection. 
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

### Typedef
`typedef` is a keyword in C++ that allows you to give a new name or alias to an existing type. This can make your code more readable and easier to understand.
* Usually the new datatype has **_t** at the end of the name.
* New datatype can be used the same way as old datatype, and old datatype can be used at the same time as new datatype.

####  ❗***HINT***
`typedef` is usually replaced by `usung` (using works better with templates).

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

#### Syntax
```C++
for( <datatype> <name_single_element> : <anme_of_dataset>){...}
```

#### Examples
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

#### Passing to function (❗***HINT***)
Example:
```C++
void swap (int x, int y){
    int temp = x;
    x = y;
    y = temp;
}
void swap2 (int &x, int &y){
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
    swap3(&x,&y);               //pass addresses and work with addresses
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

#### Example
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
- `auto` make the compiler deduce that the result type should be.

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
* The compiler will choose the correct function based on the parameters passed.
* Function's **signature** (name + parameters list) MUST be unique.

```C++
int summ(int x, int y) { return x+y; }
double summ(double x, double y) { return x+y; }
int summ(double x, double y) { return x+y; }
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

## Methods
In C++, methods are functions that are associated with a class or an object. They define the behavior of the objects created from that class. 

### Theory
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

#### Syntax of Methods
**Example 1:**
*Defining a Class with Methods:*
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
```

*Using Methods:*
```C++
int main() {
    MyClass obj(10); // Create an object of MyClass
    obj.display();   // Call the instance method

    MyClass::staticMethod(); // Call the static method

    obj.constMethod(); // Call the const method

    return 0;
}
```

**Example 2**
*Example of Method Overloading:*
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

### Build in methods
#### String methods
Include:
- length
- emptiness 
- clean
- append
- get a char
- insert string
- find char
- erase part
- [etc](https://cplusplus.com/reference/string/string/)

**String length**
```C++
std::string full_name;
std::getline(std::cin, name);
int length = full_name.length();
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


## Object and Class

### General 
#### Class
- A class is a blueprint or template for creating objects;
- It defines the structure and behavior of objects;
- It contains data members (variables) and member functions;
- Classes are abstract concepts, not physical entities;
- They are defined using the `class` keyword;
- No memory is allocated when a class is defined.
- 
#### Object
- An object is an instance of a class;
- It represents a concrete entity with specific values for data members;
- Objects contain actual data stored in memory;
- They are created from classes using [constructors](#constructor);
- Objects are physical entities that exist at runtime;
- Memory is allocated when an object is created.

#### Summary
Object is a collection of attributes and methods. **Attributes** are characteristics of an object, **methods** are functions that object can preform. **Object** is an instance of a data when **class** is the definition of an object.
- Objects can be created from a user-defined data type **class**, that acts like a blueprint for an object.
- **Class** encapsulates data (*attributes*) and functions (*methods*) that operate on that data into a single unit. 
- **Classes** are a fundamental part of *object-oriented programming* (**OOP**) in C++, allowing for the modeling of real-world entities and promoting code reusability, modularity, and abstraction.
- [General example](#general)

#### Example
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


### Abstraction+
- **Encapsulation** is one of the fundamental principles of object-oriented programming (OOP). It refers to the bundling of data (attributes) and methods (functions or procedures) that operate on that data into a single unit, known as a class. More importantly, encapsulation restricts direct access to some of an object's components, which is a means of preventing unintended interference and misuse of the object's internal state.
- **Abstraction** is one of the fundamental principles of object-oriented programming (OOP) that focuses on simplifying complex systems by modeling classes based on the essential properties and behaviors an object should have while hiding the unnecessary details. 
  - Simple speaking it means *hiding unnecessary data from outside a class*
  - Abstraction is achieved by using **access modifiers**.
- **Access modifiers** are keywords used in object-oriented programming to set the accessibility or visibility of **classes**, **methods**, **Attributes** and other members. They control how and where these members can be accessed from other parts of the program. 
  - The main purpose of access modifiers is to implement **encapsulation**, which is a fundamental principle of object-oriented design.
  - **Attributes** and **methods** have ***access modifiers***:
      - `public`: can be accessed from anywhere.
      - `private`: can only be accessed within the class.
      - `protected`: can be accessed within the class and its derived classes.
- Related functions:
  - `getter` - function that makes a private attribute READABLE.
  - `setter` - function that makes a private attribute WRITABLE.

| Aspect | Encapsulation | Abstraction | 
|----------------------|---------------------------------------------------|--------------------------------------------------| 
| **Definition** | Encapsulation is the bundling of data (attributes) and methods (functions) that operate on that data into a single unit, typically a class. It restricts direct access to some of an object's components, which is a means of preventing unintended interference and misuse of the object's internal state. |Abstraction is the process of simplifying complex systems by modeling classes based on the essential properties and behaviors an object should have while hiding the unnecessary details. It focuses on what an object does rather than how it does it.|
| **Purpose** | To protect the internal state of an object and control access to it. | To simplify complex systems by exposing only essential features. | 
| **Focus** | Focuses on data hiding and restricting access to the internal state. | Focuses on exposing only relevant attributes and behaviors. |
| **Implementation** | Achieved using access modifiers (e.g., private, public) and getter/setter methods. | Achieved using abstract classes and interfaces. | 
| **Example** | A class with private variables and public methods to access them. | An interface defining a contract that various classes must implement. | 
| **Real-World Analogy** | A pill capsule that protects the medicine inside from external factors. | A TV remote that allows you to control the TV without needing to know how it works internally. |

#### Example
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
### Inheritance
Inheritance is a principle of *OOP* that allows a new class (subclass/derived class/**child class**) to inherit *attributes* and *methods* from an existing class (superclass/base class/**parent class**). 
- This method helps to reuse similar code found within multiple classes.

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
Check [/C&C++/materials/example_1.cpp](/C&C++/materials/example_1.cpp)


## Links
[6 hours basic tutorial (EN)](https://youtu.be/-TkoO8Z07hI?si=vifWswvQmeKroSGu)
[Beginning of series of tutorial videos (RU)](https://youtu.be/RKMyJKXXpKM?si=5yCHTqHpgMCdhmfm)
