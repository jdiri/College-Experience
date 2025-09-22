#include <stdio.h>

// Global variables
int n;

// Forward definition 
void initializeTriangle (int[n][n]);
void printTriangle (int[n][n]);
void computePascalTriangle (int[n][n]);

// Main function 
int main (){
	// Read the n value from the user to know how
	// many rows of the Pascal triangle to print
	printf("Please give the number N to print the Pascal triangle	");
	// ToDo read the n value from the user
	scanf("%d",&n);
	// Define the matrix for the Pascal triangle
	int triangle[n][n];

	// Initialize the matrix for the Pascal triangle
	initializeTriangle(triangle);

	// Compute the matrix with the Pascal triangle
	computePascalTriangle(triangle);
	
	// Print the Pascal triangle
	printf("The Pascal triangle with %d rows is:\n", n);
	if(n == 0){
		printf("There is not triangle to print as N was 0 ");
	}
	printTriangle(triangle);
	return 0;
}

// Function to initialize the triangle with all values in 1s
void  initializeTriangle (int t[n][n]){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			t[i][j]=1;
}

// Function to print the triangle
void printTriangle (int t[n][n]){
	//ToDo write the code to print the Pascal triangle
	for(int i = 0;i<n;i++){
		for (int j = 0; j <= i; j++)
		{
			/* code */
			printf("%d\t",t[i][j]);
		}
		printf("\n");
	}
}
 
// Function to compute the Pascal triangle
void computePascalTriangle (int t[n][n]){
	//ToDo write teh code to compute the Pascal triangle
	for(int i = 2;i<n;i++){
		for (int j = 1; j < i; j++)
		{
			/* code */
			t[i][j]=(t[i-1][j-1]+t[i-1][j]);
		}
	}
}
