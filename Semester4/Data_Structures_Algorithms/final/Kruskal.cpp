//************************************************************************
// Description: this is the main program that reads input from keyboard,
// it then use disjoint set data structure to perform Kruskal MST algorithm
// on the graph.
// //---- is where you need to add your own codes
//**************************************************************************

//include necessary header file
//----
#include <iostream>
#include <iomanip>
#include <string>
#include "Map.h"
#include "Route.h"

using namespace std;

void getArrSiteInfo(string oneArrSiteInfo, string& arrSiteName, double& distance);

int main()
{
    //Maximum possible sites and route number
    const int MAX_SITE_NUM = 50, MAX_ROUTE_NUM = 100;
    int numOfSites = 0, numOfRoutes = 0;  //counter used to track actual number of sites and routes


   //create an array of Site which store all Site (vertex of the graph)
   //----
   Site siteArray[MAX_SITE_NUM];

   //create an array of Route which store all Route (edges of the graph)
   //----
   Route routeArray[MAX_ROUTE_NUM];

   //declare all necessary local variables here
   //
    string depSiteName, arrSiteName;
    double distance;

   string oneLine;

   getline(cin, oneLine);

   while(oneLine.compare("End") != 0)
   {
      //get one line of the input, extract the first token
      //create a Site object if it does not exist in site array,
      //insert it inside the site array. This will be first point of the 'aNewRoute'
      //----
      //----

      //extract the arrival site info. check whether it exists in
      //site array or not, if not, create a new Site object, add it inside.
      //This site will be the second point of the 'aNewRoute'
      //----
      depSiteName = oneLine;
      getline(cin, oneLine);
      getArrSiteInfo(oneLine, arrSiteName, distance);
      //----

      //by using the two sites we got above, create a new route, add
      //it inside route array
      //----
      int depSiteIndex = -1;
      for (int i = 0; i < numOfSites; i++){
            if (siteArray[i].siteName == depSiteName)
            {
                depSiteIndex = i;
                break;
            }
        }
        if (depSiteIndex == -1){
            siteArray[numOfSites] = Site(depSiteName);
            depSiteIndex = numOfSites;
            numOfSites++;
        }

        int arrSiteIndex = -1;
        for (int i = 0; i < numOfSites; i++)
        {
            if (siteArray[i].siteName == arrSiteName)
            {
                arrSiteIndex = i;
                break;
            }
        }

        if (arrSiteIndex == -1)
        {
            siteArray[numOfSites] = Site(arrSiteName);
            arrSiteIndex = numOfSites;
            numOfSites++;
        }
        routeArray[numOfRoutes] = Route(&siteArray[depSiteIndex], &siteArray[arrSiteIndex], distance);
        numOfRoutes++;
      //----

      //get next line
      getline(cin, oneLine);
   } //repeat until the 'End'

   //Create a Map object by using site array and route array
   //----
   Site* siteAP = siteArray;
   Route* routeAP = routeArray;
   Map newMap(numOfSites, numOfRoutes, siteAP, routeAP);
   cout << "Total historical sites you will visit: " << numOfSites << endl;
   //Run Kruskal MST algorithm on above map
   //----
   map.MST_Kruskal();
}

//****************************************************************
//By giving a string, for example 'Pantheon(300.5)', this function
//extract the arrival site 'Pantheon' and distance '300.5' meters
//Note: the delimiter is left and right parenthesis
//****************************************************************
void getArrSiteInfo(string oneArrSiteInfo, string& arrSiteName, double& distance)
{
   //----
    size_t start = oneArrSiteInfo.find_first_of('(');
    size_t end = oneArrSiteInfo.find_first_of(')');
    arrSiteName = oneArrSiteInfo.substr(0, start);
    distance = stod(oneArrSiteInfo.substr(start + 1, end - start - 1));
   //----
}
