import Code.A;

public class A{
    public String name;

    // Constructor of A
    public A(String n){
        name = n;
    }

    public void printA(){
        System.out.println(name);
    }
}

class B{
    // private int a;
    private A a;        // an instance variable of B

    // Constructor of B
    public B(A a){
        this.a = a;     // the name of the local variable (in the parenthesis)
                        // equals the name of the instance variable
    }

    public A getA(){    // since a in B is private
        return a;       // we use method getA to get access to a
    }
}
