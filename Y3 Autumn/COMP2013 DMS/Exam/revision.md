# DMS-Revision

## Intro

### Maintainability

**5 properties**

-   Modularity
-   Reusability
-   Analysability
-   Modifiability
-   Testability

**3 Principles**

-   Maintainability benefits most from adhering to simple guidelines
-   Maintainability is not an afterthought, but should be addressed from the very beginning of a development project
-   Some violations are worse than others; the more a software system compiles with the guidelines, the more maintainable it is

**Simple Guidlines**

1. Write short units (constructors/methods) of code

2. Write simple units of code

3. Write code once

4. Keep unit interfaces small

5. Separate concerns in modules (classes)

6. Couple architecture components loosely

7. Keep your codebase small

8. Automate your development pipeline and tests

9. Write clean code

**Three Main Categories of Maintenance**

-   Corrective Maintenance
    -   e.g. fix bugs
-   Adaptive Maintenance
    -   e.g. update links to resources after change
-   Perfective + Preventive Maintenance

**What is involved in Software Maintenance**

-   Understand the client
-   Understand the code
-   Refactor the code
-   Extend the code
-   Working as a team
-   Managing client expectation

### Java Collections Framework

-   Java Collections Framework principle ideas:
    -   We have container objects that contain objects
    -   All containers are either collections or maps (ArrayList or HashMap)
    -   All containers provide a common set of method signatures, in addition to their unique set of method signatures

<img src="assets/Screenshot 2024-01-21 at 14.37.11.png" alt="Screenshot 2024-01-21 at 14.37.11" style="zoom:50%;" />

## GUI

**Swing vs. JavaFX**

-   Swing: built on the earlier AWT (Abstract Window Toolkit)
-   JavaFX: 
    -   Able to **separate GUI** code from program code using **FXML file**
    -   Formatting uses CSS

**FXML and SceneBuilder**

-   **FXML**: Supports the idea of separating 'Design' and 'Functionality'
-   **SceneBuilder**: A design tool for created FXML files graphically

**Simple use of CSS to style interface**

```java
class Demo {
    void func() {
        demo.setStyle();
    }
}
```

**MVC**

-   The **model** provides a way for **views to subscribe** to its state change notifications
-   Any interested views subscribe to the model to **receive state change notifications**
-   The model notifies all views that had subscribed whenever a model's state change

**Benefits**

-   **Separation of Concerns**
-   **Reflexivity**: easy to maintain, extend and testing
-   **Reusability**

<img src="assets/Screenshot 2024-01-21 at 17.44.06.png" alt="Screenshot 2024-01-21 at 17.44.06" style="zoom:50%;" />

**Threading**

-   **The Facts**
    -   JavaFX launches the UI on a JavaFX Application thread
    -   This thread should be left handling the **UI interaction**
    -   Heavy computation should be done elsewhere to prevent freezing!
-   JavaFX provides a **solution**:
    -   Package `javafx.concurrent`
    -   A way for JavaFX to create and communicate with other threads

## UML

![Screenshot 2024-01-21 at 23.40.02](assets/Screenshot 2024-01-21 at 23.40.02.png)

| UML              | Used for                                                     |
| ---------------- | ------------------------------------------------------------ |
| UCD              | describe **a set of actions** that **systems can perform in collaboration with external users** |
| Activity Diargam | Graphical representations of **workflows of stepwise activities and actions related to an individual use case** or across many use cases |
| Sequence Diagram | a temporal representation of **objects and their interactions** |
| State Machine    | Show the **possible states of a single object**, the events or messages that **cause a transition from one state to another**, and **the action that result from that state change** |
| Class Diagram    | **the existence of classes** and their **structures and relationships** |

### Class Diagram

<img src="assets/Screenshot 2024-01-22 at 17.21.41.png" alt="Screenshot 2024-01-22 at 17.21.41" style="zoom:50%;" />

| Name           | Relation                                                     |
| -------------- | ------------------------------------------------------------ |
| Association    | reference                                                    |
| Dependency     | calls a method                                               |
| Aggregation    | Logically or physically contain                              |
| Composition    | hold the creation and control of a lifetime                  |
| Realization    | implements an interface                                      |
| Generalization | extends a class                                              |
| Multiplicity   | Number of links between each instance of a source class and instances of a target |

-   Association

-   Dependency

<img src="assets/Screenshot 2024-01-21 at 20.40.12.png" alt="Screenshot 2024-01-21 at 20.40.12" style="zoom:50%;" />

```java
class Die {
    public void roll() {...}
}
class Player {
    public void play(Die die) {
        die.roll();
    }
}
```

-   Aggregation

```java
public class A {
    private B b;
    public void setB(B b) {
        this.b = b;
    }
}
```

-   Composition

<img src="assets/Screenshot 2024-01-21 at 20.43.05.png" alt="Screenshot 2024-01-21 at 20.43.05" style="zoom:50%;" />

```java
public class Piece {
    ...
}
public class Player {
    private Piece piece = new Piece();
}
```

-   Realisation

<img src="assets/Screenshot 2024-01-21 at 20.44.42.png" alt="Screenshot 2024-01-21 at 20.44.42" style="zoom:50%;" />

```java
public SearchService implements SiteSearch {
    
}
```

-   Generalization

<img src="assets/Screenshot 2024-01-21 at 20.45.42.png" alt="Screenshot 2024-01-21 at 20.45.42" style="zoom:50%;" />

```java
public Child extends Parent {
    
}
```

-   Multiplicity
    -   1 = exactly 1
    -   = unlimited number (zero or more) 
    -   0..* = zero or more 
    -   1..* = one or more 
    -   0..1 = zero or 1 
    -   3..7 = specified range (from 3 to 7)

```java
class Teacher {		// source class
    private List<Student> students = new ArrayList<>();
}

class Student {		// target class
    private String name;
}
```

## Coding Tools

### Documenting Code

**Bob's Rules**

1.   Method length ≤ 75
2.   Indentation
3.   Line length below 80 characters
4.   Class variable names
5.   Accessor Methods
6.   Accessor Methods
7.   Class Variables => private
8.   Method Naming
9.   Method Parameters ≤ 5
10.   Symbolic Constants

**Javadoc**

-   `@param`: to explain a method parameter 
-   `@return`: to annotate a method return value 
-   `@throws/@exception`: for your exception handling 
-   `@deprecated`: bits of the code you no longer use 
-   {`@code`}: puts syntax in your documentation
-   **Class level** – see the inline comments `@link` and `@author`

### **Build tools**

**Why use build tools**

-   Project Compilation
-   Dependencies
-   Automated testing
-   Reduces errors from manually running steps,
-   Increases the consistency of the process.
-   Allow for better maintenance (keep a build log)
-   Deployment
-   Supports documentation
-   Repository management

### Testing

**Unit Testing vs. Regression Testing**

|             | Unit Testing                                                 | Regression Testing                                           |
| ----------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Scope       | Focuses on the smallest unit of code, like **functions**     | Often involves a broader set of functionalities and **parts of the application** |
| Purpose     | Ensures that **individual code** units function as expected. | Ensures that the **whole application** still works as expected after changes. |
| Timing      | Generally conducted during the development phase, **immediately** after code is written | Conducted before software release or after code changes to ensure new errors have not been introduced. |
| Maintenance | Requires updates as the logic of the code changes.           | May need updates to cover new features or changes in the software. |

**Unit Testing**

-   Unit Testing is a type of software testing where **individual units or components** of the software are tested for correctness.

-   Focuses on very small, specific areas, typically a single method or function.
-   Aims to quickly identify logical errors in the code.

-   Unit tests are often automated and can be implemented using various unit testing frameworks (e.g., JUnit for Java, NUnit for .NET).

**Regression Testing**

-   A type of testing to confirm that a recent program or code change has not adversely change the exisiting features

**Test Driven Development** (Three rules from SE)

-   How it works
    -   Write a test
    -   Check if test fails
    -   Test fails => Write production code
    -   Run all tests
    -   All tests succeed => Clean up code
-   Before writing tests
    -   Test can be derived from **requirements**, so it makes sure we meet the specs
    -   We write the **minimum amount of code to pass** (following XP's YAGNI principle)
    -   We write maintainable code

>   1.  **编写失败的单元测试之前，不要编写任何生产代码**
>   2.  **编写刚好足以使失败的单元测试通过的代码**
>   3.  **重构代码**

## Version Control

### Git

**Why Use Version Control**

-   Track changes
-   Fosters collaboration
-   Manage concurrency

**Copy-Modify-Merge Solution**

<img src="assets/Screenshot 2024-01-21 at 21.17.42.png" alt="Screenshot 2024-01-21 at 21.17.42" style="zoom:50%;" />

**Concurrency Management**

-   The copy-modify-merge model: for text files
-   Users work in parallel
-   Concurrent changes are automatically merged
-   Conflicts are infrequent
-   The lock-modify-unlock model: for binary file

**Working Copies and Revision**

## Design Principles and Design Patterns

### Design Principles

>   二级

**Basic OO Concepts**

-   Abstraction
-   Encapsulation
-   Inheritance
-   Polymorphism
    -   Overload: Method in the same class have same names but different parameters
    -   Override: A method could be re-write in subclass if it is already defined in the superclass

**Benefit of Encapsulation**

-   Data protection
-   Reusability
-   Flexibity

**The Object Model**

-   Abstraction
-   Encapsulation
-   Modularity
-   Hierarchy

**Core OO concepts**

-   Abstraction
-   Inheritance
-   Polymorphism
-   Interface

**SOLID Principle**

-   S: Single Responsibility Principle
    -   A class should have one and only one responsibility
-   O: Open-closed principle
    -   open for extension, closed for modification
-   L: Liskov's Substitution principle
    -   Subtypes must be **substitutable** for their base types
    -   e.g. duck class should work in everywhere a bird class works
-   I: Interface Segregation Principle
    -   Clients should not be forced to depend upon interfaces that they do not use
    -   e.g. An interface should not contain too much stuff, it should break into several interfaces
-   D: Dependency Inversion Principle
    -   High-level modules should not depend on low-level modules. Both should depend on abstractions.

### Design Pattern Examples

**A pattern specification has four essential elements**

1.   Name 
2.   Problem
3.   Solution
4.   Consequences

**Design patterns are organised in two ways**

-   **Purpose**: reflect **what pattern does**

    -   **Creational Pattern**: concern the **process of object creation**

    -   **Structural Patterns**: deal with the **composition of classes and objects**

    -   **Behavioural Patterns**: characterise the way in which **classes and objects interact and distribute responsibility**

-   **Scope**: specifies **where the pattern applies** to classes or objects

    -   **Class**: deal with relationships between classes and subclasses
    -   **Object**: deal with object relationships

<img src="assets/Screenshot 2024-01-21 at 22.07.01.png" alt="Screenshot 2024-01-21 at 22.07.01" style="zoom:50%;" />

### **Singleton**

-   ensures that one and only one instance of a class is created

```java
public class Singleton {
    private static Singleton instance;
    
    // private constructor
    private Singleton() {}

    public static Singleton getInstance() {
        if (instance == null) {
            instance = new Singleton();
        }
        return instance;
    }
}
```

### **Factory Pattern**

-   **create objects without exposing the creation logic to the client and refer to newly created object using a common interface.**

-   **Two patterns**

    -   Factory Method Pattern

    -   Abstract Factory Pattern

**Factory Method Pattern**

```java
interface Animal {}

class Dog implements Animal {}
class Cat implements Animal {}

interface AnimalFactory {
    Animal createAnimal();
}
class DogFactory implements AnimalFactory {
    @Override
    public Animal createAnimal() {
        return new Dog();
    }
}
class CatFactory implements AnimalFactory {
    @Override
    public Animal createAnimal() {
        return new Cat();
    }
}
```

**Abstract Factory Pattern**

```java
class Dog implements Animal {}
class Cat implements Animal {}
class DogFood implements Food {}
class CatFood implements Food {}

interface AbstractFactory {
    Animal createAnimal();
    Food createFood();
}
class DogProductFactory implements AbstractFactory {
    @Override
    public Animal createAnimal() {
        return new Dog();
    }
    @Override
    public Food createFood() {
        return new DogFood();
    }
}
class CatProductFactory implements AbstractFactory {
    @Override
    public Animal createAnimal() {
        return new Cat();
    }
    @Override
    public Food createFood() {
        return new CatFood();
    }
}
```

>   在**工厂方法模式**中，每个工厂类（如`DogFactory`和`CatFactory`）负责创建单一类型的产品（`Dog`或`Cat`）。而在**抽象工厂模式**中，一个工厂类（如`DogProductFactory`）负责创建一系列相关产品（`Dog`和`DogFood`）。这展示了抽象工厂可以创建多种类型的相关对象，而工厂方法通常只创建一种类型的对象。

![Screenshot 2024-01-22 at 00.15.34](assets/Screenshot 2024-01-22 at 00.15.34.png)

### Adapter Pattern

-   This pattern involves a single class which is responsible to join functionalities of independent or incompatible interfaces.

<img src="assets/Screenshot 2024-01-22 at 00.17.16.png" alt="Screenshot 2024-01-22 at 00.17.16" style="zoom:50%;" />

```java
// 旧的音频接口
interface OldAudioInterface {
    void playAnalogAudio();
}
// 新的音频接口
interface NewAudioInterface {
    void playDigitalAudio();
}
// 旧的音响系统
class OldSpeaker implements OldAudioInterface {
    @Override
    public void playAnalogAudio() {
        System.out.println("Playing analog audio");
    }
}
// 适配器
class AudioAdapter implements NewAudioInterface {
    private OldAudioInterface oldSpeaker;

    public AudioAdapter(OldAudioInterface oldSpeaker) {
        this.oldSpeaker = oldSpeaker;
    }
    @Override
    public void playDigitalAudio() {
        System.out.println("Converting digital audio to analog...");
        oldSpeaker.playAnalogAudio();
    }
}
// 使用适配器的示例
public class AdapterExample {
    public static void main(String[] args) {
        OldSpeaker oldSpeaker = new OldSpeaker();
        NewAudioInterface adapter = new AudioAdapter(oldSpeaker);
        adapter.playDigitalAudio(); // 通过适配器播放数字音频
    }
}

```

### Observable Pattern

**What is**

-   Observer pattern is used when there is **one-to-many relationship** between objects such that if one object is modified, its dependent objects are to be **notified automatically**.

**Why is it useful**

-   **Inbuilt** into the `java.util` and in JDK, in JavaBeans and Swing.
-   **Jbutton** - `addActionListener()` method is the subject's register observer method.
-   **Two objects are loosely coupled**
    -   It does not need to know the class of the observer.
    -   We can add new observers at any time irrespective of the state of the subject object and without modifying the subject object.
    -   Changes to either subject or object will not affect the other.

## Refactoring

**Different Categories of Refactoring**

-   **Composing Methods**
    -   refactoring within a method or within an existing class

```java
// 重构前
public void printDetails(String name, int age, String address) {
    System.out.println("Name: " + name);
    System.out.println("Age: " + age);
    System.out.println("Address: " + address);
}

// 重构后
public void printDetails(String name, int age, String address) {
    printName(name);
    printAge(age);
    printAddress(address);
}

private void printName(String name) {
    System.out.println("Name: " + name);
}

private void printAge(int age) {
    System.out.println("Age: " + age);
}

private void printAddress(String address) {
    System.out.println("Address: " + address);
}
```

-   **Moving Features Between Objects**
    -   refactoring changing the responsibility of a class

```java
// 重构前
class Car {
    void startEngine() { /*...*/ }
    void stopEngine() { /*...*/ }
}

// 重构后
class Engine {
    void start() { /*...*/ }
    void stop() { /*...*/ }
}

class Car {
    Engine engine = new Engine();

    void startEngine() {
        engine.start();
    }

    void stopEngine() {
        engine.stop();
    }
}
```

-   **Organizing Data**
    -   refactoring to improve data structures and object linking

```java
// 重构前
class Person {
    public String name;
    public String address;
}

// 重构后
class Person {
    private String name;
    private String address;

    public String getName() { return name; }
    public void setName(String name) { this.name = name; }

    public String getAddress() { return address; }
    public void setAddress(String address) { this.address = address; }
}
```

-   **Simplifying Conditional Expressions**
    -   encapsulation of conditions by replacing with polymorphism

```java
// 重构前
public class Discount {
    double calculateDiscount(Order order) {
        if (order.isSpecialDeal()) {
            return order.getPrice() * 0.95;
        } else {
            return order.getPrice() * 0.98;
        }
    }
}

// 重构后
public class Discount {
    double calculateDiscount(Order order) {
        return order.getPrice() * (order.isSpecialDeal() ? 0.95 : 0.98);
    }
}
```

-   **Making Method Calls Simpler**
    -   refactorings that make interfaces simpler

```java
// 重构前
class Customer {
    void createAccount(String name, String address, String email, String phone) { /*...*/ }
}

// 重构后
class Customer {
    void createAccount(CustomerDetails details) { /*...*/ }
}

class CustomerDetails {
    String name;
    String address;
    String email;
    String phone;
}
```

-   **Dealing with Generalization:** 
    -   moving methods up and down the hierarchy of inheritance by (often) applying the Factory or Template design pattern

```java
// 重构前
class Vehicle { /*...*/ }
class Car extends Vehicle { void startCar() { /*...*/ } }
class Bike extends Vehicle { void startBike() { /*...*/ } }

// 重构后
class Vehicle { void start() { /*...*/ } }
class Car extends Vehicle { /*...*/ }
class Bike extends Vehicle { /*...*/ }
```

-   **Big Refactorings**
    -   architectural refactoring to promote loose coupling or to realise a redesign via object orientation (Note: this is extremely difficult for most projects).

## Open Software Development

### Library 

**What is Library**

-   Some 3rd party software packaged up (in binaries) and ready-to-use in your own code
-   It is a shared resource

**What is in a  Library**

-   A jar file
-   An API
-   A license

### Open Source Software

-   **What is OSS** 
    -   OSS is (generally) free software that uses any licence approved by the Open Source Initiative (OSI) from their list of approved open source licences

-   **Why Go Open Source**

    -   Higher Quality

    -   Customisable

    -   Improvable

    -   Collaborative bug finding/fixing

    -   Redistributable

    -   Transparency

    -   Free

### Licences

**Common OSS licences**

-   Permissive licence
    -   Subsequent users can produce 'closed source' versions and sell the software
-   Copyleft licence
    -   Any subsequent versions are left with the same rights e.g. source code must be supplied, and can be modified
-   Examples:
    -   Apache Licence 2.0 =>  Permissive licence
    -   BSD 3-Clause "New" or "Revised" licence => Permissive licence
    -   GNU General Public Licence (GPL) => CopyLeft licence
    -   MIT licence => Permissive licence
    -   Mozilla Public Licence 2.0 => Permissive licence

>   **宽松许可证（Permissive License）**：
>
>   -   这是开源软件领域的一种特定类型的许可证。
>   -   它允许用户在几乎没有限制的情况下使用、修改和重新分发软件，即使在商业软件中也是如此。
>   -   宽松许可证不要求用户在他们的修改或衍生作品中**保留相同的许可证**。
>   -   典型的例子包括MIT许可证和Apache许可证。
>
>   **版权许可证（Copyright License）**：
>
>   -   这是一个更广泛的术语，涵盖所有类型的软件许可证，包括开源许可证和传统的专有许可证。
>   -   版权许可证是软件作者用来授权其他人使用、分发和修改其软件的法律协议。
>   -   在版权许可证中，软件作者保留一定的权利（比如版权），但授予用户特定的使用权。

**Contribute to an Exisiting Project**

-   Look at the README file
-   Fork the project
-   Check for any rules on how contributors should work
