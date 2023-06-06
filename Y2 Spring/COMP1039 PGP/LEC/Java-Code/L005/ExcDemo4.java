class ExcDemo4{
    public static void main(String[] args){

		int[] nums = {4, 2, 8, 16};
		int[] nums2 = {0, 3};
		
		for(int i = 0; i < nums.length; i++){
			try{
				System.out.println(nums[i] / nums2[i]);
			}catch(ArithmeticException e){
				System.out.println("Can't divide by Zero");
			}catch(ArrayIndexOutOfBoundsException e){
				System.out.println("Index out of bounds");
			}
		}
    }
}
