//include necessary header file here
//----
#include "MinPriorityQueue.h"

using namespace std;

class Graph
{
   private:
   int numOfNode;
   MinPriorityQueue* departureHeap;     //adjacency list of the graph, it is a min-heap
                                        //of Departure objects based on d value
   public:
   Graph(int numOfNode, MinPriorityQueue* departureHeap);
   ~Graph();
   MinPriorityQueue* getDepartureHeap();
   void printGraph();
   void initialize_single_source(string sourceDepAddress);
   void relax(Departure u, Departure v);
   int findOneDeparture(string aDepAddress);
   void dijkstra(string sourceDepAddress);
   void printDijkstraPath(string sourceDepAddress);

   //add any auxiliary functions here in case you need them
   //----
};

//*******************************************************************
//Constructor
Graph::Graph(int numOfNode, MinPriorityQueue* departureHeap)
{
   //----
    this->numOfNode = numOfNode;
    this->departureHeap = departureHeap;
   //----
}

//*******************************************************************
//Destructor Graph::~Graph()
Graph::~Graph()
{
   //----
   delete departureHeap;
   //----
}

//*******************************************************************
//void printGraph();
//This function prints the graph. It traverse through the vertex list,
//then for each vertex, it print its adjacent list from head to tail.
void Graph::printGraph(){
    for (int i = 0; i < numOfNode; i++) {
        Departure current = departureHeap->getDepartureArr()[i];
        cout << "Vertex " << current.depAddress << ": ";
        current.arrList->printArrivalList();
        /*
        Arrival* arrivalL = current.arrList->getHead();
        while (arrivalL->next != nullptr) {
            cout << arrivalL. << " ";
            current = current->getNext();
        }
        cout << endl;
        */
    }
}


//According to above class definition, define all other functions accordingly
//----
MinPriorityQueue* Graph::getDepartureHeap(){
    return departureHeap;
}

void Graph::initialize_single_source(string sourceDepAddress){
    int start = departureHeap->isFound(sourceDepAddress);
    for(int i = 0; i < numOfNode; i++){
        departureHeap->getDepartureArr()[i].d = 5000;
        departureHeap->getDepartureArr()[i].pi = NULL;
    }
    departureHeap->getDepartureArr()[start].d = 0;
}

void Graph::relax(Departure u, Departure v) {
    int uIndex = departureHeap->isFound(u.depAddress);
    int vIndex = departureHeap->isFound(v.depAddress);
    int weight = u.d + v.d;

    if (weight < departureHeap->getDepartureArr()[vIndex].d) {
        departureHeap->getDepartureArr()[vIndex].d = weight;
        int parentIndex = departureHeap->parent(vIndex);
        departureHeap->getDepartureArr()[parentIndex].depAddress = u.depAddress;
    }
}

int Graph::findOneDeparture(string aDepAddress) {
    return departureHeap->isFound(aDepAddress);
}

void Graph::dijkstra(string sourceDepAddress) {
    int temp = numOfNode;
    while (temp != 0) {
        Departure u = departureHeap->getHeapMin();
        departureHeap->extractHeapMin();
        Arrival* current = u.arrList->getHead();

        while (current != nullptr) {
            Departure v = departureHeap->getDepartureArr()[departureHeap->isFound(current->arrAddress)];
            relax(u, v);
            current = current->next;
        }
    }
}

void Graph::printDijkstraPath(string sourceDepAddress) {
    int sourceIndex = departureHeap->isFound(sourceDepAddress);

    for (int i = 0; i < numOfNode; i++) {
        cout << "Shortest path from " << sourceDepAddress << " to " << departureHeap->getDepartureArr()[i].depAddress << ": ";
        string current = departureHeap->getDepartureArr()[i].depAddress;

        while (current != sourceDepAddress) {
            cout << current << " <- ";
            current = departureHeap->getDepartureArr()[departureHeap->parent(sourceIndex)].depAddress;
            departureHeap->getDepartureArr()[departureHeap->parent(sourceIndex)];
        }

        cout << sourceDepAddress << " (Distance: " << departureHeap->getDepartureArr()[i].d << ")" << endl;
    }
}
//----