
//include necessary header file here
//----
#include "sstream"
#include "Graph.h"

using namespace std;

void getDepartureInfo(string oneLine, string& depAddress, ArrivalList* arrList);
void getArrivalInfo(string oneArrivalInfo, string& arrAddress, double& distance, string& roadCategory); //**optional

int main()
{
    try{
   int count;       //a variable for number of nodes
   string oneLine, sourceDepAddress;
   string answer = "yes";       //a variable to decide whether to run Dijkstra multiple times or not

   //cout << "Enter number of departure address: ";
   cin >> count;
   cin.ignore(20, '\n');

   //Create an array called 'departureArr' that holds 'count' number of Departure objects
   //----
   MinPriorityQueue* departureHeap = new MinPriorityQueue(count);
   Departure* departureArr = departureHeap->getDepartureArr();
   //Initialize departureArr. Note: you will need to initialize each of the instance variable
   //including arrival list
   for(int i = 0; i < count; i++)
   {
      departureArr[i].d = 10000.0 + i;  //***this is to make sure each node has different d value
      //----
      departureArr[i].pi = NULL;
        departureArr[i].arrList = new ArrivalList();
      //----
   }

   //get input line by line and create the departureArr
   for(int i = 0; i< count; i++)
   {
      getline(cin, oneLine);
      //----
      getDepartureInfo(oneLine, departureArr[i].depAddress, (departureArr[i].arrList));
      //----
   }
  //create a Graph object
  //----
  Graph graph(count,departureHeap);

   //print the graph adjacency list before running Dijkstra algorithm
   cout << "\nPrint the graph adjacency list before running Dijkstra algorithm" << endl;
   //----
   graph.printGraph();

   //Next you need to design a sentinel value controlled while loop base on 'answer'
   //If user answer is 'yes', get departure address, run Dijkstra algorithm, print
   //shortest traveling time and path, then ask whether user want to continue or not...
    while (answer == "yes"){
        cout << "Enter source departure address: ";
        getline(cin, sourceDepAddress);

        // Find the source departure address in the departureArr
        int sourceIndex = -1;
        for (int i = 0; i < count; i++){
            if (departureArr[i].depAddress == sourceDepAddress){
                sourceIndex = i;
                break;
            }
        }
        if (sourceIndex != -1){
            // Run Dijkstra algorithm
            graph.dijkstra(departureArr[sourceIndex].depAddress);

            // Print the shortest traveling time and path
            graph.printDijkstraPath(departureArr[sourceIndex].depAddress);

            cout << "Do you want to continue? (yes/no): ";
            cin >> answer;
            cin.ignore(20, '\n');
        }
      else
      {
         cout << "Source departure address not found!" << endl;
      }
   }

   delete[] departureArr;

   return 0;
   } catch (const char* exceptionString) {
}
}

//********************************************************************************
//Give one line in input file, this function extract tokens and get departure address
//and all arrival info.
void getDepartureInfo(string oneLine, string& depAddress, ArrivalList* arrList)
{
   //----
   // Extract the departure address from the given string
   stringstream ss(oneLine);
   string token;

   // Extract the departure address
   getline(ss, depAddress, ',');

   // Extract the arrival information
   while (getline(ss, token, ','))
   {
      string arrAddress;
      double distance;
      string roadCategory;
      getArrivalInfo(token, arrAddress, distance, roadCategory);

      arrList->addArrival(arrAddress, distance, roadCategory);
   }
}

//******************************************************************************************
//Given such as Y(1803.2/I), this function extracts arrival Address "Y", distance 1803.2
//and roadCategory "I" info. out
void getArrivalInfo(string oneArrivalInfo, string& arrAddress, double& distance, string& roadCategory)
{
   //----
   // Create a stringstream object from the input string
   stringstream ss(oneArrivalInfo);

   // Declare variables to store the extracted values
   string temp;
   double tempDistance;

   // Extract the arrival address
   if(oneArrivalInfo.find("(") == true){
    getline(ss, arrAddress, '(');

   // Extract the distance as a string
   getline(ss, temp, '/');

   // Convert the distance string to a double
   tempDistance = stod(temp);

   // Extract the road category
   getline(ss, roadCategory, ')');

   // Assign the extracted values to the output variables
   distance = tempDistance;
   }
}