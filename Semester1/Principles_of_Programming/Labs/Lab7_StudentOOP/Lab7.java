//import student.java;
import java.util.Scanner;

class Lab7
{
   public static void main(String[] args)
   {
      System.out.println();
      Student student1;
      Scanner scan = new Scanner(System.in);
      //System.out.print("Enter first name: ");
      String a = scan.nextLine();
      //System.out.print("Enter last name: ");
      String b = scan.nextLine();
      //System.out.print("Enter student major: ");
      String c = scan.nextLine();
      //System.out.print("Enter student ID: ");
      int d = scan.nextInt();
      //System.out.print("Enter # of points: ");
      int e = scan.nextInt();
      //System.out.print("Enter # of credits: ");
      int f = scan.nextInt();
      
      student1 = new Student(d, a, b, c, e, f);
      System.out.print("Student Name: \t" + student1.getFullName() + "\n");
      System.out.print("\n" + student1.getId() + "\n");
      System.out.print(student1);
      
      System.out.print(student1.getFullName() + " has changed major from " + student1.getMajor() + " to " + student1.changeMajor("International Affairs", 345,1000) + "\n");
      System.out.print(student1);
   }
   
}
