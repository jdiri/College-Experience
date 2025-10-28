package application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.time.LocalDate;

public class ReceptionistView {

    public ReceptionistView(Stage primaryStage, Scene mainView) {
        GridPane layout = new GridPane();
        layout.setVgap(10);
        layout.setHgap(10);
        layout.setStyle("-fx-padding: 20;");
        
        TextField fNameField = new TextField();
        TextField lNameField = new TextField();
        TextField emailField = new TextField();
        TextField phoneField = new TextField();
        TextField historyField = new TextField();
        TextField insuranceField = new TextField();
        
        layout.add(new Label("First Name:"), 0, 0);
        layout.add(fNameField, 1, 0);
        layout.add(new Label("Last Name:"), 0, 1);
        layout.add(lNameField, 1, 1);
        layout.add(new Label("Email:"), 0, 2);
        layout.add(emailField, 1, 2);
        layout.add(new Label("Phone Number:"), 0, 3);
        layout.add(phoneField, 1, 3);
        layout.add(new Label("Health History:"), 0, 4);
        layout.add(historyField, 1, 4);
        layout.add(new Label("Insurance ID:"), 0, 5);
        layout.add(insuranceField, 1, 5);
        
        Button saveButton = new Button("Save and Schedule");
        layout.add(saveButton, 1, 6);
        
        saveButton.setOnAction(e -> {
            if (fNameField.getText().isEmpty() || lNameField.getText().isEmpty() || 
			        emailField.getText().isEmpty() || phoneField.getText().isEmpty() || 
			        historyField.getText().isEmpty() || insuranceField.getText().isEmpty()) {
			        showAlert(Alert.AlertType.ERROR, "Validation Error", "All fields must be filled!");
			    } else {
			        LocalDate selectedDate = promptForDate(primaryStage);
			        if (selectedDate != null) {
			        	String patientID = generatePatientID();
			            savePatientData(patientID,fNameField.getText(), lNameField.getText(), emailField.getText(),
			                            phoneField.getText(), historyField.getText(), insuranceField.getText(), 
			                            selectedDate);
			            showAlert(Alert.AlertType.INFORMATION, "Success", "Patient data saved successfully!\nPatient ID: " + patientID);
			            primaryStage.setScene(mainView);
			        }
			    }
        });
        
        primaryStage.setScene(new Scene(layout, 500, 400));
    }
    
    private LocalDate promptForDate(Stage owner) {
        DatePicker datePicker = new DatePicker();
        Alert dateDialog = new Alert(Alert.AlertType.CONFIRMATION);
        dateDialog.setTitle("Schedule Exam Date");
        dateDialog.setHeaderText("Please select a date for the exam.");
        dateDialog.initOwner(owner);

        dateDialog.getDialogPane().setContent(datePicker);

        dateDialog.showAndWait();

        return datePicker.getValue(); 
    }
    
    private void savePatientData(String patientID, String fName, String lName, String email, String phone, String history, String insurance, LocalDate examDate) {
    	String fileName = patientID + "_PatientInfo.txt";

    	String content = "Patient ID: " + patientID + "\n" +
    			"First Name: " + fName + "\n" +
    			"Last Name: " + lName + "\n" +
    			"Email: " + email + "\n" +
    			"Phone Number: " + phone + "\n" +
    			"Health History: " + history + "\n" +
    			"Insurance ID: " + insurance + "\n" +
    			"Exam Date: " + examDate + "\n";

    	try {
    		Files.write(Paths.get(fileName), content.getBytes());
    	} catch (IOException ex) {
    		showAlert(Alert.AlertType.ERROR, "Error", "Failed to save patient data!");
    	}
    }
    
    private String generatePatientID() {
        return String.format("%05d", (int) (Math.random() * 100000));
    }
    
    private void showAlert(Alert.AlertType type, String title, String message) {
        Alert alert = new Alert(type);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
