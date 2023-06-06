class ExcDemo1{
    // main method
    public static void main(String[] args){
		int[] nums = new int[4];
		
		try{
			System.out.println("Before");
			nums[7] = 10;
			System.out.println("After");

		}catch(ArrayIndexOutOfBoundsException e){
			System.out.println("Index out of bounds!");
		}
		System.out.println("Catch finishes");

    }
} 
