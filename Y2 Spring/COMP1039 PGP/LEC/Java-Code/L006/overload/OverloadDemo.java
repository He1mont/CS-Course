class OverloadDemo{
    public static void main(String[] args){
		Overload ob = new Overload();
		int resI;

		ob.ovlDemo();
		System.out.println();

		ob.ovlDemo(2);
		System.out.println();

		resI = ob.ovlDemo(4, 6);
		System.out.println("Result of (4, 6): " + resI);
		
    }
}
