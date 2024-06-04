class Parent{
    void PrintData() {
        System.out.println("method of parent class");
    }
}

class Child extends Parent{
    void PrintData() {
        System.out.println("method of child class");
    }
}

class Sample1{
    public static void main(String args[]){
        Child obj1 = new Child();
        Parent obj2 = new Parent();
        Parent obj3 = new Child();
        Child obj4 = new Parent();

        Child obj5 = (Child) obj2;
        Child obj6 = (Child) obj3;
    }
}
