// All "import" lines must be before class
import java.util.Scanner;

// class name should match the file name
class Lab4
{
     public static void main(String[] args)
     {
     // declare variable
     int userInput;
    

     // create a Scanner object
     Scanner scan = new Scanner(System.in);
     
     System.out.println("Enter a number between 1-7");
     userInput = scan.nextInt();
     
     if (userInput > 7 || userInput < 1)
     {
            System.out.println("Invalid input, input must be between 1 to 7");
     }
     else
     {
           // System.out.println("correct input");
            if (userInput == 1)
            {
               System.out.println("Monday");
            }
            if (userInput == 2)
            {
               System.out.println("Tuesday");
            }
            if (userInput == 3)
            {
               System.out.println("Wednesday");
            }
            if (userInput == 4)
            {
               System.out.println("Thursday");
            }
            if (userInput == 5)
            {
               System.out.println("Friday");
            }
            if (userInput == 6)
            {
               System.out.println("Saturday");
            }
            if (userInput == 7)
            {
               System.out.println("Sunday");
            }
            
     }
     switch (userInput)
         {
         case 1:
             System.out.println("Monday - by switch");
         break;
         case 2:
            System.out.println("Tuesday - by switch");
         break;
         case 3:
            System.out.println("Wednesday - by switch");
         break;
         case 4:
            System.out.println("Thursday - by switch");
         break;
         case 5:
            System.out.println("Friday - by switch");
         break;
         case 6:
            System.out.println("Saturday - by switch");
         break;
         case 7:
            System.out.println("Sunday - by switch");
         break;
         }       
      }
}
