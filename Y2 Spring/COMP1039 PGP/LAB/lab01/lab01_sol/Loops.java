public class Loops{
    public static void main(String[] args){
	int a = 0;
	int b = 2;
	int n = 10;

	int power2 = 1;
        for(int j = 0; j < n; j++){
	    a += power2 * b;
	    System.out.print(a + " ");
	    power2 = power2 * 2;
        }
        System.out.println();
    }
}
