// import the java.util package
import java.util.*;

class ScanDemo2{
    // main method here
    public static void main(String[] args){
	// create a scanner to read input from system.in
	Scanner scanner = new Scanner(System.in);
	System.out.println("Enter an integer number: ");
	int total = 0;
	int input = -1;
	
	while(input != 0){
	    try{
		input = scanner.nextInt();
		//System.out.println("The input integer is: " + input);
		total+=input;
	    }catch(InputMismatchException e){
		System.out.println("The input should be an integer, please enter another integer number.");
		// ignore that value
		//String invalid = scanner.next();
	    }
	}
	System.out.println("The total value is: " + total);
	
    }
	
}
