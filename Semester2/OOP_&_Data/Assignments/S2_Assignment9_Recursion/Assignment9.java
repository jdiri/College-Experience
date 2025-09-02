// 	Assignment #: 9
//          Name: John Diri
//     StudentID: 1221905451
//       Lecture: 11:15-12:05
//   Description: This class reads an integer from a file and proforms multiple opperations with an array list using recursion
	
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Assignment9 {
    public static void main(String[] args) {
    	try {
    		int[] array;
	    	char inputOpt = ' ';
	    	printMenu();
	    	InputStreamReader isr = new InputStreamReader(System.in);
	        BufferedReader stdin = new BufferedReader(isr);
	        do {
	        	inputOpt = stdin.readLine().trim().charAt(0);
	        	switch(inputOpt) {
	        	case '1':
	        		array = parseInts(stdin);
	        		System.out.print("The largest number in the array is: " + getHighest(array,0) + "\n");	
	        		printMenu();
	        		break;
	        	case '2':
	        		array = parseInts(stdin);
	        		ArrayList<Integer> primes = new ArrayList<>();
	        		primeFinder(array,0,primes);
	        		System.out.print("The product of all prime numbers in the array is: " + mult(array,primes,primes.size()) + "\n");
	        		printMenu();
	        		break;
	        	case '3':
	        		array = parseInts(stdin);
	        		System.out.print("The largest sum of digits in the array is: " + getSum(array,array.length) + "\n");
	        		printMenu();
	        		break;
	        	case '4':
	        		System.out.print("Please enter String: \n");
	        		String input = stdin.readLine();
	        		System.out.print("String after adjacent duplicate characters were removed: " + fixString(input,input.length()) + "\n");
	        		printMenu();
	        		break;
	        	case '5':
	        		inputOpt = '5';
	        		break;
	        	default:
	        		System.out.print("Please choose a number between 1 and 5.\n");
	        		printMenu();
	        		break;
	        	}
	        }while (inputOpt != '5');
    	}catch(IOException exception) {
    		System.out.print("Please choose a number between 1 and 5.\n");
    		printMenu();
    	}
	
    }


    // Utility method for printing the menu 
    public static void printMenu() {
        System.out.print("\nWhat would you like to do?\n\n");
        System.out.print("1: Find the largest number in an array of integers\n");
        System.out.print("2: Calculate the product of all prime numbers in an array of integers\n");
        System.out.print("3: Find the element with the largest sum of digits in an array of integers\n");
        System.out.print("4: Remove adjacent duplicate characters in a String\n");
        System.out.print("5: Quit\n\n");
    }

    // utility method for parsing integers from standard input
    public static int[] parseInts(BufferedReader reader) {
        String line = "";
        ArrayList<Integer> container = new ArrayList<>();
        try {
            System.out.print("Please enter integers:\n");
            line = reader.readLine();
            int num = Integer.parseInt(line);

            while (num > 0) {
                container.add(num);
                line = reader.readLine();
                num = Integer.parseInt(line);
            }

        } catch (IOException ex) {
            System.out.println("IO Exception");
        }

        int[] result = new int[container.size()];
         for(int i = 0; i < container.size(); i++){
             result[i] = container.get(i);
         }
        return result;
    }
    
    public static int getHighest(int[] x,int y) {
    	if(y >= x.length-1) {
    		return x[y];
    	}
    	else {
    		return Math.max(x[y], getHighest(x,y+1));
    	}
    }
    //finds prime numbers
    public static int primeFinder(int[] integers, int counter,ArrayList<Integer> primeHolder) {
    	if(counter >= integers.length-1) {
    		if(isPrime(integers[counter],2))
    			primeHolder.add(counter);
    		return integers[integers.length-1];
    	}
    	else {
    		if(isPrime(integers[counter],2)) {
    			primeHolder.add(counter);
    			return primeFinder(integers,counter+1,primeHolder);
    		}
    		else
    			return primeFinder(integers,counter+1,primeHolder);
    	}
    }
    
    public static boolean isPrime(int idkPrime,int y) {
    	if(y <= idkPrime) {
	    	if(idkPrime == 2) {
	    		return true;
			}
	    	if(idkPrime < 2) {
	    		return false;
	    	}
			if(idkPrime%y == 0) {
				return false;
			}
			if(y*y>idkPrime) {
				return true;
			}
		return isPrime(idkPrime,y+1);
    	}
    	else 
    		return false;
    }
    //multiplies the found prime num
    public static int mult(int[] x, ArrayList<Integer> y,int a) {
    	if(a == 1) {
    		return x[y.get(a-1)];
    	}
    	else {
    		return x[y.get(a-1)]*mult(x,y,a-1);
    	}
    	
    }
    //gets largest sum of digits
    public static int getSum(int[] x,int a) {
    	if(a == 1) {
    		return x[a-1]/100000 + x[a-1]/10000%10 + x[a-1]/1000%100%10 + x[a-1]/100%1000%100%10 + x[a-1]/10%100000%1000%100%10 + x[a-1]%10%10%10%10%10%10;
    	}
    	else {
    		return Math.max(x[a-1]/100000 + x[a-1]/10000%10 + x[a-1]/1000%100%10 + x[a-1]/100%1000%100%10 + x[a-1]/10%100000%1000%100%10, getSum(x,a-1));
    	}
    }
    //adjusts String
    public static String fixString(String s, int x) {
    	String s1,s2;
    	if(x == 1) {
    		return s;
    	}
    	else {
    		if(s.charAt(x-1) == s.charAt(x-2)) {
    			s1 = s.substring(0, x-1);
    			s2 = s.substring(x, s.length());
    			return fixString(s1+s2,x-1);
    		}
    		else
    			return fixString(s,x-1);
    	}
    }

}
