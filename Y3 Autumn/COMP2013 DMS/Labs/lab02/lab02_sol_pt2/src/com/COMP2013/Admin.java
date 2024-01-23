package com.COMP2013;

public class Admin extends Employee {

	public Admin(String name) {
		super(name);
	}

	@Override
	public int calculateChristmasBonus() {
		return (int) (getSalary()*0.08);
	}

}
