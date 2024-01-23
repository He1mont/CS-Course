package com.COMP2013;

public abstract class Employee implements Employable {
    private int id;
    private String name;
    private int salary;
    public Employee(String name){
        setEmployeeName(name);
        setSalary(1000);
    }
    @Override
    public void setEmployeeID(int num) {
        id = num;
    }
    @Override
    public int getEmployeeID() {
        return id;
    }
    @Override
    public void setEmployeeName(String name) {
        this.name = name;
    }
    @Override
    public String getEmployeeName() {
        return name;
    }
    @Override
    public int getSalary() {
        return salary;
    }
    @Override
    public void setSalary(int salary) {
        this.salary = salary;
    }
    @Override
    public double calculateChrismasBonus() {
        return 0;
    }
}
