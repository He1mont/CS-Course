package com.COMP2013;

import java.util.ArrayList;

public class Compound {
	private String location;
	private ArrayList<Animal> animals;
	private int compoundID;
	public static int numCompounds;

	public Compound(String location) {
		this.location=location;
		numCompounds++;
		setCompoundID(numCompounds);
		animals=new ArrayList<>();
	}

	public void addAnimal(Animal animal) {
		animals.add(animal);
	}

	public int getCompoundID() {
		return compoundID;
	}

	private void setCompoundID(int compoundID) {
		this.compoundID = compoundID;
	}

	public void printInfo() {
		System.out.println("Compound "+this.getCompoundID()+" located in "+location+" Zoo has "+animals.size()+" animal(s)");
	}
}
