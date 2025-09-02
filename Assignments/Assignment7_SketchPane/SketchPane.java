// Assignment #7, CSE205, Arizona State University 
// Name: John Diri
// StudentID: 1221905451
// Lecture time: 11:15-12:05
// Description: creates a pane where you can choose between shapes and draw on the pane

import javafx.scene.layout.*;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.Shape;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.paint.Color;
import javafx.geometry.Pos;

import java.util.ArrayList;

import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;


public class SketchPane extends BorderPane {
	
	//Task 1: Declare all instance variables listed in UML diagram
	private ArrayList<Shape> shapeList;
	private ArrayList<Shape> tempList;
	private Button undoButton;
	private Button eraseButton;
	private Label fillColorLabel;
	private Label strokeColorLabel;
	private Label strokeWidthLabel;
	private ComboBox<String> fillColorCombo;
	private ComboBox<String> strokeColorCombo;
	private ComboBox<String> strokeWidthCombo;
	private RadioButton radioButtonLine;
	private RadioButton radioButtonRectangle;
	private RadioButton radioButtonCircle;
	private Pane sketchCanvas;
	private Color[] colors;
	private String[] strokeWidth;
	private String[] colorLabels;
	private Color currentStrokeColor;
	private Color currentFillColor;
	private int currentStrokeWidth;
	private Line line;
	private Circle circle;
	private Rectangle rectangle;
	private double x1;
	private double y1;
	//Task 2: Implement the constructor
	
	//declaring final default color
	final Color black = Color.BLACK;
	//final Color white = Color.WHITE;
	public SketchPane() {
		shapeList = new ArrayList<Shape>();
		tempList = new ArrayList<>();
		
		//shapes
		radioButtonLine = new RadioButton("Line");
		radioButtonCircle = new RadioButton("Circle");
		radioButtonRectangle = new RadioButton("Rectangle");
		ToggleGroup t = new ToggleGroup();
		radioButtonLine.setToggleGroup(t);
		radioButtonCircle.setToggleGroup(t);
		radioButtonRectangle.setToggleGroup(t);
		t.selectToggle(radioButtonLine);
		
		// Colors, labels, and stroke widths that are available to the user
		colors = new Color[] {Color.BLACK, Color.GREY, Color.YELLOW, Color.GOLD, Color.ORANGE, Color.DARKRED, Color.PURPLE, Color.HOTPINK, Color.TEAL, Color.DEEPSKYBLUE, Color.LIME} ;
        colorLabels = new String[] {"black", "grey", "yellow", "gold", "orange", "dark red", "purple", "hot pink", "teal", "deep sky blue", "lime"};
        fillColorLabel = new Label("Fill Color:");
        strokeColorLabel = new Label("Stroke Color:");
        strokeWidthLabel = new Label("Stroke Width:");
        strokeWidth = new String[] {"1", "3", "5", "7", "9", "11", "13"};  
        
        //comboBoxes
      	fillColorCombo = new ComboBox<String>();
      	strokeColorCombo = new ComboBox<String>();
      	strokeWidthCombo = new ComboBox<String>();
      	currentStrokeColor = black;
      	currentFillColor = black;
      	currentStrokeWidth = 1;
      	strokeWidthCombo.setValue("1");
      	strokeColorCombo.setValue("black");
      	fillColorCombo.setValue("black");
      	fillColorCombo.getItems().addAll(colorLabels);
      	strokeColorCombo.getItems().addAll(colorLabels);
      	strokeWidthCombo.getItems().addAll(strokeWidth);
      	
      	
      	
        //set buttons/combo/radio
        undoButton = new Button("Undo");
        eraseButton = new Button("Erase");
        eraseButton.setOnAction(new ButtonHandler());
        undoButton.setOnAction(new ButtonHandler());
        fillColorCombo.setOnAction(new ColorHandler());
        strokeColorCombo.setOnAction(new ColorHandler());
        strokeWidthCombo.setOnAction(new WidthHandler());
        
        //setting background color
        sketchCanvas = new Pane();
        sketchCanvas.setStyle("-fx-background-color: ffffff");//CSS!!
        //sketchCanvas.getChildren().addAll(shapeList);
        setCenter(sketchCanvas);
        sketchCanvas.addEventHandler(MouseEvent.ANY, new MouseHandler());
        
        //hbox for comboboxes
        HBox comboHolder = new HBox();
        comboHolder.setSpacing(20);
        comboHolder.setAlignment(Pos.CENTER);
        comboHolder.setMinSize(20, 40);
        comboHolder.setStyle("-fx-background-color: d3d3d3");
        comboHolder.getChildren().addAll(fillColorLabel,fillColorCombo,strokeWidthLabel,strokeWidthCombo,strokeColorLabel,strokeColorCombo);
        setTop(comboHolder);
        
        //hbox for radioboxes
        HBox radioHolder = new HBox();
        radioHolder.setSpacing(20);
        radioHolder.setAlignment(Pos.CENTER);
        radioHolder.setMinSize(20, 40);
        radioHolder.setStyle("-fx-background-color: LIGHTGREY;");
        radioHolder.getChildren().addAll(radioButtonLine,radioButtonRectangle,radioButtonCircle,undoButton,eraseButton);  
        setBottom(radioHolder);
	}

	private class MouseHandler implements EventHandler<MouseEvent> {
		@Override
		public void handle(MouseEvent event) {
			// TASK 3: Implement the mouse handler for Circle and Line
			// Rectange Example given!
			if (radioButtonRectangle.isSelected()) {
				//Mouse is pressed
				if (event.getEventType() == MouseEvent.MOUSE_PRESSED) {
					x1 = event.getX();
					y1 = event.getY();
					rectangle = new Rectangle();
					rectangle.setX(x1);
					rectangle.setY(y1);
					shapeList.add(rectangle);
					rectangle.setFill(Color.WHITE);
					rectangle.setStroke(black);	
					sketchCanvas.getChildren().add(rectangle);
				}
				//Mouse is dragged
				else if (event.getEventType() == MouseEvent.MOUSE_DRAGGED) {
					if (event.getX() - x1 <0) 
						rectangle.setX(event.getX());
					if (event.getY() - y1 <0) 
						rectangle.setY(event.getY());
					rectangle.setWidth(Math.abs(event.getX() - x1));
					rectangle.setHeight(Math.abs(event.getY() - y1));

				}
				//Mouse is released
				else if (event.getEventType() == MouseEvent.MOUSE_RELEASED) {
					rectangle.setFill(currentFillColor);
					rectangle.setStroke(currentStrokeColor);
					rectangle.setStrokeWidth(currentStrokeWidth);
				}
			}
			
			//radiobutton circle
			else if(radioButtonCircle.isSelected()) {
				if (event.getEventType() == MouseEvent.MOUSE_PRESSED) {
					x1 = event.getX();
					y1 = event.getY();
					circle = new Circle();
					circle.setCenterX(x1);
					circle.setCenterY(y1);
					//circle.setRadius(getDistance(event.getX(),circle.getCenterX(),event.getY(),circle.getCenterY()));
					shapeList.add(circle);
					circle.setFill(Color.WHITE);
					circle.setStroke(black);
					sketchCanvas.getChildren().add(circle);					
				}
				else if(event.getEventType() == MouseEvent.MOUSE_DRAGGED) {
					//circle.setFill(Color.WHITE);
					//circle.setStroke(black);
					/*PointerInfo cursor = MouseInfo.getPointerInfo();
					Point finder = cursor.getLocation();				
					//x1 = finder();
					//y1 = finder.getY();*/
					circle.setRadius(getDistance(x1,y1,event.getX(),event.getY()));
					//sketchCanvas.getChildren().add(circle);
					
				}
				else if(event.getEventType() == MouseEvent.MOUSE_RELEASED) {
					//Circle circle = new Circle();
					//circle.setCenterX(event.getX());
					//circle.setCenterY(event.getY());
					circle.setFill(currentFillColor);
					circle.setStroke(currentStrokeColor);
					circle.setStrokeWidth(currentStrokeWidth);
				}
			}
			
			//radiobutton line
			else if (event.getEventType() == MouseEvent.MOUSE_PRESSED) {
				x1 = event.getX();
				y1 = event.getY();
				line = new Line();
				line.setStartX(x1);
				line.setStartY(y1);
				line.setEndX(x1);
				line.setEndY(y1);
				shapeList.add(line);
				sketchCanvas.getChildren().add(line); 
			}
			else if(event.getEventType() == MouseEvent.MOUSE_DRAGGED) {
				line.setEndX(event.getX());
				line.setEndY(event.getY());
			}
			else if(event.getEventType() == MouseEvent.MOUSE_RELEASED) {
				line.setFill(currentFillColor);
				line.setStroke(currentStrokeColor);
				line.setStrokeWidth(currentStrokeWidth);
			}
		}
	}
		
	private class ButtonHandler implements EventHandler<ActionEvent> {
		@Override
		public void handle(ActionEvent event) {
			// TASK 4: Implement the button handler
				if(event.getTarget() == eraseButton) {
					for(int i = 0; i < shapeList.size();i++) {
						tempList.add(shapeList.get(i));
					}
					sketchCanvas.getChildren().clear();
					shapeList.clear();
				}
				else if(event.getTarget() == undoButton) {
					if(shapeList.size() == 0) {
						sketchCanvas.getChildren().addAll(tempList);
						for(int i = 0; i < tempList.size();i++) {
							shapeList.add(tempList.get(i));
						}
						tempList.clear();						
					}
					else {
						sketchCanvas.getChildren().remove(shapeList.size()-1);
						shapeList.remove(shapeList.size()-1);
					}
				}
		}
	}

	private class ColorHandler implements EventHandler<ActionEvent> {
		@Override
		public void handle(ActionEvent event) {
			// TASK 5: Implement the color handler
			if(event.getSource() == fillColorCombo) {
				currentFillColor = colors[fillColorCombo.getSelectionModel().getSelectedIndex()];
			}
			if(event.getSource() == strokeColorCombo) {
				currentStrokeColor = colors[strokeColorCombo.getSelectionModel().getSelectedIndex()];
			}
		}
	}
	
	private class WidthHandler implements EventHandler<ActionEvent> {
		@Override
		public void handle(ActionEvent event){
			// TASK 6: Implement the stroke width handler
			if(strokeWidthCombo.getSelectionModel().getSelectedItem() != null) {
				currentStrokeWidth = Integer.parseInt(strokeWidth[strokeWidthCombo.getSelectionModel().getSelectedIndex()]);
			}
		}
	}
	
		
	// Get the Euclidean distance between (x1,y1) and (x2,y2)
    private double getDistance(double x1, double y1, double x2, double y2)  {
        return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    }

	}