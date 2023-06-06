class ExcDemo3{
	public static void main(String[] args){

	    int[] nums = {4, 0, 8, 16};
	    int total = 0;

	    for(int n : nums){
			try{
				System.out.println(80 / n);
				total += 80/n;
			}catch(ArithmeticException e){
				System.out.println("Can’t divide by Zero");
			}
			//catch(Exception e){
			//e.printStackTrace();
			//}
	    }
	    System.out.println("Total: " + total);
	}
} 
