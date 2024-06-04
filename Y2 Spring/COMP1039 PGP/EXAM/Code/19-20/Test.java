class Outer{

    void out(){
        System.out.println("I am outer");
    }

    class Inner{
         void in(){
            System.out.println("I am inner");
        }
    }

}


public class Test{
    public static void main(String[] args){
        Outer o = new Outer();
        o.out();
        Outer.Inner i = o.new Inner();
        i.in();

    }
}