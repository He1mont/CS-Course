public class SumDemo{
    public static void main(String[] args){
		Summation s1 = new Summation(5);
		Summation s2 = new Summation(s1);

		System.out.println("s1.sum: " + s1.sum);
		System.out.println("s2.sum: " + s2.sum);
    }
}
