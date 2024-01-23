package com.COMP2013;

public class Bike {
    private String type;
    private String color;

    public Bike(String type, String color){
        this.type=type;
        this.color=color;
    }

    public String getType() {
        return type;
    }
    public void setType(String type) {
        this.type = type;
    }
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }
}
