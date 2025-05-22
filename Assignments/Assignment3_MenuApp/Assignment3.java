// Author: john diri
// Description: learn  Math lang

import java.text.DecimalFormat;
import java.util.Scanner;
import java.lang.Math;

class Assignment3
{
   public static void main(String[] args)
   {
      DecimalFormat fmt1 = new DecimalFormat("0.000");
      System.out.println();
      System.out.println("1) Convert kilometers into miles" +
                        "\n2) Display a triangle shape" +
                        "\n3) Predict bacteria's population" +
                        "\n4) Quit");
      System.out.println();
      Scanner scan = new Scanner(System.in);
      int option = scan.nextInt();
      while (option < 1 || option > 4)
      {
         System.out.println("Wrong choice! You can pick 1 to 4 only\nplease re-enter: ");
         option = scan.nextInt();
      }
      do
      {
         switch(option)     
         {
         case 1:
            double kilo, miles;
            final double constant = 0.6214;
            //System.out.println("Enter a positive Integer");
            kilo = scan.nextDouble();
            while(kilo <= 0)
            {
               System.out.println("Error, number must be positive");
               System.out.println();
            }
            
               System.out.println("Kilos\tMiles");
               for(int i = 1; i <= kilo; i++)
               {
                  miles = i * constant;
                  System.out.println(i + "\t" + fmt1.format(miles));
               }
               System.out.println();
           
            System.out.println("1) Convert kilometers into miles" +
                        "\n2) Display a triangle shape" +
                        "\n3) Predict bacteria's population" +
                        "\n4) Quit");
            option = scan.nextInt();
            break;
            case 2:
               //System.out.println("Please enter number of rows:");
               int row;
               row = scan.nextInt();
               while (row <= 0)
               {
                  System.out.println("Error, number of rows must be positive");
                  row = scan.nextInt();
               }
               System.out.println();
               
               for(int j = 1; j <= row; j++)
               {
                  int numOfSpaces = row - j;
                  for(int k = 1; k <= numOfSpaces; k++)
                  {
                     System.out.print(" ");
                  }
                  int numCarrots = 2 * j - 1;
                  for(int l = 1; l <= numCarrots; l++)
                  System.out.print("^");
                  System.out.println();
               }
               System.out.println();
               System.out.println("1) Convert kilometers into miles" +
                        "\n2) Display a triangle shape" +
                        "\n3) Predict bacteria's population" +
                        "\n4) Quit");
               System.out.println();
               System.out.println();
               option = scan.nextInt();
               break;
            case 3:
               double rate;
               int startingBac, days, pop; 
               //System.out.println("Enter the starting number of bacterias (2 or more):");
               startingBac = scan.nextInt();
               if(startingBac < 2)
               {
                  System.out.print("Error, starting number must be at least 2");
                  startingBac = scan.nextInt();
               }
               pop = startingBac;
               //System.out.println("Enter the daily population increase rate as a percentage(e.g 3.5) :");
               rate = scan.nextDouble();
            
               if (rate <= 0)
               {
                  System.out.println("Error, increase rate must be positive");
                  rate = scan.nextDouble();
               }
                  //System.out.println("Enter the number of days the bacterias will be left to multiply: ");
                  days = scan.nextInt();
                  if(days < 0)
                  {
                     System.out.println("Error");
                     days = scan.nextInt();
                  }
                     System.out.println();
                     System.out.println();
                     for(int m = 1; m <= days; m++)
                     {
                           pop = (int)(pop*rate)/100 + pop;
                           //pop += startingBac;   
                        System.out.println("Population after day " + m + ": " + (int)pop);
                     }   
                     System.out.println();         
                     System.out.println("1) Convert kilometers into miles" +
                        "\n2) Display a triangle shape" +
                        "\n3) Predict bacteria's population" +
                        "\n4) Quit");
                     System.out.println();
                     option = scan.nextInt();
                     break;
         }                    
      }while(option != 4);
   }
}
