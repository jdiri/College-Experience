import java.util.Scanner;

public class Lab8
{ 
    public static void main(String[] args)
    {
         Scanner scan = new Scanner(System.in);
         int size, numOfNeg = 0;
         double element, sum = 0.0, largest;
         
         size = scan.nextInt();
         double[] array = new double[size];
         
         //initialize array values
         for(int i = 0; i < array.length; i++)
         {
            element = scan.nextDouble();
            array[i] = element;
         }
         
         largest = array[0];
         
         System.out.print("\nArray content is: ");
         double temp;
         //reverse the array
         for(int i = 0; i < size/2; i++)
         {  
            temp = array[i];
            array[i] = array[size-i-1];
            array[size-i-1] = temp;
         }
         //print it        
         for(int i = 0; i < size; i++)
         {
            
            System.out.print(array[i] + " ");
            if(largest < array[i])
               largest = array[i];
            if(array[i] < 0)
               numOfNeg++;
            
            sum += array[i];
         }
         System.out.println();
         System.out.print("\nSum of the array elements is " + sum);
         System.out.print("\n\n" + numOfNeg + " array elements are negative.");  
         System.out.print("\n\nThe largest array element is " + largest);     
    }      
   
}
