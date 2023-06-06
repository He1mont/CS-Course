import java.io.*;

class BuffDemo{
    public static void main(String[] args) //throws IOException
    {
	
	// create a bufferedreader
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	System.out.println("Enter an integer number: ");
	
	try{
	    String input = br.readLine();
	    int num = Integer.parseInt(input);
	    System.out.println("The input integer is: " + num);
	}
	catch(NumberFormatException e){
	    System.out.println("The input should be an integer.");
	}
	catch(IOException e){
	    System.out.println("There is an IOException.");
	}
	
    }
}
