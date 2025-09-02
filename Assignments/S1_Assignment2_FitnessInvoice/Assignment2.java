 // Description: learn  Math lang
 
 import java.util.Scanner;
 import java.text.DecimalFormat;
 
 class Assignment2
 {
   public static void main(String[] args)
   {
      Scanner scan = new Scanner(System.in);
      DecimalFormat fmt = new DecimalFormat("$0.00");
      
      int category, people;
      String name;
      char orderAnswer, deliveryAnswer;
      double deliveryCharge = 0.0;
      double memTotal, month = 44.50, shirtCharge, memPrice, famPrice;
      
      
      System.out.println("***** Mountainside Fitness Center Program *****");
      System.out.println("Category #1\tMonth-To-Month Membership\t$44.50 per month");
      System.out.println("Category #2\t3-Month Membership\t\t10% discount");
      System.out.println("Category #3\t6-Month Membership\t\t15% discount");
      System.out.println("Category #4\t12-Month Membership\t\t20% discount");
      System.out.println("======================================");
      System.out.println("Mountainside Fitness Center Invoice\n");
      
      //name
      System.out.println("Customer Name:");
      name = scan.nextLine();
      
      //category
      //System.out.println("Pick membership category (enter 1~4):");
      category = scan.nextInt();
     
      //shirts
      //System.out.println("Number of people:");
      people = scan.nextInt();
      //System.out.print("Do you want to purchase group sport shirts for each member?(Y/N):");
      orderAnswer = (scan.next()).charAt(0);
      if(orderAnswer == 'y' || orderAnswer == 'Y')
      {
         shirtCharge = people*24.99;
         //System.out.println("Do you want the shirts delivered?(Y/N):");
         deliveryAnswer = scan.next().charAt(0);
         if(deliveryAnswer == 'y' || deliveryAnswer == 'Y')
         {
            deliveryCharge = people*4.99;
            if(deliveryCharge > 50)
            {
            deliveryCharge = 50;
            }
         } 
      } 
      else
      {
         shirtCharge = 0.0;
         deliveryCharge = 0.0; 
      }      
      switch(category) 
      {
         case 1:
            memPrice = month;
            famPrice = memPrice*people;
            break;
         case 2:
            memPrice = 3*(month * .9);
            famPrice = memPrice*people;
            break;
         case 3:
            memPrice = 6*(month * .85);
            famPrice = memPrice * people;
            break;
         case 4:
            memPrice = 12*(month * .8);
            famPrice = memPrice * people;
            break;
         default:
            System.out.println("Error");
            memPrice = 0;
            famPrice = 0;
            break;
         
      }
      System.out.println("Customer: " + name);
      System.out.println(people + " people @ " + fmt.format(memPrice) + " each = " + fmt.format(famPrice));
      System.out.println("Group shirt charge = " + fmt.format(shirtCharge));
      System.out.println("Delivery charge = " + fmt.format(deliveryCharge));
      memTotal = famPrice + shirtCharge + deliveryCharge;
      System.out.println("Total amount due = " + fmt.format(memTotal));
   }
}
      
      
   
