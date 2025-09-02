import javafx.util.Duration;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

// Assignment 12: Arizona State University CSE205
//         Name: john diri
//    StudentID: 1221905451
//      Lecture: 11:15-12:05
//  Description: graphs the sin/cos graph with an animation


public class WaveDisplayPane extends Pane {

	// Task #1: immplement instance variables, constructor, and methods
	// as outlned in the UML diagram and assignment description
	private Timeline timeLine;
	private int time;
	private int waveLength;
	private int waveAmp;
	private int paneWidth;
	private Color color;

	
	public WaveDisplayPane(int paneWidth, Color color) {
		waveAmp = 100;
		waveLength = 50;
		this.paneWidth = paneWidth;
		this.color = color;
		time = 0;
		setStyle("-fx-background-color: white;");
		setStyle("-fx-border-color: black;");
		
		//settup timeline
		KeyFrame frame = new KeyFrame(Duration.millis(500), new WaveHandler());
		timeLine = new Timeline(frame);
		timeLine.setCycleCount(Timeline.INDEFINITE);
		timeLine.setRate(20);
		timeLine.play();
	}
	

	// defines an event listener to draw a new point
	private class WaveHandler implements EventHandler<ActionEvent> {
		public void handle(ActionEvent event) {
			//System.out.print(timeLine.currentTimeProperty() + "\n");
			time++;
			int x = (waveLength * time) / 314;
			int y = (int) (waveAmp * Math.sin((0.0174533) * time) + 115);
			if (x < paneWidth) {
				Circle dot = new Circle(x, y, 2);
				dot.setFill(color);
				getChildren().add(dot);
			} else suspend();
		}
	}
	
	public void resume() {
		timeLine.play();
	}

	public void suspend() {
		timeLine.stop();
		time = 0;
	}
	
	public void changeColor(Color color) {
		this.color = color;
	}
	
	public void clear() {
		getChildren().clear();
	}
	
	public void setWaveLength(int newLength) {
		waveLength = newLength;
	}
	
	public void setWaveAmp(int newAmp) {
		waveAmp = newAmp;
	}
	
	public void setRate(int newRate) {
		timeLine.setRate(newRate);
	}
}
