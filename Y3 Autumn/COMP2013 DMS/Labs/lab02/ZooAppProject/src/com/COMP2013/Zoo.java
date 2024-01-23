package com.COMP2013;

import java.util.ArrayList;

public class Zoo {
    private static int numZoo = 0;
    private String location;
    private int numCompound;
    private int zooID;
    private ArrayList<Compound> compounds;

    public Zoo() {
        this("unknown", 30);
    }
    public Zoo(String location, int numCompound) {
        numZoo += 1;
        setZooID(numZoo);
        this.setLocation(location);
        this.setNumCompound(numCompound);
        compounds = new ArrayList<Compound>();
        for (int i = 0; i < numCompound; i++) {
            addCompound(new Compound());
        }
    }
    public String getLocation() {
        return location;
    }
    public void setLocation(String location) {
        this.location = location;
    }
    public int getNumCompound() {
        return numCompound;
    }
    public void setNumCompound(int num) {
        numCompound = num;
    }
    public void buildNewCompound() {
        numCompound += 1;
    }
    public static int getNumZoo() {
        return numZoo;
    }
    public int getZooID() {
        return zooID;
    }
    public void setZooID(int num) {
        zooID = num;
    }
    private void addCompound(Compound compound) {
        compounds.add(compound);
    }
    public String printInfo() {
        return "The location is " + location + " and the number of compounds is " + numCompound;

    }
}
