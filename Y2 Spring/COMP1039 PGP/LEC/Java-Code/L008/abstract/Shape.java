public class Shape {

	public static void main(String[] args) {
		// create a triangle objects
		Triangle t1 = new Triangle();

		t1.width = 4.0;
		t1.height = 4.0;
		t1.style = "outlined";

		System.out.println("Info for t1: ");
		t1.showStyle();
		t1.showDim();

		// TwoDShape t2 = new TwoDShape();
		// System.out.println("area of twoD: " + t2.area());
	}
}
