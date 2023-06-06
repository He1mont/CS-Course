import java.util.*;

public class ScannerDemo{
    public static void main(String[] args){
		Scanner sr = new Scanner(System.in);

		// read a line
		System.out.print("Please enter a string: ");
		String line = sr.nextLine();
		System.out.println("String: " + line);

		// read an integer
		System.out.print("Please enter an integer: ");
		int i = sr.nextInt();					// report error when given character or float number
		System.out.println("Integer: " + i);	// we can use try and catch to handle exceptions

		// read a double
		System.out.print("Please enter a double: ");
		double d = sr.nextDouble();				// report error when given character
		System.out.println("Double: " + d);

		// read a character
		System.out.print("Please enter a character: ");
		char c = sr.next().charAt(0);			// get the first char of the given string
		System.out.println("Character: " + c);
		
		// read a word
		System.out.print("Please enter a word: ");
		String w = sr.next();					// get the first word of the given string
		System.out.println("Word: " + w);

    }
}
