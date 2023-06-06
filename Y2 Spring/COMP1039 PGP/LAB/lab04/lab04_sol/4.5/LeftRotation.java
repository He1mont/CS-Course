class LeftRotation{
    public static void main(String[] args){
	// convert the input string to an integer
	int d = Integer.parseInt(args[0]);

	// shift each element
	for(int i = 1; i < args.length; i++){
	    // 
	    System.out.print(args[(i - 1 + d) % (args.length-1)+1] + " ");
	}
	System.out.println();
	    
	
    }
}
