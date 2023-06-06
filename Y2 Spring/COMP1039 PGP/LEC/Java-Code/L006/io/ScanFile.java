import java.util.*;
import java.io.*;

class ScanFile{
    public static void main(String[] args){
        try(Scanner sr = new Scanner(new FileReader("2.txt"))){
            String str;
            while(sr.hasNextLine()){
                str = sr.nextLine();
                System.out.println(str);
            }
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}
