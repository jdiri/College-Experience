// Author: john diri
// For: Lab #3
// Description: learn  Math lang

import java.util.Scanner;
import java.text.DecimalFormat;
import java.lang.Math;

class Lab3
{
   public static void main(String[] args)
      {
      double x, y, z, A;
      final double pi = 3.1415926;
   
      Scanner scan = new Scanner(System.in);
      
         System.out.println("Enter x value: ");
         x = scan.nextDouble();
         System.out.println("Enter y value: ");
         y = scan.nextDouble();
         System.out.println("Enter z value: ");
         z = scan.nextDouble();
         
      DecimalFormat fmt = new DecimalFormat("0.000");
      //i first do the numerator
         A = (Math.sqrt((Math.pow((((3*(Math.pow(x, 2)))+(2*y))), 2)) - (z*4)));
      //now the denomanator
         A = (A/((pi*(Math.pow(z, 2))) - (x *= 2)));
      System.out.println("A value is: " + fmt.format(A));
      }
}
