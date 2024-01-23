package com.COMP2013;

public class Admin extends Employee {
    public Admin(String name) {
        super(name);
    }
    @Override
    public double calculateChrismasBonus() {
        return getSalary()*0.08;
    }
}
