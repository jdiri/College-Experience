package application;
	
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.control.Button;
import javafx.scene.control.Label;


public class Main extends Application {
	@Override
	public void start(Stage primaryStage) {
		try {
			StackPane stackPane = new StackPane();
			
			Rectangle outline = new Rectangle(400,400);
			outline.setFill(Color.CORNSILK);
			outline.setStroke(Color.BLACK);
			
			VBox mainMenu = new VBox(10);	
	        mainMenu.setStyle("-fx-padding: 20; -fx-alignment: center;");
	        
	        Label label = new Label("Welcome to Heart Health Imaging and Recording System");
	        
	        Button receptionistButton = new Button("Patient Intake");
	        receptionistButton.setPrefSize(170, 20);
	        Button technicianButton = new Button("CT Scan Tech. View");
	        technicianButton.setPrefSize(170, 20);
	        Button patientButton = new Button("Patient View");
	        patientButton.setPrefSize(170, 20);
	        
	        Scene mainView = new Scene(stackPane, 1000, 1000);
	        
	        receptionistButton.setOnAction(e -> new ReceptionistView(primaryStage,mainView));
	        technicianButton.setOnAction(e -> new TechnicianView(primaryStage,mainView));
	        patientButton.setOnAction(e -> new PatientView(primaryStage));
	        
	        mainMenu.getChildren().addAll(label, receptionistButton, technicianButton, patientButton);
	        stackPane.getChildren().addAll(outline,mainMenu);
	        
	        primaryStage.setScene(mainView);
	        primaryStage.setTitle("Heart Health Imaging System");
	        primaryStage.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		launch(args);
	}
}
