import java.util.Scanner;
import java.text.DecimalFormat;
 
public class Lab9
{ 
    public static void main(String[] args)
    {
      Scanner scan = new Scanner(System.in);
      DecimalFormat fmt = new DecimalFormat("#0.00");
      double sum = 0, avg;
      final int monkeys = 3;
      final int days = 7;
      double[][] pounds = new double[monkeys][days];
      for(int i = 0; i < pounds.length; i++)
      {
         for(int j = 0; j < pounds[0].length;j++)
         {
            pounds[i][j] = scan.nextDouble();
         }
      }
      
      sum += findGroupTotal(pounds);
      avg = sum/days;
      System.out.print("\nAverage amount of food eaten per day\nby the entire family of monkeys = " + fmt.format(avg) + " pounds.\n");
      double leastAmount = findLeastAmtFood(pounds);
      System.out.print("\nLeast amount of food eaten all week by any monkeys is: " + fmt.format(leastAmount) + " pounds.");
      //compute total/monkey
      double tot1 = 0, tot2 = 0, tot3 = 0;
      for(int i = 0; i < pounds[0].length;i++)
         tot1 += pounds[0][i];
      System.out.print("\nMonkey #1 eat total of " + fmt.format(tot1) + " pounds of food in this week.\n");
      for(int i = 0; i < pounds[0].length;i++)
         tot2 += pounds[1][i];
      System.out.print("\nMonkey #2 eat total of " + fmt.format(tot2) + " pounds of food in this week.\n");
      for(int i = 0; i < pounds[0].length;i++)
         tot3 += pounds[2][i];
      System.out.print("\nMonkey #3 eat total of " + fmt.format(tot3) + " pounds of food in this week.\n");
      
      //compute total on monday
      double mondayTotal = 0, satTotal = 0;
      for(int i = 0; i < pounds.length;i++)
         mondayTotal += pounds[i][0];
      System.out.print("\nThe 3 monkeys eat an average " + fmt.format(mondayTotal/monkeys) + " pounds of food on Monday.\n");
      for(int i = 0; i < pounds.length;i++)
         satTotal += pounds[i][5];
      System.out.print("\nThe 3 monkeys eat an average " + fmt.format(satTotal/monkeys) + " pounds of food on Saturday.");
    } 
    
    public static double findGroupTotal(double[][] a2DArray)
    {
      double sum = 0;
      for(int i = 0; i < a2DArray.length; i++)
      {
         for(int j = 0; j < a2DArray[0].length;j++)
         {
            sum += a2DArray[i][j];
         }
      }
      return sum;
    }
    
    public static double findLeastAmtFood(double[][] a2DArray)
    {
      double smallest = a2DArray[0][0];
      for(int i = 0; i < a2DArray.length; i++)
      {
         for(int j = 0; j < a2DArray[0].length;j++)
         {
            if(a2DArray[i][j] < smallest)
               smallest = a2DArray[i][j];
         }
      }
      return smallest;
    }
}
