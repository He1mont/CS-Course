class Gen<T> { // T is a generic type
    T ob; // declare a reference to an object of type T

    Gen(T o) { // constructor
        ob = o;
    }

    T getOb() {
        return ob;
    }

    void showType() {
        System.out.println(ob.getClass().getName());
    }
}
