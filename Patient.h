#include <iostream>
#include <string>
#include <fstream>    // header to include file input and output stream 
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Patient {
	// modules required for our software
	int patientId;
	int status;
	int id;
	int roomNo;
	string dob;
	string disease;
	string symptoms;
	string name;
	string address;
	string past_diseases;
	string currentPres;
	string bloodgroup;
	string ward;
	string sex;
	string already_admitted;
	string need_admission;
	friend int allotId(); // calculating number of objects of patients created 
public:
	int getId();  
	void setProfile();  // used to assign values to an instance of the patient class
	void updateProfile(); // used to update an existing patients record
	void printProfile(); // Used to print all the record of a certain patient
	const void writetofile(); // this function is used to write patients data in the database and updates total number of recorded patients
	const void rewrite(); // rewrites patient data to database without altering the total
	string getname(); //return name 
	friend void readfromfile(); // used to read all patient records and load them from the databse 
	friend void choices(); // Home screen for the entire program. Provides user with various options on what to do 
};

int allotId(); //assigns a new patient a new unique patient id
// checker 
void check_true(string a);
int check_status();
void updateTotal();
void gender_check(string a);
void blood_check(string a);
void getTotal();
void readfromfile(); // displaying the existing record of a patient 
void intro(void);  //  output screen
int passScreen();  //  output screen
void userScreen(); // output screen
void intro2(void);  // output screen
int findpatient(int ID); // Finding a patient record using his ID or name 
int findpatient(string name);// overloading a function
int search(); // searching a specific patient record
void writealltofile(); //
void choices(void); 
