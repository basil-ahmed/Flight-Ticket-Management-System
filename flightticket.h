#ifndef FLIGHT_TICKET_H
#define FLIGHT_TICKET_H

#include<iostream>
using namespace std;

class Flight_Ticket
{
	private:
		string companyName;
		int flightNumber;
		string country_of_origin;
		string country_of_destination;
		string stopOver;
		string price;
		string time_of_departure;
		string time_of_arrival;
		string date;

	public:
		Flight_Ticket() {};
		Flight_Ticket(string companyName, int flightNumber, string country_of_origin, string country_of_destination, string stopOver, string price, string time_of_departure, string time_of_arrival, string date)
		{
			this->companyName = companyName;
			this->flightNumber = flightNumber;
			this->country_of_origin = country_of_origin;
			this->country_of_destination = country_of_destination;
			this->stopOver = stopOver;
			this->price = price;
			this->time_of_departure = time_of_departure;
			this->time_of_arrival = time_of_arrival;
			this->date = date;
		};

		void setCompanyName(string cn);
		void setFlightNumber(int fn);
		void setCountry_of_origin(string co);
		void setCountry_of_destination(string cd);
		void setStopOver(string s);
		void setPrice(string p);
		void setTime_of_departure(string td);
		void setTime_of_arrival(string ta);
		void setDate(string d);

		string getCompanyName();
		int getFlightNumber();
		string getCountry_of_origin();
		string getCountry_of_destination();
		string getStopOver();
		string getPrice();
		string getTime_of_departure();
		string getTime_of_arrival();
		string getDate();

		friend bool operator==(Flight_Ticket &rhs, Flight_Ticket &lhs);
};

#endif
