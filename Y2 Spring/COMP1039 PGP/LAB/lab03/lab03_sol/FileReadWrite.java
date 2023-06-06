import java.io.*;
class FileReadWrite{
    public static void main(String[] args){
	try(BufferedReader br = new BufferedReader(new FileReader("input.txt")); FileWriter fw = new FileWriter("output.txt")){
	    String content = br.readLine();
	    while(content != null){
		fw.write(content.toUpperCase() + "\r\n");
		content = br.readLine();
	    }
	    
	}
	catch(IOException e){
	    e.printStackTrace();
	}
    }
}
