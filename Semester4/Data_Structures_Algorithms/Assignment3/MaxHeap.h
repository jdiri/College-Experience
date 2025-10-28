//********************************************************
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Each Flight has a unique flightNum
struct Flight
{
    string airLine;
    int flightNum;
    string deptDate;
};

//class MaxHeap represents a max heap that contains Flight objects. The underline data structure
//is a one dimensional array of Flight.
class MaxHeap
{
    private:
    struct Flight* flightArr;	//an array of Flight
    int capacity, size;

	public:
    MaxHeap(int capacity);
    ~MaxHeap();

	Flight* getFlightArr();
	int getSize();
	int getCapacity();
	int isFound(int aFlightNum);
	bool heapIncreaseFlightNum(int index, Flight oneFlightWithNewFlightNum);
	bool heapInsert(string airLine, int flightNum, string deptDate);
	void heapify(int index);
	Flight getHeapMax();
	void extractHeapMax();
	int leftChild(int parentIndex);
	int rightChild(int parentIndex);
	int parent(int childIndex);
	void printHeap();
};

//Constructor to dynamically allocate memory for a heap with the specified capacity
MaxHeap::MaxHeap(int capacity)
{
 	//----
    this->capacity = capacity;
    size = 0;
    this->flightArr = new Flight[capacity];
 	//----
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the heap.
//and prints the number of nodes deleted by it.
MaxHeap::~MaxHeap()
{
 	//----
    delete[] flightArr;
    int flightCount = size;
 	//----
	cout << "\nThe number of deleted flights is: " << flightCount << endl;
}


//Insert the relevant Flight object inside the heap at the correct location
bool MaxHeap::heapInsert(string airLine, int flightNum, string deptDate)
{
	//if the flight already exist, return false
	if (isFound(flightNum)>=0)
	{
		cout << "\nDuplicated flight. Not added" << endl;
		return false;
	}
	//----
    if((size) >= (capacity)){
            capacity = capacity * 2;
            Flight* newHeap = new Flight[capacity];
            for (int i = 0; i < size; i++) {
                newHeap[i] = flightArr[i];
            }
            delete[] flightArr;
            flightArr = newHeap;
            cout << "\nReach the capacity limit, double the capacity now.\n"
                << "\nThe new capacity now is " << capacity << endl;
        }

    Flight* newF = new Flight;
    newF->airLine=airLine;
    newF->flightNum=flightNum;
    newF->deptDate=deptDate;
    
    flightArr[size] = *newF;
    int index = size;
    while (index > 0 && flightArr[index].flightNum > flightArr[parent(index)].flightNum) {
        *newF = flightArr[index];
        flightArr[index] = flightArr[parent(index)];
        flightArr[parent(index)] = *newF;
        index = parent(index);
        flightArr[parent(index)];
    }
    size++;
    return true;
	//----
 }

void MaxHeap::printHeap()
{
	//----
    if(size==0){
        cout << "\nEmpty heap, no elements" << endl;
    }
	//----
    if(size!=0){
        cout << "\nHeap capacity = " << getCapacity() << endl;
        cout << "\nHeap size = " << getSize() << "\n" << endl;
        for(int i = 0;i<size;i++){
            cout << left;
            cout << setw(5)  << flightArr[i].airLine
                << setw(10) << flightArr[i].flightNum
                << setw(12) << flightArr[i].deptDate << endl;
        }
    }
}

//design all other functions according to the function definition and the resulting output testing cases
//----
Flight* MaxHeap::getFlightArr(){
    return flightArr;
}

int MaxHeap::getSize(){
    return size;
}

int MaxHeap::getCapacity(){
    return capacity;
}

int MaxHeap::isFound(int flightNum){
    for(int i = 0;i<size;i++){
        if(flightArr[i].flightNum == flightNum){
            return i;
        }
    }
    return -1;
}

void MaxHeap::heapify(int index){
    int l,r,largest;
    Flight* temp = new Flight;
    l = leftChild(index);
    r = rightChild(index);
    if(l<=size && flightArr[l].flightNum>flightArr[index].flightNum){
        largest = l;
    }
    else {
        largest = index;
    }
    if(r<=size && flightArr[r].flightNum>flightArr[largest].flightNum){
        largest = r;
    }
    if(largest != index){
        *temp = flightArr[index];
        flightArr[index]=flightArr[largest];
        flightArr[largest] = *temp;
        heapify(largest);
    }
    delete temp;
}

int MaxHeap::leftChild(int parentIndex){
    return parentIndex*2+1;
}
int MaxHeap::rightChild(int parentIndex){
    return parentIndex*2+2;
}
int MaxHeap::parent(int childIndex){
    return (childIndex-1)/2;
}

bool MaxHeap::heapIncreaseFlightNum(int index, Flight oneFlightWithNewFlightNum){
    if(index < 0){
        cout << "\nThe old flight number you try to increase does not exist" << endl;
        return false;
    }
    if(index > size){
        return false;
    }
    /*if(flightArr[index].flightNum >= oneFlightWithNewFlightNum.flightNum){
        cout << "\nIncrease flight number error: new flightNum is smaller than the current flightNum" << endl;
        return false;
    }*/
    flightArr[index].flightNum = oneFlightWithNewFlightNum.flightNum;
    while (index > 0 && flightArr[index].flightNum > flightArr[parent(index)].flightNum) {
        Flight newF = flightArr[index];
        flightArr[index] = flightArr[parent(index)];
        flightArr[parent(index)] = newF;
        index = parent(index);
        flightArr[parent(index)];
    }
    return true;
}

Flight MaxHeap::getHeapMax(){
    return flightArr[0];
}

void MaxHeap::extractHeapMax(){
    flightArr[0] = flightArr[size-1];
    size--;
    heapify(0);
}
//----