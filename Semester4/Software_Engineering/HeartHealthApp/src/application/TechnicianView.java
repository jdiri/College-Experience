package application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

import java.io.IOException;

public class TechnicianView {

    public TechnicianView(Stage primaryStage, Scene mainView) {
        GridPane layout = new GridPane();
        layout.setVgap(10);
        layout.setHgap(10);
        layout.setStyle("-fx-padding: 20;");
        
        TextField patientIDField = new TextField();
        TextField totCACField = new TextField();
        TextField lmField = new TextField();
        TextField ladField = new TextField();
        TextField lcxField = new TextField();
        TextField rcaField = new TextField();
        TextField pdaField = new TextField();
        
        layout.add(new Label("Patient ID:"), 0, 0);
        layout.add(patientIDField, 1, 0);
        layout.add(new Label("The Total Agatston CAC Score:"), 0, 1);
        layout.add(totCACField, 1, 1);
        
        layout.add(new Label("Vessel level Agatston CAC score"), 0, 2, 2, 1);
        layout.add(new Label("LM:"), 0, 3);
        layout.add(lmField, 1, 3);
        layout.add(new Label("LAD:"), 0, 4);
        layout.add(ladField, 1, 4);
        layout.add(new Label("LCX:"), 0, 5);
        layout.add(lcxField, 1, 5);
        layout.add(new Label("RCA:"), 0, 6);
        layout.add(rcaField, 1, 6);
        layout.add(new Label("PDA:"), 0, 7);
        layout.add(pdaField, 1, 7);
        
        Button saveButton = new Button("Save Results");
        layout.add(saveButton, 2, 7);
        
        saveButton.setOnAction(e -> {
            try {
                String patientID = patientIDField.getText();
                FileManager.saveCTScanData(
                        patientID,
                        totCACField.getText(),
                        lmField.getText(),
                        ladField.getText(),
                        lcxField.getText(),
                        rcaField.getText(),
                        pdaField.getText()
                );
                showAlert("Success", "CT scan data saved successfully for Patient ID: " + patientID);
            } catch (IOException ex) {
                showAlert("Error", "Failed to save CT scan data.");
            }
        });
        
        primaryStage.setScene(new Scene(layout, 500, 400));
    }
    
    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
