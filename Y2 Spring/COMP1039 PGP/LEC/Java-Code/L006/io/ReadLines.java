import java.io.*;

class ReadLines{
    public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str;

		do{
			System.out.print("Please type a string: ");
			str = br.readLine();
			System.out.println(str + ";");
		}while(!str.equals("stop"));

    }
}
