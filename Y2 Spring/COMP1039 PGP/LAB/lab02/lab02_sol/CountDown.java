public class CountDown{
    // a static method for counting down
    public void countdown(int n){
		// first check if the given integer is non-negative to avoid infinite loops
		if(n < 0)
			return;
		// In all cases, we should first print the given non-negative integer
		System.out.println(n);
		if(n == 0){// the base case here
			System.out.println("Blast off");
		}else{
			// recursive step
			countdown(n-1); 
		}
	}

    // main method
    public static void main(String[] args){
		CountDown cd = new CountDown();
		long current = System.currentTimeMillis();
		cd.countdown(1000);
		System.out.println(System.currentTimeMillis() - current);
	
		current = System.currentTimeMillis();
		for(int i = 0; i < 1000; i++){
			System.out.println(1000-i);
		}
		System.out.println("Blast off");
		System.out.println(System.currentTimeMillis() - current);
    }
}
