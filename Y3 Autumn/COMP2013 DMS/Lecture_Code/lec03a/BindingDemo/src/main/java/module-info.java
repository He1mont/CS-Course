module com.comp2013.bindingdemo {
    requires javafx.controls;
    requires javafx.graphics;
    requires javafx.fxml;


    opens com.comp2013.bindingdemo to javafx.fxml;
    exports com.comp2013.bindingdemo;
}