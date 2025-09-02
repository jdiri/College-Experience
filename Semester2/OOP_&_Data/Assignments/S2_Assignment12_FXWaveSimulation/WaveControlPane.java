// Assignment 12: Arizona State University CSE205
//         Name: John Diri
//    StudentID: 1221905451
//      Lecture: 11:15-12:05
//  Description: controls what you can do with the graph
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.TilePane;
import javafx.scene.layout.VBox;
import javafx.scene.control.Button;
import javafx.scene.control.ColorPicker;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.paint.Color;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.geometry.Pos;


public class WaveControlPane extends Pane {

	private WaveDisplayPane wavePane;
	private int width, height;
	private Color color;
	private ColorPicker picker;

	// ******************************************************************
	// Task #2a: add instance variables for sliders, buttons, and labels
	// ******************************************************************
	
	Button start;
	Button stop;
	Button clear;
	Button suprise;
	Slider speedSlider;
	Slider widthSlider;
	Slider heightSlider;
	Label speedLabel;
	Label widthLabel;
	Label heightLabel;

	// constructor to create all components, set their handler/listener,
	// and arrange them using layout panes.
	public WaveControlPane(int h, int w, Color initialColor) {
		this.color = initialColor;
		this.width = (int) (h * 0.68);
		this.height = w - 10;

		// creates a pane to display waves with the specified color
		wavePane = new WaveDisplayPane(width, color);
		wavePane.setMinSize(width, height);
		wavePane.setMaxSize(width, height);

		// create a color picker with the specified initial color
		picker = new ColorPicker(color);
		picker.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);

		// ************************************************************************
		// Task #2b: create 4 buttons and resize them to the width of the VBox pane,
		// then add them to the VBox buttonPane instantiated below.
		// *************************************************************************

		start = new Button("Start"); start.setMaxWidth(Double.MAX_VALUE);
		stop = new Button("Stop"); stop.setMaxWidth(Double.MAX_VALUE);
		clear = new Button("Clear"); clear.setMaxWidth(Double.MAX_VALUE);
		suprise = new Button("Suprise!"); suprise.setMaxWidth(Double.MAX_VALUE);
		


		VBox buttonPane = new VBox(start,stop,clear,suprise,picker);
		
		buttonPane.setPrefSize(100, 100);
		buttonPane.setAlignment(Pos.CENTER);

		
		// ************************************************************************
		// Task #2c: create 3 sliders and 3 labels and add them to the VBox panes
		// instantiated below. 
		// *************************************************************************
		
		speedLabel = new Label("Speed");
		speedSlider = new Slider(5,100,20);
		speedSlider.setMajorTickUnit(10);
		speedSlider.setMinorTickCount(5);
		speedSlider.setShowTickMarks(true);
		speedSlider.setShowTickLabels(true);
		speedSlider.setOrientation(Orientation.VERTICAL);
		widthLabel = new Label("Width");
		widthSlider = new Slider(5,100,50);
		widthSlider.setMajorTickUnit(10);
		widthSlider.setMinorTickCount(5);
		widthSlider.setShowTickMarks(true);
		widthSlider.setShowTickLabels(true);
		widthSlider.setOrientation(Orientation.VERTICAL);
		heightLabel = new Label("Height");
		heightSlider = new Slider(5,100,100);
		heightSlider.setMajorTickUnit(10);
		heightSlider.setMinorTickCount(5);
		heightSlider.setShowTickMarks(true);
		heightSlider.setShowTickLabels(true);
		heightSlider.setOrientation(Orientation.VERTICAL);


		VBox speedSliderPane = new VBox(speedLabel,speedSlider);
		VBox waveLengthSliderPane = new VBox(widthLabel,widthSlider);
		VBox waveAmplitudeSliderPane = new VBox(heightLabel,heightSlider);

		TilePane sliderPane = new TilePane();
		sliderPane.setPrefColumns(3);
		sliderPane.setPadding(new Insets(5, 5, 5, 5));
		sliderPane.setAlignment(Pos.CENTER);
		sliderPane.getChildren().addAll(speedSliderPane, waveLengthSliderPane, waveAmplitudeSliderPane);

		HBox controls = new HBox(buttonPane, sliderPane);
		controls.setAlignment(Pos.CENTER);

		BorderPane controlsAndWaves = new BorderPane();
		controlsAndWaves.setLeft(controls);
		controlsAndWaves.setCenter(wavePane);

		this.getChildren().add(controlsAndWaves);

		// ************************************************************************
		// Task #2d: Register the buttons, sliders, and color picker with the
		// appropriate handler object 
		// *************************************************************************

		//buttons
		start.setOnAction(new ActionHandler());
		stop.setOnAction(new ActionHandler());
		clear.setOnAction(new ActionHandler());
		suprise.setOnAction(new ActionHandler());

		//color picker
		picker.setOnAction(new colorHandler());

		//sliders
		heightSlider.valueProperty().addListener(new HeightHandler());
		widthSlider.valueProperty().addListener(new WidthHandler());
		speedSlider.valueProperty().addListener(new SpeedHandler());
	}

	// ************************************************************************
	// Task #3: Implement event handlers for the four buttons (task #3a), 
	// the color picker (task #3b), the speed slider (task #3c), and the
	// sliders for wave amplitude and legth (tasks #3d, #3e)
	// *************************************************************************
	
	private class ActionHandler implements EventHandler<ActionEvent> {
		public void handle (ActionEvent e) {
			if(e.getSource() == start) {
				wavePane.resume();
			}
			if(e.getSource() == stop) {
				wavePane.suspend();
			}
			if(e.getSource() == clear) {
				wavePane.clear();
				wavePane.suspend();
			}
			if(e.getSource() == suprise) {
				int speed;
				double r,g,b;
				wavePane.suspend();
				height = (int)(Math.random()*101) + 5;
				wavePane.setWaveAmp(height);
				heightSlider.adjustValue(height);
				width = (int)(Math.random()*101) + 5;
				wavePane.setWaveLength(width);
				widthSlider.adjustValue(width);
				speed = (int)(Math.random()*101) + 5;
				wavePane.setRate(speed);
				speedSlider.adjustValue(speed);
				r = Math.random();
				g = Math.random();
				b = Math.random();
				color = new Color(r, g, b, 1);
				picker.setValue(color);
				wavePane.changeColor(color);
				wavePane.resume();
			}
		}
	}
	
	
	private class SpeedHandler implements ChangeListener<Number> {
		@Override
		public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue){
			// TODO Auto-generated method stub
				int speed = newValue.intValue();
				wavePane.setRate(speed);			
		}
	}
	
	private class HeightHandler implements ChangeListener<Number> {
		public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {
			height = newValue.intValue();
			wavePane.setWaveAmp(height);
		}
	}
	
	private class WidthHandler implements ChangeListener<Number> {
		public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {
			width = newValue.intValue();
			wavePane.setWaveLength(width);
		}
	}
	
	private class colorHandler implements EventHandler{
		@Override
		public void handle(Event e) {
			// TODO Auto-generated method stub
				color = picker.getValue();
				wavePane.changeColor(color);
		}
		
	}
}


