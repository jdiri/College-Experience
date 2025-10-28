// Description: This is the header file that defines an undirected graph
//              with an array of sites and routes

//include necessary header file here
//----
#include <iostream>
#include <iomanip>
#include <string>
#include "Route.h"

using namespace std;

class Map
{
   private:
      int numOfSites, numOfRoutes;
      Site* setOfSites;   //an array of Site. Note: you are NOT allowed to change it to Site**
      Route* setOfRoutes; //an array of Route. Note: you are NOT allowed to change it to Route**

   public:
      Map(int numOfSites, int numOfRoutes, Site* siteArray, Route* routeArray);
     ~Map();
      void make_set(Site* oneSite);
      Site* find_set(Site* oneSite);
      void link(Site* aSite, Site* bSite);
      void Union(Site* aSite, Site* bSite);
      void sortRoutes();
      void MST_Kruskal();

      //add any auxiliary functions in case you need them
      //----
      void merge(Route* arr, int left, int mid, int right);
      void mergeSort(Route* arr, int left, int right);
};


//finish each function according to above definition
//----
Map::Map(int numOfSites, int numOfRoutes, Site* siteArray, Route* routeArray){
    this->numOfSites = numOfSites;
    this->numOfRoutes = numOfRoutes;
    setOfSites = new Site[numOfSites];
    setOfRoutes = new Route[numOfRoutes];

    for (int i = 0; i < numOfSites; i++)
    {
        setOfSites[i] = siteArray[i];
    }

    for (int i = 0; i < numOfRoutes; i++)
    {
        setOfRoutes[i] = routeArray[i];
    }
}

Map::~Map()
{
    delete[] setOfSites;
    delete[] setOfRoutes;
}

void Map::make_set(Site* aSite){
    aSite->parent = aSite;
    aSite->rank = 0;
}

Site* Map::find_set(){
    if (aSite->parent != aSite)
    {
        aSite->parent = find_set(aSite->parent);
    }
    return aSite->parent;
}

Site* Map::find_set(Site* aSite)
{
    if (aSite->parent != aSite)
    {
        aSite->parent = find_set(aSite->parent);
    }
    return aSite->parent;
}

void Map::link(Site* aSite, Site* bSite)
{
    if (aSite->rank > bSite->rank)
    {
        bSite->parent = aSite;
    }
    else
    {
        aSite->parent = bSite;
        if (aSite->rank == bSite->rank)
        {
            bSite->rank++;
        }
    }
}

void Map::Union(Site* aSite, Site* bSite)
{
    link(find_set(aSite), find_set(bSite));
}

void Map::sortRoutes() {
    mergeSort(setOfRoutes, 0, numOfRoutes - 1);
}
//----


//*******************************************************************
//This function performs the Kruskal algorithm on the graph
void Map::MST_Kruskal()
{
   cout << "\nMST Kruskal Algorithm Result\n" << endl;
   double totalDistance = 0.0;

   //----
   sortRoutes();

    for (int i = 0; i < numOfSites; i++)
    {
        make_set(&setOfSites[i]);
    }

    for (int i = 0; i < numOfRoutes; i++)
    {
        Site* site1 = setOfRoutes[i].getSite1();
        Site* site2 = setOfRoutes[i].getSite2();

        if (find_set(site1) != find_set(site2))
        {
            Union(site1, site2);
            totalDistance += setOfRoutes[i].getDistance();
            setOfRoutes[i].printRoute();
        }
    }
   //----
   //----

   cout << "=====================================================================================" << endl;
    cout << "Total Distance: " << totalDistance << " meters" << endl;
}

void Map::merge(Route* arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    Route* L = new Route[n1];
    Route* R = new Route[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].getDistance() <= R[j].getDistance()) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Delete temporary arrays
    delete[] L;
    delete[] R;
}

void Map::mergeSort(Route* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}
