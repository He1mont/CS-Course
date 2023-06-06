class VehicleDemo{ //pasted code from chapter4 of text book
	public static void main(String[] args) {

		/*
	    Vehicle van = new Vehicle();
	    Vehicle car = new Vehicle();
	    
	    car.mpg = 12;
	    car.fuelCap = 14;
	    System.out.println("car's mpg: " + car.mpg);
	    System.out.println("car's fuelCap: " + car.fuelCap);
	    System.out.println("------------------------------");

	    van.mpg = 21;
	    van.fuelCap = 16;
	    System.out.println("van's mpg: " + van.mpg);
	    System.out.println("van's fuelCap: " + van.fuelCap);
	    System.out.println("------------------------------");

	    car.mpg = van.mpg;
	    System.out.println("car's mpg: " + car.mpg);
	    car.mpg = 10;
	    System.out.println("van's mpg: " + van.mpg);
	    System.out.println("------------------------------");

	    van = car;		// pass by reference
	    van.mpg = 20;
	    System.out.println("car's mpg: " + car.mpg);
		
		car.range();
		System.out.println("range: " + car.ret_range());
		System.out.println("fule needed for 750 miles: " + car.fuelNeeded(750));
		System.out.println("------------------------------");
		*/

		// Use Constructor with Parameters
		
	    Vehicle car = new Vehicle(4,14,12);
	    Vehicle van = new Vehicle(7,16,21);	    
	       
	    System.out.println("car's mpg: " + car.mpg);
	    System.out.println("car's fuelCap: " + car.fuelCap);
	    System.out.println("------------------------------");

	    System.out.println("van's mpg: " + van.mpg);
	    System.out.println("van's fuelCap: " + van.fuelCap);
	    System.out.println("------------------------------");
	    
		
	}
}
