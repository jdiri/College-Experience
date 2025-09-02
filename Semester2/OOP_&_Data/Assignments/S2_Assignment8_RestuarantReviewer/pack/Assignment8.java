// Assignment: 
// Name:
// StudentID:
// Lecture:
// Description:
package pack;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.NotSerializableException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class Assignment8 {
    public static void main(String[] args) {
        //ArrayList reviews = new ArrayList();
    	
    	// Menu options
        char inputOpt = ' ';
        String inputLine;
        // restuarant and Cuisine information
        String restuarantName, cuisineName;
        String review = null, location, signatureDish, priceRange;

        int rating;
        // Output information
        String outFilename, inFilename;
        String outMsg, inMsg;
        // restuarant manager
        ReviewManager reviewManager = new ReviewManager();
        // Operation result
        boolean opResult;     
        
        try {
            printMenu();
            InputStreamReader isr = new InputStreamReader(System.in);
            BufferedReader stdin = new BufferedReader(isr);

            do {
                System.out.print("\nWhat action would you like to perform?\n");
                inputLine = stdin.readLine().trim();
                if (inputLine.isEmpty()) {
                    continue;
                }
                inputOpt = inputLine.charAt(0);
                inputOpt = Character.toUpperCase(inputOpt);

                switch (inputOpt) {

                    case 'A': // Add a new restuarant Review
                        System.out.print("Please enter the restaurant information:\n");
                        System.out.print("Enter the restuarant name:\n");
                        restuarantName = stdin.readLine().trim();
                        System.out.print("Enter the review:\n");
                        review = stdin.readLine().trim();
                        System.out.print("Enter the price range:\n");
                        priceRange = stdin.readLine().trim();
                        System.out.print("Enter the rating:\n");
                        rating = Integer.parseInt(stdin.readLine().trim());
                        System.out.print("Enter the cuisine name:\n");
                        cuisineName = stdin.readLine().trim();
                        System.out.print("Enter the location:\n");
                        location = stdin.readLine().trim();
                        System.out.print("Enter the signature dish\n");
                        signatureDish = stdin.readLine().trim();
                        /*********************************************************************
                        * Complete the code by calling the addReview method.                 *
                        * If the review has been added successfully, show                    *
                        * "restuarant added\n" on screen, otherwise "restuarant NOT added\n" *
                        **********************************************************************/
                        if(reviewManager.addReview(restuarantName,rating,review,priceRange,cuisineName,location,signatureDish) == true) {	
                        	reviewManager.addReview(restuarantName,rating,review,priceRange,cuisineName,location,signatureDish);
                        	System.out.print("Restaurant added\n");
                        	System.out.print("\n" + reviewManager.reviewList.get(0) + "\n");
                        }
                        else
                        	System.out.print("Restaurant NOT added\\n");
                        break;
                        
                        


                    case 'D': // Search a restuarant
                        System.out.print("Please enter the restaurant name to search:\n");
                        restuarantName = stdin.readLine().trim();
                        System.out.print("Please enter the restaurant's location':\n");
                        location = stdin.readLine().trim();
                        
                        /*********************************************************************
                        * Complete the code. If a restuarant review exists, print            *
                        * "restuarant found. Here's the review:\n"                           *
                        * Otherwise, print "restuarant not found. Please try again\n"        *
                        **********************************************************************/      
                        if(reviewManager.restuarantExists(restuarantName, location) == 0) {
                        	System.out.print("restuarant found. Here's the review:\n" );
                        	System.out.print(reviewManager.reviewList.get(reviewManager.restuarantExists(restuarantName, location)));
                        	break;
                        }
                        else
                        	System.out.print("restuarant not found. Please try again\n");
                        	break;


                    case 'E': // Search a cuisine
                        System.out.print("Please enter the cuisine name to search:\n");
                        cuisineName = stdin.readLine().trim();
                        
                        /*******************************************************************************
                        * Complete the code. If a cuisine is found, show on the screen how many       *
                        * restuarants match that cuisine by printing                                  *
                        * "%s restuarants matching %s cuisine were found:\n" followed by the reviews. *
                        * Otherwise, print "Cuisine: %s was NOT found\n"                              *
                        ******************************************************************************/   
                        if(reviewManager.cuisineExists(cuisineName) != null) {
                        	System.out.print(reviewManager.cuisineExists(cuisineName).length + " restuarants matching " + cuisineName + " cuisine were found:\n");
                        	for(int i = 0; i<reviewManager.cuisineExists(cuisineName).length;i++) {
                        		System.out.print(reviewManager.reviewList.get(i).toString());
                        	}
                        }
                        else
                        	System.out.print("Cuisine: " + cuisineName + " was NOT found\\n");
                        
   
                    case 'L': // List restuarant's reviews
                        System.out.print("\n" + reviewManager.listReviews() + "\n");
                        break;
                        
                     /******************************************************************************************
                     * Complete the code by adding two cases:                                                  *
                     * case 'N': sorts the restuarant reviews by rating and prints "sorted by rating\n"        *
                     * case 'P': sorts the restuarant reviews by cuisine name and prints "sorted by cuisine\n" *
                     ******************************************************************************************/   
                    case 'N':
                    	ReviewManager.sortByRating(reviewManager.reviewList, new ReviewRatingComparator());
                    	System.out.print("sorted by rating\\n");
                    	break;
                    
                    case 'P':
                    	ReviewManager.sortByCuisine(reviewManager.reviewList, new ReviewCuisineComparator());
                    	System.out.print("sorted by cuisine\\n");
                    	break;
                        
                    case 'Q': // Quit
                        break;

                    case 'R': // Remove a review
                        System.out.print("Please enter the restuarant name of the review to remove:\n");
                        restuarantName = stdin.readLine().trim();
                        System.out.print("Please enter the location to remove:\n");
                        location = stdin.readLine().trim();
                        
                        /*******************************************************************************
                        * Complete the code. If a review for a certain restuarant at a given location  *
                        * is found, remove the review and print that it was removed. Otherwise         *
                        * print that it was NOT removed.                                               * 
                        *******************************************************************************/
                        
                        if(reviewManager.deleteReview(restuarantName, location) == true) {
                        	System.out.print("The review was removed");
                        }
                        else
                        	System.out.print("The review was not removed");
                      
                        
                    case 'T': // Close reviewList
                        reviewManager.closeReviewManager();
                        System.out.print("restuarant management system was reset\n");
                        break;

                    case 'U': // Write restuarant names and reviews to a text file
                        System.out.print("Please enter a file name that we will write to:\n");
                        outFilename = stdin.readLine().trim();
                        System.out.print("Please enter the name of the restuarant:\n");
                        restuarantName = stdin.readLine().trim();
                        System.out.println("Please enter a review to save locally:\n");
                        review = stdin.readLine().trim();
                        outMsg = restuarantName + "\n" + review + "\n";
                        
                        /*************************************************************************************
                        * Add a try and catch block to write the string outMsg into the user-specified file  *
                        * Then, print in the screen that the file " is written\n"                            *
                        * In case of an IO Exception, print "Write string inside the file error\n"           *                                                             
                        *************************************************************************************/                    
                              

                    case 'V': // Read strings from a text file
                        System.out.print("Please enter a file name which we will read from:\n");
                        inFilename = stdin.readLine().trim();
                        
                        /******************************************************************************************
                        * Add a try and catch block to read from the above text file. Confirm that the file       *
                        * " was read\n" and then print "The contents of the file are:\n" followed by the contents *
                        * In case of an IO Exception, print "Read string from file error\n"                       *  
                        * In case of a file not found exception, print that the file " was not found\n"           *                                                             
                        ******************************************************************************************/ 
                        
 
                    case 'W': // Serialize ReviewManager to a data file
                        System.out.print("Please enter a file name to write:\n");
                        outFilename = stdin.readLine().trim();
                        
                        /****************************************************************************
                        * Add a try and catch block to serialize ReviewManager to a data file.      *
                        * Catch two exceptions and print the corresponding messages on the screen:  *
                        * "Not serializable exception\n"                                            *
                        * "Data file written exception\n"                                           * 
                        ****************************************************************************/                    
                        

                    case 'X': // Deserialize ReviewManager from a data file
                        System.out.print("Please enter a file name which we will read from:\n");
                        inFilename = stdin.readLine().trim();
                        
                        /*****************************************************************************
                         * Add a try and catch block to deserialize ReviewManager from a data file.  *
                         * Catch three exceptions and print the corresponding messages on the screen:*
                         * "Class not found exception\n"                                             *
                         * "Not serializable exception\n"                                            * 
                         * "Data file read exception\n"                                              *
                         ****************************************************************************/  
                        

                    case '?': // Display help
                        printMenu();
                        break;

                    default:
                        System.out.print("Unknown action\n");
                        break;
                }

            } while (inputOpt != 'Q' || inputLine.length() != 1);
        }
        catch (IOException exception) {
            System.out.print("IO Exception\n");
        }
    }

    public static void printMenu() {
        System.out.println("Welcome to Kelp! ");
        System.out.println("Find or post reviews for your favorite (and not so favorite) restuarants.");

        System.out.print("Choice\t\tAction\n" + "------\t\t------\n" + "A\t\tAdd a review\n"
                + "D\t\tSearch for a restuarant\n" + "E\t\tSearch for a cuisine\n"
                + "L\t\tList all reviews\n" + "N\t\tSort by stars\n" + "P\t\tSort by cuisine\n"
                + "Q\t\tQuit\n" + "R\t\tRemove a review\n"
                + "U\t\tAdd personal review to a local file\n" + "V\t\tRetrieve personal review from a local file\n"
                + "W\t\tSave reviews to a file\n"
                + "X\t\tUpload reviews from a file\n"
                + "T\t\t(admin) reset database\n"
                + "?\t\tDisplay Help\n");
    }
}
