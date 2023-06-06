class Person{
    int age;

    Person (int n){
        age = n;
    }

    public void self(){
        System.out.println("I am a person");
    }
}

class Student extends Person{
    int grade;

    Student (int m, int n){
        super(m);
        grade = n;
    }

    // override method
    public void self(){
        System.out.println("I am a student.");
    }

    public void print(){
        System.out.println("super.age = " + super.age);
        System.out.println("my.age    = " + age);
    }
}

public class demo{
    public static void main(String[] args){

        Person p = new Student(10, 20);
        
        System.out.println("p.age = "+ p.age);
        System.out.println("p.grade = "+ p.grade);
        p.self();

    }
}