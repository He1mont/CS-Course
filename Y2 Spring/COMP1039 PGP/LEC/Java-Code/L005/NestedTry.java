class NestedTry{

	// once the error is handled in the method, then it wouldn't appear in the caller function

    static void method1(){
		try{
			// invoke method 2
			method2();
			System.out.println("After Method 2");

		}catch(ArithmeticException e){
			System.out.println("Exception Method 1");
			//throw new ArithmeticException();
		}
    }

    static void method2(){
		try{
			// invoke method 3
			method3();
			System.out.println("After Method 3");

		}catch(ArithmeticException e){
			System.out.println("Exception Method 2");
			//throw new ArithmeticException();
		}
    }

    static void method3() throws ArithmeticException {
		try{
			int x = 4 / 0;
			System.out.println("Error here");

		}catch(ArithmeticException e){
			System.out.println("Exception Method 3");
			//throw new ArithmeticException();
		}
    }
    
    public static void main(String[] args){
		try{
			method1();
			System.out.println("After Method 1");

		}catch(ArithmeticException e){
			System.out.println("Exception in main");
		}
    }
}

