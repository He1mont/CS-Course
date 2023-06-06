class NonIntResultException extends Exception{
	int n, d;
	NonIntResultException(int i, int j){
		n = i;
		d = j;
	}	
	public String toString(){
		return "Result of " + n + " / " + d + " is not an integer value";
	}
}
