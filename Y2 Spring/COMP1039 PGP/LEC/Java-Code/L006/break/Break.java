public class Break{
    public static void main(String[] args){
		int[] nums = {1, 11, 22, 3, 4, 66, 77, 2, 100, 212};
		int[] xs = new int[4];
		int index = 0;

		for(int num: nums){
			if(num > 10){
				xs[index++] = num;
				if(index >= 4)
					break;
			}
		}
		for(int x: xs){
			System.out.print(x + " ");
		}
		System.out.println();
    }
}
