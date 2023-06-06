public class ElephantDemo{

    public static void main(String[] args){
		
		Elephant bill = new Elephant();
		Elephant andy = new Elephant();
		
		bill.name = "Bill";
		bill.color = "Grey";
		bill.age = 6;
		System.out.println("Name: " + bill.name + " Color: " + bill.color + " Age: " + bill.age);
		
		andy.name = "Andy";
		andy.color = "White";
		andy.age = 9;
		System.out.println("Name: " + andy.name + " Color: " + andy.color + " Age: " + andy.age);

    }
}
