import java.text.DecimalFormat;
class Clothes
{
   private int ID;
   private double price;
   private String color, size;
   DecimalFormat fmt = new DecimalFormat("$##.00");
   //constructer
   public Clothes(int newId, String sizeNew, String colorNew, double newPrice)
   {
      ID = newId;
      price = newPrice;
      color = colorNew;
      size = sizeNew;
   }
   
   //calling methods
   public int getId()
   {
      return ID;
   }
   
   public String getSize()
   {
      return size;
   }
   
   public String getColor()
   {
      return color;
   }
   
   public double getPrice()
   {
      return price;
   }
   
   //modifier methods
   public void changeId(int newId)
   {
      ID = newId;
   }
   
   public void changeSize(String newSize)
   {
      size = newSize;
   }
   
   public void changeColor(String newColor)
   {
      color = newColor;
   }
   
   public void raisePrice(double raiseRate)
   {
      raiseRate = raiseRate+1;
      price = price * raiseRate; 
   }
   
   public void reducePrice(double reduceRate)
   {
      reduceRate = 1-reduceRate;
      price = price * reduceRate;
   }
   public String toString()
   {
      String info = "\nID:\t\t" + ID +
                    "\nSize:\t" + size +
                    "\nColor:\t" + color +
                    "\nPrice:\t" + fmt.format(price) + "\n";
      return info;
   }
}
