import java.io.*;

class FileReaderDemo{
    
    public static void main(String[] args){

		FileReader fr = null;
		BufferedReader br = null;

		try{
			fr = new FileReader("2.txt");
			br = new BufferedReader(fr);
			
			String content = br.readLine();
			while(content != null){
				System.out.println(content);
				content = br.readLine();		// 空格会被读进去
			}
		} 
		catch(IOException e){

		} 
		finally{
			try{
				br.close();
			}
			catch(IOException e){

			}
		}
		
	
		/*
		try(BufferedReader br = new BufferedReader(new FileReader("2.txt"))){

			String content = br.readLine();
			while(content != null){
				System.out.println(content);
				content = br.readLine();
			}
		} catch(IOException e){
			System.out.println("The file does not exist!");
		}
		*/
    }
}
