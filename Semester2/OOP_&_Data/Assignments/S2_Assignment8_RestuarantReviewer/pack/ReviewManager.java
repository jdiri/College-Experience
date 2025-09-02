// Assignment:
// Name:
// StudentID:
// Lecture:
// Description:
package pack;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Comparator;

public class ReviewManager implements Serializable {
    // The serialVersionUID is used to verify compatibility of senders and
    // receivers. See the document for more details:
    // https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/io/Serializable.html
    private static final long serialVersionUID = 205L;
    int index;
    ArrayList<Restuarant> reviewList;

     public ReviewManager() {
        reviewList = new ArrayList<>();
    }

    /**
     * Add a restuarant object to the reviewList and return true if such an object
     * is added successfully. Otherwise, return false. Two restuarants are
     * considered duplicated if they have exactly the same restuarant name and
     * cuisine name.
     * 
     * @param  restuarantName the name of the restuarant
     * @param  stars the number of stars for the restuarant
     * @param  review   the restuarant review
     * @param  priceRange    the integer price range
     * @param  cuisineName  the Cuisine's name
     * @param  location   the restuarant location (street address)
     * @param  signatureDish  most famous dish
     * @return            true if the operation is successful; false otherwise
     */
    public boolean addReview(String restuarantName, int stars, String review, String priceRange, String cuisineName, String location, String signatureDish) {
        if (restuarantExists(restuarantName, location) == -1) {
            int price = priceRange.length();
            Cuisine newCuisine = new Cuisine(signatureDish, cuisineName);
            Restuarant newrestuarant = new Restuarant(restuarantName, stars, review, price, location, newCuisine);
            reviewList.add(newrestuarant);
            return true;
        }
        return false;
    }
    
    public int restuarantExists(String name, String Location) {
    	for(int i = 0; i < reviewList.size(); i++) {
    		if(name.compareToIgnoreCase(reviewList.get(i).getName())==0) {
    			if(Location.compareToIgnoreCase(reviewList.get(i).getLocation())==0) {
    				index = i;
    				return 0;
    			}
    			else
    				if(i == reviewList.size()-1) {
        				return -1;
        			}
    				else
    					continue;
    		}
    		else
    			if(i == reviewList.size()-1) {
    				return -1;
    			}
    			else
    				continue;
    	}
    	return -1;
    }
    
    public int[] cuisineExists(String x) {
    	int counter = 0;
    	int[] cuisineNum = new int[counter];
    	for(int i = 0; i < reviewList.size(); i++) {
    		if(reviewList.get(i).getCuisine().getName()==x) {
    			counter++;
    			cuisineNum[counter]=reviewList.indexOf(reviewList.get(i));
    		}
    	}
    	return cuisineNum;
    }
    
    public boolean deleteReview(String name, String Location) {
    	if(restuarantExists(name,Location) == 0) {
    		for(int i = 0; i < reviewList.size(); i++) {
        		if(name.compareToIgnoreCase(reviewList.get(i).getName())==0) {
        			if(Location.compareToIgnoreCase(reviewList.get(i).getLocation())==0) {
        				reviewList.remove(i);
        				return true;
        			}
        			else
        				continue;
        		}
    		}
    		return false;
    	}
    	else
    		return false;
    }
    
    public static void sortByRating(ArrayList<Restuarant> x, Comparator<Restuarant> y) {
    	Sorts.sort(x,y);
    }
    
    public static void sortByCuisine(ArrayList<Restuarant> x, Comparator<Restuarant> y) {
    	Sorts.sort(x, y);
    }
    
    public Restuarant getRestuarant(int x) {
    	return reviewList.get(x);
    }
    
    public String listReviews() {
    	int numOfRs = 0;
    	String listRestuarants = null; 
    	do {
    		listRestuarants += reviewList.get(numOfRs).toString() + "\n";
    		numOfRs++;
    	}while(numOfRs<reviewList.size());
    	return listRestuarants;
    }
    
    public void closeReviewManager() {
    	reviewList.clear();
    }

}
