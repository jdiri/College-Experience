import java.util.Scanner;
import java.text.DecimalFormat;
class Assignment5
{
   public static void main(String[] args)
   {
      DecimalFormat fmt = new DecimalFormat("$#0.00");
      Scanner scan = new Scanner(System.in);
      String title = scan.nextLine();
      String row = scan.nextLine();
      int seat = scan.nextInt();
      double price = scan.nextDouble();
      char option;
      
      MovieTicket movie1 = new MovieTicket(title, row, seat, price);
      System.out.print("\nWelcome to Harkins Theatre" +
                       "\n==========================" +
                       "\nChoose an Action" +
                       "\n-------------------");
                       
      System.out.println("\nT\t Change Movie Ticket Title" +
                       "\nR\t Change Movie Ticket Row" +
                       "\nN\t Change Movie Ticket Number" +
                       "\nI\t Adjust Movie Ticket Price" +
                       "\nD\t Discount the Price" +
                       "\nS\t Show Movie Ticket Info." +
                       "\n?\t Display the Menu"+
                       "\nQ\t Exit Program\n");
      option = scan.next().charAt(0);
      do{
      switch(option)
      {
      case 't':
      case 'T':
         //scan.nextLine();
         String newTitle; 
         newTitle = scan.nextLine();
         movie1.setTitle(newTitle);
         System.out.print("\nThe ticket title has been changed from " + title + " to " + newTitle + "\n");
         break;
      case 'r':
      case 'R':
         scan.nextLine();
         String newRow = scan.nextLine();
         movie1.setRow(newRow);
         System.out.print("\nThe ticket row has been changed from " + row + " to " + newRow + "\n");
         break;
      case 'N':
      case 'n':
         int newSeat = scan.nextInt();
         movie1.setSeatNum(newSeat);
         System.out.print("\nThe ticket seat number has been changed from " + seat + " to " + newSeat + "\n");
         break;
      case 'i':
      case 'I':
         double newPrice = scan.nextDouble();
         movie1.adjustPrice(newPrice);
         System.out.print("\nPrice was adjusted from " + fmt.format(price) + " to new price of " + fmt.format(newPrice) + "\n");
         break;
      case 'D':
      case 'd':
         double rate = scan.nextDouble();
         movie1.discount(rate);
         double discountPrice = movie1.getPrice();
         System.out.print("\nPrice was reduced by " + rate*100 + "0%, the new price is " + fmt.format(discountPrice) + "\n");
         break;
      case 'S':
      case 's':
         System.out.print(movie1.toString());
         break;
      case '?':
         System.out.print("\nChoose an Action" +
                          "\n-------------------");
         System.out.println("\nT\t Change Movie Ticket Title" +
                            "\nR\t Change Movie Ticket Row" +
                            "\nN\t Change Movie Ticket Number" +
                            "\nI\t Adjust Movie Ticket Price" +
                            "\nD\t Discount the Price" +
                            "\nS\t Show Movie Ticket Info." +
                            "\n?\t Display the Menu"+
                            "\nQ\t Exit Program\n");
                            break;
      case 'q':
      case 'Q':
         break;
      }
      option = scan.next().charAt(0);
      }while(option != 'q' && option != 'Q');              
      
   }
}
