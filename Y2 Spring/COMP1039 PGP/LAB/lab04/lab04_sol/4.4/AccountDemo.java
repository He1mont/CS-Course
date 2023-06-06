class AccountDemo{
    public static void main(String[] args){
	Account[] accs = new Account[3];
	accs[0] = new SavingAccount(0, 0.01);
	accs[1] = new CurrentAccount(1, 5000);
	accs[2] = new SavingAccount(2, 0.02);

	accs[0].deposit(1000);
	accs[1].withdraw(1000);
	accs[2].deposit(1000);

	Bank bk = new Bank(accs);
	bk.update();

	for(Account acc : accs){
	    acc.print();
	}
	
	
    }
}
