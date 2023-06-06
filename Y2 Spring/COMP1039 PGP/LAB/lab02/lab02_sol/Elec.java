public class Elec{
    // main method
    public static void main(String[] args){
	int budget = 60; // initial budget
	int[] keyboards = {40, 50, 60}; // prices for keyboards
	int[] usb = {5, 8, 12}; // prices for USB

	int max = -1; // most expensive items we can buy, if there is no such pair, -1 will be used
	// two for loop to check each possibility
	for(int i = 0; i < keyboards.length; i++){
	    for(int j = 0; j < usb.length; j++){
		// get the summation of two items
		int sum = keyboards[i] + usb[j];
		// check if it satisfies the budget and is also more expensive than max
		if(sum <= budget && sum > max)
		    max = sum;
	    }
	}

	System.out.println("output: " + max);
    }
}
