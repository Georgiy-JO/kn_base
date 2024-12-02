# Dictionary of some sort

## Abstraction
**Abstraction** is one of the fundamental principles of object-oriented programming (OOP) that focuses on simplifying complex systems by modeling classes based on the essential properties and behaviors an object should have while hiding (ignoring) the unnecessary details. For example classes are hiding complexity of their implementation and provide a simple interface for interaction.


### C++ Example
In C++, abstraction is achieved through various mechanisms, such as:

- **Classes and Objects**: Classes allow the creation of abstractions that serve as templates for objects. A class defines the properties (attributes) and behaviors (methods) of the objects that will be created from it.
    ```C++
    class Animal {
    public:
        virtual void makeSound() = 0; // Pure virtual function
    };
    ```
- **Interfaces**: In C++, interfaces can be implemented using abstract classes that contain pure virtual functions. This allows for the creation of different implementations of the same interface.
    ```C++
    class Dog : public Animal {
    public:
        void makeSound() override {
            std::cout << "Woof!" << std::endl;
        }
    };
    ```
- '**Modules and Namespaces**': Abstraction can also be achieved through modules and namespaces, which help organize code and hide implementation details.

## Encapsulation
- **Encapsulation** is one of the fundamental principles of object-oriented programming (OOP). It refers to the bundling of data (attributes) and methods (functions or procedures) that operate on that data into a single unit, known as a class. More importantly, encapsulation restricts direct access to some of an object's components, which is a means of preventing unintended interference and misuse of the object's internal state.

### Encapsulation vs Abstraction
| Aspect | **Encapsulation** | **Abstraction** | 
|----------------------|---------------------------------------------------|--------------------------------------------------| 
| **Definition** | Encapsulation is the bundling of data (attributes) and methods (functions) that operate on that data into a single unit, typically a class. It restricts direct access to some of an object's components, which is a means of preventing unintended interference and misuse of the object's internal state. |Abstraction is the process of simplifying complex systems by modeling classes based on the essential properties and behaviors an object should have while hiding the unnecessary details. It focuses on what an object does rather than how it does it.|
| **Purpose** | To protect the internal state of an object and control access to it. | To simplify complex systems by exposing only essential features. | 
| **Focus** | Focuses on data hiding and restricting access to the internal state. | Focuses on exposing only relevant attributes and behaviors. |
| **Implementation** | Achieved using access modifiers (e.g., private, public) and getter/setter methods. | Achieved using abstract classes and interfaces. | 
| **Example** | A class with private variables and public methods to access them. | An interface defining a contract that various classes must implement. | 
| **Real-World Analogy** | A pill capsule that protects the medicine inside from external factors. | A TV remote that allows you to control the TV without needing to know how it works internally. |


## Layers
**Layers** in programming refer to an architectural approach that divides a system into several levels or layers, each responsible for specific aspects of functionality. This improves modularity, testability, and maintainability of the code. In C++, layers can be implemented as follows:

- **Architectural Layers**: Software can be organized into layers, such as:
  - **Presentation Layer**: Responsible for user interaction;
  - **Application Logic Layer**: Contains business logic;
  - **Data Access Layer**: Manages interaction with databases or other data sources.
- **Modularity**: Each layer can be implemented as a separate module or library, allowing for independent development and testing.
- **Encapsulation**: Each layer can hide its internal details from other layers, providing only the necessary interfaces for interaction.
  
### C++ Example
Let’s consider a simple example where we use abstraction and layers to create an application that manages animals:
```C++
// Abstraction
class Animal {
public:
    virtual void makeSound() = 0; // Pure virtual function
};

// Implementation
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

// Application (Application Logic)
void makeAnimalSound(Animal* animal) {
    animal->makeSound();
}

int main() {
    Dog dog;
    Cat cat;

    makeAnimalSound(&dog); // Output: Woof!
    makeAnimalSound(&cat); // Output: Meow!

    return 0;
}
```

## Properties
**Properties** are often used to refer to a higher-level abstraction that encapsulates the attributes of a class. They can be thought of as a combination of attributes and the methods that access or modify them. In some programming languages (like C#), properties are a specific language feature that allows you to define getters and setters in a more concise way. In other languages, properties might be implemented using getter and setter methods.


## SOLID
The SOLID principles are a set of five design principles intended to make software designs more understandable, flexible, and maintainable. They are particularly relevant in object-oriented programming but can be applied in various programming paradigms. 

### The acronym SOLID stands for:

#### S - Single Responsibility Principle (SRP):
- A class should have only one reason to change, meaning it should only have one job or responsibility. This principle promotes separation of concerns, making the code easier to understand and maintain.
- Example: If a class handles both user authentication and user data storage, it violates SRP. Instead, you should have one class for authentication and another for data storage.

#### O - Open/Closed Principle (OCP):
- Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification. This means you should be able to add new functionality to a class without changing its existing code.
- Example: Instead of modifying a class to add new behavior, you can use inheritance or interfaces to extend its functionality.

#### L - Liskov Substitution Principle (LSP):
- Objects of a superclass should be replaceable with objects of a subclass without affecting the correctness of the program. This principle ensures that a subclass can stand in for its superclass.
- Example: If you have a class Bird and a subclass Penguin, the Penguin class should not override methods in a way that breaks the expected behavior of Bird. For instance, if Bird has a method fly(), Penguin should not implement it in a way that causes errors.

#### I - Interface Segregation Principle (ISP):
- Clients should not be forced to depend on interfaces they do not use. This principle encourages the creation of smaller, more specific interfaces rather than a large, general-purpose interface.
- Example: Instead of having a single interface Animal with methods like fly(), swim(), and walk(), you should create separate interfaces like Flyable, Swimmable, and Walkable. This way, classes only implement the methods relevant to them.

#### D - Dependency Inversion Principle (DIP):
- High-level modules should not depend on low-level modules; both should depend on abstractions (e.g., interfaces). Additionally, abstractions should not depend on details; details should depend on abstractions. This principle promotes loose coupling between components.
- Example: Instead of a class directly instantiating its dependencies, it should receive them through constructor injection or method parameters. This allows for easier testing and flexibility in changing implementations.

### Recap:
- **S**: Single Responsibility Principle (one reason to change);
- **O**: Open/Closed Principle (open for extension, closed for modification);
- **L**: Liskov Substitution Principle (subtypes must be substitutable for their base types);
- **I**: Interface Segregation Principle (no forced dependencies on unused interfaces);
- **D**: Dependency Inversion Principle (depend on abstractions, not on concrete implementations).

## Polymorphism
Polymorphism is a core concept in object-oriented programming (OOP) that allows objects of different classes to be treated as objects of a common superclass. It enables a single interface to represent different underlying forms (data types).

### Types of Polymorphism
There are two main types of polymorphism in programming.

|**Compile-time Polymorphism** (**Static Polymorphism**)|**Run-time Polymorphism** (**Dynamic Polymorphism**)|
|---|---|
|This type of polymorphism is resolved during compile time. |This type of polymorphism is resolved during runtime|
|It is typically achieved through **method overloading** and **operator overloading**.|It is typically achieved through **method overriding** in the context of **inheritance**.|
- **Method Overloading**: This occurs when multiple methods in the same class have the same name but different parameters (different type or number of parameters).
    ```C++
    class Math {
        public:
            int add(int a, int b) {
                return a + b;
            }

            double add(double a, double b) {
                return a + b;
            }
    };
    int main(){
        Math math;
        int sumInt = math.add(5, 10);       // Calls the first add method
        double sumDouble = math.add(5.5, 10.5); // Calls the second add method
        return 0;
    }
    ```
- **Operator Overloading**: This allows you to define how operators (like +, -, *, etc.) behave with user-defined types.
- **Method Overriding**: This occurs when a subclass provides a specific implementation of a method that is already defined in its superclass. The method to be executed is determined at runtime based on the object type.
    ```C++
    class Animal {
        public:
            virtual void makeSound() {
                std::cout << "Some generic animal sound" << std::endl;
            }
    };
    class Dog : public Animal {
        public:
            void makeSound() override {
                std::cout << "Bark" << std::endl;
            }
    };
    class Cat : public Animal {
        public:
            void makeSound() override {
                std::cout << "Meow" << std::endl;
            }
    };

    void playSound(Animal* animal) {
        animal->makeSound(); // Calls the appropriate method based on the actual object type
    }
    int main() {
        Dog dog;
        Cat cat;

        playSound(&dog); // Outputs: Bark
        playSound(&cat); // Outputs: Meow
    }
    ```

### Benefits of Polymorphism
- F**lexibility and Extensibility**: Polymorphism allows for the creation of more flexible and extensible code. You can introduce new classes that implement existing interfaces without modifying the code that uses those interfaces.
- **Code Reusability**: It promotes code reusability by allowing the same function or method to operate on different types of objects.
- **Simplified Code**: It can simplify code by allowing the same interface to be used for different underlying forms, reducing the need for type checking and casting.


