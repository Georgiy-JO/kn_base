# Python 

## Contents




## Other info
### [Interpreter](General_info.md#interpreter)
### [Code style](General_info.md#code-style)

## Variables

### Types
Python is [dynamically typed language](/General/Dictionaty.md#dynamically-typed-languages).

***Example***:
```python
a=7
print(type(a))      # <class 'int'>
a=4.5
print(type(a))      # <class 'float'>
a="Hello"
print(type(a))      # <class 'str'>
```
- ```type(...)``` allows to get the type of the variable.

#### Type casting
```python
a = 5.8     #5.8    --> float
b = int(a)  #5      --> int
#*

a = "5"     #"5"    --> str
b = int(a)  #5      --> int
# but
a = "5.5"   #"5.5"  --> str
b = int(a)  #error
b=float(a)  #5.5    --> float
#*
```
- Can truncate numbers.
- Can cast numbers from strings, but only if the format is correct (for int there must be only digits).


### References
- Any variable is a reference to the data.
    ```python
    a=5
    b=a         # reference the same object (does not copy data into new one)
    ``` 
- Every object has an ID:
    ```python
    a=5
    b=a
    print (id(a), id(b))  # will get two identical numbers
    ```

#### Multiple assignment     
Other names: **unpacking assignment**, **simultaneous assignment**, **tuple unpacking**, **множественное присваивание**.

***Example***:
```python
# "multiple assignment"
a, b = 10, 20
print(a, b)         # 10 20

a, b = b, a
print(a, b)          # 20 10

# "tuple unpacking"
x, y, z = (1, 2, 3)
print(x, y, z)      # 1 2 3

# "unpacking assignment" (официальный термин в документации)
first, *middle, last = [10, 20, 30, 40, 50]
print(first, middle, last)          # 10 [20, 30, 40] 50 
```

## Input && Output 

### Output
#### Print parameters
```python
a=5
b=6.5
print(a,b)              # 5 6.5
print(a,b, sep=" | ")   # 5 | 6.5
#* 

print("Hello")
print("world")
# Hello
# world
print("Hello", end=" ")
print("world")
# Hello world
#*
```
- ```sep``` - sets the separator between arguments (default is space).
- ```end``` - sets parameter to the end on print (default is new line ('\n')).

#### Print formatting (f-strings)
```python
x=5.5
y=-25
# Old style
print("Point coordinates: x = ", x, "; y = ", y)          # Point coordinates: x =  5.5; y =  -25
print("Point coordinates: x = ", x, "; y = ", y, seg="")  # Point coordinates: x = 5.5; y = -25
# F - string style (python 3.6+)
print(f"Point coordinates: x = {x}; y = {y}")           # Point coordinates: x = 5.5; y = -25
```

### Input
```input()``` allows reading data from standard input stream (console by default).
- Returning data is a **string** by default. This can be changed by [type casting](#type-casting).
    ```python
    a = input()         # writing: -12345
    print(type(a))      # <class 'str'>
    b = abs(a)          #error

    a = int(input())    # writing: -12345
    print(type(a))      # <class 'int'>
    b = abs(a)          #12345

    a = int(input())    # writing: -123.45  --> error
    a = float(input())  # writing: -123.45  --> a = -123.45     --  float
    ```

***Example***:
```python
a = float(input())
b = float(input())
print("Perimeter =", 2 * (a + b))
# console:
# 5.5 44 
# !ERROR!

# console:
# 5.5
# 44
# Perimeter = 99.0

a = float(input("Enter a: "))
b = float(input("Enter b: "))
print("Perimeter =", 2 * (a + b))
# console:
# Enter a: 5.5
# Enter b: 44
# Perimeter = 99.0

a, b = map(float, input("Enter a and b: ").split())
print("Perimeter =", 2 * (a + b))
# console:
# Enter a and b: 5.5 44
# Perimeter = 99.0
```



## Math
### Simple Calculus
```python
a = 2 + 3       #5      --> int
a = 2 + 3.0     #5.0    --> float
a = 2 + 3.5     #5.5    --> float
a = 5 * 6       #30     --> int
a = 6 * 2.5     #15.0   --> float
a = 8 / 2       #4.0    --> float
a = 3 / 6       #0.5    --> float

a = 8 // 2      #4      --> int
a = 7 // 2      #3      --> int     --> floor division
a = -7 // 2     #-4     --> int     --> floor division

a = 7 % 2       #1      --> int
a = 9 % 5       #4      --> int
a = -9 % 5      #1      --> int     --> remainder from negative number rule
a = 9 % -5      #-1     --> int     --> remainder from dividing by negative number rule
a = -9 % -5     #-4     --> int     --> remainder from dividing negative number by negative number rule

a = 2 ** 0      #1      --> int
a = 2 ** 3      #8      --> int
a = 25 ** 0.5   #5.0    --> float
a = 3 ** 3 ** 2 #19683  --> int     --> the only operation that goes from right to left

a = 27 ** 1/3   #9.0    --> float   --> operation priority
a = 27 ** (1/3) #3.0    --> float
a = 2 + 3 * 5   #17     --> int
a = 32 / 4 * 2  #16.0   --> float

a = 5           #5
a += 1          #6
a -= 2          #4
a *= 3          #12
a /= 2          #6.0
```

### Math functions
### Basic math functions
Are included by default:
```python
abs(-5)                     #5
abs(5)                      #5
abs(-5.6)                   #5.6

min(1, 2, 3)                #1
min(-55.5, -4, 0, -25, 100) #-55.5
min(5)                      #error


max(1, 2, 3)                #3
max(-55.5, -4, 0, -25, 100) #100
max(5)                      #error

pow(6,2)                    #36
pow(27, 1/3)                #3.0

round(0.3)                  #0
round(0.7)                  #1
round(0.5)                  #0
round(1.5)                  #2
round(10.5)                 #10
round(10.5000000001)        #11
round(11.5)                 #12
#*

round(7.8766, 2)            #7.88
round(7.8766, 3)            #7.877
round(7.8766, 4)            #7.8766
round(7.8766, 5)            #7.8766
round(7.8766, -1)           #10.0
round(787.66, -2)           #800.0
round(787.66, -1)           #790.0
```
- Python uses banker's rounding (round half to even).

#### Math module functions
Functions imported by "math" module:
```python
import math

math.ceil(5.2)              #6
math.ceil(5.8)              #6
math.ceil(-5.2)             #-5

math.floor(5.2)             #5
math.floor(5.8)             #5
math.floor(-5.2)            #-6

math.trunc(5.2)             #5
math.trunc(5.8)             #5
math.trunc(-5.2)            #-5
#*

math.factorial(5)            #120
math.factorial(0)            #1
math.factorial(1)            #1
math.factorial(-1)           #error

math.log2(8)                 #3.0
math.log10(100)              #2.0
math.log(2.7)                #0.9932517730102834 --> natural logarithm 
math.log(27, 3)              #3.0
math.log(8, 2)               #3.0
math.log(100, 10)            #2.0

math.sqrt(9)                 #3.0

math.sin(0)                  #0.0
math.sin(math.pi/2)          #1.0
math.sin(3.14/2)             #0.9999996829318346
etc.

a = math.pi                  #3.141592653589793
b = math.e                   #2.718281828459045
```
- [Type casting](#type-casting) works the same way and is used way more often.



