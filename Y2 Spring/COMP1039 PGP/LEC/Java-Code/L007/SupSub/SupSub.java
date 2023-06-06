class X {
    int a;

    X(int i) {
        a = i;
    }
}

class Y extends X {
    int b;

    Y(int i, int j) {
        super(j);
        b = i;
    }

    void ym() {

    }
}

public class SupSub {
    public static void main(String[] args) {

		// X x = new X(10); // a = 10
		// X x2;
		// Y y = new Y(5, 6); // y.a = 6; y.b = 5;

		// x2 = x;
		// System.out.println("x2.a: " + x2.a);

		// x2 = y;
		// System.out.println("x2.a: " + x2.a);

		// x2.b = 27;

		X[] xs = new X[2];
		xs[0] = x;
		xs[1] = y;

		Y y2 = (Y) xs[1];
		y2.b = 27;

        // to check the real type
        if (xs[1] instanceof Y){
            Y y2 = (Y) xs[1];
        }
	}
}
