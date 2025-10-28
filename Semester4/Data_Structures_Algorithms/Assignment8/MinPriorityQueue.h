
//include necessary header file here
//----
#include "string"
#include "ArrivalList.h"

using namespace std;

//represent each node of the graph which is a departure location
//with all the relevant info.
struct Departure
{
    string depAddress;
    double d;
    struct Departure* pi;
    ArrivalList* arrList;
};

//class MinPriorityQueue represents a Min-heap that contains Departure objects.
class MinPriorityQueue
{
    private:
        struct Departure* departureArr;	//a Departure array
        int tCapacity, size;

	public:
        MinPriorityQueue(int capacity);
        ~MinPriorityQueue();

        Departure* getDepartureArr();
        int getSize();
        int getCapacity();
        int isFound(string oneDepAddress);
        bool decreaseKey(int index, Departure oneDepartureWithNewDValue);
        bool insert(Departure oneDeparture);
        void heapify(int index);
        Departure getHeapMin();
        void extractHeapMin();
        int leftChild(int parentIndex);
        int rightChild(int parentIndex);
        int parent(int childIndex);
        void printHeap();
        void build_min_heap();

        //add other function definitions here if 100% necessary
        //----
};


//*********************************************************
void MinPriorityQueue::printHeap()
{
    cout << "\nHeap size = " << getSize() << "\n" << endl;
    cout << left;
    cout << setw(15) << "Departure"
            << setw(12) << "d Value"
            << setw(15) << "PI"
            << "Arrival List" << endl;
    //----
    for(int i = 0;i<size;i++){
        cout << left;
        cout << setw(15)  << departureArr[i].depAddress
            << setw(12) << departureArr[i].d
            << setw(15) << departureArr[i].pi << endl;
    }
    //----
}

//************************************************************
//when you create the dummy node, initialize its d value to be
//50000 which represents infinite large
bool MinPriorityQueue::insert(Departure oneDeparture)
{
    //----
    if (size == tCapacity) {
            tCapacity *= 2;
            Departure* newDepartureArr = new Departure[tCapacity];
            copy(departureArr, departureArr + size, newDepartureArr);
            delete[] departureArr;
            departureArr = newDepartureArr;
        }

        int i = size;
        while (i > 0 && departureArr[parent(i)].d > oneDeparture.d) {
            departureArr[i] = departureArr[parent(i)];
            i = parent(i);
        }
        if(i==0){
            return false;
        }
        departureArr[i] = oneDeparture;
        size++;
        return true;
    //----
}

//****************************************************************************
//Given the original departureArr, the function build a min-heap by using d value
void MinPriorityQueue::build_min_heap()
{
    //----
    for (int i = size / 2 - 1; i >= 0; i--) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && departureArr[left].d < departureArr[smallest].d) {
            smallest = left;
        }

        if (right < size && departureArr[right].d < departureArr[smallest].d) {
            smallest = right;
        }

        if (smallest != i) {
            swap(departureArr[i], departureArr[smallest]);
        }
    }
    //----
}

//According to above class definition, define all other functions accordingly
//----
Departure* MinPriorityQueue::getDepartureArr(){
    return departureArr;
}

int MinPriorityQueue::getCapacity(){
    return tCapacity;
}

int MinPriorityQueue::getSize(){
    return size;
}

MinPriorityQueue::MinPriorityQueue(int capacity){
    departureArr = new Departure[capacity];
    size = 0;
    tCapacity = capacity;
}

MinPriorityQueue::~MinPriorityQueue(){
    delete[] departureArr;
}

int MinPriorityQueue::parent(int i) {
    return (i - 1) / 2;
}

int MinPriorityQueue::leftChild(int i) {
    return 2 * i + 1;
}

int MinPriorityQueue::rightChild(int i) {
    return 2 * i + 2;
}

void MinPriorityQueue::extractHeapMin() {
    if (size == 0) {
        throw "Heap is empty";
    }

    Departure minDeparture = departureArr[0];
    departureArr[0] = departureArr[size - 1];
    size--;
    heapify(0);
}

Departure MinPriorityQueue::getHeapMin(){
    return departureArr[0];
}

void MinPriorityQueue::heapify(int i) {
    int l = leftChild(i);
    int r = rightChild(i);
    int smallest = i;

    if (l < size && departureArr[l].d < departureArr[i].d) {
        smallest = l;
    }
    if (r < size && departureArr[r].d < departureArr[smallest].d) {
        smallest = r;
    }

    if (smallest != i) {
        swap(departureArr[i], departureArr[smallest]);
        heapify(smallest);
    }
}

bool MinPriorityQueue::decreaseKey(int index, Departure oneDepartureWithNewDValue){
    if(index < 0){
        cout << "\nThe old flight number you try to increase does not exist" << endl;
        return false;
    }
    if(index > size){
        return false;
    }
    departureArr[index].d = oneDepartureWithNewDValue.d;
    while (index > 0 && departureArr[index].d < departureArr[parent(index)].d) {
        Departure newF = departureArr[index];
        departureArr[index] = departureArr[parent(index)];
        departureArr[parent(index)] = newF;
        index = parent(index);
        departureArr[parent(index)];
    }
    return true;
}

int MinPriorityQueue::isFound(string oneDepAddress){
    for(int i = 0;i<size;i++){
        if(departureArr[i].depAddress == oneDepAddress){
            return i;
        }
    }
    return -1;
}
//----