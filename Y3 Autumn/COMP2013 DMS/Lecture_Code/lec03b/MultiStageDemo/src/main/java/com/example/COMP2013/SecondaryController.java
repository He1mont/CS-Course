package com.example.COMP2013;

import javafx.fxml.FXML;
import javafx.scene.control.Label;

import java.io.IOException;

public class SecondaryController {
    @FXML
    private Label welcomeText;

    @FXML
    private void switchToPrimary() throws IOException {
        MultiStageDemoApp.setRoot("primary");
    }
}