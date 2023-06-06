import Code.A;

public class Test{
    public static void main(String[] args){
		A a1 = new A("A1");		// a1 is a public object with name "Ai"
		pt1_1 b1 = new pt1_1(a1);		// b1 is a private object with instance variance a1

		A a2 = b1.getA();		// a2指向b1里的a指向的东西
		a2.printA();	
		a2.name = "A2";			// 因此当a2指向的东西改变时,pass by reference
		b1.getA().printA();		// b1里的a指向的东西也会改变
	}
}
