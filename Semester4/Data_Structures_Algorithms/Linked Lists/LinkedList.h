
// Description: this is the header file containing all the methods and functions for the main classs' 
//Flight linked list

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Flight represents a departure flight
struct Flight
{
    string airLine;
    int flightNum;
    string deptDate;        //departure date
    struct Flight* next;
};

//class LinkedList will contains a linked list of flights
class LinkedList
{
    private:
        struct Flight* head;

    public:
        LinkedList();
        ~LinkedList();
        bool searchFlight(string airLine, int flightNum, string deptDate);
        bool addFlight(string airLine, int flightNum, string deptDate);
        void displayAllFlights();
        void displayFlightsByAirLine(string airLine);
        void displayFlightsByDate(string date);
        bool cancelOneFlight(string airLine, int flightNum, string deptDate);
        bool cancelFlightsByAirLine(string airLine);
        bool cancelFlightsByDate(string deptDate);
        bool delayAFlight(string airLine, int flightNum, string oldDeptDate, string newDeptDate);
        bool changeAFlightAirLine(string oldAirLine, int flightNum, string deptDate, string newAirLine);
};

//Constructor to initialize an empty linked list
LinkedList::LinkedList()
{
    //Add your own code
    //----
    head = nullptr;

}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the existing linked list.
//It deletes all the nodes including the head and finally prints the number of nodes deleted by it.
//Return value: Prints the number of nodes deleted by it.
LinkedList::~LinkedList()
{
	//Add your own code
    //----
    int flightCount = 0;
    while(head!=NULL){
        Flight* pointr = head;
        head=head->next;
        delete pointr;
        flightCount++;
    }
    cout<< "\nThe number of deleted flights is: " << flightCount << "\n";
}

//A function to find if the parameterized flight is inside the LinkedList or not.
//Return true if it exists and false otherwise.
bool LinkedList::searchFlight(string airLine, int flightNum, string deptDate)
{
	//Add your own code
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
}

//***This is the most important function you need to work on since it build the linked list****
//Creates a new node and inserts it into the list at the right place.
//It also maintains an alphabetical ordering of flights by the airLine, flight number
//and departure date. i.e. first by airLine, then by flight numbers. i.e. if two flights
//come from the same airline, the flight should be inserted by the increasing order of
//their flight numbers. Also it is possible that two or more flights have same airline
//and flight numbers, but with different departure date, then they should be inserted into
//the list by departure date. Early departure date flight should be put in front.
//Return value: true if it is successfully inserted and false in case of failures.
//Note: You should always consider 1) if list is empty; 2) if insert at the front, etc.
bool LinkedList::addFlight(string airLine, int flightNum, string deptDate)
{
    Flight* newest = new Flight;
    newest->airLine = airLine;
    newest->flightNum = flightNum;
    newest->deptDate = deptDate;
    newest->next = nullptr;

    if (head == nullptr) {     //check to see if the list is empty
        head = newest;
        return true;
    }else if(newest->airLine.compare(head->airLine)<0){   //checks to see if it should be placed before the head
        newest->next = head;
        head = newest;
        return true;
    }else if(newest->airLine.compare(head->airLine)==0 && newest->flightNum<head->flightNum){  //checks to see if it should be placed before the head
        newest->next = head;
        head = newest;
        return true;
    }else if(newest->airLine.compare(head->airLine)==0 && newest->flightNum==head->flightNum && newest->deptDate.compare(head->deptDate)<0){  //checks to see if it should be placed before the head
        newest->next = head;
        head = newest;
        return true;
    }else if(newest->airLine.compare(head->airLine)==0 && newest->flightNum==head->flightNum && newest->deptDate.compare(head->deptDate)==0){ //checks to see if the flights already there
        return false;
    }else{
    Flight* current = head;
    Flight* previous = nullptr;
    while (current != nullptr) {   //add it where it needs to go
        previous = current;
        current = current->next;
        if (current == nullptr) {
        break;
        }
        if(newest->airLine.compare(current->airLine)<0){
            break;
        }else if(newest->airLine.compare(current->airLine)==0 && newest->flightNum<current->flightNum){
            break;
        }else if(newest->airLine.compare(current->airLine)==0 && newest->flightNum==current->flightNum && newest->deptDate.compare(current->deptDate)<0){
            break;
        }else if(newest->airLine.compare(current->airLine)==0 && newest->flightNum==current->flightNum && newest->deptDate.compare(current->deptDate)==0){
            return false;
        }
    }
    if (current == nullptr) {
    previous->next = newest;
    //newest->next = nullptr; // Set the next pointer of the newest node to nullptr
    }else{
    previous->next = newest;
    newest->next = current;
    }
    return true;
    }
}

//Display all flights in the linked list starting from the head.
void LinkedList::displayAllFlights()
{
    //Add your own code
    //----
    int counter = 0;
    Flight* temp = head;
    while(temp != NULL){
        cout << left    << setw(5)  << temp->airLine
                        << setw(10) << temp->flightNum
                        << setw(12) << temp->deptDate   << "\n";
        counter++;
        temp = temp->next;
    }
    cout << "\nTotal # of flights: " << counter << "\n";
    
}

//Display all flights in the list with the specified airLine.
void LinkedList::displayFlightsByAirLine(string airLine)
{
    //Add your own code
    //----
    int counter = 0;
    Flight* temp = head;
    //cout <<"\n";
    while(temp != NULL){
        if(temp->airLine == airLine){
            cout << left    << setw(5)  << temp->airLine
                            << setw(10) << temp->flightNum
                            << setw(12) << temp->deptDate   << "\n";
            counter++;
        }
        temp = temp->next;
    }
	if (counter == 0)//add your own condition------done
        cout << "\nNo flights with the specified airLine found\n";
    else
        cout << "\nTotal: " << counter << " flights found with airline " << airLine << "\n";
}

//Display all flights with the specified date
void LinkedList::displayFlightsByDate(string date)
{
    //Add your own code
    //----
    int counter = 0;
    Flight* temp = head;
    //cout <<"\n";
    while(temp != NULL){
        if(temp->deptDate == date){
            cout << left    << setw(5)  << temp->airLine
                            << setw(10) << temp->flightNum
                            << setw(12) << temp->deptDate   << "\n";
            counter++;
        }
        temp = temp->next;
    }
	if (counter == 0)//add your own condition-------done
        cout << "\nNo flights with the specified date found\n";
    else
        cout << "\nTotal: " << counter << " flights found on " << date << "\n";
}

//Cancel the specified flight from the list, releases the memory and updates pointers.
//Return true if it is successfully canceled, false otherwise.
bool LinkedList::cancelOneFlight(string airLine, int flightNum, string deptDate)
{
    //Add your own code
    //----
    Flight* temp = head;
    Flight* prev = NULL;
    while(temp != NULL){
        if(temp->airLine.compare(airLine) == 0 && temp->flightNum == flightNum && temp->deptDate.compare(deptDate) == 0){
            /*cout << left    << setw(5)  << temp->airLine
                            << setw(10) << temp->flightNum
                            << setw(12) << temp->deptDate   << "\n";*/
            if(prev == NULL){
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->next;
    }
    return false;
}

//Cancel all flights from a specific airline, releases the memory and updates pointers.
//Return true if it is successfully canceled, false otherwise. Note: multiple flights
//might be canceled
bool LinkedList::cancelFlightsByAirLine(string airLine)
{
    Flight* temp = head;
    Flight* prev = NULL;
    bool canceled = false;

    while(temp != NULL){
        if(temp->airLine == airLine){
            if(prev == NULL){
                // If the first node matches the airline, update the head pointer
                head = temp->next;
            } else {
                // If a middle or last node matches the airline, update the previous node's next pointer
                prev->next = temp->next;
            }
            
            Flight* toDelete = temp;
            temp = temp->next;
            delete toDelete;

            canceled = true;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    return canceled;
}
/*bool LinkedList::cancelFlightsByAirLine(string airLine)
{
    //Add your own code
    //----
    Flight* temp = head;
    while(temp != NULL){
        if(temp->airLine == airLine){
            delete temp;
        }
        temp = temp->next;
    }
    return false;
}*/

//Removes all flights with the specified date, releases the memory and updates pointers.
//Return true if they are successfully removed, false otherwise. Note: all Flights with
//the same departure date should be removed from the list.
bool LinkedList::cancelFlightsByDate(string deptDate)
{
    //Add your own code
    //----
    Flight* current = head;
    Flight* previous = nullptr;
    bool removed = false;

    while (current != nullptr) {
        if (current->deptDate == deptDate) {
            if (previous == nullptr) {
                // If the flight to be removed is the head, update the head pointer
                head = current->next;
            } else {
                // If the flight to be removed is not the head, update the previous flight's next pointer
                previous->next = current->next;
            }

            // Delete the flight and release the memory
            delete current;

            // Move to the next flight
            current = previous == nullptr ? head : previous->next;

            removed = true;
        } else {
            // Move to the next flight
            previous = current;
            current = current->next;
        }
    }
    return removed;
}

//Modifies the departure date of the given flight. Return true if it modifies successfully and
//false otherwise.
bool LinkedList::delayAFlight(string airLine, int flightNum, string oldDeptDate, string newDeptDate)
{
    //Add your own code
    //----
    Flight* temp = head;
    Flight* prev = nullptr;
    while(temp!=NULL){
        if(temp->airLine == airLine && temp->flightNum == flightNum && temp->deptDate == oldDeptDate)
        {   
            prev->next=temp->next;
            delete temp;
            this->addFlight(airLine,flightNum,newDeptDate);
            return true;
        }
        prev=temp;
        temp = temp->next;
    }
    return false;
}

//Change a specific flight airline info. if it is found and change its airline successfully, return
//true; otherwise return false. Note: after successfully change its airline information, the linked list must
//still be in alphabetical order
bool LinkedList::changeAFlightAirLine(string oldAirLine, int flightNum, string deptDate, string newAirLine)
{
    //Add your own code
    //----
    Flight* temp = head;
    Flight* prev = nullptr;
    while(temp->next!=NULL){
        if(temp->airLine == oldAirLine && temp->flightNum == flightNum && temp->deptDate == deptDate)
        {
            prev->next=temp->next;
            delete temp;
            this->addFlight(newAirLine,flightNum,deptDate);
            return true;
        }
        prev = temp;
        temp = temp->next;
    }
    if(temp->airLine == oldAirLine && temp->flightNum == flightNum && temp->deptDate == deptDate){
            prev->next=temp->next;
            delete temp;
            this->addFlight(newAirLine,flightNum,deptDate);
            return true;
    }
    return false;
}
