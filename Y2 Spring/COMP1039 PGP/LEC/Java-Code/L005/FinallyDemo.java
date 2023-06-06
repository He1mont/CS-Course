
class FinallyDemo{
    public static void main(String[] args){

		try{
			System.out.println("Before");
			throw new ArithmeticException(); // no exception detected, but we manually throw one exception	
			
		}catch(ArithmeticException exc){
			System.out.println("Exception caught");
			return;
		}
		//finally{
		//  System.out.println("Finally");
		//}
		System.out.println("After");
	
    }
}
