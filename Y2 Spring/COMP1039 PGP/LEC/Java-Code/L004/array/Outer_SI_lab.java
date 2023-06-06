public class Outer_SI_lab {
	int outerInt = 3; 
	
	static class Inner_SI {
		public void display() { 
			System.out.println("This is a static inner class "+outerInt);
		}
	}
	public static void main(String args[]) {
		Outer_SI_lab.Inner_SI innerObj = new Outer_SI_lab.Inner_SI();	 
		innerObj.display();
	}
}
