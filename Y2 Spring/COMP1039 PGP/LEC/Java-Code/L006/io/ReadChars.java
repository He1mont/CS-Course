import java.io.*;

class ReadChars{

	// IOException could also be handled by try and catch
    public static void main(String[] args) throws IOException{
		
		// put together the translation and creation
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Please Enter a character:");

		char c = (char)br.read();
		System.out.println("Character: " + c);

		// try{
		// 	char c = (char)br.read();
		// 	System.out.println("Character: " + c);

		// } catch(IOException){
		// 	// code
		// }

    }
}
