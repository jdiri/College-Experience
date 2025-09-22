#include <stdio.h>
#pragma warning(disable : 4996) // needed in VS
#define pow2(x) (x * x)//8*9
#define expMacro(a, b) (a + b + a * a + b * b + a * a * a + b * b * b)
int expFunc(int a, int b) {
return (a + b + a * a + b * b + a * a * a + b * b * b);
}
// Part 1:
void part1(int x) {
int result;
++x;
result = pow2(x);
printf("pow2(8) = %d \n\n", result);
// Why did this error occur? 
// Please provide the answer in your own words as part of the 
// printf statement below.
// 5 points
printf("Explanation: because it multiples 8*9 making the answer 72 so i incrimented x first and just passed x\n\n\n");
}
// Part 2:
// We want to pass incremented value of x and the decremented value of y 
// to the macro and function to compare their outputs in VS and GCC.
// Run this program in Visual Studio(VS) and then again in GCC. 
// Fill the blanks below with the output values for expFunc and expMacro.
// Then correct/edit the function so that expFunc and expMacro produce 
// same correct output of 587.
// (10 points)
// 
void part2(int x, int y) {
int x_copy = x, y_copy = y;
++x_copy; --y_copy;
printf("expFunc(x, y) = %d\nexpMacro(x, y) = %d\n\n", expFunc(++x, --y), 
expMacro(x_copy, y_copy));
printf("In VS, the result of expFunc = 587 and expMacro = 2327 \n"); 
printf("In GCC: the result of expFunc = 587 and expMacro = 1946 \n\n"); 
// Explain in a short sentence why VS and GCC could possibly produce 
// a different value for the same program and for the same input.
// 5 points
printf("Explanation: so i believe this is just the difference in how each compiler compiles the code. for example how each macro recieves its data\n\n");
}
// Do not edit main()  
int main()
{
int x = 7, y = 2;
printf("Part 1:\n\n");
part1(x);
printf("Part 2:\n\n");
part2(x, y);
// while (1); // needed to keep console open in VS
return 0;
}