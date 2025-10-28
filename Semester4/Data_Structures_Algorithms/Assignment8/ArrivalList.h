
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Arrival represents an arrival address with distance and road
//category info. from a specific departure address
struct Arrival
{
    string arrAddress;
    double distance;        //miles from the departure location to this arrival address
    string roadCategory;    //Interstates, Arterials, Collectors or Local streets
    struct Arrival* next;
};

//class ArrivalList contains a linked list of Arrival objects
class ArrivalList
{
    private:
        struct Arrival* head;

    public:
        ArrivalList();
        ~ArrivalList();
        Arrival* getHead();
        Arrival* findArrival(string oneAddress);
        bool addArrival(string oneAddress, double distance, string roadCategory);
        void printArrivalList();
};

ArrivalList::ArrivalList(){
    head = nullptr;
}

//*****************************************************************************************************
//Destructor. Before termination, the destructor is called to free the associated memory occupied by the
//existing linked list. It deletes all the Arrivals including the head and finally prints the number of
//Arrival deleted by it.
//----
ArrivalList::~ArrivalList(){
//----
    int addressCount;
    while(head->next!=nullptr){
        Arrival* current = head;
        head = head->next;
        delete current;
        addressCount++;
    }
    cout<< "The number of deleted arrival addresses are: " << addressCount <<"\n";
}
//According to above class definition, define all functions accordingly
//----
//----
Arrival* ArrivalList::getHead(){
    return head;
}
Arrival* ArrivalList::findArrival(string oneAddress){
    Arrival* current = head;
        while (current != nullptr) {
            if (current->arrAddress == oneAddress) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
}
bool ArrivalList::addArrival(string oneAddress, double distance, string roadCategory){
    Arrival* newNode = new Arrival;
    newNode->arrAddress = oneAddress;
    newNode->distance = distance;
    newNode->roadCategory = roadCategory;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Arrival* current = head;
        Arrival* prev = nullptr;
        while (current != nullptr && current->arrAddress < oneAddress) {
            prev = current;
            current = current->next;
        }
        if (prev == nullptr) {
            newNode->next = head;
            head = newNode;
        }
        else {
            prev->next = newNode;
            newNode->next = current;
        }
    }
    return true;
}

//Prints all the arrival address in the linked list starting from the head.
void ArrivalList::printArrivalList()
{
    //----
    Arrival* temp = head;
    while(temp->next!=nullptr)
    //----
    {
		cout << temp->arrAddress
             << fixed << setprecision(2) << "(" << temp->distance << "/" << temp->roadCategory << "),";
		temp = temp->next;
	}
	cout <<"\n";
}