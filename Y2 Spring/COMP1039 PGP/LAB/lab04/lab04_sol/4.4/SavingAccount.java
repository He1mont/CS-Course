public class SavingAccount extends Account{
    private double interest; // the intrest value

    public SavingAccount(int a, double value){
	super(a);
	if(value >= 0 && value <= 1){
	    interest = value;
	}else{
	    interest = 0;
	    System.out.println("interst value is invalid!");
	}
	
    }

    public void addInterest(){
	if(getBalance() > 0){
	    deposit(getBalance() * interest); 
	} 
    }
}
