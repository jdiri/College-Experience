// Author: john diri
// For: Lab #5 
// Description: do while statements

import java.util.Scanner;

class Lab5
{
   public static void main(String[] args)
   {
      Scanner scan = new Scanner(System.in);
      int choice, n, sum = 0, i = 1, fact = 1;
      
      //choice selection
      do
      {
         System.out.println("1) Calculate the sum of integers 1 to m");
         System.out.println("2) Calculate the factorial of a given number");
         System.out.println("3) Find the first digit of a given number");
         System.out.println("4) Quit");
         choice = scan.nextInt();
         
         //switch statement
         switch(choice)
         {
         case 1:
            n = scan.nextInt();
            while(i <= n)
            {
               sum = sum + i;
               i++;
            }
            System.out.println("\nThe sum of 1 to " + n + " is " + sum);
            System.out.println();
            break;
         case 2:
            n = scan.nextInt();
            for(i = 1; i <= n; i++)
               {
                  fact = fact*i;
               }
            System.out.println("\nThe factorial of " + n + " is " + fact);
            System.out.println();
            break;
         case 3:
            int rem = 0, num;
            num = scan.nextInt();        
            while(num != 0)
            {
            
            //System.out.print("Enter the number: ");
            
            rem = num % 10;
            num = num / 10;          
            }
            System.out.println("\nThe leftmost digit is " + rem);
            break;             
         }
      }while(choice != 4);
   }
}
