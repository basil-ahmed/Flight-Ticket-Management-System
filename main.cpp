//=================================================================================
// Name         : DS Assignment#4 
// Author       : 
// Version      : 1.0
// Date Created : 00-00-2022
// Date Modified: 
// Description  : Starter Code for Contact Travel Management System using HASH TABLE in C++
//=================================================================================
#include<iostream>
#include<cstdlib>
#include<sstream>

#include "flightticket.h"
#include "flighthashtable.h"

//==========================================================
void listCommands()
{
	cout<<"\n----------------------------------"<<endl;
	cout<<"import <path>      	:Import flight-tickets from a CSV file"<<endl
		<<"export <path>      	:Export flight-tickets to a CSV file"<<endl
		<<"count_collisions   	:Print Number of Collisions"<<endl
		<<"add                	:Add a new flight-ticket"<<endl
		<<"delete <key>       	:Delete a flight-ticket"<<endl
		<<"find <key>         	:Find a flight-ticket's details"<<endl
		<<"allinday <date>    	:Display all flight-tickets in a day"<<endl
		<<"printASC <key>     	:Print flight-tickets in ascending order"<<endl
		<<"exit               	:Exit the program"<<endl;
}
//==========================================================

// to be completed with all the necessary method definitions

//==========================================================
int main(void)
{
	FlightHASHTABLE myFlightHASHTABLE(125003);
	string user_input;
	string command;
	string key;

	while(true)
	{
		listCommands();
		getline(cin,user_input);

		// parse userinput into command and parameter(s)
		stringstream sstr(user_input);
		getline(sstr,command,' ');
		getline(sstr,key);

		cout<<"----------------------------------"<<endl;
		if (command =="import")	cout<<myFlightHASHTABLE.importCSV(key)<<endl;
		else if (command =="export")	cout<<myFlightHASHTABLE.exportCSV(key)<<endl;
		else if (command == "count_collisions") cout<<myFlightHASHTABLE.count_collisions();
		else if (user_input =="add" || user_input=="a") 
		{ 
			string companyName, flightNumber, country_of_origin, country_of_destination, stopOver, price, time_of_departure, time_of_arrival, date;

			cout<<"Please enter the details of the flight ticket:"<<endl;
			cout<<"Company Name: "; getline(cin, companyName);
			cout<<"Flight Number: "; cin>>flightNumber;
			cout<<"Country of Origin: "; cin>>country_of_origin;
			cout<<"Country of Destination: "; cin>>country_of_destination;
			cout<<"StopOver: "; cin>>stopOver;
			cout<<"Price: "; cin>>price;
			cout<<"Time of Departure: "; cin>>time_of_departure;
			cout<<"Time of Arrival: "; cin>>time_of_arrival;
			cout << "Date: "; cin >> date; cin.ignore();

			Flight_Ticket* newTicket = new Flight_Ticket(companyName, stoi(flightNumber), country_of_origin, country_of_destination, stopOver, price, time_of_departure, time_of_arrival, date);

			int success = myFlightHASHTABLE.add(newTicket);

			if (success == 1)
				cout<<"Flight Ticket has successfully been added!"<<endl;
			else if (success == -1)
				cout<<"The Flight Ticket already exists!"<<endl;
		}
		else if (command == "delete")
		{
			string companyName, flightNumber;
			stringstream sstr(key);
			//cout<<key<<endl;
			getline(sstr, companyName, ',');
			getline(sstr, flightNumber);
			//cout<<companyName<<flightNumber<<endl;
			myFlightHASHTABLE.removeRecord(companyName, stoi(flightNumber));
		}
		else if (command == "find")
		{
			string companyName, flightNumber;
			stringstream sstr(key);
			getline(sstr, companyName, ',');
			getline(sstr, flightNumber);
			myFlightHASHTABLE.find(companyName, stoi(flightNumber));
		}
		else if (command == "allinday")
			myFlightHASHTABLE.allinday(key);
		else if (command == "printASC")
		{
			string companyName, flightNumber;
			stringstream sstr(key);
			getline(sstr, companyName, ',');
			getline(sstr, flightNumber);
			myFlightHASHTABLE.printASC(companyName, stoi(flightNumber));
		}
		else if( user_input == "exit") {return EXIT_SUCCESS;}
		else cout<<"Invalid command !!!"<<endl;

	}

	return 0;
}
