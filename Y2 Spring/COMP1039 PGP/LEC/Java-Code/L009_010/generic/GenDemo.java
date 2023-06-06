class GenDemo {
	public static void main(String[] args) {

		Gen<Integer> iob = new Gen<Integer>(88); // create an object of integer

		iob.showType();// show the type
		int value = iob.getOb(); // get the integer;
		System.out.println("value: " + value);

		Gen<String> sob = new Gen<>("Generic"); // create an object of String
		sob.showType();// show the type
		String s = sob.getOb(); // get the integer;
		System.out.println("value: " + s);
	}
}
