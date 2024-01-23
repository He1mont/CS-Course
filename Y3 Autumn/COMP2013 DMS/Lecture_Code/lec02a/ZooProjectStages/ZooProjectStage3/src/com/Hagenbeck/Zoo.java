package com.Hagenbeck;

public class Zoo {
	
	private String location;
	
	public Zoo() {
		this("Unknown");
	}

	public Zoo(String location) {
		//this.location=location;
		this.setLocation(location);
		System.out.println("\nConstructing "+this);
	}

	public void doSomething() {
		Manager manager=new Manager();
	}

	public String getLocation() {
		return location;
	}

	public void setLocation(String location) {
		this.location = location;
	}
	@Override
	public String toString() {
		return getClass().getSimpleName()+"("+this.getLocation()+")";		
	}	
}
