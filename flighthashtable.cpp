#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<stdexcept>
#include<sstream>
#include<exception>
#include<stdexcept>
#include<random>
#include<fstream>
#include<math.h>
#include "flightticket.h"
#include "flighthashtable.h"

using namespace std;

template <typename T>
MyList<T>::MyList()
{
	this->head = NULL;
	size = 0;
}
//====================================
// destructor to clean up all nodes
template <typename T>
MyList<T>::~MyList()
{
	while (!empty()) removeFront(); //checks if it is not empty then removes the front
}
//====================================
// Check if the list is empty or not
template <typename T>
bool MyList<T>::empty() const
{
	return head == NULL; //if head is empty returns true
}
//====================================
// add a node at the front of the list
template <typename T>
void MyList<T>::addFront(T& elem)
{
	Node<T>* v = new Node<T>(elem);
	v->next = head;
	head = v;
	size++;
}
//====================================
// remove the first node from the list
template <typename T>
void MyList<T>::removeFront()
{
	if (!empty())
	{
		Node<T>* old = head;
		head = head->next;
		delete old;
	}
	else
	{
		cout << "Error: List is empty" << endl;
	}
}

template <typename T>
void MyList<T>::display() const
{
	cout << "Head -> ";
	Node<T>* current = this->head;
	while (true)
	{
		if (current == NULL)
		{
			break;
		}
		cout << current->elem.getValue().getCompanyName() << " " << current->elem.getValue().getFlightNumber() << " -> ";
		current = current->next;
	}
	cout << "Tail\n";
}

FlightHASHTABLE::FlightHASHTABLE(int capacity)
{
    buckets = new MyList<HashNode>[capacity];      //Array of a list/chain
    this->capacity = capacity;
    this->size = 0;
    this->probes = 0;
}

FlightHASHTABLE::~FlightHASHTABLE()
{
	delete [] this->buckets;
}

unsigned long FlightHASHTABLE::hashCode(string key)
{	
		unsigned long hash = 0;
		const int p = 37;
		long p_pow = 1;
		const int m = 1e9 + 7;
		int strLength = key.length();
		for (int i = 0; i < strLength; i++)
		{
			hash = (hash + (int(key[i] - 'a' + 1) * p)%m);
			p_pow = (p_pow * p) % m;
			hash = hash % capacity;
		}
		return hash;

}

int FlightHASHTABLE::importCSV(string path)
{
    int count = 0;
    ifstream CSVfile(path);

    if (CSVfile.is_open())
    {

        string line;

        while (getline(CSVfile, line))
        {
            string companyName, flightNumber, country_of_origin, country_of_destination, stopOver, price, time_of_departure, time_of_arrival, date;
            // string temp_key;

            int commas = 0;

            // Iterate over the entire line, split it according to the number of commas, add the words into a list
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ',')
                {
                    commas++;
                }
                else
                {
                    if (commas == 0 && line[i] != ' ') companyName += line[i];
                    else if (commas == 1 && line[i] != ' ') flightNumber += line[i];
                    else if (commas == 2 && line[i] != ' ') country_of_origin += line[i];
                    else if (commas == 3 && line[i] != ' ') country_of_destination += line[i];
                    else if (commas == 4 && line[i] != ' ') stopOver += line[i];
                    else if (commas == 5 && line[i] != ' ') price += line[i];
                    else if (commas == 6 && line[i] != ' ') time_of_departure += line[i];
                    else if (commas == 7 && line[i] != ' ') time_of_arrival += line[i];
                    else if (commas == 8 && line[i] != ' ') date += line[i];

                }
            }
            if (flightNumber == "flightNumber")
            {
            	continue;
            }
            //cout<<flightNumber<<endl;

            // temp_key = companyName + " " + flightNumber; // Making the key for the contact

            //count++; // Increment number of contacts added

            //use the loaded data to create a contact
            Flight_Ticket* newTicket = new Flight_Ticket(companyName, stoi(flightNumber), country_of_origin, country_of_destination, stopOver, price, time_of_departure, time_of_arrival, date);

            int success = add(newTicket); // Insert contact into the Hash Table

            if (success == 1)
				count++;
        }

    }
    else
    {
        // Error Message in case file cannot open
        cerr << "Error! File could not be opened." << endl;
        return -1;
    }

    return count; // Return the number of contacts added
}

int FlightHASHTABLE::exportCSV(string path)
{
	ofstream output(path);
	int num_records=0;
	for (int i = 0; i < capacity; i++)
	{
		if (buckets[i].size == 0)
			continue;
		else
		{
			Node<HashNode>* iterator = buckets[i].head;

				
				output << iterator->elem.value.getCompanyName() << ","<< iterator->elem.value.getFlightNumber() << ","<< iterator->elem.value.getCountry_of_origin() << ","<< iterator->elem.value.getCountry_of_destination() << ","<< iterator->elem.value.getStopOver() << ","<< iterator->elem.value.getPrice() << ","<< iterator->elem.value.getTime_of_departure() << ","<< iterator->elem.value.getTime_of_arrival() << ","<< iterator->elem.value.getDate() << endl;
				
				iterator = iterator->next;
				
				num_records++;
		}
	}
	return num_records;
}

int FlightHASHTABLE::count_collisions()
{
	int collisions = 0;
	for (int i = 0; i < capacity; i++)
	{
		if (buckets[i].size == 0)
			continue;
		else
		{
			collisions += buckets[i].size - 1;
		}
	}
	return collisions;

	// int collisions = 0;

	// for (int i = 0; i < capacity; ++i)
	// {
	// 	if (!buckets->empty())
	// 	{
	// 		string* array = new string[buckets[i].size];
	// 		Node<HashNode>* current = buckets[i].head;
	// 		string key = current->elem.value.getCompanyName() + to_string(current->elem.value.getFlightNumber());
	// 		string newKey;
	// 		array[0] = key;
	// 		current = current->next;

	// 		int i = 1;

	// 		while (current != nullptr)
	// 		{
	// 			bool search = false;

	// 			for (int j = 0; j<i; j++)
	// 			{
	// 				newKey = current->elem.value.getCompanyName() + to_string(current->elem.value.getFlightNumber());
	// 				if (newKey == array[j])
	// 				{
	// 					search = true;
	// 				}
	// 			}

	// 			if (!search)
	// 			{
	// 				collisions++;
	// 				array[i] = newKey;
	// 				i++;
	// 			}
	// 			current = current -> next;
	// 		}
	// 	}
	// }

	// return collisions;
}

int FlightHASHTABLE::add(Flight_Ticket* data)
{
	string key = data->getCompanyName() + to_string(data->getFlightNumber());
	HashNode* node = new HashNode(key, *data);
    
    long hashIndex = hashCode(key);
    //import /Users/basilahmed/Documents/flight-ticket1k.csv

    /*if (*data == buckets[hashIndex].front().value)
    {
    	return -1;
    }*/

    //cout<<key<<endl;
    // while (key == buckets[hashIndex].back().key && buckets[hashIndex].size() > hashIndex)
    // {
    //     hashIndex++;
    //     hashIndex %= capacity;
    // }

    // //cout<<"Yes"<<endl;

    // if (buckets[hashIndex].size() < hashIndex)
    // {
    //     probes++;
    // }

    buckets[hashIndex].addFront(*node);
    //buckets[hashIndex].display();
    size++;

    //array[array.back()+1] = hashIndex;

    return 1;

}

void FlightHASHTABLE::find(string companyName, int flightNumber)
{
	string key = companyName + to_string(flightNumber);
	int count = 0;

	unsigned long hashIndex = hashCode(key);
	bool found = false;

    //MyList <HashNode> :: iterator i;
    for (Node<HashNode>* i = buckets[hashIndex].head; i != nullptr; i = i->next)
    {
    	if (i->elem.key == key)
    	{
	    	//cout<<buckets[hashIndex].size<<" records found: "<<endl;
	    	cout << ++count << "." << endl;

	    	cout << "Company Name: " << i->elem.value.getCompanyName() << endl;
			cout << "Flight Number: " << i->elem.value.getFlightNumber() << endl;
			cout << "Country of origin: " << i->elem.value.getCountry_of_origin() << endl;
			cout << "Country of destination " << i->elem.value.getCountry_of_destination() << endl;
			cout << "Stopover: " << i->elem.value.getStopOver() << endl;
			cout << "Price: " << i->elem.value.getPrice() << endl;
			cout << "Time of departure: " << i->elem.value.getTime_of_departure() << endl;
			cout << "Time of arrival: " << i->elem.value.getTime_of_arrival() << endl;
			cout << "Date: " << i->elem.value.getDate() << endl<<endl;
			found = true;
		}
    }

    if (!found)
    	cout<<endl<<"Flight Not Found!"<<endl;
}

void FlightHASHTABLE::removeRecord (string companyName, int flightNumber)
{
	string key = companyName + to_string(flightNumber);
	string choice;
	int count = 0;

	unsigned long hashIndex = hashCode(key);

    //MyList <HashNode> :: iterator i;
    for (Node<HashNode>* i = buckets[hashIndex].head; i != nullptr; i = i->next)
    {
        if (i->elem.key == key) 
        {
        	//cout<<buckets[hashIndex].size<<" records found: "<<endl;

        	cout << ++count << "." << endl;
        	cout << "Company Name: " << i->elem.value.getCompanyName() << endl;
			cout << "Flight Number: " << i->elem.value.getFlightNumber() << endl;
			cout << "Country of origin: " << i->elem.value.getCountry_of_origin() << endl;
			cout << "Country of destination " << i->elem.value.getCountry_of_destination() << endl;
			cout << "Stopover: " << i->elem.value.getStopOver() << endl;
			cout << "Price: " << i->elem.value.getPrice() << endl;
			cout << "Time of departure: " << i->elem.value.getTime_of_departure() << endl;
			cout << "Time of arrival: " << i->elem.value.getTime_of_arrival() << endl;
			cout << "Date: " << i->elem.value.getDate() << endl<<endl;

			cout<<"Which record do you want to delete: "; cin>>choice;
        }

        break;
    }

    // if (i != buckets[hashIndex].end())
    //     buckets[hashIndex].erase(i);
    // else 
    //     cout<< "Key Not Found"<<endl;
}

void FlightHASHTABLE::allinday(string date)
{
	int num_records = 0;
	for (int count = 0; count < capacity; count++)
	{

		Node<HashNode>* iterator = buckets[count].head;

		// MyList <HashNode> :: iterator i;
		for (Node<HashNode>* i = buckets[count].head; i != nullptr; i = i->next)
		{
			if (i->elem.value.getDate() == date)
			{

				cout << i->elem.value.getCompanyName() << ","<< i->elem.value.getFlightNumber() << ","<< i->elem.value.getCountry_of_origin() << ","<< i->elem.value.getCountry_of_destination() << ","<< i->elem.value.getStopOver() << ","<< i->elem.value.getPrice() << ","<< i->elem.value.getTime_of_departure() << ","<< i->elem.value.getTime_of_arrival() << ","<< i->elem.value.getDate() << endl;

				num_records++;
			}
		}

		iterator = iterator->next;
	}

	cout << num_records << " records found.";
}

void FlightHASHTABLE::sort(int hashIndex)
{
	bool change = true;
	while (change)
	{
		change = false;
		Node<HashNode>* iterator = buckets[hashIndex].head;

			if (iterator->elem.value.getCountry_of_destination() > iterator->next->elem.value.getCountry_of_destination())
			{
				Flight_Ticket temp = iterator->elem.value;
				iterator->elem.value = iterator->next->elem.value;
				iterator->next->elem.value = temp;
				change = true;

			}
			iterator = iterator->next;
	}
}
void FlightHASHTABLE::printASC(string companyName, int flightNumber)
{
	string key;
	key = companyName + to_string(flightNumber);
	unsigned long hashIndex = hashCode(key);
	sort(hashIndex);
	Node<HashNode>* i = buckets[hashIndex].head;
	while (i!= nullptr)
	{	
		if (i->elem.key == key)
		{
			cout << i->elem.value.getCompanyName() << ","<< i->elem.value.getFlightNumber() << ","<< i->elem.value.getCountry_of_origin() << ","<< i->elem.value.getCountry_of_destination() << ","<< i->elem.value.getStopOver() << ","<< i->elem.value.getPrice() << ","<< i->elem.value.getTime_of_departure() << ","<< i->elem.value.getTime_of_arrival() << ","<< i->elem.value.getDate() << endl;

		}
		
		i = i->next;
	}
}

bool operator==(Flight_Ticket &rhs, Flight_Ticket &lhs)
{
	return (rhs.companyName==lhs.companyName && rhs.flightNumber==lhs.flightNumber && rhs.country_of_origin==lhs.country_of_origin && rhs.country_of_destination==lhs.country_of_destination && rhs.stopOver==lhs.stopOver && rhs.price==lhs.price && rhs.time_of_arrival==lhs.time_of_arrival && rhs.time_of_departure==lhs.time_of_departure && rhs.date==lhs.date);
};