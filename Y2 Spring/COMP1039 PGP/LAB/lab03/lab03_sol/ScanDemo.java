// import the java.util package
import java.util.*;

class ScanDemo{
    // main method here
    public static void main(String[] args){
	// create a scanner to read input from system.in
	Scanner scanner = new Scanner(System.in);
	System.out.println("Enter an integer number: ");

	try{
	    int input = scanner.nextInt();
	    System.out.println("The input integer is: " + input);
	}catch(InputMismatchException e){
		System.out.println("The input should be an integer.");
	}
    }
	
}
