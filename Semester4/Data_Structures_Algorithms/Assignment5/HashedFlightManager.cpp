// Description: this is the main program that reads input from keyboard,
// it then call hash functions to execute hash commands given in the input.


//include necessary header file here
#include "Hash.h"
//----

#include <sstream>

using namespace std;

//This function used to get all info. of a Flight object
void getFlightInfo(string oneLine, string& airLine, int& flightNum, string& deptDate);

int main()
{
   int size = 0;

   //a counter used to count # of valid Flight objects entered
   //Note: duplicated flights will NOT be counted inside
   int counter = 0;

   string airLine, deptDate;
   int flightNum;

   //declare any other necessary variables here
   //----
   string input;

   //cout << "Enter the size of the hash table: ";  //used to test on local PC
   cin >> size;
   cin.ignore(20, '\n');

   //Instantiate the hash table with the relevant number of slots
   //----
   Hash hash(size);


   do {
         //use this do..while loop to repeatedly get one line Flight info. and extract tokens
         //create one Flight object and insert it inside the hashTable until seeing 'InsertionEnd'
         //----
         cin >> input;
         if(input == "InsertionEnd"){
            break;
         }
         getFlightInfo(input,airLine,flightNum,deptDate);
         /*
         stringstream ss(inputString);
         getline(ss,airLine,',');
         ss >> flightNum;
         getline(ss,deptDate,',');
         */
        if(hash.hashInsert(airLine,flightNum,deptDate)==true){
            counter++;
         }
         //----

   } while(true);

    cout << "\nHash table size is: " << size;
    cout << "\nTotal Flight objects entered is: " << counter;

   //This do..while loop used to get the commands until 'End'
   do {
        cin >> input;
        if(input == "End"){
            break;
        }
        //get one line command
        if (input == "hashDisplay") {
            hash.hashDisplay();
        }
        if (input == "hashLoadFactor") {
            double loadFactor = hash.hashLoadFactor();
            double ideal = (double)counter/size;
            cout << fixed << setprecision(2);
            cout << "\nThe ideal load factor is: " << ideal;
            cout << "\nMy hash table real load factor is: " << loadFactor;
            cout << "\nMy hash table performance ratio is: " << loadFactor/ideal << endl;
        }
        if (input.substr(0, 10) == "hashSearch") {
            string searchInput = input.substr(11);
            getFlightInfo(searchInput,airLine,flightNum,deptDate);

            hash.hashSearch(airLine, flightNum,deptDate);
        }
        if (input.substr(0, 10) == "hashDelete") {
            string deleteInput = input.substr(11);
            getFlightInfo(deleteInput,airLine,flightNum,deptDate);

            hash.hashSearch(airLine, flightNum,deptDate);
            if(hash.hashDelete(airLine, flightNum,deptDate) == true){
                counter--;
            }
        }
    } while(true);

   return 0;
}

//***************************************************************************
//From one line, this function extracts the tokens and get one Flight info.
//This function is completed and given here as a study guide for extracting tokens
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
}