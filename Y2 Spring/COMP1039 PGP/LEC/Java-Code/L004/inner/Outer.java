public class Outer{
    int x = 10;

    class Inner{
		int y = 5;
		void printX(){
			System.out.println(x);
		}
    }

    int addition(){
		Inner inner = new Inner();
		return x + inner.y;
    }
}
