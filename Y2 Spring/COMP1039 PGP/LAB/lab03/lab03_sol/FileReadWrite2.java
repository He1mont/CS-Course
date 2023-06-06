import java.io.*;
import java.util.*;

class FileReadWrite2{
    public static void main(String[] args){
	try(Scanner sr = new Scanner(new FileReader("input.txt")); FileWriter fw = new FileWriter("output.txt")){
	    while(sr.hasNextLine()){
		fw.write(sr.nextLine().toUpperCase() + "\r\n");
	    }
	}
	catch(IOException e){
	    e.printStackTrace();
	}
    }
}
