class VehicleDemo{ //pasted code from chapter4 of text book
	public static void main(String[] args) {

	    Vehicle car = new Vehicle(4,14,12);

	    // car.mpg = 20;	// fail, since mpg is private

		// 通过getMpg函数来访问Vehicle文件里的mpg值
	    System.out.println("car's mpg: " + car.getMpg());

	    // System.out.println("car's fuelCap: " + car.fuelCap);
	    System.out.println("------------------------------");
		
	}
}
