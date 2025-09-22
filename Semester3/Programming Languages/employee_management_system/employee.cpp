// CSE240 Spring 2023 Assignment 06
// Write your name here

#include "employee.h"
#include <iostream>
#include <string>

using namespace std;

// Q1 Employee constructor
// Employee() constructor assigns the following default values to class data members
// name: abc
// salary (monthly): 10000
// yearOfStartDate: 2000
// ID: 0
Employee::Employee()
{
    // TODO: Implement the constructor
    m_name = "abc";
    m_salary = 10000;
    m_yearOfStartDate = 2000;
    m_ID = 0;
}

// Q2 Employee methods
// 2 points for each method

// Define all the class member methods.
// While defining member methods, note that these methods will be called using
// a 'Employee' object which will represent one employee.
// Eg-  Employee e[20]; creates 20 Employee objects
//		e[3].setID(10); will set 4th employee's ID to 10

// setName assigns 'name_input' to class data member 'name'
void Employee::setName(string name_input)
{
    // TODO: Implement the code below
    m_name = name_input;
}

// setSalary assigns salary_input to class data member 'salary'
void Employee::setSalary(int salary_input)
{
    //  TODO: Implement the code below
    m_salary = salary_input;
}

// setYearOfStartDate assigns 'yearOfStartDate_input' to class data member 'yearOfStartDate'
void Employee::setYearOfStartDate(int yearOfStartDate_input)
{
    // TODO: Implement the the code below
    m_yearOfStartDate = yearOfStartDate_input;
}

// setID assigns 'ID_input' to class data member 'ID'
void Employee::setID(int ID_input)
{
    // TODO: Implement the code below
    m_ID = ID_input;
}

// calculateBonus returns the class data member 'bonus'.
// Bonus is calculated as follows:
// If salary is less than or equal to 10000, bonus is 5% of the salary.
// If salary is between 10001 and 20000, bonus is 10% of the salary.
// If salary is greater than 20000, bonus is 15% of the salary.
float Employee::calculateBonus(int salary_input)
{
    // TODO: Implement the code below
    if(salary_input<=10000&&salary_input>=0)
        return (float)(salary_input * 0.05);
    if(salary_input>10000&&salary_input<=20000)
        return (float)(salary_input * 0.1);
    if(salary_input>20000)
        return (float)(salary_input * 0.15);
    else
	return 1;
}

// calculateTax returns the class data member 'tax'.
// Tax is calculated as follows:
// If salary is less than or equal to 10000, tax is 0%.
// If salary is greater than 10000 and less than or equal to 20000, tax is 10%.
// If salary is greater than 20000, tax is 20%.
float Employee::calculateTax(int salary_input)
{
    // TODO: Implement the code below
    if(salary_input<=10000&&salary_input>=0)
        return 0;
    if(salary_input>10000&&salary_input<=20000)
        return 0.1;
    if(salary_input>20000)
        return 0.2;
    else
	return 1;
}

// displayEmployee displays the name, salary, Start Date Year, ID, Bonus and Tax of the employee
// See expected output in question file.
void Employee::displayEmployeeDetails()
{
    cout << "Name: " << m_name << endl;
    cout << "Salary: " << m_salary << endl;
    cout << "Start Date Year: " << m_yearOfStartDate << endl;
    cout << "ID: " << m_ID << endl;
    cout << "Bonus: " << calculateBonus(m_salary) << endl;
    cout << "Tax: " << calculateTax(m_salary) << endl;
    cout << "-----------------------------\n";
}

// getName returns the class data member 'name'.
string Employee::getName()
{
    // TODO: Implement the code below
    return m_name;
}

// getSalary returns the class data member 'salary'.
int Employee::getSalary()
{
    // TODO: Implement the code below
    return m_salary;
}

// getYearOfStartDate returns the class data member 'yearOfPublication'.
int Employee::getYearOfStartDate()
{
    // TODO: Implement the code below
    return m_yearOfStartDate;
}

// getID returns the class data member 'ID'.
int Employee::getID()
{
    // TODO: Implement the code below
    return m_ID;
}
