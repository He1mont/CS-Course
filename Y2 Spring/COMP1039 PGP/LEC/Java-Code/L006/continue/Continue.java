public class Continue{
    public static void main(String[] args){
		int sum = 0;
		int[] xs = {1, 5, 2, 8, 10, 11, 22};

		
		for(int i = 0; i < xs.length; i++){
			if(xs[i] % 2 == 1) continue;
			sum += xs[i];
		}
		System.out.println("sum: " + sum);
    }
}
