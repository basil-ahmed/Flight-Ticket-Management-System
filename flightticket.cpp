#include <iostream>
#include "flightticket.h"

using namespace std;

void Flight_Ticket::setCompanyName(string cn) {this->companyName = cn;};
void Flight_Ticket::setFlightNumber(int fn) {this->flightNumber = fn;};
void Flight_Ticket::setCountry_of_origin(string co) {this->country_of_origin = co;};
void Flight_Ticket::setCountry_of_destination(string cd) {this->country_of_destination = cd;};
void Flight_Ticket::setStopOver(string s) {this->stopOver = s;};
void Flight_Ticket::setPrice(string p) {this->price = p;};
void Flight_Ticket::setTime_of_departure(string td) {this->time_of_departure = td;};
void Flight_Ticket::setTime_of_arrival(string ta) {this->time_of_arrival = ta;};
void Flight_Ticket::setDate(string d) {this->date = d;};

string Flight_Ticket::getCompanyName() {return companyName;};
int Flight_Ticket::getFlightNumber() {return flightNumber;};
string Flight_Ticket::getCountry_of_origin() {return country_of_origin;};
string Flight_Ticket::getCountry_of_destination() {return country_of_destination;};
string Flight_Ticket::getStopOver() {return stopOver;};
string Flight_Ticket::getPrice() {return price;};
string Flight_Ticket::getTime_of_departure() {return time_of_departure;};
string Flight_Ticket::getTime_of_arrival() {return time_of_arrival;};
string Flight_Ticket::getDate() {return date;};