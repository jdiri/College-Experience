import java.util.Scanner;
import java.text.DecimalFormat;
class Assignment6
{
   static int j = 0;
   //static double sum = 0;
   static int finalAvg;
   static DecimalFormat fmt = new DecimalFormat("$###,###.00");
   public static void main(String[] args)
   {
      Scanner scan = new Scanner(System.in);
      int reps = 30;
      double[] money = new double[reps];
      String[] name = new String[reps];
      boolean Continue = true;
      char answer = 'y';
      int i = 0;
      while(Continue){
            name[i] = scan.nextLine();
            money[i] = scan.nextDouble();
            scan.nextLine();
            answer = scan.next().charAt(0);
            scan.nextLine();
            if(answer == 'n'|| answer == 'N')
            {
               Continue = false;
            }
            i++;
            j++;
            }
      System.out.print("\n=== PPG Industries Sales Report ===");
      printPerformance(money, name, getAverage(money, money.length), name.length);     
   }
   
   public static double getTotal(double[] salesArray, int size)
   {  
      double sum = 0;
      for(int i = 0; i < size; i++)
      {
         sum += salesArray[i];
      }
      return sum;
   }
   
   public static double getAverage(double[] array, int size)
   {
      double sum = 0;
      int i;
      for(i = 0; i < size; i++)
      {
         sum += array[i];
      }
      sum /= j;
      return sum;
   }
   
   public static int getHighestIndex(double[] array, int size)
   {
      int i = 0;
      double largest = array[0];
      while(i < array.length) {
         if(array[i] > largest)
         {
            largest = array[i];
            return i;
         }
         i++;
      }
      return i-array.length;
   }
   
   public static int getLowestIndex(double[] array, int size)
   {
      int i = 0;
      double lowest = array[0];
      while(i < array.length) {
         if(array[i] < lowest)
         {
            lowest = array[i];
            return i;
         }
         i++;
      }
      return i-array.length;
   }
   
   public static int countAboveAverage(double[] array, int size)
   {
      double sum = 0;
      for(int i = 0; i < size; i++)
      {
         sum += array[i];
      }
      finalAvg = (int)sum/size;
      int avgCount = 0;
      for(int i = 0; i < size; i++)
      {
         if(array[i] >= finalAvg)
         {
            avgCount++;
            
         }
      }
      return avgCount;
   }
   
   public static void printPerformance(double[] revenueArray, String[] nameArray, double avgRev, int size)
   {
      System.out.print("\nNumber of sales person: " + j);
      System.out.print("\nTotal sales revenue: $" + fmt.format(getTotal(revenueArray, j)));
      System.out.print("\nAverage sales revenue: $" + fmt.format(getAverage(revenueArray, j)));
      System.out.print("\n" + countAboveAverage(revenueArray, j) + " salesperson's revenue are above average");
      System.out.print("\n" + nameArray[getHighestIndex(revenueArray, revenueArray.length)+1] + " has the highest sales revenue of $" + fmt.format(revenueArray[getHighestIndex(revenueArray, j)+1]));
      System.out.print("\n" + nameArray[getLowestIndex(revenueArray, revenueArray.length)] + " has the lowest sales revenue of $" + fmt.format(revenueArray[getLowestIndex(revenueArray, j)]) + "\n");
      System.out.print("\n=== Individual Sales Performance Report ===\n");
      System.out.print("Name\t\t\t   Sales Revenue\t  Above Avg");
      for(int i = 0; i < j; i++)
      {
         System.out.printf("\n" + nameArray[i] + "\t\t " + fmt.format(revenueArray[i]));
         if(revenueArray[i] >= finalAvg)
            System.out.print("\t\t  yes");
         else
            System.out.print("\t\t no");
      }
   }
}
