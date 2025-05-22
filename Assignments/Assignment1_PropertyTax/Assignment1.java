


import java.util.Scanner; 
import java.lang.Math;
import java.text.DecimalFormat;

class Assignment1

{
   public static void main(String[] args)
   {
      //create variables
      double propertyValue, quarterlyPay, assesedValue, propertyTax, tax;
      String fullName, address;
      int age;
      
      //create a decimalformat
      DecimalFormat fmt1 = new DecimalFormat("$##,##0.00");
      
      //scanner creation
      Scanner scan = new Scanner(System.in);
      
      //now i create out put to aquire name address and age
      //System.out.println("Enter home owner's name: ");
      fullName = scan.nextLine();
      //System.out.println("Enter property's address: ");
      address = scan.nextLine();
      //System.out.println("Enter home owner's age: ");
      age = scan.nextInt();
      //System.out.println("whats the full value of the property");
      propertyValue = scan.nextDouble();
      //System.out.println("Enter tax rate: ");
      tax = scan.nextDouble();
      
      //calculations
      assesedValue = propertyValue * .6;
      if (age > 65) 
         {
            assesedValue = assesedValue - 5000;
         }
      propertyTax = (assesedValue/100)*tax;
      
      
      //output
      System.out.println("****** Maricopa County Property Tax Report ******");
      System.out.println("Owner:\t\t" + fullName);
      System.out.println("Address:\t" + address);
      System.out.println("Age:\t\t" + age);
      System.out.println("\nProperty Value:\t" + fmt1.format(propertyValue));
      System.out.println("Assessed Value:\t" + fmt1.format(assesedValue));
      if (age > 65)
         {
            System.out.println("Senior Exemp:\t$5,000.00");
         }
      else
         {
            System.out.println("Senior Exemp:\t$0.00");
         }   
      System.out.println("Property Tax:\t" + fmt1.format(propertyTax));
      quarterlyPay = propertyTax/4;
      System.out.println("Qtly Payment:\t" + fmt1.format(quarterlyPay));

   }
}
