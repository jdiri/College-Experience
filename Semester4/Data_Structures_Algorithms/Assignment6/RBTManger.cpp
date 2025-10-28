
#include "RedBlackTree.h"

using namespace std;

//This function used to get the info. of a Flight object
void getFlightInfo(string oneLine, string& airLine, int& flightNum, string& deptDate);

int main()
{

   string airLine;
   int flightNum;
   string deptDate;
   string command, oneLine, token;
   string delimiter = ",";

   int pos = 0;

   //Create a RedBlackTree object here, use it throughout the program
   //----
   RedBlackTree tree = RedBlackTree();
   //----

   do
   {
      getline(cin, oneLine);
      pos = oneLine.find(delimiter);
      token = oneLine.substr(0, pos);
      command = token;
      oneLine.erase(0, pos + delimiter.length());

      if(command.compare("quit")==0)
      {
         cout << "\nCommand: quit" << endl;
         //call the relevant function on the red black tree

         //----
         break;
      }
      else if(command.compare("tree_preorder")==0)
      {
         cout << "\nCommand: tree_preorder" << endl;

         //call the relevant function on the red black tree
         //----
         tree.treePreorder();
      }
      else if(command.compare("tree_inorder")==0)
      {
         cout << "\nCommand: tree_inorder" << endl;

         //call the relevant function on the red black tree
         //----
         tree.treeInorder();
      }
      else if(command.compare("tree_postorder")==0)
      {
         cout << "\nCommand: tree_postorder" << endl;

         //call the relevant function on the red black tree
         //----
         tree.treePostorder();
      }
      else if(command.compare("tree_minimum")==0)
      {
         cout << "\nCommand: tree_minimum" << endl;

         //call the relevant function on the red black tree
         //----
         tree.treeMinimum();
      }
      else if(command.compare("tree_maximum")==0)
      {
         cout << "\nCommand: tree_maximum" << endl;

         //call the relevant function on the red black tree
         //----
         tree.treeMaximum();
      }
      else if(command.compare("tree_predecessor")==0)
      {
        //call the relevant function to get the Flight info. first
        //----
        cout << "\nCommand: tree_predecessor" << endl;
        getFlightInfo(oneLine, airLine, flightNum, deptDate);
        
        //call the relevant function on the red black tree
        //----
        tree.treePredecessor(airLine,flightNum,deptDate);
      }
      else if(command.compare("tree_successor")==0)
      {
        //call the relevant function to get the Flight info. first
        //----
        cout << "\nCommand: tree_successor" << endl;
        getFlightInfo(oneLine, airLine, flightNum, deptDate);
        //call the relevant function on the red black tree
        //----
        tree.treeSucessor(airLine,flightNum,deptDate);
      }
      else if(command.compare("tree_search")==0)
      {
        //call the relevant function to get the Flight info. first
        //----
        cout << "\nCommand: tree_search" << endl;
        getFlightInfo(oneLine, airLine, flightNum, deptDate);
        //call the relevant function on the red black tree
        //----
        tree.treeSearch(airLine,flightNum,deptDate);
      }
      else if(command.compare("tree_insert")==0)
      {
        //call the relevant function to get the Flight info. first
        //----
        getFlightInfo(oneLine, airLine, flightNum, deptDate);
        cout << "\nCommand: tree_insert" << endl;
        cout << left;
        cout << setw(5)  << airLine
             << setw(10) << flightNum
             << setw(12) << deptDate   << endl;
        //call the relevant function to insert the Flight inside the RBT
        //----
        tree.treeInsert(airLine,flightNum,deptDate);
      }
   } while(true);  //continue until 'quit'
   return 0;
}

//************************************************************************************
//This function from one line, extracts the airLine, flightNum and deptDate of a Flight
void getFlightInfo(string oneLine, string& airLine, int& flightNum, string& deptDate)
{
    string delimiter = ",";
	int pos = oneLine.find(delimiter);
	string token = oneLine.substr(0,pos);
	airLine = token;
	oneLine.erase(0, pos+delimiter.length());

	pos = oneLine.find(delimiter);
	token = oneLine.substr(0,pos);
	flightNum = stoi(token);
	oneLine.erase(0, pos+delimiter.length());

	pos=oneLine.find(delimiter);
	token = oneLine.substr(0,pos);
	deptDate = token;
	oneLine.erase(0, pos+delimiter.length());
   //----
}