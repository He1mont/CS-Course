
public class RM{
    // main method
    public static void main(String[] args){
	int count = 0; // count the number of times the result is larger than 0.5
	int num = 100; // number of iterations
	for(int i = 0; i < num; i++){
	    double value = Math.random(); // generate a random floating number 
	    if(value > 0.5)
		count++;
	}
	// be careful here, count is originally an integer
	System.out.println((double)count / num);
    }
}
