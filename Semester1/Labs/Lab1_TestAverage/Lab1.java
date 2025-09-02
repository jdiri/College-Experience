/* JOHN DIRI
For: Lab1
   The goal of this program is to create a test using 
   basic programing knowledge to calculate the percent the tester got
*/
import java.util.Scanner;
class Lab1
{
   public static void main(String[] args)
      {
      //Here I declare 3 variables
      int test1, test2, test3;
      //here is where i create a constant for the num of tests
      final int NUM_OF_TESTS = 3;
      //I also need to assigne a variable to the average overall the student gets
      double average;
      
      Scanner in = new Scanner(System.in);
      //now Im creating a prompt for the reader to answer
      System.out.println("Enter the score on the first test:");
      //here is where i give the variable test 1,2,3 a number
      test1 = in.nextInt();
      System.out.println("Enter the score on the second test:");
      test2 = in.nextInt();
      System.out.println("Enter the score on the third test:");
      test3 = in.nextInt();
      //now i will calculate the avrages but also need to asigne avrage to a variable
      
      average = (test1 + test2 + test3) / (double)NUM_OF_TESTS;
      //now I will write the final prompt giving the average of the tests
      System.out.println("Your test average is: " + average);
      for (int i = 0; i < 6; i++)
{
    if (i == 4)
    {
        continue;
    }
    System.out.print(i + " ");
}
      }
}


    
