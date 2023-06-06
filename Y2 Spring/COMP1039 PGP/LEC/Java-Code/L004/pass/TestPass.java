
class TestPass{

	static void make3(int x){
		System.out.println("(2)" + x);
		x = 3;
		System.out.println("(3)" + x);
	}

	public static void main(String[] args){
		int x = 4;
		System.out.println("(1)" + x);
		make3(x);
		System.out.println("(4)" + x);
	}
}
