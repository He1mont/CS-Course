package com.COMP2013;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;
public class BikeController {
    @FXML
    private ListView<Bike> bikeListView;
    @FXML
    private TextField bikeNameField;
    @FXML
    private TextField bikeColorField;
    private BikeModel model;

    public void initialize() {
        // Set up the ListView to display the list of bikes
        model = new BikeModel();
        ObservableList<Bike> bikes = model.getBikes();
        bikeListView.setItems(bikes);
    }

    @FXML
    private void onAddBikeBtnClick() {
        String name = bikeNameField.getText();
        String color = bikeColorField.getText();
        Bike newBike = new Bike(name, color);
        model.addBike(newBike);
    }

    @FXML
    private void viewAllTypes(){

    }

    @FXML
    private void onExitClick(){
        System.exit(0);
    }


}