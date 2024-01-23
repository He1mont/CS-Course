module com.example.multistagedemo {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.COMP2013 to javafx.fxml;
    exports com.example.COMP2013;
}