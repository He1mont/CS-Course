package com.COMP2013;

import java.util.ArrayList;
public class ZooCorp {
    private ArrayList<Zoo> zoos;

    public ZooCorp(Zoo zoo) {
        zoos = new ArrayList<Zoo>();
        addZoo(zoo);
    }
    public void addZoo(Zoo zoo) {
        zoos.add(zoo);
    }
}
