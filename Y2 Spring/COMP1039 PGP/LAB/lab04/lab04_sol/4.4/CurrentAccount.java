class CurrentAccount extends Account{
    private double overdraft_limit;

    public CurrentAccount(int a, double limit){
	super(a);
	if(limit >= 0){
	    overdraft_limit = limit;
	}else{
	    overdraft_limit = 0;
	    System.out.println("interst value is invalid!");
	}
    }

    public void withdraw(double sum){
	if(sum <= 0)
	    System.out.println("Account.deposit(...): "
			       +"cannot deposit negative amount.");
	else if (getBalance() - sum + overdraft_limit < 0)
	    System.out.println("Error, exceed the overdraft limit!");
	else
	    super.withdraw(sum);
	
    }

    
}
