import java.util.Scanner;

class Assignment7
{
   static Scanner scan = new Scanner(System.in);
   public static void main(String[] args)
   {
      TicketManager PhxChildrenTheater = new TicketManager();
      PhxChildrenTheater.TicketManager();
      PhxChildrenTheater.menu();
      char option;
      option = scan.nextLine().charAt(0);
      do{
         switch(option){
         case 'd':
         case 'D':
            PhxChildrenTheater.displaySeats();
            option = scan.nextLine().charAt(0);
            break;
         case 'p':
         case 'P':
            System.out.print("Number of seats desired (1 - 10): \n");
            int numOfSeats = scan.nextInt();
            System.out.print("Desired row (1-15): \n");
            int row = scan.nextInt();
            System.out.print("Desired starting seat number in the row (1 - 10): \n");
            int starting = scan.nextInt();
            PhxChildrenTheater.purchaseTickets(numOfSeats, row, starting);
            scan.nextLine();
            option = scan.nextLine().charAt(0);
            break;
         case 's':
         case 'S':
            PhxChildrenTheater.displaySalesReport();
            PhxChildrenTheater.menu();
            option = scan.nextLine().charAt(0);
            break;
         case '?':
            System.out.print("D: Display Seat Map\n"
                     + "P: PPurchase Theater Ticket\n"
                     + "S: Display Sales Report\n"
                     + "?: Display the menu again\n"
                     + "Q: Quit this program\n");
            System.out.print("\n\nPlease enter a command: \n");
                     option = scan.nextLine().charAt(0);
                     break;
         }
         }while (option != 'q'&& option != 'Q');         
   }
}
