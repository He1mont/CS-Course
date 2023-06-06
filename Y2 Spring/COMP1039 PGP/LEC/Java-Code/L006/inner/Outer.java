public class Outer{
	public int x = 10;

	public class Inner{
		public int y = 5;
		
		public void printX(){
			System.out.println(x);
		}
    }

    public int addition(){
		Inner inner = new Inner();
		return x + inner.y;
    }
}
