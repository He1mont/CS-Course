class Triangular{
    // main method
    public static void main(String[] args){
	// create a two-dimensional array
	int[][] ts = new int[10][];
	// the outer loop 
	for(int i = 0; i < ts.length; i++){
	    // the size of each array is set to be the row number + 1
	    int[] ys = new int[i+1];
	    // an inner loop to set up values for each element
	    for(int j = 0; j < ys.length; j++){
		ys[j] = i + j;
		// output the result
		System.out.print(ys[j] + " ");
	    }
	    // change to next line, when it finishes
	    System.out.println();
	    // this array is stored in corresponding 2D slot.
	    ts[i] = ys;
	}
    }
}
