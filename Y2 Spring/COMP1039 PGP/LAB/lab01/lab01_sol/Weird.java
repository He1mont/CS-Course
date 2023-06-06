public class Weird{
    public static void main(String[] args){
	int n = 3;

	// if n is an odd number
	if(n % 2 == 1){
	    System.out.println("Weird");
	}else{
	    // if n is in the range [2, 5]
	    if(n>=2 && n <=5){
		 System.out.println("Not Weird");
	    }
	    // if n is in the range [6, 20]
	    else if(n>=6 && n <= 20){
		 System.out.println("Weird");
	    }
	    // otherwise, n is an even number and greater than 20
	    else{
		 System.out.println("Not Weird");
	    }
	}
    }
}
