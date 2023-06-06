public class USDemo{
    public static void main(String[] args){
	
		USMoney m1 = new USMoney(3, 130);// create the first object
		m1.printMoney(); // check its value
		USMoney m2 = new USMoney(1, 99); // create our second object
		m2.printMoney(); // check its value
		USMoney m3 = m1.plus(m2); //add them together
		m3.printMoney();
    }
}
