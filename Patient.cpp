#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "Patient.h"
using namespace std;
string dummy;
int total_patients = 0;
Patient P[500];

int Patient::getId()
{
	return patientId;
}
void Patient::setProfile()
{
	patientId = allotId();
	cout << "Enter Patient Name: ";
	getline(cin, name);
	fflush(stdin);
	cout << "Enter Patient DOB (dd/mm/yy): ";
	getline(cin, dob);
	fflush(stdin);
	cout << "Enter Patients Gender: ";
	getline(cin, sex);
	fflush(stdin);
	gender_check(sex);
	cout << "Enter ID (Only Integers): ";
	cin >> id;
	getline(cin, dummy);
	fflush(stdin);
	fflush(stdin);
	cout << "Enter Patient Address: ";
	getline(cin, address);
	fflush(stdin);
	cout << "Enter Patients Blood Group: ";
	cin >> bloodgroup;
	blood_check(bloodgroup);
	getline(cin, dummy);
	fflush(stdin);
	cout << "Enter Patients Past Diseases: ";
	getline(cin, past_diseases);
	fflush(stdin);
	cout << "Enter Patients Current Disease: ";
	getline(cin, disease);
	fflush(stdin);
	cout << "Enter Patients Symptoms: ";
	getline(cin, symptoms);
	fflush(stdin);
	cout << "Enter Patients Current Prescription: ";
	getline(cin, currentPres);
	fflush(stdin);
	cout << "Enter Patients Current Status[ Healthy(0), Critical(1), Stable(2)]: ";
	status = check_status();
	fflush(stdin);
	if (status == 1) {
		need_admission == "y";
		cout << "Is the Patient already admitted?(Y/N)";
		cin >> already_admitted;
		if (already_admitted == "y") {
			need_admission = "n";
			cout << "Enter Ward: ";
			cin >> ward;
			cout << "Enter Patient Room Number: ";
			cin >> roomNo;
		}
		else {
			already_admitted = "y";
			cout << "Enter Ward: ";
			cin >> ward;
			cout << "Enter Patient Room Number: ";
			cin >> roomNo;
		}

	}
	else {
		cout << "Is the Patient already admitted?(Y/N)";
		cin >> already_admitted;
		if (already_admitted == "y") {
			need_admission = "n";
			cout << "Enter Ward: ";
			cin >> ward;
			cout << "Enter Patient Room Number: ";
			cin >> roomNo;
		}
		else {
			cout << "Does the Patient need to be admitted (Y/N): ";
			cin >> need_admission;
			if (need_admission == "y") {
				cout << "Enter Ward: ";
				cin >> ward;
				cout << "Enter Patient Room Number: ";
				cin >> roomNo;
				already_admitted = "y";
				need_admission = "n";
			}
			else {
				ward = "NA";
				roomNo = -1;
			}
		}
	}
	writetofile();
}
void Patient::updateProfile() {
	cout << "Updating profile of " << name << "\n Patient ID: " << getId() << endl;
	int control = 0, var = 0, stat = 0;
	string s;
	cout << "Choose what to change or -1 to finish updating.\n1. Symptoms\n2. Disease\n3. Current Prescription\n4. Status\n5. Address" << endl;
	if (already_admitted == "y" || already_admitted == "Y") {
		cout << "6. Ward\n7. Room\n8. Discharge" << endl;
		var = 8;
	}
	else if (already_admitted == "n" || already_admitted == "N") {
		cout << "6. Needs to be admitted" << endl;
		var = 6;
	}
	cin >> control;
	int array[8] = { 0 };
	if (var == 8) {
		for (int i = 1; i <= 8; i++) {
			array[i - 1] = i;
		}
	}
	else if (var == 6) {
		for (int i = 1; i <= 6; i++) {
			array[i - 1] = i;
		}
		array[6] = 6;
		array[7] = 6;
	}
	while (control != array[0] && control != array[1] && control != array[2] && control != array[3] && control != array[4] && control != array[5] && control != array[6] && control != array[7] && control != -1) {
		cout << "Invalid choice. Please Enter a valid choice: ";
		fflush(stdin);
		cin >> control;
	}
	string x;
	switch (control) {
	case -1:
		break;
	case 1:
		getline(cin, dummy);
		cout << "Please Input a list of patients symptoms: ";
		fflush(stdin);
		getline(cin, s);
		symptoms += ", " + s;
		system("CLS");
		printProfile();
		updateProfile();
		break;
	case 2:
		getline(cin, dummy);
		cout << "Does Patient still have previous diseases: (Y/N): ";
		getline(cin, x);
		if (x == "y") {
			cout << "Input Patients new diagnosis or disease: ";
			fflush(stdin);
			getline(cin, s);
			disease += ", " + s;
		}
		else if (x == "n") {
			cout << "Input Patients new diagnosis or disease: ";
			fflush(stdin);
			getline(cin, s);
			disease = s;
		}
		system("CLS");
		printProfile();
		updateProfile();
		break;
	case 3:
		getline(cin, dummy);
		cout << "Input Patients new Prescription: ";
		fflush(stdin);
		getline(cin, s);
		currentPres = s;
		system("CLS");
		printProfile();
		updateProfile();
		break;
	case 4:
		getline(cin, dummy);
		cout << "Input Patients current status(0 for Healthy, 1 for Critical and 2 for Stable): ";
		fflush(stdin);
		cin >> stat;
		status = stat;
		system("CLS");
		printProfile();
		updateProfile();
		break;
	case 5:
		getline(cin, dummy);
		cout << "Input Patients new Address: ";
		fflush(stdin);
		getline(cin, s);
		address = s;
		system("CLS");
		printProfile();
		updateProfile();
		break;
	case 6:
		getline(cin, dummy);
		if (already_admitted != "y") {
			cout << "Does the Patient need to be admitted: ";
			fflush(stdin);
			getline(cin, s);
			//check_true(s);
			need_admission = s;
			if (need_admission == "y") {
				already_admitted = "y";
				getline(cin, dummy);
				cout << "Please Input Ward to put Patient in: ";
				cin >> ward;
				getline(cin, dummy);
				cout << "Please Input Patients Room Number: ";
				cin >> roomNo;
			}
		}
		else {
			cout << "Enter Patients new ward: ";
			fflush(stdin);
			getline(cin, s);
			ward = s;
		}
		system("CLS");
		printProfile();
		updateProfile();
		break;
	case 7:
		getline(cin, dummy);
		cout << "Enter Patients new Room number: ";
		fflush(stdin);
		cin >> roomNo;
		system("CLS");
		printProfile();
		updateProfile();
		break;
	case 8:
		getline(cin, dummy);
		cout << "Is the Patient safe to discharge: ";
		fflush(stdin);
		getline(cin, s);
		if (s == "y") {
			need_admission = "n";
			already_admitted = "n";
			ward = "NA";
			roomNo = -1;
		}
		system("CLS");
		printProfile();
		updateProfile();
		break;
	}
}
void Patient::printProfile()
{
	cout << "Patient name: " << name << endl;
	cout << "Patient ID: " << patientId << endl;
	cout << "ID: " << id << endl;
	cout << "Date Of Birth: " << dob << endl;
	cout << "Gender: " << sex << endl;
	cout << "Address: " << address << endl;
	cout << "Blood Group: " << bloodgroup << endl;
	cout << "Patient Disease: " << disease << endl;
	cout << "Disease Symptoms: " << symptoms << endl;
	cout << "Patient Disease History: " << past_diseases << endl;
	cout << "Current Prescription: " << currentPres << endl;
	cout << "Health Status: ";
	if (status == 0)
		cout << "Healthy" << endl;
	if (status == 1)
		cout << "Critical" << endl;
	if (status == 2)
		cout << "Stable" << endl;
	cout << "Patient Allocated: " << already_admitted << endl;
	if (already_admitted == "y" || already_admitted == "Y") {
		cout << "Name of Admitted Ward: " << ward << endl;
		cout << "Ward Room Number: " << roomNo << endl;
	}
	cout << "\n\n" << endl;
}
const void Patient::writetofile()
{
	fstream fout;
	fout.open("_secure\\patient_record.dat", ios::app);
	if (!fout) {
		ofstream file;
		file.open("_secure\\patient_record.dat");
		file.close();
		fout.open("_secure\\patient_record.dat");
	}
	fout << patientId << "\n";
	fout << name << "\n" << dob << "\n" << sex << "\n" << id << "\n" << address << "\n" << bloodgroup << "\n" << past_diseases << "\n" << disease << "\n" << symptoms << "\n" << currentPres << "\n" << status << "\n" << already_admitted << "\n" << need_admission << "\n" << ward << "\n" << roomNo << "\n" << endl;
	total_patients++;
	updateTotal();
	fout.close();
}
const void Patient::rewrite()
{
	fstream fout;
	fout.open("_secure\\patient_record.dat", ios::app);
	fout << patientId << "\n";
	fout << name << "\n" << dob << "\n" << sex << "\n" << id << "\n" << address << "\n" << bloodgroup << "\n" << past_diseases << "\n" << disease << "\n" << symptoms << "\n" << currentPres << "\n" << status << "\n" << already_admitted << "\n" << need_admission << "\n" << ward << "\n" << roomNo << "\n" << endl;
	fout.close();
}
string Patient::getname()
{
	return name;
}
int allotId()
{
	return total_patients + 1;
}
void check_true(string a)
{

	while (a[0] != 'Y' && a[0] != 'N' && a[0] != 'y' && a[0] != 'n')
	{
		cout << "Please enter a valid choice: ";
		fflush(stdin);
		getline(cin, a);
	}
}
int check_status(void){
	string a;
	getline(cin, a);
	while (a != "0" && a != "1" && a != "2")
	{
		cout << "Invalid Input. Please input a valid option: ";
		getline(cin, a);
	}
	if (a == "0")
		return 0;
	else if (a == "1")
		return 1;
	else if (a == "2")
		return 2;
}
void updateTotal()
{
	fstream f;
	f.open("_secure\\patientnumber.dat");
	f << total_patients;
	f.close();
}
void gender_check(string a)
{
	while (a != "m" && a != "f" && a != "M" && a != "F" && a != "Male" && a!= "Female" && a != "male" && a != "female" )
	{
		cout << "Please enter a valid gender: ";
		fflush(stdin);
		getline(cin,a);
	}
}
void blood_check(string a)
{
	int temp = 0;
	while (temp != 1)
	{
		if (a != "A+" && a != "A-" && a != "AB+" && a != "AB-" && a != "B+" && a != "B-" && a != "O+" && a != "O-")
		{
			cout << "Please input valid Blood Group" << endl;
			getline(cin, a);
		}
		else
			temp++;
	}
}
void getTotal()
{
	ifstream f;
	f.open("_secure\\patientnumber.dat");
	if (!f) {
		ofstream file;
		file.open("_secure\\patientnumber.dat");
		file << 0;
		file << "\n" << "\n";
		total_patients = 0;
		file.close();
	}
	f >> total_patients;
	f.close();
}
void readfromfile() {
	Patient temp;
	ifstream fin;
	fin.open("_secure\\patient_record.dat", ios::app);
	fin.seekg(0, ios::beg);
	for (int i = 0; i < total_patients; i++) {
		fin >> temp.patientId;
		getline(fin, dummy);
		getline(fin, temp.name);
		getline(fin, temp.dob);
		getline(fin, temp.sex);
		fin >> temp.id;
		getline(fin, dummy);
		getline(fin, temp.address);
		getline(fin, temp.bloodgroup);
		getline(fin, temp.past_diseases);
		getline(fin, temp.disease);
		getline(fin, temp.symptoms);
		getline(fin, temp.currentPres);
		fin >> temp.status;
		getline(fin, dummy);
		getline(fin, temp.already_admitted);
		getline(fin, temp.need_admission);
		getline(fin, temp.ward);
		fin >> temp.roomNo;
		getline(fin, dummy);
		getline(fin, dummy);
		P[i] = temp;
	}
	fin.close();
}
void intro(void)
{	
	readfromfile();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
	cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
	cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
	cout << "\t\t\t\t\t@@|                           HOSPITAL MANAGEMENT SYSTEM                                  |@@\n";
	cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
	cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
	cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
	cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
	cout << "\t\t\t\t\t@@|             Brought To You by Syed Muhammad Kamran            |@@\n";
	cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
	cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
	cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n";
	system("pause");
	system("cls");
}
int passScreen() {
	string password = "pass123";
	string input;
	system("CLS");
	cout << "\t\t\t\t\t\t|                                                                 |\n";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t \n\n";
	cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
	cout << "\t\t\t\t\t\t|	                                       	                  |\n";
	cout << "\t\t\t\t\t\t|                                                                 |\n";
	cout << "\t\t\t\t\t\t|                      ENTER PASSWORD                             |\n";
	cout << "\t\t\t\t\t\t|                                                                 |\n";
	cout << "\t\t\t\t\t\t|                                                                 |\n";
	cout << "\t\t\t\t\t\t|                                                                 |\n";
	cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";
	getline(cin, input);
	if (input == password) {
		cout << "Password Accepted. Press Enter to Proceed.";
		getchar();
		system("CLS");
		return 1;
	}
	else {
		cout << "Incorrect Password entered. Please Press Enter to Return to Username Screen again and attempt login again.\n";
		getchar();
		system("CLS");
		return -1;
	}
}
void userScreen() {
	getTotal();
	string username = "adminuser";
	string input;
	cout << "\t\t\t\t\t\t|                                                                 |\n";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t \n\n";
	cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
	cout << "\t\t\t\t\t\t|	                                       	                  |\n";
	cout << "\t\t\t\t\t\t|                                                                 |\n";
	cout << "\t\t\t\t\t\t|                      INPUT USERNAME                             |\n";
	cout << "\t\t\t\t\t\t|                                                                 |\n";
	cout << "\t\t\t\t\t\t|                                                                 |\n";
	cout << "\t\t\t\t\t\t|                                                                 |\n";
	cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";
	getline(cin, input);
	if (input == username) {
		cout << "Username Recognized. Please Press Enter to Proceed.";
		getchar();
		system("CLS");
		int c = passScreen();
		if (c == -1)
		{
			userScreen();
		}
	}
	else {
		cout << "Invalid/Unrecognized Username. Please Press Enter and Input Username Again.\n";
		getchar();
		system("CLS");
		userScreen();
	}
}
void intro2(void)
{
	getTotal();
	cout << "\t\t\t\t\t\t|                                                                 |\n";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
	cout << "\n\n\t\t\t\t\t\t\t    Please,  Choose from the following Options: \n\n";
	cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
	cout << "\t\t\t\t\t\t|	                                       	                  |\n";
	cout << "\t\t\t\t\t\t|             1  >> Add New Patient Record                        |\n";
	cout << "\t\t\t\t\t\t|             2  >> Update Patient Record                         |\n";
	cout << "\t\t\t\t\t\t|             3  >> Search for Patient                            |\n";
	cout << "\t\t\t\t\t\t|             4  >> Display Patient Info                          |\n";
	cout << "\t\t\t\t\t\t|             5  >> Exit The Program                              |\n";
	cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";
}
int findpatient(int ID) {
	int control = -1;
	for (int i = 0; i < total_patients; i++) {
		if (ID == P[i].getId())
			control = i;
	}
	return control;
}
int findpatient(string name) {
	int control = -1;
	for (int i = 0; i < total_patients; i++) {
		if (P[i].getname() == name)
			control = i;
	}
	return control;
}
int search() {
	int c = 0;
	cout << "1. Search by name." << "\n" << "2. Search by Patient ID" << "\n" << "Enter -1 to go back." << endl;
	cout << "Please enter your choice: ";
	cin >> c;
	while (c != 1 && c != 2 && c != -1) {
		cout << "Invalid Choice. Please enter the correct choice or enter -1 to go back.";
		fflush(stdin);
		cin >> c;
	}
	string s;
	int index;
	switch (c) {
	case 1:
		getline(cin, dummy);
		fflush(stdin);
		cout << "Enter Patient Name: ";
		fflush(stdin);
		getline(cin, s);
		index = findpatient(s);
		if (index != -1) {
			getline(cin, dummy);
			fflush(stdin);
			P[findpatient(s)].printProfile();
			getchar();
			return index;
		}
		else if (index == -1) {
			cout << "Patient Not Found." << endl;
			string control;
			getline(cin, dummy);
			cout << "Would you like to create a new profile with this name(Y/N): ";
			getline(cin, control);
			if (control == "y") {
				P[total_patients + 1].setProfile();
			}
			return -1;
		}
		fflush(stdin);
		getchar();
		getline(cin, dummy);
		fflush(stdin);
		system("CLS");
		search();
		break;
	case 2:
		cout << "Enter Patient ID: ";
		int x;
		fflush(stdin);
		cin >> x;
		index = findpatient(x);
		if (index != -1) {
			getline(cin, dummy);
			fflush(stdin);
			P[findpatient(x)].printProfile();
			getchar();
			getline(cin, dummy);
			fflush(stdin);
			return index;
		}
		else if (index == -1) {
			getline(cin, dummy);
			cout << "Patient Not Found.";
		}
		fflush(stdin);
		getchar();
		fflush(stdin);
		system("CLS");
		search();
		break;
	case -1:
		system("CLS");
		return -1;
		break;
	}
}
void writealltofile() {
	getTotal();
	remove("_secure\\patient_record.dat");
	ofstream file("_secure\\patient_record.dat");
	for (int i = 0; i < total_patients; i++) {
		P[i].rewrite();
	}
	file.close();
}
void choices(void)
{
	int choice;
	int c;
	fflush(stdin);
//	getline(cin, ch);
//	getline(cin, dummy);
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
	{
		cout << "Invalid choice. Please input a correct option: ";
		fflush(stdin);
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
		getline(cin, dummy);
		fflush(stdin);
		system("CLS");
		P[total_patients + 1].setProfile();
		system("CLS");
		intro2();
		choices();
		break;
	case 2:
		getline(cin, dummy);
		fflush(stdin);
		system("CLS");
		cout << "Search for Patient" << endl;
		c = search();
		if (c == -1) {
			system("CLS");
			intro2();
			choices();
		}
		else {
			P[c].updateProfile();
			writealltofile();
		}
		system("CLS");
		intro2();
		choices();
		break;
	case 3:
		getline(cin, dummy);
		fflush(stdin);
		system("CLS");
		cout << "Search for Patient." << endl;
		system("CLS");
		search();
		system("CLS");
		intro2();
		choices();
		break;
	case 4:
		getline(cin, dummy);
		fflush(stdin);
		system("CLS");
		readfromfile();
		for (int i = 0; i < total_patients; i++) {
			P[i].printProfile();
			cout << "\n\n";
		}
		getchar();
		system("CLS");
		intro2();
		choices();
		break;
	case 5:
		cout << "Thank you for using the program!";
		break;
	default:
		cout << "Choose a valid number.";
	}

}
