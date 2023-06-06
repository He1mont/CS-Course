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
        super(name);
        this.furColor = furColor;
    }

    void makeSound() {
        super.makeSound();  // call the makeSound() method of the parent class
        System.out.println("The " + name + " purrs.");
    }
}

public class sample {
    public static void main(String[] args) {
        Cat myCat = new Cat("Fluffy", "White");
        myCat.makeSound(); // output: The Fluffy makes a sound. The Fluffy purrs.
    }
}
