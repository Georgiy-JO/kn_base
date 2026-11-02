# C#
- Created in year 2000.
- Highly [Object-oriented programming](/General/Dictionaty.md#object-oriented-programming) (OOP) language.
- Evolution of C.
  - Plenty of C elements, functions, etc. works here...
  - In some cases works similar to C++, in other differ from it...

#### This document notes 
- More documentation and info can be found at websites in [links](#links)
- ❗ This document contains knowledge and notes about **C#** that are highly based on [C++ doc](/C&C++&C-Sharp/parts/C++.md), please consider reading it before moving forward.
- ❗ This document is work in progress - some definitions and info might be old, not complete or not professionally written.
- ❗ (❗update) -  used for places that need to be updated.

## Contents
(❗update)

## C# vs. C++
- Inheritance, namespaces inclusion, fields of a class/structure etc is accessed using `.` in **C#**, while in **C++** in some of those cases it would be `:;`.
  - ex.
    ```C++
    // C++
    math::abs(-5);
    ```
    ```C#
    // C#
    Math.Abs(-5);
    ```

## Code Style (❗update)


## Classes

### Inheritance  
  (❗update)
### Constructors & Destructors
- Constructors can't reference (call) other constructors in the same class, but still can reference (call) parent class constructors using `base`.
- Destructors can't be called in usual C#, but are needed if you are working with unsafe methods or data structures.

## Structures
- Usually is used for storing and passing data, but has almost the same functionality as classes.
- Can't be interfaces.
### Configure structures
- That is a normal practice for C++ and C# to create a special structure to pass values to a constructor if there are a lot of parameters.
- There is a special key words `record` to do it. It creates a structure with given fields and even given default parameters.
  - Each field will work identical to:
    ```C#
    public <Type> <Name>
    {
        get;
        set;
    }
    ```
**Ex**:
```C#
record struct AnimalData(uint MaxHealth = 1, uint MaxFullness = 1, uint MeatValue = 1, uint FieldOfView = 1, Sizes Size = Sizes.szMedium, uint HungerTimer = 2, uint LifelossTimer = 2, uint MoveDistance = 1) : IConfig;
```

### Key words
#### `Using`
- Used to include libraries, namespaces, types. (❗update)
|Feature|using Namespace;|using static Type;|
|---|---|---|
|What it imports|"Types (classes, structs, enums…)"|Static members of one type|
|Example|`using System.Linq;`|`using static System.Math;`|
|Allows|`List<T>`, `Dictionary<K,V>`|`Sqrt()`, `PI`, `Max()`|
|Does not allow|Calling static methods directly|Using the type name itself without qualification|

#### [`record`](#configure-structures)
#### [`base`](#constructors--destructors)

### Namespaces 
- Check out [using](#using)



## Links