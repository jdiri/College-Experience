import java.util.Scanner;
import java.text.DecimalFormat;

class Lab6
{
   public static void main(String[] args)
   {
      DecimalFormat fmt1 = new DecimalFormat("0.00");
      Scanner scan = new Scanner(System.in);
      displayMenu();
      int option = scan.nextInt();
      //varify answer
      if (option < 1 || option > 4)
      {
         System.out.println("Error");
         option = scan.nextInt();
      }
      do{
      switch(option)
      {
      case 1:
         //System.out.print("Enter the number: ");
         int num = scan.nextInt();
         //checkPrime(num); //true || false
         if (checkPrime(num))
            System.out.println(num + " is prime\n");
         else 
            System.out.println(num + " is NOT a prime\n");
            displayMenu();
            option = scan.nextInt();
            break;
      case 2:
         //System.out.print("Enter the fahrenheit temperature: \n");
         double farenTemp = scan.nextDouble();
         double celsius = tempConvert(farenTemp);
         System.out.printf("Fahrenheit " + farenTemp + " degree is equivalent to Celcis %.2f degree", celsius);
         displayMenu();
         option = scan.nextInt();
         break;
      case 3:
         //System.out.println("Enter a sentence: ");
         scan.nextLine();
         String s = scan.nextLine();
         System.out.print("The sentence contains  " + countE(s) + " 'e' and 'E'\n");
         displayMenu();
         option = scan.nextInt();
         break;
      }
        }while(option != 4);
   }
   
   
   public static void displayMenu()
   {
      System.out.println("\nASU CSE110 Lab #6 - Methods\n");
      //menu
      System.out.println("1) Check to see whether a number is prime or not\n" + 
                         "2) Convert temperature from Fahrenheit to Celsius\n" + 
                         "3) Count the number of character 'e' & 'E' in a string\n" +
                         "4) Quit\n");
   }
   
   
   public static boolean checkPrime(int num)
   {
      int modula, primeChecker = 0;
      for(int i = num; i >= 1; i--)
      {
         modula = num%i;
         if(modula == 0)
            primeChecker++;
      }
      if (primeChecker == 2)
         return true;
      else 
         return false;
   }
   
   public static double tempConvert(double farenTemp)
   {
      double cels = 0;
      cels = (farenTemp-32)*(5.0/9);
      return cels;
   }
   
   public static int countE(String line)
   {
      char letter;
      int e = 0;
      int length = line.length();
      for (int i = 0; i < length; i++)
      {
         letter = line.charAt(i);
         if(letter == 'e' || letter == 'E')
         {
            e++;
         }
      }
      return e;
   }
}
