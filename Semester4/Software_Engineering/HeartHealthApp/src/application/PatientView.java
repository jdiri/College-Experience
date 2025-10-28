package application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class PatientView {

    public PatientView(Stage primaryStage) {
        GridPane loginLayout = new GridPane();
        loginLayout.setVgap(10);
        loginLayout.setHgap(10);
        loginLayout.setStyle("-fx-padding: 20;");
        
        TextField patientIDField = new TextField();
        
        loginLayout.add(new Label("Enter Patient ID:"), 0, 0);
        loginLayout.add(patientIDField, 1, 0);
        
        Button loginButton = new Button("Submit");
        loginLayout.add(loginButton, 1, 1);
        
        loginButton.setOnAction(e -> {
            String patientID = patientIDField.getText();
            if (patientID.isEmpty()) {
                showAlert("Error", "Patient ID cannot be empty.");
            } else {
                showPatientDataScene(primaryStage, patientID);
            }
        });

        primaryStage.setScene(new Scene(loginLayout, 400, 200));
    }

    private void showPatientDataScene(Stage primaryStage, String patientID) {
        GridPane dataLayout = new GridPane();
        dataLayout.setVgap(10);
        dataLayout.setHgap(10);
        dataLayout.setStyle("-fx-padding: 20;");
        
        String patientName = getPatientName(patientID);
        Label greetingLabel = new Label("Hello, " + patientName);
        greetingLabel.setStyle("-fx-font-size: 18; -fx-font-weight: bold;");
        
        Label patientIDLabel = new Label("Patient ID: " + patientID);
        String totCAC = getData(patientID, "totCAC");
        String lm = getData(patientID, "lm");
        String lad = getData(patientID, "lad");
        String lcx = getData(patientID, "lcx");
        String rca = getData(patientID, "rca");
        String pda = getData(patientID, "pda");

        if (totCAC.equals("N/A") && lm.equals("N/A") && lad.equals("N/A") && lcx.equals("N/A") && rca.equals("N/A") && pda.equals("N/A")) {
            showAlert("No Data", "CT scan data not available yet.");
        }

        Label totCACLabel = new Label("Total Agatston CAC Score: " + totCAC);
        Label lmLabel = new Label("LM: " + lm);
        Label ladLabel = new Label("LAD: " + lad);
        Label lcxLabel = new Label("LCX: " + lcx);
        Label rcaLabel = new Label("RCA: " + rca);
        Label pdaLabel = new Label("PDA: " + pda);
        
        dataLayout.add(greetingLabel, 0, 0);
        dataLayout.add(patientIDLabel, 0, 1);
        dataLayout.add(totCACLabel, 0, 2);
        dataLayout.add(lmLabel, 0, 3);
        dataLayout.add(ladLabel, 0, 4);
        dataLayout.add(lcxLabel, 0, 5);
        dataLayout.add(rcaLabel, 0, 6);
        dataLayout.add(pdaLabel, 0, 7);
        
        Button backButton = new Button("Back");
        dataLayout.add(backButton, 1, 8);
        
        backButton.setOnAction(e -> {
            new PatientView(primaryStage);
        });

        primaryStage.setScene(new Scene(dataLayout, 400, 400));
    }

    private String getPatientName(String patientID) {
        String fileName = patientID + "_PatientInfo.txt";
        Path filePath = Paths.get(fileName);

        try {
            List<String> lines = Files.readAllLines(filePath);
            String fname = "";
            String lname = "";
            
            for (String line : lines) {
                if (line.startsWith("First Name:")) {
                    fname = line.split(":")[1].trim();  
                }
                if (line.startsWith("Last Name:")) {
                    lname = line.split(":")[1].trim();  
                }
            }
            if(fname + " " + lname != " ") {
            	return fname + " " + lname;
            }
            else
            	return "Unknown Patient";
        } catch (IOException e) {
            e.printStackTrace();
        }

        return "Unknown Patient";  
    }

    private String getData(String patientID, String field) {
        String fileName = patientID + "_CTResults.txt";
        Path filePath = Paths.get(fileName);

        try {
            List<String> lines = Files.readAllLines(filePath);

            for (String line : lines) {
                switch (field) {
                    case "totCAC":
                        if (line.startsWith("Total Agatston CAC Score:")) {
                            return line.split(":")[1].trim(); 
                        }
                        break;
                    case "lm":
                        if (line.startsWith("  LM:")) {
                            return line.split(":")[1].trim();
                        }
                        break;
                    case "lad":
                        if (line.startsWith("  LAD:")) {
                            return line.split(":")[1].trim();
                        }
                        break;
                    case "lcx":
                        if (line.startsWith("  LCX:")) {
                            return line.split(":")[1].trim();
                        }
                        break;
                    case "rca":
                        if (line.startsWith("  RCA:")) {
                            return line.split(":")[1].trim();
                        }
                        break;
                    case "pda":
                        if (line.startsWith("  PDA:")) {
                            return line.split(":")[1].trim();
                        }
                        break;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return "N/A"; 
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
