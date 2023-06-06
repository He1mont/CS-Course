class Bank{
    private Account[] accounts;

    public Bank(Account[] a){
	accounts = a;
    }


    public void update(){
	
	for(int i = 0; i < accounts.length; i++){
	    if(accounts[i] instanceof SavingAccount){
		
		SavingAccount sa = (SavingAccount) accounts[i];
		sa.assInterest();
		
		((SavingAccount) accounts[i]).addInterest();
		
	    }else if(accounts[i] instanceof CurrentAccount){
		if(accounts[i].getBalance() < 0){
		    System.out.println("A letter received for account " + (i+1));
		}
	    }	
	}
    }

    
    

    
}
