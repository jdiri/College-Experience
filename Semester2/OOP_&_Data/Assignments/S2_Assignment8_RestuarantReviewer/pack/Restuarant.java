package pack;

import java.io.Serializable;

public class Restuarant implements Serializable{
	private static final long serialVersionUID = 205L;
	private String restuarantName;
	private int stars;
	private String review;
	private int priceRange;
	private String location;
	private Cuisine cuisine;
	private String tempStars = "*";
	private String tempPrice = "$";
	
	//constructor
	public Restuarant(String name,int stars,String review,int priceRange,String location,Cuisine cuisine) {
		this.restuarantName = name;
		this.stars = stars;
		this.review = review;
		this.priceRange = priceRange;
		this.location = location;
		this.cuisine = cuisine;
	}
	
	//getter
	public String getName() {
		return restuarantName;
	}
	public int getStars() {
		return stars;
	}
	public String getReview() {
		return review;
	}
	public String getLocation() {
		return location;
	}
	public int getPriceRange() {
		return priceRange;
	}
	public Cuisine getCuisine() {
		return cuisine;
	}
	
	//toString
	public String toString() {
		return (restuarantName + " restaurant\n" + modifyStars(stars) + "\t\t" + modifyPrice(priceRange) + "\n" + cuisine.toString() + "Location: " + location + "\n" + "Review:\t" + review + "\n\n");
	}
	
	public String modifyStars(int x) {
		for(int i = 1;i < x;x++) {
			tempStars = tempStars + "*";
		}
		return tempStars;
	}
	public String modifyPrice(int x) {
		for(int i = 1;i < x;x++) {
			tempPrice = tempPrice + "*";
		}
		return tempPrice;
	}

}
