module com.comp2013.hellowjavafxapp {
    requires javafx.controls;
    requires javafx.graphics;
    requires javafx.fxml;

    opens com.comp2013.hellowjavafxapp to javafx.fxml;
    exports com.comp2013.hellowjavafxapp;
}