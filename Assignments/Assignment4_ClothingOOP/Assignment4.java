import java.text.DecimalFormat;
import java.util.Scanner;

class Assignment4
{
   public static void main(String[] args)
   {  
      DecimalFormat fmt = new DecimalFormat("##.00%");
      DecimalFormat fmt1 = new DecimalFormat("$##.00");
      Scanner scan = new Scanner(System.in);
      int id = scan.nextInt();
      String size = scan.next();
      String color = scan.next();
      double price = scan.nextDouble();
      Clothes Clothes1;
      Clothes1 = new Clothes(id, size, color, price);
      
      //header
      System.out.print("\nWelcome to Target Clothing Dept" +
                       "\n==============================" +
                       "\nChoose an Action" +
                       "\n-------------------");
      
      System.out.println("\nS\t Change Clothes Size" +
                       "\nC\t Change Clothes Color" +
                       "\nI\t Increase the Price" +
                       "\nR\t Reduce the Price" +
                       "\nP\t Print Clothes Info" +
                       "\n?\t Display the Menu"+
                       "\nQ\t Exit Program\n");
      char option;
      option = scan.next().charAt(0);
      do{switch(option)
      {
         case 'S':
         case 's':
            String newSize = scan.next();
            Clothes1.changeSize(newSize);
            System.out.print("\nThe size has been changed from " + size + " to " + newSize + "\n");
            break;
         case 'C':
         case 'c':
            String newColor = scan.next();
            Clothes1.changeColor(newColor);
            System.out.print("\nThe color has been changed from " + color + " to " + newColor + "\n");
            break;
         case 'I':
            double Irate = scan.nextDouble();
            Clothes1.raisePrice(Irate);
            System.out.print("\nPrice was increased by " + fmt.format(Irate) + ", the new price is " + fmt1.format(Clothes1.getPrice()) + "\n");
            break;
         case 'R':
            double Rrate = scan.nextDouble();
            Clothes1.reducePrice(Rrate);
            System.out.print("\nPrice was reduced by " + fmt.format(Rrate) + ", the new price is " + fmt1.format(Clothes1.getPrice()) + "\n");
            break;
         case 'P':
            System.out.print(Clothes1.toString());
            break;
         case '?':
            System.out.println("\nChoose an Action" +
                               "\n-------------------" +
                               "\nS\tChange Clothes Size" +
                               "\nC\tChange Clothes Color" +
                               "\nI\tIncrease the Price" +
                               "\nR\tReduce the Price" +
                               "\nP\tPrint Clothes Info" +
                               "\n?\tDisplay the Menu"+
                               "\nQ\tExit Program");
                                break;
         case 'Q':
            break;
         default: 
            System.out.print("try again");
            break;
      }
      //scan option again
      if(option != 'q'&&option != 'Q')
      {
        /* System.out.println("\nS\t\tChange Clothes Size" +
                         "\nC\tChange Clothes Color" +
                         "\nI\tIncrease the Price" +
                         "\nR\tReduce the Price" +
                         "\nP\tPrint Clothes Info" +
                         "\n?\tDisplay the Menu"+
                         "\nQ\tExit Program");  */
         option = scan.next().charAt(0);
      }
      }while(option != 'q'&&option != 'Q');      
   }
}
/*1234
Medium
White
19.99
P
Q*/
