import java.io.*;

class BuffDemo2{
    public static void main(String[] args) throws IOException
    {
	
	// create a bufferedreader
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	System.out.println("Enter an integer number: ");

	int total = 0;
	int num = -1;

	while(num != 0){
	    try{
		String input = br.readLine();
		num = Integer.parseInt(input);
		total += num;
		System.out.println("The input integer is: " + num);
	    }
	    catch(NumberFormatException e){
		System.out.println("The input should be an integer.");
	    }
	}

	System.out.println("The total value is: " + total);
	

	
    }
}
