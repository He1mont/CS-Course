package com.COMP2013;

public class ZooApp {
    public static void main(String[] args) {
        Zoo z1 = new Zoo();
        Zoo z2 = new Zoo(20,"Taizhou");

        System.out.println(z1.printInfo());
        System.out.println(z2.printInfo());
        System.out.println("The number of zoo is " + Zoo.getNumZoo());

    }
}
