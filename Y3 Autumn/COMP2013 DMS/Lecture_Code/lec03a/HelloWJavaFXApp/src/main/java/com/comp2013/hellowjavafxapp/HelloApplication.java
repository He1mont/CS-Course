package com.comp2013.hellowjavafxapp;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import java.io.IOException;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        stage.setTitle("Hello Java FX");
        Button button1 = new Button("Close App");
        button1.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent actionEvent) {
                System.out.println("Bye Bye!");
                System.exit(0);
            }
        });
        StackPane root = new StackPane();
        root.getChildren().add(button1);
        stage.setScene(new Scene(root, 600, 600));
        stage.show();
    }
    public static void main(String[] args) {
        launch();
    }
}