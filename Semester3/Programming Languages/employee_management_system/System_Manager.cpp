#include "employee.h"
#include <iostream>
#include <string>

#define MAX_EMPLOYEE 20

using namespace std;

void executeAction(char);

int addEmployee(string name_input, int salary_input, int yearOfPublication_input, int ID_input);
void displayEmployeesList(Employee e[], int currentCount);
void sortEmployeesBySalary(Employee e[], int currentCount);
void updateEmployeeSalary(int ID_input);

Employee e[MAX_EMPLOYEE]; // array of objects
int currentCount = 0;     // number of employees in the list

int main()
{
    int addcondition = 0;
    addcondition = addEmployee("John", 10000, 2019, 101); // Expected Outcome: 1
    cout << "addcondition = " << addcondition << endl;
    addcondition = addEmployee("Emma", 9500, 2020, 102); // Expected Outcome: 1
    cout << "addcondition = " << addcondition << endl;
    addcondition = addEmployee("John", 15500, 2021, 102); // Expected Outcome: 0 (employee with ID 102 already exists)
    cout << "addcondition = " << addcondition << endl;
    addcondition = addEmployee("Michael", 17000, 2022, 103); // Expected Outcome: 1
    cout << "addcondition = " << addcondition << endl;
    addcondition = addEmployee("Sarah", 21000, 2018, 104); // Expected Outcome: 1
    cout << "addcondition = " << addcondition << endl;

    displayEmployeesList(e, currentCount); // should display the details of all employees added so far

    char choice = 'i'; // initialized to a dummy value
    do
    {
        cout << "\Management System\n";
        cout << "Please select an action:\n";
        cout << "\t a: add a new employee\n";
        cout << "\t d: display employees list\n";
        cout << "\t s: sort the employees in descending order based on salary (within a range)\n";
        cout << "\t u: update the employee's salary respect to the employee's ID\n";
        cout << "\t q: quit\n";
        cin >> choice;
        cin.ignore(); // ignores the trailing \n
        executeAction(choice);
    } while (choice != 'q');

    return 0;
}

// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
    string name_input;
    int salary_input, yearOfStartDate_input, ID_input, result = 0;

    switch (c)
    {
    case 'a': // add an employee
              // input employee details from user
        cout << "Please enter employee name: ";
        getline(cin, name_input);
        cout << "Please enter salary of the employee: ";
        cin >> salary_input;
        cout << "Please enter the year of employee's start date: ";
        cin >> yearOfStartDate_input;
        cin.ignore();
        cout << "Please enter employee ID: ";
        cin >> ID_input;
        cin.ignore();

        // add the book to the list
        result = addEmployee(name_input, salary_input, yearOfStartDate_input, ID_input);
        if (result == 0)
            cout << "\nThat employee is already in the list or list is full! \n\n";
        else
            cout << "\nEmployee successfully added to the list! \n\n";
        break;

    case 'd': // display the list
        displayEmployeesList(e, currentCount);
        break;

    case 's': // sort the list
        sortEmployeesBySalary(e, currentCount);
        break;

    case 'u': // update the employee's salary respect to the ID
        cout << "Please enter employee ID: ";
        cin >> ID_input;
        cin.ignore();
        updateEmployeeSalary(ID_input);
        break;

    case 'q': // quit
        break;

    default:
        cout << c << " is invalid input!\n";
    }
}

// This function adds a new employee with the details given in function arguments.
// This function returns 1 if the book is added successfully, else it returns 0 for the cases mentioned above.
int addEmployee(string name_input, int salary_imput, int yearOfStartDate_input, int ID_input)
{
    // TODO: Implement function
    // Check if employee already exists in the list
    if(currentCount == 0){
        e[currentCount].setName(name_input);
        e[currentCount].setSalary(salary_imput);
        e[currentCount].setYearOfStartDate(yearOfStartDate_input);
        e[currentCount].setID(ID_input);
	currentCount++;
	return 1;
    }
	for(int i = 0; i<currentCount;i++){
       	    if(e[i].getID() == ID_input)
            return 0;
    	}
    if(currentCount<MAX_EMPLOYEE){
        e[currentCount] = Employee();
        e[currentCount].setName(name_input);
        e[currentCount].setSalary(salary_imput);
        e[currentCount].setYearOfStartDate(yearOfStartDate_input);
        e[currentCount].setID(ID_input);
	currentCount++;
        return 1; // edit this line if needed
    }
    else
        return 0;
}

// Q4 displayEmployeesList
// This function displays the list of employees.
void displayEmployeesList(Employee e[], int currentCount)
{
    // TODO: Implement function
    for(int i = 0; i<currentCount;i++){
        e[i].displayEmployeeDetails();
    }
}

// Q5 sortEmployeesBySalary
// This function sorts the employees in descending order respect to salary, and then display the employees within a given range of salary.

void sortEmployeesBySalary(Employee e[], int currentCount)
{
    Employee tempEmployee;
    int lowerBoundSalary;
    int upperBoundSalary;

    // TODO: Implement function
    cout << "Please enter lower bound: ";
    cin >> lowerBoundSalary;
    cout << "Please enter upper bound: ";
    cin >> upperBoundSalary;

    for(int i = 0; i < currentCount - 1; i++) {
        for(int j = 0; j < currentCount - i - 1; j++) {
            if(e[j].getSalary() < e[j+1].getSalary()) {
                tempEmployee = e[j];
                e[j] = e[j+1];
                e[j+1] = tempEmployee;
            }
        }
    }

    cout << "Employees within salary range [" << lowerBoundSalary << ", " << upperBoundSalary << "]\n";

    for(int i = 0; i < currentCount; i++) {
        if(e[i].getSalary() >= lowerBoundSalary && e[i].getSalary() <= upperBoundSalary) {
            e[i].displayEmployeeDetails();
        }
    }
}

// This functions updates the salary of an employee based on the employee ID.
// Note that the employee ID is unique for each employee.
// If the employee ID is not found in the list, display a message "Employee ID not found!".
// If the employee ID is found, ask the user for the new salary and update the salary of the employee.
void updateEmployeeSalary(int ID_input)
{
    int n_salary;
    // TODO: Implement function
    for(int i = 0; i<currentCount;i++){
        if(e[i].getID() == ID_input){
            cout << "Please enter new Salary ";
            cin >> n_salary;
            e[i].setSalary(n_salary);
	}
    }
}
