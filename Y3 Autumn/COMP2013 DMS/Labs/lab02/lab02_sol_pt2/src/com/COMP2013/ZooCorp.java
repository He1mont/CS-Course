package com.COMP2013;

import java.util.ArrayList;

public class ZooCorp {
	private ArrayList<Zoo> zoos;
	private ArrayList<Employable> personnel;
	
	public ZooCorp(Zoo zoo) {
		zoos=new ArrayList<Zoo>();
		addZoo(zoo);
		personnel=new ArrayList<Employable>();
	}

	public void addZoo(Zoo zoo) {
		zoos.add(zoo);	
	}

	public void addStaff(Employable person){
		personnel.add(person);	
	}
}
