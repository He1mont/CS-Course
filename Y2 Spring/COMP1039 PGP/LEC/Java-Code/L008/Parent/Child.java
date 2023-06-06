class Child extends Parent {
    int i;

    Child(int n, int m) {
        i = m;
    }

    void show() {
        System.out.println("i in superclass: " + super.i);
        System.out.println("i in subclass: " + i);
    }
}
