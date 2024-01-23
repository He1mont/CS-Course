package com.example.COMP2013;

import javafx.fxml.FXML;

import java.io.IOException;

public class PrimaryController {

    @FXML
    private void switchToSecondary() throws IOException {
        MultiStageDemoApp.setRoot("secondary");
    }
}
