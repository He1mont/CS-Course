class ExcDemo2{

    // a static method which may cause anexception
    public static void genException(){
		System.out.println("Before");
		int[] nums = new int[4];
		nums[7] = 0;
		System.out.println("After");
    }

    // main method
    public static void main(String[] args){
		// create a try block
		try{	
			genException();		// method called inside the try block

		}catch(ArrayIndexOutOfBoundsException e){
			System.out.println("Index out of bounds!");
		}
		System.out.println("Catch finishes");
    }
} 
