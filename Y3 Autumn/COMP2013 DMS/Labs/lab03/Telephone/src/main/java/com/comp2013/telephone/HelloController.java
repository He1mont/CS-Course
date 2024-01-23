package com.comp2013.telephone;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.Pane;

import java.util.Random;

public class HelloController implements Phone {
    @FXML
    private Button b0;
    @FXML
    private Button b1;
    @FXML
    private Button b2;
    @FXML
    private Button b3;
    @FXML
    private Button b4;
    @FXML
    private Button b5;
    @FXML
    private Button b6;
    @FXML
    private Button b7;
    @FXML
    private Button b8;
    @FXML
    private Button b9;
    @FXML
    private Button call;
    @FXML
    private Button clear;
    @FXML
    private Label label;
    @FXML
    private Pane pane;

    @FXML
    protected void updateLabel(String text) {
        label.setText(text);
    }
    @FXML
    protected void onClickButton0(ActionEvent event) {
        String text = b0.getText();
        updateLabel(label.getText() + text);
    }
    @FXML
    protected void onClickButton1(ActionEvent event) {
        String text = b1.getText();
        updateLabel(label.getText() + text);
    }
    @FXML
    protected void onClickButton2(ActionEvent event) {
        String text = b2.getText();
        updateLabel(label.getText() + text);
    }
    @FXML
    protected void onClickButton3(ActionEvent event) {
        String text = b3.getText();
        updateLabel(label.getText() + text);
    }
    @FXML
    protected void onClickButton4(ActionEvent event) {
        String text = b4.getText();
        updateLabel(label.getText() + text);
    }
    @FXML
    protected void onClickButton5(ActionEvent event) {
        String text = b5.getText();
        updateLabel(label.getText() + text);
    }
    @FXML
    protected void onClickButton6(ActionEvent event) {
        String text = b6.getText();
        updateLabel(label.getText() + text);
    }
    @FXML
    protected void onClickButton7(ActionEvent event) {
        String text = b7.getText();
        updateLabel(label.getText() + text);
    }
    @FXML
    protected void onClickButton8(ActionEvent event) {
        String text = b8.getText();
        updateLabel(label.getText() + text);
    }
    @FXML
    protected void onClickButton9(ActionEvent event) {
        String text = b9.getText();
        updateLabel(label.getText() + text);
    }
    @FXML
    protected void clearLabel(ActionEvent event) {
        updateLabel("");
    }
    @FXML
    @Override
    public void makeCall(String number) {
//        int duration = (new Random()).nextInt((2500) + 1) + 500;
        // fake phone call time
//        try {
//            Thread.sleep(duration);
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }
//        updateLabel("Call Successfully!");
    }
}