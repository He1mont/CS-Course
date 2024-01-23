package com.Hagenbeck;

public class Manager {
	
	private Zoo zoo;
	
	public Manager(Zoo zoo) {
		this.setZoo(zoo);
		System.out.println("Constructing "+this);
	}
	
	public void sayHello() {
		//boolean returnEarly=false;
		boolean returnEarly=true;
		if(returnEarly) {
			System.out.println(this+":returnEarly");
			return;
		}
		System.out.println(this+":returnLate");
	}
	
	public Zoo getZoo() {
		return zoo;
	}

	public void setZoo(Zoo zoo) {
		this.zoo = zoo;
	}

	public String toString() {
		return getClass().getSimpleName()+"("+zoo.getLocation()+")";		
	}
}
