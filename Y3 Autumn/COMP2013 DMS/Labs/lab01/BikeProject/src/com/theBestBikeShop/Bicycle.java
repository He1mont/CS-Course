package com.theBestBikeShop;

public class Bicycle {
	private int gear;
	private int speed;
	private boolean light = false;

	Bicycle(int gear, int speed) {
		this.gear = gear;
		this.speed = speed;
	}

	public void setGear(int newValue) {
		gear = newValue;
	}

	public void applyBrake(int decrement) {
		speed -= decrement;
	}

	public void speedUp(int increment) {
		speed += increment;
	}

	public void switchLightStatus() {
		light = !light;
	}
	public void currentState() {
		System.out.println("The current gear is: " + gear);
		System.out.println("The current speed is: " + speed);
		if (light)
			System.out.println("The current light is on");
		else
			System.out.println("The current light is off");
	}
}
