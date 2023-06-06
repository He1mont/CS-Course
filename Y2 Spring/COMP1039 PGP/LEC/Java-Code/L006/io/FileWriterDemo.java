import java.io.*;

class FileWriterDemo{
    public static void main(String[] args){
		String str;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		try(FileWriter fw = new FileWriter("2.txt")){
			str = br.readLine();
			fw.write(str);
			fw.write("\r\n");		// 用\r\n换行来保证在windows下文本的兼容性
			while(!str.equals("stop")){
				str = br.readLine();
				fw.write(str);
				fw.write("\r\n");
			}
		}
		catch(IOException e){
			e.printStackTrace();
		}
    }
}
