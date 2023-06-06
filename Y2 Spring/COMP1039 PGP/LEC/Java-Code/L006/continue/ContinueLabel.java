public class ContinueLabel{
    public static void main(String[] args){
		int[] xs = {1, 11, 22, 3, 4, 66, 77, 2, 100, 212};
		int[] ys = {3, 30, 50, 23, 99};

		loop1:
		for(int x: xs){
			for(int y: ys){
				System.out.println("--------------------");
				System.out.println("x: " + x);
				System.out.println("y: " + y);

				if(x + y > 40){
					System.out.println("Invalid");
					continue loop1;
				}
			}
		}
    }
}
