/*
John Diri
Lab#2
this Lab will demonstrate how to write a java program that asks the user to enter two strings
first name and last name then will Concatenate them to form a full name Using some methods of class String like
length() and toUpperCase() on full name.
*/
 
 import java.util.Scanner;
 class Lab2
 {
   public static void main(String[] args)
   {
   // step#1 identify variables
   String lastName, firstName, fullName;
   int nameLength = 0;
   Scanner scan = new Scanner(System.in);
   
   //now create a prompt to get the first and last name
   //System.out.println("What is your first name ");
   firstName = scan.nextLine();
   //System.out.println("What is your last name ");
   lastName = scan.nextLine();
   
   //now i will combine the first and last name 
   fullName = firstName + " " + lastName;
   String upperName = fullName.toUpperCase();
   nameLength = upperName.length();
   
   
   String subStr = upperName.substring(5, 9);
   char charAtIndex2 = upperName.charAt(2);
   
   //system output for lab
   System.out.println("Full name (in capitals): " + upperName);
   System.out.println("Length of full name: " + nameLength);
   System.out.println("Sub string between index 5 and 9 is: " + subStr);
   System.out.println("Character at index 2 is: " + charAtIndex2);
   
   
   //I will now compare two variables to check if both hold the same value or not
   //using if else statements
   String title1 = new String("java");
   String title2 = new String("java");
   String title3 = new String("Java");
      {if (title1 == title2)
         System.out.println("String comparison using \"==\" sign works");
      else 
         System.out.println("String comparison using \"==\" sign does NOT work");
      }
      
      {if (title1.equals(title2))
         System.out.println("String comparison using \"equals\" method works");
      else
         System.out.println("String comparison using \"equals\" method does NOT work");
      }
      {if (title1.equalsIgnoreCase(title3))
         System.out.println("String comparison using \"equalsIgnoreCase\" method works");
      else
         System.out.println("String comparison using \"equalsIgnoreCase\" method does NOT work");
      }
   
   
   }
 }
