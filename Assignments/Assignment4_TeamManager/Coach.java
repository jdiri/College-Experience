/* Assignment #: 4
Description: Coach class is used in the Assignment 4 class to create a object coach
 */

public class Coach {
	//create private variables for class
	private String first, last;
	private int years;
	
	//create constructer
	public Coach(String first, String last, int years) {
		this.first = first;
		this.last = last;
		this.years = years;
	}
	
	//create getters
	public String getFirst() {
		return first;
	}

	public String getLast() {
		return last;
	}
	
	public int getYears() {
		return years;
	}
	
	
	//toString
	public String toString() {
		return "\nCoach Information:\nLast Name:\t" + last
				+ "\nFirst Name:\t" + first + "\nYears of Experience:\t" + years + "\n";
	}
}
