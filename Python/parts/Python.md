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
- **To numbers**:
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

- **To strings**:
    ```python
    a = 5
    b = "Answer = "
    c = b + str(a)  #Answer = 5
    c = str(55.5)   #"55.5"
    c = str(True)   #"True"
    ```

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

    a=55    
    b=a 
    print(a)        # 55
    print(b)        # 55
    print(id(a))    # 11757416       
    print(id(b))    # 11757416    

    a-=5
    print(a)        # 50
    print(b)        # 55
    print(id(a))    # 11757256
    print(id(b))    # 11757416
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

## General
### Comparison
```python
a = 5

print(a <= 10 and a > 0)                #True
print(a <= 10 or a < 0)                 #True
print(0 < a <= 10)                      #True
print(a % 3 == 0 or a % 2 == 0)         #False
print(a % 3 != 0 or a % 2 != 0)         #True
print(not (a % 3 == 0 or a % 2 == 0))   #True
```
- Instead of *&&* and *||* are used *and* and *or*.
- Operator's priority:
    |Operator| Priority|
    |---|---|
    |or|1|
    |and|2|
    |not|3|
  - The Highest priority goes first.

### Service functions
#### bool()
```python
bool(1)         #True
bool(0)         #False
bool(-1)        #True
bool(10)        #True
bool(0.0)       #False
bool(0.1)       #True
bool("")        #False
bool(" ")       #True
bool("Hello")   #True
```

## Strings
Unchangeable type.
### General
Operators: **+**, **\***.
```python
s1 = "Line"
s2 = 'Line too'

text1 = ''' Many line text is
a text with many lines
because text is longer with longer
lines.'''                               # /n at the ends of the lines are included

s3 = s1 + ' ' + s2                       # Line Line too
s4 = s1 + 5                              # error
s4 = s1 + str(5)                         # Line5
#*

s5 = s1 * 5                             # LineLineLineLineLine
s5 = s1 * 5.5                           # error

st = "path\to\my\file.txt"
print(st)            # path    o\my            ile.txt
st = "path\\to\\my\\file.txt"
print(st)          # path\to\my\file.txt
st = r"path\\to\\my\\file.txt"
print(st)         # path\\to\\my\\file.txt
st = r"path\to\my\file.txt"
print(st)         # path\to\my\file.txt
#*
```
- Use [type casting](#type-casting) to transform any data into string
- ```r``` before string making that string raw (aka special symbols will not be interpreted).

### Indexing
Operator **[]**.
```python
s1 = "Line"
s1[0]                           # L
s1[1]                           # i
s1[4]                           # error
s1[-1]                          # e
s1[-2]                          # n
s1[-6]                          # error
#*
"My Line"[3]                    # L
s1[1:3]                         # in
s1[1:]                          # ine
s1[:3]                          # Lin
s1[:]                           # Line  
s1[1:-2]                        # in
s1[-2:1]                        # ''    #empty string
#*

s2 = "I love python"
s2[2:-3:2]                      # 'lv y'
s2[2::3]                        # 'leyo'
s2[2::2]                        # 'lv yhn'
s2[::4]                         # 'Ivyn'
s2[::-1]                        # 'nohtyp evol I'
s2[-2:-7:-1]                    # 'ohtyp'
s2[-7:-2:-1]                    # ''
s2[::-3]                        # 'nt oI'

s1[0] = 'H'                     # error
s6 = 'l' + s1[1:]               # line
#*
```
- Negative indexes allow counting elements from the end of the string.
- Taking a segment of a string:
  -  ```s[n:m]``` works like **[n, m)** (*m* is not included);
  -  if the edges of the segment are not set, they are set automatically as string edges.
- Strings are **unchangeable** data type (aka. you can only create a new string, not change the old one).


#### Comparison
Operators: **==**, **!=**, **>**, **>=**, **<**, **<=**.
```python
print(s1 == 'Line')                     #True
print(s1 == 'line')                     #False
print(s1 != 'Line ')                    #True

print("abc" < "abd")                    #True
print("abc" > "abd")                    #False
print("abc" > "abc")                    #False
print("abc" >= "abc")                   #True
print("abc" > "Abc")                    #True
#*
```
- `>` and `<` use lexicographic (лексикографическое) comparison - compare each latter, the one earlier in the alphabet (ASCII) is smaller.


### Service functions, operators, methods
#### str()
Check out [type casting](#type-casting).

#### len()
Calculate length of the string.
```python
len('hello')        #5
len('')             #0
```

#### in
Check if one string is in another (operator).
```python
print('lab' in 'matlabkomabsamabtolib')     #True
print('aaa' in 'matlabkomabsamabtolib')     #False
print('lab' not in 'matlabkomabsamabtolib') #False
print('aaa' not in 'matlabkomabsamabtolib') #True
```

#### ord()
Returns a number representing the decimal Unicode code (ASCII code) of a specified character.
```python
print(ord('A'))     #65
```

#### upper() and lower()
```python
s = 'python'
print(s.upper())    #PYTHON
print(s)            #python
print(s.upper)      #<built-in method upper of str object at 0x7f51b6bac0f0>
s = 'PYTHON'
print(s.lower())    #python
```

#### count(), find(), rfind() and index()
- **count()** - counting amount of substrings in string.
- **find()** - finding the substring in string (if there is none, return ```-1```).
- **rfind()** - same as **find()**, but goes from the end of the string.
- **index()** - same as **find()**, but if there is no substrings found returns ```ValueError```.

```python
s = "I love python! Python that is a programming language. Snake python is nice too though."

print(s.count('python'))            # 2
print(s.count('Python'))            # 1
print(s.count('python',2))          # 2
print(s.count('python',2,14))       # 1
print(s.count('python',2,13))       # 1
print(s.count('python',2,12))       # 0
print(s.count('python',2,100))      # 2

print(s.find('Python'))             # 15
print(s.find('python'))             # 7
print(s.find('python',0,4))         # -1
print(s.find('python',14))          # 60
print(s.find('python',14,1004))     # 60
print(s.find('python',14,65))       # -1
print(s.find('python',14,66))       # 60
print(s.find('pithon'))             # -1

print(s.rfind('Python'))            # 15
print(s.rfind('python'))            # 60
print(s.rfind('python',0,4))        # -1
print(s.rfind('python',0,15))       # 7
print(s.rfind('python',14))         # 60
print(s.rfind('python',14,1004))    # 60
print(s.rfind('python',14,65))      # -1
print(s.rfind('python',14,66))      # 60

print(s.index('python'))            # 7
print(s.index('pithon'))            # ValueError: substring not found
```

#### replace()
Replacing substrings.
- Can the amount of replacements be set (```-1``` - unlimited).
```python
s = "Banana Republic"

print(s.replace('a','o'))       # Bonono Republic
print(s)                        # Banana Republic    
print(s.replace('a','o',1))     # Bonana Republic
print(s.replace('a','o',2))     # Bonona Republic
print(s.replace('a','o',3))     # Bonono Republic
print(s.replace('a','o',-1))    # Bonono Republic
print(s.replace('A','o'))       # Banana Republic
print(s.replace('A',''))        # Banana Republic
```

#### isalpha(), isdigit(), isalnum()
```python
s = "Banana"
print(s.isalpha())      # True
print(s.isdigit())      # False
print(s.isalnum())      # True
s = "Banana or not"
print(s.isalpha())      # False
s = '123'
print(s.isalpha())      # False
print(s.isdigit())      # True
print(s.isalnum())      # True
s = '123.5'
print(s.isdigit())      # False
print(s.isalnum())      # False
s = '-123'
print(s.isdigit())      # False
print(s.isalnum())      # False
s = '123 '
print(s.isdigit())      # False
print(s.isalnum())      # False
s = '123a'
print(s.isdigit())      # False
print(s.isalnum())      # True
```
#### rjust(), ljust(), center()
- **rjust()** - add symbols (default:" ") to the beginning of the string, so it will have the set length.
- **ljust()** - add symbols (default:" ") to the end of the string, so it will have the set length.
- **center()** - add symbols (default:" ") to the beginning and end of the string, so it will have the set length.
```python
s1 = "Banana"     
s2 = '123'
print(s1.rjust(2))          # Banana
print(s1.rjust(10))         #     Banana
print(s2.rjust(5, '0'))     # 00123
print(s2.rjust(5, '00'))    # ERROR

print(s1.ljust(10,'*'))     # Banana****

print(s1.center(10,'&'))    # &&Banana&&
print(s1.center(11,'&'))    # &&&Banana&&
```

#### split() and join()
- **split()** - sprits the string into substrings according to separator (default:" ").
- **join()** - join strings putting separator between them.
```python
s = "He stand up to the crowed, walked to the door, get to the street and drove to his work."

print(s.split(','))
# ['He stand up to the crowed', ' walked to the door', ' get to the street and drove to his work.']
print(s.split('to'))
# ['He stand up ', ' the crowed, walked ', ' the door, get ', ' the street and drove ', ' his work.']

s = "1,  2,3,4   ,5, 6, 7,   8,    9"
d = s.replace(" ","").split(',')
print(d)
# ['1', '2', '3', '4', '5', '6', '7', '8', '9']

print(", ".join(d))             # 1, 2, 3, 4, 5, 6, 7, 8, 9
print("".join(d))               # 123456789

s = "John Johnson Riverside"
print(", ".join(s.split()))     # John, Johnson, Riverside
```

#### strip() and rstrip() and lstrip()
Removes spaces, new lines, tabs etc for strings.
- **strip()** - both sides.
- **rstrip()** - right side.
- **lstrip()** - left side.
```python
s = "\t      \n\n\t\t ME \t\t\n\n      \n\n"

s.strip()           # ME
s.rstrip()          # \t      \n\n\t\t ME
s.lstrip()          # ME \t\t\n\n      \n\n
```

### Forenamed strings 
#### format()
```python
st = "Uncle {0} is {1} years old. {0} lives in {2}."
a = "Ben"
b = 55
c = "Japan"
print(st.format(a,b,c))
# Uncle Ben is 55 years old. Ben lives in Japan.


sg = "Mayor {Name} is {Age} years old. {Name} Works in {job}."
a = "Samantha"
b = 35
c = "SG"
print(sg.format(Name=a,Age=b,job=c))
# Mayor Samantha is 35 years old. Samantha Works in SG.
```

#### f-strings
- Works with Python 3.6+.
- Read more at [PEP 498](https://peps.python.org/pep-0498/)
```python
name = "Samantha"
age = 5
job = "sg"
sg = f"Mayor {name} is {age*7} years old. {name} Works in {job.upper()}."
print(sg)
# Mayor Samantha is 35 years old. Samantha Works in SG.
```