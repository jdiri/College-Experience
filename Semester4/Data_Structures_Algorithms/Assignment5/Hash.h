// Description: this is where you need to design functions on Hash hashTable,
// such as hashInsert, hashDelete, hashSearch and hashDisplay
// ---- is where you should add your own code

//include any necessary header here
//----
#include <sstream>
#include "LinkedList.h"

using namespace std;

class Hash
{
    private:
		LinkedList* hashTable;     //hashTable is a one-dimensional array of LinkedList
		int m;      //m is the slot number of the hash table
	public:
      Hash(int size);
      ~Hash();
      bool hashSearch(string airLine, int flightNum, string deptDate);
      bool hashInsert(string airLine, int flightNum, string deptDate);
      bool hashDelete(string airLine, int flightNum, string deptDate);
      double hashLoadFactor();
      void hashDisplay();
      int hashFunction(string key);
 };


//constructor
Hash::Hash(int size)
{
   //----
   m = size;
   hashTable = new LinkedList[size];
   //----
}

//Destructor
Hash::~Hash()
{
   //----
   delete[] hashTable;
   //----
}

//This function searches for a key inside the hash table and
//return true if it is found and false otherwise
//Note: key is the combination of airLine, flightNum and deptDate
bool Hash::hashSearch(string airLine, int flightNum, string deptDate)
{
    bool found = false;
    //----
    string key = airLine + to_string(flightNum) + deptDate;
    int slot = hashFunction(key);
    found = hashTable[slot].searchFlight(airLine,flightNum,deptDate);
    //----

    if (found == true)
        cout << "\n"       << left
            << setw(5)    << airLine
            << setw(10)   << flightNum << " on "
            << setw(12)   << deptDate
            << " is found inside the hash table." << endl;
    else
        cout << "\n"      << left
            << setw(5)   << airLine
            << setw(10)  << flightNum << " on "
            << setw(12)  << deptDate
            << " is NOT found inside the hash table." << endl;
    //----
    return found;
    //----
}

//hashInsert inserts a Flight with the relevant info. into the hashTable.
//it returns true if the data is inserted successfully and false otherwise
bool Hash::hashInsert(string airLine, int flightNum, string deptDate)
{
   //----
    string key = airLine + to_string(flightNum) + deptDate;
    int slot = hashFunction(key);
    bool inserted = hashTable[slot].insertFlight(airLine,flightNum,deptDate);
    return inserted;
   //----
}

//hashDelete deletes a Flight with the relevant key from the hashTable.
//it returns true if it is deleted successfully and false otherwise
//Note: key is the combination of airLine, flightNum and deptDate
bool Hash::hashDelete(string airLine, int flightNum, string deptDate)
{
   //----
    string key = airLine + to_string(flightNum) + deptDate;
    int slot = hashFunction(key);
    bool deleted = hashTable[slot].deleteFlight(airLine,flightNum,deptDate);
   //----
   if(deleted == true){
   cout << left
        << setw(5)   << airLine
        << setw(10)  << flightNum << " on "
        << setw(12)  << deptDate
        << " is deleted from hash table." << endl;
   }
   //----
   else{
   //----
   cout << left
        << setw(5)   << airLine
        << setw(10)  << flightNum << " on "
        << setw(12)  << deptDate
        << " is NOT deleted from hash table." << endl;
   }
   return deleted;
   //----
   //----
}

//This function computes your hash table real load factor
//it is the longest linked list size
double Hash::hashLoadFactor()
{
   //----
    double longestListSize = 0;
    
    for (int i = 0; i < m; i++)
    {
        double listSize = hashTable[i].getSize();
        if (listSize > longestListSize)
        {
            longestListSize = listSize;
        }
    }
    return longestListSize;
   //----
}

//This function prints all elements from the hashTable.
void Hash::hashDisplay()
{
   //----
   for (int i = 0; i < m; i++){
        cout << "\nHashTable[" << i << "], size = " << hashTable[i].getSize() << endl;
        hashTable[i].displayList();
   }
   //----
}

//This is the hash function you need to design. Given a
//string key, the function should return the slot number
//where you should hash the key to.
int Hash::hashFunction(string key)
{
   //----
    int hashValue = 0;
    
    for (char c : key)//iterates through key string
    {
        hashValue += static_cast<int>(c);
    }
    
    return hashValue % m;
   //----
}