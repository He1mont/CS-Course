
public class USMoney{
    private int dollar; // an integer for the dollar part
    private int cents; // an integer fo the cents part

    // constructor
    public USMoney(int d, int c){
		// it only works if the given value is non-negative
		if(d >= 0 && c >= 0)
			setMoney(d, c);
		else
			System.out.println("Money cannot be negative!");
    }

    // a private method to help translate cents to dollar and then assign them to the instance variables
    private void setMoney(int x, int y){
		this.dollar = x + y / 100;
		this.cents = y % 100;
    }

    // a method to return the dollar value
    public int getDollar(){
		return this.dollar;
    }

    // a method to return the cents value
    public int getCents(){
		return this.cents;
    }

    // a method to add togeter the given USMoney and the current object
    // and then return a new USMoney representing the value of their summation
    public USMoney plus(USMoney m){
		return new USMoney(m.getDollar() + this.dollar, m.getCents() + this.cents);
    }

    // this method is used to check the current value 
    public void printMoney(){
		System.out.println(dollar + " Dollar " + ((cents == 0) ? "" : (cents + " Cents")));
    }
}
