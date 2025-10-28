// Description: This program displays a menu of choices to a user
//              and performs the chosen task. It will keep asking a user to
//              enter the next choice until the choice of 'Q' (Quit) is entered.
//             	//---- is where you should add your own code
//********************************************************************************

//----
#include "MaxHeap.h"
//----
using namespace std;

void printMenu();
void heapSort(MaxHeap* oneMaxHeap);

int main()
{
	char input1 = 'Z';
	string airLine;
    int flightNum;
	string deptDate;
	int capacity;   //array capacity

	bool success = false;

	//declare any other variables in case you need them
	//----

    Flight oneFlight;

	// instantiate an empty Heap
	MaxHeap* heap1 = nullptr;
	printMenu();

	do {
		cout << "\nWhat action would you like to perform?" << endl;
		cin.get(input1);
		cin.ignore(20, '\n');	//flush the buffer
		input1 = toupper(input1);

		// matches one of the cases
		switch (input1)
		{
			case 'C':	//create empty Heap with the relevant capacity
				cout << "\nPlease enter the heap capacity: ";
				cin >> capacity;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				//----
                heap1 = new MaxHeap(capacity);
				break;

			case 'D':	//delete the heap, call the destructor explicitly
				cout << "\nDelete the heap" << endl;
				//Add your own code
				//----
                heap1->~MaxHeap();
				//re-initialize it with default capacity 5
				//Add your own code
				//----
                heap1 = new MaxHeap(5);
				break;

			case 'E':	//Extract the maximum node
                if (heap1 == nullptr)
                    cout << "\nEmpty heap, can NOT extract max" << endl;
                else
                {
                    //Add your own code
                    //----
                    cout << "\nBefore extract heap max operation:" << endl;
                    heap1->printHeap();
                    cout << "\nAfter extract heap max operation:" << endl;
                    heap1->extractHeapMax();
                    heap1->printHeap();
                }
                break;

			case 'F':	//Find a Flight
				cout << "\nEnter the flight number you want to search: ";
				cin >> flightNum;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				//----
                if(heap1->isFound(flightNum) >= 0){
                    cout << "\nFlight with number: " << flightNum << " is found" << endl;
                }
                else
                    cout << "\nFlight with number: " << flightNum << " is NOT found" << endl;
				break;

			case 'I':	//Insert a Flight
				cout << "\nEnter the flight airLine: ";
				cin >> airLine;

				cout << "\nEnter the flight number: ";
				cin >> flightNum;

				cout << "\nEnter the flight departure date: ";
				cin >> deptDate;

                cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				//----
                oneFlight.airLine = airLine;
                oneFlight.flightNum = flightNum;
                oneFlight.deptDate = deptDate;
                if(heap1->heapInsert(airLine,flightNum,deptDate) == true){
                    cout << "\nFlight: " << airLine << " " << flightNum << " on " << deptDate << " is added" << endl;
                    break;
                }
                cout << "\nFlight: " << airLine << " " << flightNum << " on " << deptDate << " is NOT added" << endl;
				break;

			case 'K':	//increase the FlightNum
                int newFlightNum;
				cout << "\nEnter the original flight number which you want to increase: ";
				cin >> flightNum;
				cout << "\nEnter the new flight number: ";
				cin >> newFlightNum;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				//----
                oneFlight.flightNum = newFlightNum;
                if(heap1->isFound(newFlightNum) >= 0){
                    cout << "\nThe new flight number you entered already exist, increase flight number operation failed";
                    break;
                }
                else if(flightNum>newFlightNum){
                    cout << "\nIncrease flight number error: new number is smaller than current number" << endl;
                    break;
                }
                else if(heap1->isFound(flightNum) >= 0){
                    cout << "\nBefore increase flight number operation:" << endl;
                    heap1->printHeap();
                    cout << "\nFlight with old number: " << flightNum << " is increased to new number: " << newFlightNum << endl;
                    cout << "\nAfter increase flight number operation:" << endl;
                    heap1->heapIncreaseFlightNum(heap1->isFound(flightNum),oneFlight);
                    heap1->printHeap();
                    break;
                }
                heap1->heapIncreaseFlightNum(heap1->isFound(flightNum),oneFlight);
				break;

			case 'M':	//get maximum node
			    //Add your own code
				//----
                if(heap1->getSize()==0){
                    cout << "Empty heap, can NOT get max node" << endl;
                    break;
                }
                oneFlight = heap1->getHeapMax();
                cout << "\nThe maximum heap node is: " << endl;
                cout << left;
                cout << setw(5) << oneFlight.airLine
                    << setw(10) << oneFlight.flightNum
                    << setw(12) << oneFlight.deptDate  << endl;
				break;

			case 'P':	//Print heap contents
			    //Add your own code
				//----
                heap1->printHeap();
				break;

			case 'S':	//HeapSort
				cout << "\nHeap sort. Flights will be sorted in increasing order of their numbers" << endl;
				//Add your own code
				//----
                //heap1.
                heapSort(heap1);
				break;

			case 'Q':	//Quit
				delete heap1;
				break;

			case '?':	//Display Menu
				printMenu();
				break;

			default:
				cout << "\nUnknown action" << endl;
				break;
		} //end of switch
	} while (input1 != 'Q');
	return 0;
}

//***********************************************************************
//Given a max heap, we want to sort it in increasing order of flightNum, put the
//sorting result inside another array and print it out
void heapSort(MaxHeap* oneMaxHeap)
{
    //Add your own code
    //----
    
    MaxHeap* heap = new MaxHeap(oneMaxHeap->getSize());
    int size = 0;
    for(int i = oneMaxHeap->getSize()-1;i>=0;i--){
        heap->getFlightArr()[i] = oneMaxHeap->getHeapMax();
        size++;
        oneMaxHeap->extractHeapMax();
    }
    for(int i = 0; i<size;i++){
        cout << left;
                cout << setw(5) << heap->getFlightArr()[i].airLine
                    << setw(10) << heap->getFlightArr()[i].flightNum
                    << setw(12) << heap->getFlightArr()[i].deptDate  << endl;
    }
}

//**The function displays the menu to a user**
void printMenu()
{
	cout << "Choice\t\tAction\n";
	cout << "------\t\t------\n";
	cout << "C\t\tCreate a heap\n";
	cout << "D\t\tDelete the heap\n";
	cout << "E\t\tExtract max node\n";
	cout << "F\t\tFind a flight by number\n";
	cout << "I\t\tInsert a flight\n";
	cout << "K\t\tIncrease a flight number\n";
	cout << "M\t\tGet the max node\n";
	cout << "P\t\tPrint the heap\n";
	cout << "S\t\tHeap Sort\n";
	cout << "Q\t\tQuit\n";
	cout << "?\t\tDisplay Help\n\n";
}