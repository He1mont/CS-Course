class Parent{
    int age;
    String name;

    static int cash = 10000;

    static void self(){
        System.out.println("I am a Parent");
    }

    static void self(int a){
        System.out.println("a = " + a);
    }


}

// class Son extends Parent{
//     void self(){
//         System.out.println("I am a son");
//     }
// }

// class Daughter extends Parent{
//     void self(){
//         System.out.println("I am a daughter");
//     }
// }


public class demo{
    public static void main(String[] args){

        Parent p = new Parent();

        Parent.self();
        Parent.self(1000);
        System.out.println(Parent.cash);

    }
}