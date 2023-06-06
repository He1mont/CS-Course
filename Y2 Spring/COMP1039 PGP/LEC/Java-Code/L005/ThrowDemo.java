class ThrowDemo{
    public static void main(String[] args){
	/*
	try{
	    System.out.println("Before");
	    throw new ArithmeticException(); // no exception detected, but we manually throw one exception	
	}catch(ArithmeticException exc){
	    System.out.println("Exception caught");	
	}
	System.out.println("After try/catch block");
	*/

	
	try{
	    try{
		System.out.println("Before");
		throw new ArithmeticException();	
	    }catch(ArithmeticException exc){
		System.out.println("Exception caught");	
	 	//throw new ArithmeticException();
	    }
	}catch (ArithmeticException exc){
	    System.out.println("outer");
	}


	/*
	try{
	    System.out.println("Before");
	    throw new ArithmeticException(); // no exception detected, but we manually throw one exception
	    
	}catch(ArithmeticException exc){
	    System.out.println("Exception caught");
	    throw new ArithmeticException();
	}
	finally{
	    System.out.println("Finally");
	    }*/

    }
}
