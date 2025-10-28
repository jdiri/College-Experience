// Description: This program displays a menu of choices to a user
//              and performs the chosen task. It will keep asking a user to
//              enter the next choice until the choice of 'Q' (Quit) is entered.
//              //---- is where you should add your own code

//Add your own code
//----
#include "LinkedList.h"

using namespace std;

void printMenu();

int main()
 {
       // local variables, can be accessed anywhere from the main method
       char input1 = 'Z';
       string inputInfo;
       string airLine, deptDate;
       int flightNum;
       string line;
       bool success = false;

       //Add your own code
       //----

       // instantiate a LinkedList object
       LinkedList* list1 = new LinkedList();

       printMenu();

       do
        {
           cout << "\nWhat action would you like to perform?\n";
           cin >> (input1);
           input1 = toupper(input1);    //change it to upper case
           cin.ignore(20, '\n'); //flush the buffer whenever you enter a char, integer, double

           // matches one of the case statement
           switch (input1)
           {
             case 'A':{   //Add the flight
               cout << "\nEnter the flight information: ";
               cout << "\nEnter airline code: ";
               //----
               cin >> (airLine);
               cin.ignore(20, '\n');
               cout << "\nEnter flight num: ";
               //----
               cin >> (flightNum);
               cin.ignore(20, '\n'); //flush the buffer

               cout << "\nEnter departure date: ";
               //----
                cin >> (deptDate);
                cin.ignore(20, '\n');
               //----
               //----
               success = list1->addFlight(airLine,flightNum,deptDate);
               if (success == true)
                cout << "\nFlight: " << airLine << " " << flightNum << " on " << deptDate << " is added\n";
               else
                cout << "\nFlight: " << airLine << " " << flightNum << " on " << deptDate << " is NOT added\n";
               break;
             }

            case 'C':{  //Cancel one flight
                cout << "\nEnter the flight info. which you want to cancel: ";
                cout << "\nEnter airline: ";
                //----
                cin >> (airLine);
                cin.ignore(20, '\n');
                cout << "\nEnter flight num: ";
                //----
                cin >> (flightNum);
                cin.ignore(20, '\n'); //flush the buffer.

                cout << "\nEnter departure date: ";
               //----
                cin >> (deptDate);
                cin.ignore(20, '\n');
                //----
                success = list1->cancelOneFlight(airLine,flightNum,deptDate);
                if (success == false)
                    cout << "\nNo such flight inside the list, cannot cancel it\n";
                else
                    cout << "\nFlight: " << airLine << " " << flightNum << " on " << deptDate << " is canceled\n";
                break;
             }

             case 'D':{  //Display all Flights
               //----
               list1->displayAllFlights();
               break;
             }

             case 'E':{   //Display Flights by airline
                cout << "\nWhich airline you want to display flights: \n";
                //----
                cin >> (airLine);
                cin.ignore(20, '\n');
                list1->displayFlightsByAirLine(airLine);
                //----
                break;
             }

              case 'F': {  //Display Flights by departure date
                cout << "\nWhich date you want to display flights: \n";
                //----
                cin >> (deptDate);
                cin.ignore(20, '\n');
                list1->displayFlightsByDate(deptDate);
                //----
                break;
              }

             case 'O':{  //Cancel all flights by a specific airline
                cout << "\nWhich airline you want to cancel all flights with: ";
                //----
                cin >> (airLine);
                cin.ignore(20, '\n');
                //----
                success=list1->cancelFlightsByAirLine(airLine);

                if (success)
                    cout << "\nAll flights with " << airLine << " are canceled\n";
                else
                    cout << "\nFlights with " << airLine << " does NOT exist. Cancel failed\n";
                break;
           }

            case 'R':{  //Cancel all flights by a specific departure date
               cout << "\nWhich date you want to cancel flights with: ";
                //----
                cin >> deptDate;
                cin.ignore(20, '\n');
                //----
                success=list1->cancelFlightsByDate(deptDate);

                if (success)
                    cout << "\nAll flights on " << deptDate << " are canceled\n";
                else
                    cout << "\nFlight on " << deptDate << " does NOT exist, cancel failed\n";
                break;
            }
            case 'S':{ //search a specific flight
                cout << "\nSearch a flight: ";
                cout << "\nEnter airline: ";
                //----
                cin >> (airLine);
                cin.ignore(20, '\n');
                //----

                cout << "\nEnter flight num: ";
                //----
                cin >> (flightNum);
                cin.ignore(20, '\n'); //flush the buffer

                cout << "\nEnter departure date: ";
                //----
                cin >> (deptDate);
                cin.ignore(20, '\n');
                //----
                success=list1->searchFlight(airLine,flightNum,deptDate);

                if (success == false)
                    cout << "\nFlight: " << airLine << " " << flightNum << " on " << deptDate << " is NOT found\n";
                else
                    cout << "\nFlight: " << airLine << " " << flightNum << " on " << deptDate << " is found\n";
                break;
            }

            case 'U':{ //Delay a flight, i.e. update a flight departure date
                string oldDept;
                cout << "\nEnter airline code: ";
                //----
                cin >> (airLine);
                cin.ignore(20, '\n');
                cout << "\nEnter flight num: ";
                //----
                cin >> (flightNum);
                cin.ignore(20, '\n'); //flush the buffer

                cout << "\nEnter old departure date: ";
                //----
                cin >> (oldDept);
                cin.ignore(20, '\n');
                cout << "\nEnter new departure date: ";
                //----
                cin >> (deptDate);
                cin.ignore(20, '\n');
                //----
                success=list1->delayAFlight(airLine,flightNum,oldDept,deptDate);
                if (success == true)
                     cout << "\nFlight: " << airLine << " " << flightNum << " on " << oldDept << " departure date is changed to " << deptDate << "\n";
                else
                     cout << "\nFlight: " << airLine << " " << flightNum << " on " << oldDept << " departure date is NOT changed" << "\n";
                break;
            }

             case 'V':{  //Change a flight airline code
                string oldAirLine;
                cout << "\nEnter airline code: ";
                //----
                cin >> (oldAirLine);
                cin.ignore(20, '\n');
                cout << "\nEnter flight num: ";
                //----
                cin >> (flightNum);
                cin.ignore(20, '\n'); //flush the buffer

                cout << "\nEnter departure date: ";
                //----
                cin >> (deptDate);
                cin.ignore(20, '\n');
                cout << "\nEnter new airline code: ";
                //----
                cin >> (airLine);
                cin.ignore(20, '\n');
                //----
                success=list1->changeAFlightAirLine(oldAirLine,flightNum,deptDate,airLine);
                if (success == true)
                     cout << "\nFlight: " << oldAirLine << " " << flightNum << " on " << deptDate << " airline is changed to " << airLine << "\n";
                else
                     cout << "\nFlight: " << oldAirLine << " " << flightNum << " on " << deptDate << " airline is NOT changed" << "\n";
                break;
             }

             case 'Q':{   //Quit
                    //----
                    list1->~LinkedList();
                    //----
                    break;
             }

             case '?':{   //Display Menu
                    printMenu();
                    break;
             }

             default:{
               cout << "\nUnknown action\n";
               break;
             }
            }

        } while (input1 != 'Q');
      return 0;
   }

  /** The method displays the menu to a user**/
  void printMenu()
   {
     cout << "Choice\t\tAction\n";
     cout << "------\t\t------\n";
     cout << "A\t\tAdd a Flight\n";
     cout << "C\t\tCancel One Flight\n";
     cout << "D\t\tDisplay All Flights\n";
     cout << "E\t\tDisplay Flights by Airline\n";
     cout << "F\t\tDisplay Flights by Date\n";
     cout << "O\t\tCancel Flights by Airline\n";
     cout << "R\t\tCancel Flights by Date\n";
     cout << "S\t\tSearch one Flight\n";
     cout << "U\t\tDelay a Flight\n";
     cout << "V\t\tChange a Flight Airline\n";
     cout << "Q\t\tQuit\n";
     cout << "?\t\tDisplay Help\n\n";
  }
