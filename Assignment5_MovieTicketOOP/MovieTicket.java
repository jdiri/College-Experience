import java.text.DecimalFormat;
class MovieTicket
{  
   private String title,row;
   private double price;
   private int seat;
   DecimalFormat fmt = new DecimalFormat("$#0.00");
   public MovieTicket(String newTitle, String newRow, int newSeat, double newPrice)
   {
      title = newTitle;
      row = newRow;
      seat = newSeat;
      price = newPrice;
   }
   
   //accesors
   public String getTitle()
   {
      return title;
   }
   public String getRow()
   {
      return row;
   }
   public int getSeatNum()
   {
      return seat;
   }
   public double getPrice()
   {
      return price;
   }
   
   //mutators
   public void setTitle(String newTitle)
   {
      title = newTitle;
   }
   public void setRow(String newRow)
   {
      row = newRow;
   }
   public void setSeatNum(int newSeat)
   {
      seat = newSeat;
   }
   public void adjustPrice(double newPrice)
   {
      price = newPrice;
   }
   public void discount(double discountRate)
   {
      discountRate = 1-discountRate;
      price = price * discountRate;
   }
   public String toString()
   {  
      String info = "\nTitle:\t" + title +
                    "\nRow:\t" + row +
                    "\nSeat:\t" + seat +
                    "\nPrice:\t" + fmt.format(price) + "\n\n";
      return info;
   }
}
