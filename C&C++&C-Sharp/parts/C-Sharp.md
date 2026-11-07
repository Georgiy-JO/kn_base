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
- Inheritance, namespaces inclusion, fields of a class/structure etc is accessed using `.` in **C#**, while in **C++** in some of those cases it would be `::`.
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

## Comments
- Works the same way as in C++: `/*...*/`, `//`.
- Writing `///` before class/method/etc. will automatically create it's description (may not work in some coding environments).

## Life-Hacks
### Determining types  
#### [`GetType()`](#gettype-1)
#### `is`
```c#
foreach (var animal in animals)
{
    if (animal is Wolf wolf)  // it is Wolf
    else if (animal is Rabbit rabbit) // it is Rabbit
}
```
#### `switch`
```c#
foreach (var entity in entities)
{
    switch (entity)
{
    case Animal animal:     
        _data.Animals.Add(animal);
        break;
    case Food food:
        _data.Food.Add(food);
        break;
    default: break;
}
}
```
- This doesn't change the original type of the entity, so if Animal is only one of parent types, object of the original child type will be added

#### Check the parent class
1. [Check out](#switch)
2. `IsAssignableFrom`:
  ```c#
  Dictionary <int, Type> dic;
  if (dic.TryGetValue(id, out Type? type) && typeof(Animal).IsAssignableFrom(type))
  ```

## Key-words and Operators
### Key-words 
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
#### [`public`, `private`, `protected`, `internal` ](#modifiers)
#### `yield`
Keywords used to create **iterators** (lazy sequences).  
Typically used in methods returning `IEnumerable<T>` or `IEnumerator<T>`.

- **`yield return <value>;`**
  - Returns one element to the caller.
  - Pauses the method and saves its state.
  - Continues execution from the same point when the next element is requested.

- **`yield break;`**
  - Stops the iteration immediately.
  - Equivalent to an early end of the sequence.
```C#
// Ex.
// Method:
  public IEnumerable<int> GetNumbers()
  {
      Console.WriteLine("Start");
      yield return 1;
      Console.WriteLine("After 1");
      yield return 2;
      Console.WriteLine("After 2");
      yield return 3;
      Console.WriteLine("End");
  }
// Calling:
  foreach (var n in GetNumbers())
  {
      Console.WriteLine($"Received: {n}");
  }
// output:
  // Start
  // Received: 1
  // After 1
  // Received: 2
  // After 2
  // Received: 3
  // End
```
- If added `yield break` before `yield return` the method will stop and if called one more time will restart.


#### Namespaces 
- Check out [using](#using)

### Operators
#### `??`
null-coalescing operator
- If the part on the left of `??` returns **NOT** `null`  the line returns the result.
- If it is `null` the part on the right is executed.
```C#
//ex.
 var data = JsonSerializer.Deserialize<Data>(json, options) ?? throw new InvalidDataException("Failed to deserialize data");
```

## Methods 
### `GetType`
Allows to check the type of an object.
```C#
var wolf = new Wolf(...);
Type type = wolf.GetType();

Console.WriteLine(type.Name);          // "Wolf"                  ← только имя класса
Console.WriteLine(type.FullName);      // "Wolf_Island.Entities.Animals.Wolf"  ← с namespace
Console.WriteLine(type.Namespace);     // "Wolf_Island.Entities.Animals"
Console.WriteLine(type.ToString());    // обычно то же, что FullName
```


## Classes

### Modifiers
#### Access Modifiers

| Modifier                  | Meaning                                                                 | Typical use |
|---------------------------|-------------------------------------------------------------------------|-----------|
| **`public`**              | Everyone can see and use the class (other projects too)                 | Classes you want to expose from a library |
| **`internal`**            | Only code in the **same assembly** (same project) can use it            | Default for top-level classes. Helper classes inside a project |
| **`private`**             | Only the containing class can see it                                    | Nested classes only (you almost never put `private` on a top-level class) |
| **`protected`**           | Only the class itself and **derived classes** can see it                | Mostly used on members, rarely on classes |
| **`protected internal`**  | `protected` **or** `internal` (derived classes + same assembly)         | Advanced |
| **`private protected`**   | `protected` **and** `internal` (derived classes **in the same assembly**)| Advanced (C# 7.2+) |

#### Other class Modifiers
| Modifier       | Meaning                                                                 | When to use |
|----------------|-------------------------------------------------------------------------|-----------|
| **`sealed`**   | The class **cannot be inherited**                                       | When you want to prevent others from creating child classes (common for security, performance, or design) |
| **`abstract`** | The class **cannot be instantiated**. It is meant only to be a base class | Base classes that are incomplete (e.g. `Animal`) |
| **`static`**   | The class **cannot be instantiated** and can contain only static members | Utility / helper classes (`Math`, `Console`, your own `GameConstants`) |
| **`partial`**  | The class can be split across multiple files                            | Large classes, designer-generated code |     
- [`record`](#configure-structures) can be used for classes too.

### Inheritance  
  (❗update)
### Constructors & Destructors
- Constructors can't reference (call) other constructors in the same class, but still can reference (call) parent class constructors using `base`.
- Destructors can't be called in usual C#, but are needed if you are working with unsafe methods or data structures.

#### Automatic constructors
The same way as[`record`](#configure-structures) in C#12+ (.NET 8+) we can make C# create the constructors automatically be defining parameters in the class declaration.
```C#
//Ex.
internal sealed class FoodDataShort(string id = "None", uint value = 0, uint changeTimer = 4) : IConfig
{
    public string Id { get; init; } = id;
    public uint Value { get; init; } = value;
    public uint ChangeTimer { get; init; } = changeTimer;
}

// Will be possible to use :
var food = new FoodDataShort();                          // Id = "None", Value = 0, ChangeTimer = 4
var food2 = new FoodDataShort("Grass");                  // Id = "Grass", Value = 0, ChangeTimer = 4
var food3 = new FoodDataShort("Grass", 10);              // Id = "Grass", Value = 10, ChangeTimer = 4
var food4 = new FoodDataShort("Grass", 10, 6);           // Id = "Grass", Value = 10, ChangeTimer = 6
```

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

## Scenarios 
### Reading data from JSON
Check out [file](/C&C++&C-Sharp/materials/C-Sharp/JsonParser.cs):
- `LoadListFromFile` - reads file into text;
- `LoadListFromJsonText` - parse (deserialize) text according to the structure (`TList` should be a list of object that have the same structure as the json-file).


## Temple Notes (❗update)
### 1
StringComparer.OrdinalIgnoreCase нужен, чтобы ключи словаря не зависели от регистра букв

Сравниватель,"""Wolf"" == ""wolf""","""Wolf"" == ""WOLF""",Скорость,Рекомендуется для
StringComparer.Ordinal,Нет,Нет,Самая высокая,Когда регистр важен
StringComparer.OrdinalIgnoreCase,Да,Да,Очень высокая,"Ключи, ID, имена"
StringComparer.CurrentCultureIgnoreCase,Да,Да,Медленнее,"Для текста, который видит пользователь"
### 2
```c#
return id.ToLowerInvariant() switch
        {
            "wolf"   => new Wolf(data, position),
            "rabbit" => new Rabbit(data, position),
            // просто добавляешь новую строку, когда появится новый тип
            _ => throw new NotSupportedException($"Unknown animal type: {id}")
        };
```
### 3
...CreateInstance(...)!
Activator.CreateInstance может теоретически вернуть null.

Оператор ! говорит компилятору:«Я уверен, что здесь не будет null, не ругайся».Это нужно, потому что метод CreateAnimal возвращает Animal (не Animal?).




## Links