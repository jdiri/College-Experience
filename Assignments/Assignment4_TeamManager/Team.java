/* Assignment #: 4
Description: Coach class is used in the Assignment 4 class to create a object team
 */

public class Team {
	//create private variables for class
	private String name, city;
	private Coach teamCoach;
		
	//create constructer
	public Team(String name, Coach x, String city) {
		this.name = name;
		teamCoach = x;
		this.city = city;
	}
		
	//create getters
	public String getName() {
		return name;
	}

	public Coach getCoach() {
		return teamCoach;
	}
		
	public String getCity() {
		return city;
	}
	public String toString() {
		return "Team's name:\t" + name + " from " + city
				+ teamCoach.toString();
	}
}
