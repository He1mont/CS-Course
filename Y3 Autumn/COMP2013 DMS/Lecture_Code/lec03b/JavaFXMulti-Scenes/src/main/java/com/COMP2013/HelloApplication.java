package com.COMP2013;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.IOException;


public class HelloApplication extends Application {
    private Scene scene1, scene2;

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Java FX Multiple Scenes");
        Label label1= new Label("Primary View");
        Button button1= new Button("Switch to Secondary View");
        button1.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent actionEvent) {
                primaryStage.setScene(scene2);
            }
        });
        VBox layout1 = new VBox(20);
        layout1.setAlignment(Pos.CENTER);
        layout1.getChildren().addAll(label1, button1);
        scene1= new Scene(layout1, 300, 400);
        Label label2= new Label("Secondary View");
        Button button2= new Button("Switch to Primary View");
        button2.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent actionEvent) {
                primaryStage.setScene(scene1);
            }
        });
        VBox layout2= new VBox(20);
        layout2.setAlignment(Pos.CENTER);
        layout2.getChildren().addAll(label2, button2);
        scene2= new Scene(layout2,400,300);
        primaryStage.setScene(scene1);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}