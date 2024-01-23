package com.comp2013.bindingdemo;

import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Slider;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        stage.setTitle("Welcome to the PropertyBinding Demo!");
        Slider slider = new Slider(0, 100, 10);
        Text text = new Text(String.valueOf((int)slider.getValue()));
        text.setFont(Font.font("Verdana", 50));
        StackPane.setAlignment(slider, Pos.BOTTOM_LEFT);
        slider.valueProperty().addListener(new ChangeListener<Number>() {
            @Override
            public void changed(ObservableValue<? extends Number> observableValue, Number number, Number t1) {
                text.setText(String.valueOf((int)slider.getValue()));
            }
        });
        StackPane root = new StackPane();
        root.getChildren().addAll(slider,text);
        stage.setScene(new Scene(root, 500, 500));
        stage.show();

    }

    public static void main(String[] args) {
        launch();
    }
}

