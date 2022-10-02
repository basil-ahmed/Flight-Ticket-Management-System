#ifndef FlightHASHTABLE_H
#define FlightHASHTABLE_H

#include<iostream>
#include<list>
#include "flightticket.h"
// include additional header files if needed

using namespace std;
template <typename T> class MyList;
template <typename T>
class Node
{
private:
	T elem; //data element 
	Node* next; //Link (pointer) to the next Node

public:
	Node(T elem) : elem(elem), next(NULL)
	{}
	friend class MyList<T>;
	friend class FlightHASHTABLE;
};
//=====================================
template <typename T>
class MyList
{
private:
	Node<T>* head; // pointer to the head of list
	int size;
public:
	MyList(); // empty list constructor
	~MyList(); // destructor to clean up all nodes
	bool empty() const; // is list empty?
	void addFront(T& elem); // add a new Node at the front of the list
	void removeFront(); // remove front Node from the list
	unsigned int countElem(int elem); //count frequency of an element in the list
	int getIndexOf(int elem); //returns first index of an element in the list, -1 if the element is not present
	void display() const;
	void loadData(string); //read a file and load it into the linked list
	void dumpData(string) const; //write the linked list to a file
	void sort();  // sort the elements of the list
	friend class FlightHASHTABLE;
};

//=============================================================================
class HashNode
{
	private:
		string key; // key = companyName+flightNumber
		Flight_Ticket value;
	public:
		HashNode(string key, Flight_Ticket value)
		{
			this->key = key;
			this->value = value;
		};
		Flight_Ticket getValue(){return this->value;}
		friend class FlightHASHTABLE;
};

//=============================================================================
class FlightHASHTABLE
{
	private:
		MyList<HashNode> *buckets;		//List of Buckets, Please create your own List Class called MyList
		int size;					    //Current Size of HashTable
		int capacity;				    // Total Capacity of HashTable
		int probes;                    // Total Number of probes
		unsigned long array[1009];
		// add more attributes needed

	public:
		FlightHASHTABLE() {};						//constructor
		FlightHASHTABLE(int capacity);
		~FlightHASHTABLE();						//destructor
		unsigned long hashCode(string key); 				//implement and test different hash functions 
		int importCSV(string path); 			//Load all the flight-tickets from the CSV file to the HashTable
		int exportCSV(string path); 			//Export all the flight-tickets from the HashTable to a CSV file in an ascending order		
		int count_collisions();					//return the number of collisions on the HashTable
		int add(Flight_Ticket* data);			//add new flight to the HashTable
		void removeRecord (string companyName, int flightNumber);	//Delete a record with key from the hashtable
		void find(string companyName, int flightNumber);		//Find and Display records with same key entered 
		void allinday(string date);  					//Find and Display records with same day entered
		void printASC(string companyName, int flightNumber);  		//display the collisions for the entered key in an ascending order 
		void sort(int hash);

		//Add more methods and contructors, destructors if needed	
};

#endif
