public class Test{
    public static void main(String[] args){
		Outer outer = new Outer();
		Outer.Inner inner = outer.new Inner();
		System.out.println("(" + outer.x + "," + inner.y +")");
    }
}
