class FloatPounds{
    public static void main(String[] args){
	float twentyPence = 0.2f;

	System.out.println("20 pence = " + twentyPence);
	for(int i = 1; i < 1000; i++){
	    twentyPence += 0.2f;
	}
	System.out.println("total = " + twentyPence);
	
    }
}
