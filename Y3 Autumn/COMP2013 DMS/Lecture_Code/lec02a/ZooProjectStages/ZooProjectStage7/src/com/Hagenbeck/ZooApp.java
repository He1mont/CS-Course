package com.Hagenbeck;

public class ZooApp {

	public static void main(String[] args) {
		int avgVisitors=100;

		Zoo zoo1; // creating reference
		zoo1=new Zoo("Hamburg");
		zoo1=new Zoo("Munic"); // new object takes over reference; old object not accessible any more
		Zoo zoo2=zoo1; // references zoo1 and zoo2 point to same object
		Zoo zoo3=new Zoo();
		System.out.println("\nZoo1:"+zoo1);
		System.out.println("Zoo2:"+zoo2);
		System.out.println("Zoo3:"+zoo3);
		zoo3.setLocation("Berlin");
		zoo1.setLocation("Berlin"); // sets it for zoo1 and zoo2
		System.out.println("\nZoo1:"+zoo1);
		System.out.println("Zoo2:"+zoo2);
		System.out.println("Zoo3:"+zoo3);
		zoo1=new Zoo("SanDiego"); // sets it for zoo1 only
		System.out.println("\nZoo1:"+zoo1);
		System.out.println("Zoo2:"+zoo2);
		System.out.println("Zoo3:"+zoo3);

		zoo1.changeZoo(zoo1, avgVisitors); // passing object reference and primitive
		System.out.println("\n"+zoo1+":"+avgVisitors);
		System.out.println("\ngetNumZoosCreated(): "+Zoo.getNumZoosCreated());
	}
}

