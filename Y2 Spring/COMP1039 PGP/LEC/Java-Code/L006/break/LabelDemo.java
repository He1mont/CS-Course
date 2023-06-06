public class LabelDemo{
    public static void main(String[] args){
		for(int i = 0; i < 3; i++){
			one:{
				two:{
					System.out.println("i is " + i);
					if(i == 1)
						break one;
					if(i == 2)
						break two;
					System.out.println("won’t work");
				}
				System.out.println("After block two.");
			}
			System.out.println("After block one.");
		}
    }
}
