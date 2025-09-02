// Assignment #: 2
//  Description: construction of a program that reads in an unspecified number of
//               integers from standard input, performs some calculations on these numbers,
//				 and outputs the results.
import java.util.Scanner;
public class Assignment2 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int input, largest = 0, even = 0, pos = 0, sum = 0;
		input = scan.nextInt();
		while(input != 0) {
			if(input % 2 == 0) {
				if(input > even) {
					even = input;
				}
			}
			if(input > 0) {
				pos++;
				if(input > largest) {
					largest = input;
				}
			}
			sum += input;
			input = scan.nextInt();
		}
		System.out.print("The largest integer in the sequence is " + largest);
		System.out.print("\nThe largest even integer in the sequence is " + even);
		System.out.print("\nThe count of positive integers in the sequence is " + pos);
		System.out.print("\nThe sum of all integers is " + sum);
		scan.close();
	}

}



