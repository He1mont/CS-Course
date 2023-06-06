public class Factorial{
    // a static method 
    long factorial(int value){
	
		if(value == 0 || value ==1) // base case
			return 1;
		else if(value < 0){ // avoid infinite loop 
			System.out.println("The input integer must be non-negative!");
			return 0;
		}
		else
			return value * factorial(value-1); // recursive step
	}
    
	public static void main(String[] args){
		Factorial fl = new Factorial();
		int num = 8; // initialise the value
		System.out.println("The factorial of " + num + " is: " + fl.factorial(num));
    }
	
}
