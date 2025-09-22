#include <stdio.h>
// Global variables
int n;
// Forward definition 
void readList (int[n]);
void printList (int[n]);
void sortList (int[n]);
// Main function 
int main (){
    // Read the n value from the user
    printf("Please give the number of elements in the list ");
    // ToDo read the number from the user
    scanf("%d",&n);
    // Create the list of numbers
    int list[n];
    // Read the list of numbers
    readList(list);
    // Sort the list
    sortList(list);
    // Print ordered list
    printList(list);
    // Print the mean value in the list
    int meanPosition = n / 2;
    printf("The mean value of the list is:\t%d\n\n", list[meanPosition]);
    return 0;
}
// Function to read the list of numbers
void readList (int l[n]){
    // ToDo write the code to read the list of numbers
    for(int i = 0; i<n; i++){
        printf("Please give the number %d:\t",i);
        scanf("%d",&l[i]);
    }
    printf("\n");
}
// Function to print the list
void printList (int l[n]){
    //ToDo write the code to print the list of numbers
    for(int i = 0; i<n; i++){
        printf("%d\t",l[i]);
    }
    printf("\n\n");
}
// Function to sort the list
void sortList (int l[n]){
//ToDo write the code to sort the list
    int temp;
    for(int j = 0; j<n-1; j++){
        for(int i = 0; i<n-1; i++){
            if(l[i] > l[i+1]){
                temp = l[i];
                l[i] = l[i+1];
                l[i+1] = temp;
            }
        }
    }
}