package com.COMP2013;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

public class BikeModel {
    private ObservableList<Bike> bikes = FXCollections.observableArrayList();
    public BikeModel() {
        // Initialize the model with some sample data
        bikes.add(new Bike("Mountain Bike", "Blue"));
        bikes.add(new Bike("Road Bike", "Red"));
        bikes.add(new Bike("City Bike", "Green"));
    }
    public ObservableList<Bike> getBikes() {
        return bikes;
    }

    public void addBike(Bike bike) {
        bikes.add(bike);
    }

}
