# Flight-Ticket-Management-System

## Introduction

This is a Flight-Ticket Management application that can help you search for a ticket that suits you. The identification of a flight-ticket will be based on the key produced by the combination of the company name and flight number.

Information of flight-tickets is to be inserted/read from either the interface of your application or from an input text file. The application should support deletion of a ticket record in addition to other management features that are highlighted in the following section.

Each record is provided in ASCII format and spans at most one line of text. The user interface should allow a user to navigate and perform all the tasks/features listed in the following section.
        
It is a program utilizing the object-oriented programming (OOP) principles and appropriate data structures. You are required to use Hash Table as the primary data structure to implement the application. Use separate chaining to handle collisions.
You should implement all the data structures manually, STL based containers are not allowed to be used here.

## Implementation

### CSV File Format:

The flight-ticket record consists of the following fields:
companyName, flightNumber, country_of_origin, country_of_destination, stopover, price, time_of_departure, time_of_arrival, date
Ex.: Emirates Sky Cargo,1,Lebanon,USA,3,800,11:50,14:15,1-Apr

Examples of flights records:

Emirates Sky Cargo,1,Lebanon,USA,3,800,11:50,14:15,1-Apr 
Aeromexico,70,Bahrain,Luxembourg,1,1328,0:04,3:16,16-Dec
Gol Transportes Aéreos,103,Sweden,Lebanon,3,1387,12:58,12:26,26-Aug 
Boliviana de Aviación,43,Belarus,Cyprus,0,1157,23:02,0:07,9-Aug 
Aeromexico,52,Mongolia,United States,3,685,3:34,21:27,24-Feb 
Conviasa,75,Canada,Hungary,3,1411,1:02,18:24,21-Feb

### User Interface:

Through its prompt, the program is expected to accept several commands that we outline next; these commands accept as operand a string that provides a flight-ticket’s data, or the combination of companyName and flightNumber used as the key to look up records.
The application interacts with the user using a command line (terminal based) interface as shown below:
 
The application, after performing the user’s desired operation, presents the menu again for the next operation to be performed.

NOTE: Make sure to handle the cases of the input keys provided by the user, for example you can use the tolower () function. Moreover, the below screenshots are just examples for showing you samples of inputs and outputs, so you may have different results when executing your own code.

### Features to Implement:
1. import [path]
  - Imports a CSV file
  - Invokes a function with the following header:
       int importCSV (string path)
  - This function takes the path as an argument and loads all the flight-tickets from the CSV file into the Hash Table. The function either returns the number of flight-tickets read from the file as integer or returns -1, if a bad path is provided.
  
2. export [path]
  - Exports a CSV file
  - Invokes a function with the following header:
       int exportCSV (string path)
  - This function takes the path as an argument and writes all the flight-tickets from the Hash Table to a CSV file. The function either returns the number of flight-tickets written to the file as integer or returns -1, if file cannot be created

3. count_collisions
  - Returns the number of collisions caused by a hash function. o Invokes a function with the following header:
       int count_collisions ()
  - Thisfunction doesn’t accept any parameters. It should operate based on the existing hash table. This method returns the number of collisions in the hash table.

4. add
  - Adds a new flight record. If the element already exists, no entry will be added, but a warning message will be issued stating that the record already exists the system. 
  - Invokes a function with the following header:
       int add (FlightInfo *data)  
  - This function takes a pointer to a FlightInfo object as an argument. The function returns 1 if the record has been successfully added or -1 otherwise.
 
5. delete [companyName,flightNumber]
  - Deletes a flight-ticket record based on the entered key <companyName,flightNumber>.
    - If no such entry exists, a warning message to the standard error is printed out. 
  - Invokes a function with the following header:
    void removeRecord (string companyName, int flightNumber)
  - This function takes a key (i.e., companyName and flightNumber) as argument. It prints confirmation message if the record has been successfully added or failure message otherwise.

6. find [companyName,flightNumber]
  - Searches for a flight-ticket record of the entered key <companyName,flightNumber>. 
  - Invokes a function with the following header:
    void find (string companyName, int flightNumber)
  - This function takes a key (i.e., companyName and flightNumber) as an argument and displays the entire records that match the entered key or displays “Not Found!” message otherwise. It also prints out the actual time taken by the find execution.
 
7. allinday [date]
  - SearchesforalltheFlight-ticketsforaspecifieddate.
  - Invokes a function with the following header: 
    void allinday (string date)
  - This function takes a specific date as an argument and prints out all the flight-tickets available for that date or display “Not Found!” message otherwise.

8. printASC [companyName,flightNumber]
  - Displays in an ascending order (based on the flight destination country) all flight-tickets having the same key entered by the user <companyName,flightNumber>.
  - Invokes a function with the following header:
    void printASC (string companyName, int flightNumber)

9. exit
  - Exits the program
  
## Report
- You need to implement three different hash functions and evaluate the performance of each hash function in terms of the number of collisions when applied on the same dataset files (use the supplementary files).
- You must document the description and design of each hash function along with their evaluation results in a pdf report.
- The hash function causing the least number of collisions, on average when applied to the 3 dataset files, should be set as the default hash function to use by your system.
 [The Report](https://github.com/basil-ahmed/Flight-Ticket-Management-System/blob/main/%20Report.pdf)
