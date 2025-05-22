import java.util.Scanner;
import java.text.DecimalFormat;
class TicketManager
{
   /*NUM_ROWS:*/final int row = 15;
   /*ROW_SIZE:*/final int col = 10;
   /*SEAT_PRICE:*/ final double price = 15.0;
   /*seatsSold:*/ int seatsSold = 0;
   /*totalRevenue: */double revenue = 0.0;
   DecimalFormat fmt = new DecimalFormat("$0.00");
   DecimalFormat fmt1 = new DecimalFormat(" #");
   
   String[][] seatArray = new String[15][10];
   public void TicketManager()
   {
      for(int i = 0; i < seatArray.length; i++)
      {
         for(int j = 0; j < seatArray[0].length;j++)
         {
            seatArray[i][j] = "O  ";
         }
      }
      seatsSold = 0;
      revenue = 0;
   }
   
   public void displaySeats()
   {
      System.out.print("\n\t\t\t  Seats\n\t   1  2  3  4  5  6  7  8  9  10\n");
      for(int i = 0; i < seatArray.length; i++)
      {  
         if(i < 9){
            System.out.print("Row " + fmt1.format(i+1) + " ");
            }
            else{
            System.out.print("Row " + (i+1) + " ");
            }
         for(int j = 0; j < seatArray[0].length;j++)
         {  
            System.out.print(seatArray[i][j]);
         }
         System.out.print("\n");
      }
      System.out.print("\n");
         System.out.print("Legend:\t #  =  Sold\n" + 
                          "\t\t    O  =  Available\n");
      System.out.print("\nPhoenix Children Theater Online Purchase System\n");
      System.out.print("\n\t  Choose an Action\n"
                       + "------------------------------\n"
                       + "D: Display Seats Map\n"
                       + "P: Purchase Theater Ticket\n"
                       + "S: Display Sales Report\n"
                       + "?: Display the menu again\n"
                       + "Q: Quit this program\n");
      System.out.print("\n\nPlease enter a command: \n");
   }
   
   public boolean checkAvailability(int numSeatsRequested, int requestedRow, int startSeat)
   {
      int i = 0;
      while(startSeat < seatArray[0].length)
      {
         startSeat++;
         i++;
      }
      startSeat -= i;
      if(i < numSeatsRequested){
         System.out.print("\nOne or more of the seats you have requested do not exist, re-book please.\n");
         
         return false;
         }
      for(int j = startSeat; j < seatArray[0].length;j++)
      {
         if(seatArray[requestedRow][j] == "#  "){
            System.out.print("\nOne or more of the seats you have requested are already sold.\n");
            }
      }
      System.out.print("The seats you have requested are available for purchase.");
      System.out.print("\nThe total purchase price will be: " + numSeatsRequested + " seats X $15.0 = " + fmt.format(price*numSeatsRequested) + "\n");
      return true;
   }
   
    public void purchaseTickets(int numSeats, int requestedRow, int startSeat)
    {
      int indexSeat = startSeat;
      indexSeat--;
      boolean availability = checkAvailability(numSeats, requestedRow, indexSeat);
      if(availability){
         //print
         double amountDue = numSeats*15;
         int indexRow = requestedRow;
         indexRow--;
         System.out.print("\nDo you wish to purchase these tickets (Yes/No)? ");
         String answer = Assignment7.scan.next();
         if (answer.equalsIgnoreCase("yes")){
            System.out.print("\nThe seats you have requested are available for purchase.");
            System.out.print("\nThe total purchase price will be: " + numSeats + " seats X $15.0 = " + fmt.format(price*numSeats) + "\n");
            System.out.print("Please input amount paid: \n");
            double amountPaid = Assignment7.scan.nextDouble();
            if(amountPaid >= price*numSeats){
               for(int i = indexSeat; i < indexSeat+numSeats;i++)
               {
                  seatArray[indexRow][i] = "#  ";
               }
               seatsSold += numSeats;
               revenue += amountDue;
               System.out.print("********************************");
               System.out.print("\n\tPhoenix Children Theater\n");
               for(int t = 0; t < numSeats; t++){
                  System.out.print("\n\t Row " + requestedRow + " ~ Seat " + (startSeat+t));                 
               }
                  System.out.print("\n********************************\n\n");
               
               //summary
               double change = amountPaid-(price*numSeats);
               System.out.print("Tickets purchased : " + numSeats + "\n");
               System.out.print("Payment           : " + fmt.format(amountPaid) + "\n");
               System.out.print("Total ticket price: " + fmt.format(price*numSeats) + "\n");
               System.out.print("Change due        : " + fmt.format(change) + "\n");
               System.out.print("\n\n\nPhoenix Children Theater Online Purchase System\n");
               System.out.print("\n\t  Choose an Action\n"
                              + "------------------------------\n"
                              + "D: Display Seats Map\n"
                              + "P: Purchase Theater Ticket\n"
                              + "S: Display Sales Report\n"
                              + "?: Display the menu again\n"
                              + "Q: Quit this program\n");
               System.out.print("\n\nPlease enter a command: \n");
            }
            else
               System.out.print("\nInsufficient payment.\n\nThe sale has been cancelled and your money is being returned.\n");
        } 
     }
     else
      menu();    
    }
    
    public void printTickets(int rowNum, int firstSeatNum, int lastSeatNum)
    {
      System.out.print("********************************");
      System.out.print("\n  Phoenix Children Theater\n\n");
      while(firstSeatNum <= lastSeatNum)
         System.out.print("Row " + rowNum + " ~ Seat " + firstSeatNum);
         firstSeatNum++;
    }
    
    public void displaySalesReport()
    {
      System.out.print("\nPhoenix Children Theater Sales Report\n");
      System.out.print("===================================\n");
      System.out.print("\nSeats sold:            " + seatsSold);
      System.out.print("\nSeats available:       " + (150-seatsSold));
      System.out.print("\nTotal revenue to date: " + fmt.format(revenue));
    }
    public void menu()
    {
      System.out.print("\n\nPhoenix Children Theater Online Purchase System\n");
        System.out.print("\n\t  Choose an Action\n"
                       + "------------------------------\n"
                       + "D: Display Seats Map\n"
                       + "P: Purchase Theater Ticket\n"
                       + "S: Display Sales Report\n"
                       + "?: Display the menu again\n"
                       + "Q: Quit this program\n");
        System.out.print("\n\nPlease enter a command: \n");
    }
}
