module com.comp2013.telephone {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.graphics;
                            
    opens com.comp2013.telephone to javafx.fxml;
    exports com.comp2013.telephone;
}