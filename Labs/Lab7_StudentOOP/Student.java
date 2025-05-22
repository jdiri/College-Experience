import java.util.Scanner;

class Student
{
   private String firstName, lastName, major; 
   private int grade, totalCredits, id;
   
   
   public Student(int x, String y, String b, String c, int d, int j)
   {
      id = x;
      firstName = y;
      lastName = b;
      major = c;
      grade = d;
      totalCredits = j;
   }
   
   public String getId()
   {
       return "Student ID:\t" + id;
   }
   
   public String getFullName()
   {
      return firstName + " " + lastName;
   }
   
   public String getMajor()
   {
      return major;
   }
   
   public int getGradepoints()
   {
      return grade;
   }
   
   public int getCredits()
   {
      return totalCredits;
   }
   
   //mutator
   public String changeMajor(String newMajor)
   {
      major = newMajor;
      return major;
   }
   
   public String changeMajor(String newMajor, int newPoints, int newCredits)
   {
      Scanner scan = new Scanner(System.in);
      int oldCredits = totalCredits;
      int oldGrade = grade;
      major = newMajor;
      totalCredits = newCredits;
      grade = newPoints;
      if(totalCredits > oldCredits);
      {
         System.out.print("Invalid attempt\n\n");
         totalCredits = oldCredits;
         grade = oldGrade;
      }  
      return major;
   }
   
   // print
   public String toString()
   {
      return "\nID:\t\t\t" + id
              + "\nName:\t\t" + getFullName()
              + "\nMajor:\t\t" + major
              + "\nPoints:\t\t" + grade
              + "\nCredits:\t" + totalCredits + "\n\n";
   }
}
