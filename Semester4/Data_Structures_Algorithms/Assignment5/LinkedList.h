
// Description: A simple linked list that implements a list of Flight objects. A user can
//              perform searching, insertion or deletion on the linked list.
//              //---- is where you should add your own code

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Flight
{
    string airLine;
    int flightNum;
    string deptDate;
    struct Flight* next;
};

class LinkedList
{
	private:
		struct Flight* head;
		int size;      //number of Flight objects inside the linked list
    public:
       	LinkedList();
       	~LinkedList();
       	Flight* getHead();
       	int getSize();
       	bool searchFlight(string airLine, int flightNum, string deptDate);
       	bool insertFlight(string airLine, int flightNum, string deptDate);
       	bool deleteFlight(string airLine, int flightNum, string deptDate);
       	void displayList();
};

//Constructor
LinkedList::LinkedList()
{
    //----
    head = nullptr;
    //---
}

//Destructor
LinkedList::~LinkedList()
{
    //----
    int flightCount = 0;
    while(head!=NULL){
        Flight* pointr = head;
        head=head->next;
        delete pointr;
        flightCount++;
    }
    //---
}

Flight* LinkedList::getHead()
{
    //----
    return head;
}

//Return number of Flights inside the Linked list
int LinkedList::getSize()
{
    //----
    return size;
}

//This function does a linear search on the Flight list with the given flight info.
//it returns true if the corresponding Flight is found, otherwise it returns false.
//Note: each flight is uniquely identified by combination of airLine, flightNum and deptDate
bool LinkedList::searchFlight(string airLine, int flightNum, string deptDate)
{
    //----
    Flight* temp = head;
    
    while(temp!=NULL){
        if(temp->airLine == airLine && temp->flightNum == flightNum && temp->deptDate == deptDate)
        {
            return true; // flight found
        }
        temp = temp->next;
    }
    return false;
    //---
}

//Insert the parameter Flight at the head of the linked list.
//return true if it is inserted successfully and false otherwise
bool LinkedList::insertFlight(string airLine, int flightNum, string deptDate)
{
     //if the Flight already exist, return false
     if (searchFlight(airLine,flightNum,deptDate)==true)
     {
         cout << "\n" << airLine << " " << flightNum << " on " << deptDate << " - Duplicated. NOT added" << endl;
         return false;
     }
     else{
        Flight* newest = new Flight;
        newest->airLine = airLine;
        newest->flightNum = flightNum;
        newest->deptDate = deptDate;
        newest->next = head;
        head=newest;
        size++;
        return true;
     }
     //----
     //---
}

//Delete the Flight with the given info. from the linked list.
//Return true if it is deleted successfully and false otherwise
bool LinkedList::deleteFlight(string airLine, int flightNum, string deptDate)
{
    //----
    Flight* temp = head;
    Flight* prev = nullptr;
    while(temp != NULL){
        if(temp->airLine == airLine && temp->flightNum == flightNum && temp->deptDate == deptDate){
            if(prev == NULL){
                head = temp->next;
                delete temp;
                size--;
                return true;
            }
            prev->next = temp->next;
            delete temp;
            size--;
            return true;
        }
        prev = temp;
        temp = temp->next;
    }
    return false;
    //---
}

//This function displays the content of the linked list.
void LinkedList::displayList()
{
    //----
    Flight* temp = head;
    //----
    while(temp != NULL){
        cout    << left<< setw(5)  << temp->airLine
                << setw(10) << temp->flightNum
                << setw(12) << temp->deptDate  << "\n";
        temp = temp->next;
    }
    //----
    //----
}