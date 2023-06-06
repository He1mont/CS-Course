class SeriesDemo {
	public static void main(String[] args) {
		EvenNum even = new EvenNum();

		for (int i = 0; i < 5; i++) {
			System.out.println("Next value is " + even.getNext());
		}

		even.reset();
		System.out.println("Resetting");

		for (int i = 0; i < 5; i++) {
			System.out.println("Next value is " + even.getNext());
		}

		Series[] ss = new Series[2];
		ss[0] = even;
		ss[1] = new ByThree();

		for (int i = 0; i < ss.length; i++) {
			/**
			 * if(ss[i] instanceof EvenNum)
			 * System.out.print("An object of EvenNum ");
			 * if(ss[i] instanceof ByThree)
			 * System.out.print("An object of ByThree ");
			 **/
			System.out.println("index " + i + ": " + ss[i].getNext());
		}

		// ss[1].unique();
	}
}
