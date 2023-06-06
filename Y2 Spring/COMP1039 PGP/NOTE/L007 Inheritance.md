## L007: Inheritance



#### 1. 4 Properies of OOP

-   Encapsulation
-   Polymorphism
    -   Overload: multiple methods/constructors with the same name but different signature
    -   Override
-   Inheritance
-   Abstraction



#### 2. Inheritance

-   A class can inherit methods and data from another class
    -   the more general class is called "**superclass**"
    -   the more specific class is called "**subclass**"
    -   Subclass inherits **all the data and methods** from the superclass
-   This relationship is declared by the `extends` keyword
-   Subclasses **cannot** access the private member of its superclass
-   An example: `class Triangle extends TwoDShape`

<img src="assets/Screenshot 2023-05-01 at 21.57.59.png" alt="Screenshot 2023-05-01 at 21.57.59" style="zoom:50%;" />



#### 3. `Super`

-   An example from ChatGPT

```java
class Animal {
    String name;

    Animal(String name) {
        this.name = name;
    }

    void makeSound() {
        System.out.println("The " + name + " makes a sound.");
    }
}

class Cat extends Animal {
    String furColor;

    Cat(String name, String furColor) {
        super(name);        // call the constructor of the parent class
        this.furColor = furColor;
    }

    void makeSound() {
        super.makeSound();  // call the makeSound() method of the parent class
        System.out.println("The " + name + " purrs.");
    }
}

public class sample {
    public static void main(String[] args) {
        Cat myCat = new Cat("Fluffy", "white");
        myCat.makeSound(); // output: The Fluffy makes a sound. The Fluffy purrs.
    }
}
```

-   function `super()`
    -   **must be the first statement in constructor**
    -   call the constructor of the parent class
-   keyword `super`
    -   用来调用superclass中和subclass同名的method
    



#### 4. Objects

-   example 1:
    -   This works only when Y is a subclass of X

```java
X x = new X();
X x2;
Y y = new Y();

x2 = x; 
x2 = y;
```



-   example 2:
    -   error
    -   since Y is a subclass of X, we cannot assign an object of X to an object of Y

```java
X[] xs = new X[2];
xs[0] = x;
xs[1] = y;

Y y2 = xs[1];		// error
xs[1].b = 27;
```











