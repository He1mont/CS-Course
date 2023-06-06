# Revision Java



### 1. Before Programming

-   JDK
    -   Java Development Kit
    -   a softeware development environment used for developing java appliacations and applets
-   JRE
    -   Java Runtime Environment
    -   minimum requirements for executing a java application
-   JVM
    -   Java Virtual Machine
    -   a program to execute java **bytecode**

<img src="assets/Screenshot 2023-05-23 at 23.07.19.png" alt="Screenshot 2023-05-23 at 23.07.19" style="zoom:50%;" />



### 2. Fundamentals

-   **Identifiers**
    -   a name given to a method, variable,. ..
    -   $, _, [A-Z, a-z], [0-9]，中文
    -   ==cannot start with digit==



-   **An example**
    -   <u>keywords</u>: public static, void
    -   <u>identifiers</u>: Identifiers, main, args, String, a

```java
public class Identifiers{
    public static void main(String[] args){
        int a = 20;
    }
}
```



-   **Naming Conventions**

<img src="assets/Screenshot 2023-05-23 at 23.12.11.png" alt="Screenshot 2023-05-23 at 23.12.11" style="zoom:50%;" />



-   **Data Types**
    -   OO Types
    -   Non-OO (primitive) types: int, byte, short, long, float, double, char, boolean
    -   Integer Types: int ,byte, short, long
    -   Floating-Point Types: float and double



-   ==Irregular Arrays==
    -   we only need to specify the memory for the first dimension
        (决定几行就好了，列是irregular的)
    -   `int[][] table = int[3][]`



### 3. Object Oriented Programming

-   **What is** 
    -   programs are designed around objects and data



-   **Classes, Objects, Methods**
    -   Class: **templates** that specify how to build individuals
    -   Objects: **instances** of a particular class



-   **Four Properties**
    -   <u>Encapsulation</u>: 
        hide the implementation details of a class from outside access
        to make our code cleaner
    -   <u>Polymorphism:</u> 
        to perform the same action in many different ways.
    -   <u>Inheritance</u>: 
        the method to create a hierarchy between classes by inheriting 
    -   <u>Abstraction</u>: 
        hide the implementation details and show only the functionality



-   **Reference Variables**
    -   When we create an instance of class, the space is reserved in ==heap memory==



-   **Constructors**
    -   used to initialize an object when it is created
    -   ==to avoid code redundancy==
    -   name of a constructor must be consistent with its class name



-   **Keyword `this`**
    -   an implicit argument that refers to ==the object on which the method is called==



-   **Keyword `static`**
    -   to define a class member that will be used independently of any objects of that class
    -   Static variables are ==independent of any specific object==, can be called through its class name
    -   Instance variables could be **only called** through an object
    -   We CANNOT override static methods

<img src="assets/Screenshot 2023-05-23 at 23.49.38.png" alt="Screenshot 2023-05-23 at 23.49.38" style="zoom:30%;" />



-   **Encapsulation**
    -   links data with the code that manipulates it
    -   control the access of particular data
    -   use private access modifier to protect data.
    -   **Benefits:**
    -   对类内部的修改不会影响整体结构
    -   隐藏信息，保护数据

-   An example

```java
public class Person{
    private int height, weight, age;
    public Vehicle(int h, int w, int a){
        this.height = h;
        this.weight = w;
        this.age = a;
    }
    public int getHeight(){
        return height;
    }
}
```

```java
public class demo{
    public static void main(String[] args){
        Person p = new Person(180, 150, 20);
        System.out.println(p.height);			// fail
        System.out.println(p.getHeight);		// pass
    }
}
```



-   **Access Modifiers**
    -   <u>What is</u>: controls the member access in Java
    -   <u>4 types</u>: `public`, `private`, `default`, `protected`
    -   `public`: visible to all other classes
    -   `private`: only visible to the current class
    -   `protected`: visible to all subclasses and all classes in the same package
    -   `default`: visible to all classes within the same package

<img src="assets/Screenshot 2023-05-24 at 22.53.57.png" alt="Screenshot 2023-05-24 at 22.53.57" style="zoom:50%;" />



-   **Inner Class**

    -   <u>Nested classes:</u>

        Non-static nested classes: Inner classes

        Static nested classes

    -   <u>Scope:</u> bounded by its outer class, all variables and methods of its outer class

-   An example

```java
class Outer{
    int x = 10;
    class Inner{
        int y = 5;
    }
}
class Test{
    public static void main(String[] args){
        Outer outer = new Outer();
        Outer.Inner inner = outer.new Inner();
        System.out.println("("+outer.x+", "+inner.y+")");
    }
}
```

-   **Method-Local Inner Classes**
    -   An inner class can be defined within a method
    -   Its scope is within the method like local variables



-   **Polymorphism**
    -   the ability of an object to take on different forms
    -   <u>Overload</u>: two or more methods within the same class can share the same name but with different parameter declarations
    -   <u>Override</u>:



-   **`ArrayList`**
    -   dynamic length and more methods
    -   `ArrayList<Type> name = new ArrayList<>();`



### 4. Exception Handling

-   **Complie-time error**
    -   syntax errors, cannot be executed
    -   detected by the ==Java Compiler==
-   **Run-time error**
    -   index out of range, ... (logic problems), can be executed
    -   detected by the ==JVM==
    -   can be handle by exception handler



-   **`Throwable`**
    -   All runtime errors are classes derived from a class called `Throwable`
    -   Two direct subclass of `Throwable`
    -   `Error`: system errors beyond control
    -   `Exception`: errors that result from program activity



-   Exception Hierarchy
    -   <u>Checked</u>: enforced by the compiler and must be handled before compiling
    -   <u>Unchecked</u>: can be handled optionally, `RuntimeException` and `Error`

<img src="assets/Screenshot 2023-05-24 at 01.03.24.png" alt="Screenshot 2023-05-24 at 01.03.24" style="zoom:40%;" />



-   **Exception Handling**
    -   `try`
    -   `catch`
    -   `throw`: manually throw an exception
    -   `throws`: used in the method signature to declare an exception which might be thrown by executring this method
    -   `finally`



### 5. I/O

-   **Two types of streams**
    -   <u>Byte streams</u>: handling binary data (useful for files)
    -   <u>Character streams</u>: handling characters (more efficient)
-   **Byte streams**
    -   InputStream
    -   OutputStream
-   **Character Stream**
    -   Reader
    -   Writer



-   Three predefined stream variables (all declared as `public`, `static`, `final`)
    -   `System.in`: the standard input stream
    -   `System.out`: the standard output stream
    -   `System.err`: the standard error stream

```java
// converts a byte stream to a character stream
InputStreamReader sr = new InputStreamReader(System.in);
BufferedReader br = new BufferedReader(sr);
```



-   Examples

```java
InputStreamReader sr = new InputStreamReader(System.in);
BufferedReader br = new BufferedReader(sr);

// Reading Characters
int read() throws IOException;
char c = (char)br.read();		// returns an integer

// Reading Strings
String readLine() throws IOException;
String str = br.readLine();
```



-   **`Scanner`**
    -   used for obtaining the input of the primitive types
    -   easier than `BufferedReader` but slower

```java
Scanner sr = new Scanner(System.in)
sr.nextLine();			// read a string
```



-   `FileReader`

```java
FileReader fr = null;
BufferedReader br = null;
try{
    fr = new FileReader("1.txt");
    br = new BufferedReader(fr);
    br.readLine();
} catch(IOException e){
    System.out.println("File not found!");
} finally{
    try{
        fr.close();			// the file should be closed
    } catch(IOException e){
        System.out.println("File not closed!");
    }
}
```



-   `FileWriter`

```java
try{
    FileWriter fw = new FileWriter("1.txt");
    str = "new line";
    fw.writer(str);
} catch (IOException e){
    e.printStackTrace();
}
```



-   `String` vs `Char[]`

|                    | `String`         | `Char[]`    |
| ------------------ | ---------------- | ----------- |
| data type          | single data type | collections |
| immutability       | immutable        | mutable     |
| built-in functions | yes              | no          |
| access each char   | `charAt()`       | index       |



### 6. Inheritance

-   **Four Properties of OOP**
    -   <u>Encapsulation</u>: 
        a process of wrapping code and data together into a single unit
    -   <u>Polymorphism:</u> 
        to perform the same action in many different ways.
    -   <u>Inheritance</u>: 
        the method to create a hierarchy between classes by inheriting 
    -   <u>Abstraction</u>: 
        hide the implementation details and show only the functionality



-   **Inheritance**
    -   `superclass`： 父类
    -   `subclass` : 子类
    -   declared by `extends` keyword
    -   一个爹能有很多儿子，一个儿子只能有一个爹
    -   subclass cannot access the private member of its superclass



-   `final` keywords
    -   final class cannot be inherited
    -   final method cannot be overriden, but can be overloaded



-   **Abstract method**
    -   only specify the return type, input parameter and the name
    -   ==can only be declared within an abstract class==
-   **Abstract class**
    -   can contain both abstract and concrete methods
    -   cannot create objects
    -   ==When a class inherits an abstract class, it must implements all the abstract methods==



### 7. Interfaces

-   **What is**
    -   an abstract type that contains a collection of methods and constant variables



-   **Properties**
    -   does ==not allow concrete methods==
    -   An interface can be implemented by multiple classes
    -   One class can implement multiple interfaces
    -   Interface cannot be `private`
    -   All `non-static` and `non-default` method specified in the interface must be implemented any of the concrete classes that implements the interface
        一旦implement，所有的non-static和non-default函数都要继承
    -   Interface can only have variables but they are implicitly `public` `final` and `static`



-   **An example**
    -   ==we cannot new an interface==

```java
interface Face {
    abstract void print();
}

public class DemoInterface implements Face{
    public static void main(String[] args){
        Face demo = new DemoInterface();
        demo.print();
    }
    @Override
    public void print(){
        System.out.println("Hello world");
    }
}
```



-   **Abstract vs. Interface**

|               | Abstract class               | Interface         |
| ------------- | ---------------------------- | ----------------- |
| method        | abstract and concrete        | only abstract     |
| variable type | finalo or non, static or non | static and final  |
| keyword       | `extends`                    | `implements`      |
| accessibility | can have private members     | public by default |























