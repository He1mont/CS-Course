class SupSubRef {
	public static void main(String[] args) {

		X x = new X(10); // a = 10
		X x2;
		Y y = new Y(5, 6); // y.a = 6; y.b = 5;

		x2 = x;
		System.out.println("x2.a: " + x2.a);

		x2 = y;
		System.out.println("x2.a: " + x2.a);

		// x2.b = 27;

		// X[] xs = new X[2];
		// xs[0] = x;
		// xs[1] = y;

		// Y y2 = xs[1];
	}
}
