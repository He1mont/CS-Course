public class DieDemo{
    // main method
    public static void main(String[] args){
	Die dice1 = new Die(); // create our first die object
	Die dice2 = new Die(); // create the second die
	
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	int c5 = 0;
	int c6 = 0;
	int c7 = 0;
	int c8 = 0;
	int c9 = 0;
	int c10 = 0;
	int c11 = 0;
	int c12 = 0;
	
	

	// 1000 iterations, each time will roll these two dices and output the result to the console
	for(int i = 0; i < 1000; i++){
		int d1 = dice1.roll();
		int d2 = dice2.roll();
	    System.out.println("No." + (i+1) + " dice1: " + d1 + " dice2 :" + d2);
		switch (d1+d2){
			case 2: c2++; break;
			case 3: c3++; break;
			case 4: c4++; break;
			case 5: c5++; break;
			case 6: c6++; break;
			case 7: c7++; break;
			case 8: c8++; break;
			case 9: c9++; break;
			case 10: c10++; break;
			case 11: c11++; break;
			case 12: c12++; break;
			default: break;
		}
	}
	System.out.println("2: " + c2);
	System.out.println("3: " + c3);
	System.out.println("4: " + c4);
	System.out.println("5: " + c5);
	System.out.println("6: " + c6);
	System.out.println("7: " + c7);
	System.out.println("8: " + c8);
	System.out.println("9: " + c9);
	System.out.println("10: " + c10);
	System.out.println("11: " + c11);
	System.out.println("12: " + c12);




    }
}
