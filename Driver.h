#pragma once

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Passenger.h"
#include "Menu.h"
//#include <stack>
//#include <queue>

// Driver Class //

class Driver {
private:
	// Data Members
	int id;
	string password;
	string name;
	string contactNo;
	string vehicle;
	string vehicleClass;
	string pickup;
	string dropoff;
	int arrivalTime;
	int fare;
	Queue<Passenger> PassengerRequest;
	Stack<Passenger> RideHistory;
public:
	// Constructors
	Driver();
	// Member Functions
	void setValue();
	bool setDriverData(Linked_List<Driver>& DriverList);
	int getDriverID();
	string getDriverPass();
	string getDriverName();
	string getDriverContactNo();
	string getDriverVehicle();
	string getDriverVehicleClass();
	string getDriverPickUp();
	string getDriverDropOFf();
	int getDriverFare();
	int getDriverArrivalTime();
	int getDriverDistance();
	bool RegisterDriver(Linked_List<Driver>& DriverList);
	void SearchDriverRecord(Linked_List<Driver>& DriverList);
	void DeleteDriverRecord(Linked_List<Driver>& DriverList);
	void RecordDisplay();
	void ViewDriverRecord(Linked_List<Driver> DriverList);
	bool operator==(Driver d2) {
		if (id == d2.id) {
			return true;
		}
		else {
			return false;
		}
	}
	friend ostream& operator<<(ostream& output, Driver d) {
		output << "\n => Driver ID : " << d.id;
		output << "\n => Driver Name : " << d.name;
		output << "\n => Driver Contact No: " << d.contactNo;
		output << "\n => Driver Vehicle: " << d.vehicle;
		output << "\n => Driver Vehicle Class: " << d.vehicleClass;
		output << "\n-----------------------------------------\n" << endl;
		return output;
	}
	bool ShowPassengerRequest();
	void SetPassengerRequest(Passenger& P);
	void sendRequestToPassenger(Linked_List<Passenger>& PassengerList, int Passengerid, DriverRequest d);
	void AcceptPassengerRequest(Linked_List<Passenger>& PassengerList);
	void DeclinePassengerRequest();
};

//-------------------------------------- Memeber Functions Definition  -------------------------------------------------------------------------------------------------------

// Constructors Defintion

Driver::Driver() : id(0), password(""), name(""), contactNo(""), vehicle(""), vehicleClass(""), pickup(""), dropoff(""), arrivalTime(0), fare(0) {}

// Set Data Function
void Driver::setValue() {
	cout << "=> Enter Your ID : ";
	cin >> id;
	cout << "=> Enter Your Password : ";
	cin >> password;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Set Data Function
bool Driver::setDriverData(Linked_List<Driver>& DriverList) {
	bool check = false;
	do {
		cout << "\n\n\n\n\t >>>>>>>> DRIVER REGISTRATION <<<<<<< \n\n";
		cout << "=> Enter Driver ID : ";
		cin >> id;
		if (id <= 0) {
			cerr << " <*> Error! Wrong Input ... " << endl;
			Sleep(1000);
			system("CLS");
		}
	} while (id <= 0);

	check = DriverList.dataValidity(*this);
	if (!check) {
		cout << "\n\" <*> Driver Already Registered ...\" " << endl;
		Sleep(1000);
		return false;
	}
	cout << "=> Enter Driver Name : ";
	cin >> name;
	cout << "=> Enter Driver Contact No: ";
	cin >> contactNo;
	cout << "=> Enter Driver Vehicle: ";
	cin >> vehicle;
	cout << "=> Enter Driver Vehicle Class: ";
	cin.ignore();
	getline(cin, vehicleClass);
	cin.ignore();
	return true;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Driver ID Function
int Driver::getDriverID() {
	return id;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Driver Password Function
string Driver::getDriverPass() {
	return password;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Driver Name Function
string Driver::getDriverName() {
	return name;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Driver Contact No Function
string Driver::getDriverContactNo() {
	return contactNo;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Driver Vehicle Function
string Driver::getDriverVehicle() {
	return vehicle;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Driver Pickup Function
string Driver::getDriverPickUp() {
	return pickup;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Driver Dropoff Function
string Driver::getDriverDropOFf() {
	return dropoff;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Driver Distance Function
int Driver::getDriverDistance() {
	return arrivalTime;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Driver Vehicle Class Function
string Driver::getDriverVehicleClass() {
	return vehicleClass;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

int Driver::getDriverArrivalTime() {
	return arrivalTime;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

int Driver::getDriverFare() {
	return fare;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Driver Driver Function
bool Driver::RegisterDriver(Linked_List<Driver>& DriverList) {
	bool check = false;
	check = setDriverData(DriverList);
	if (check) {
		DriverList.InsertEnd(*this);
		return true;
	}
	return check;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Record Search Function
void Driver::SearchDriverRecord(Linked_List<Driver>& DriverList) {
	system("CLS");
	int ID;
	do {
		cout << "\n\n\n\n\t >>>>>>>> DRIVER RECORD SEARCH <<<<<<< \n\n";
		cout << "=> Enter Driver ID to Search its Record : ";
		cin >> ID;
		if (ID <= 0) {
			cerr << " <*> Error! Wrong Input ... " << endl;
			Sleep(1000);
			system("CLS");
		}
	} while (ID <= 0);

	Node<Driver>* temp = DriverList.GetHead();
	bool check = false;

	if (temp != NULL) {
		if (ID == temp->data.id) {
			temp->data.RecordDisplay();
			check = true;
		}
		else {
			while (temp != NULL) {
				if (ID == temp->data.id) {
					temp->data.RecordDisplay();
					check = true;
					break;
				}
				temp = temp->next;
			}
		}
	}

	if (check) {
		cout << "\n\" <*> Driver Record Search Successfully ...\" " << endl;
	}
	else {
		cout << "\n\" <*> No Driver Record Found ...\" " << endl;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Record Delete Function
void Driver::DeleteDriverRecord(Linked_List<Driver>& DriverList) {
	system("CLS");
	int ID;
	do {
		cout << "\n\n\n\n\t >>>>>>>> DRIVER RECORD DELETION <<<<<<< \n\n";
		cout << "=> Enter Driver ID to Delete its Record : ";
		cin >> ID;
		if (ID <= 0) {
			cerr << " <*> Error! Wrong Input ... " << endl;
			Sleep(1000);
			system("CLS");
		}
	} while (ID <= 0);

	Node<Driver>* temp = DriverList.GetHead();
	Node<Driver>* prev = DriverList.GetHead();
	bool check = false;

	if (temp != NULL) {
		if (ID == temp->data.id) {
			DriverList.SetHead(temp->next);
			delete temp;
			check = true;
		}
		else {
			while (temp->next != NULL) {
				if (ID == temp->data.id) {
					prev->next = temp->next;
					delete temp;
					check = true;
					break;
				}
				prev = temp;
				temp = temp->next;
			}
			if (temp->next == NULL && !check && ID == temp->data.id) {
				DriverList.RemoveEnd();
				check = true;
			}
		}
	}

	if (check) {
		cout << "\n\" <*> Driver Record Deleted Successfully ...\" " << endl;
	}
	else {
		cout << "\n\" <*> No Driver Record Found ...\" " << endl;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Record Display Function
void Driver::RecordDisplay() {
	cout << "\n => Driver ID : " << id;
	cout << "\n => Driver Name : " << name;
	cout << "\n => Driver Contact No: " << contactNo;
	cout << "\n => Driver Vehicle: " << vehicle;
	cout << "\n => Driver Vehicle Class: " << vehicleClass;
	cout << "\n-----------------------------------------\n" << endl;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

 // Record View Function
void Driver::ViewDriverRecord(Linked_List<Driver> DriverList) {
	system("CLS");
	cout << "\n\n\n\n\t >>>>>>>> DRIVER ALL RECORDS <<<<<<< \n\n";	Node<Driver>* temp = DriverList.GetHead();
	if (temp == NULL) {
		cout << "\n No Car Record Found" << endl;
	}
	else {
		while (temp != NULL) {
			temp->data.RecordDisplay();
			temp = temp->next;
		}
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------


void Driver::SetPassengerRequest(Passenger& P) {
	PassengerRequest.InsertRear(P);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

bool Driver::ShowPassengerRequest() {
	return PassengerRequest.CheckFront();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Driver::sendRequestToPassenger(Linked_List<Passenger>& PassengerList, int Passengerid, DriverRequest d) {
	Node<Passenger>* realPassenger = PassengerList.GetHead();
	while (realPassenger != NULL) {
		if (Passengerid == realPassenger->data.getPassengerID()) {
			realPassenger->data.setDriverRequest(d);
			break;
		}
		realPassenger = realPassenger->next;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Driver::AcceptPassengerRequest(Linked_List<Passenger>& PassengerList) {
	int ID;
	do {
		cout << "\n\n\n\n\t >>>>>>>> RIDE REQUEST <<<<<<< \n\n";
		cout << "=> Enter PASSENGER ID to Accept the Ride : ";
		cin >> ID;
		if (ID <= 0) {
			cerr << " <*> Error! Wrong Input ... " << endl;
			Sleep(1000);
			system("CLS");
		}
	} while (ID <= 0);
	cout << "=> Enter RIDE FARE : ";
	cin >> fare;
	cout << "=> Enter ARRIVAL TIME : ";
	cin >> arrivalTime;
	NodeQueue<Passenger>* temp = PassengerRequest.getHead();
	while (temp != NULL) {
		if (ID == temp->data.getPassengerID()) {
			DriverRequest d;
			d.setRequest(this->getDriverID(), this->getDriverName(), this->getDriverContactNo(), this->getDriverVehicle(), this->getDriverVehicleClass(), this->getDriverFare(), this->getDriverArrivalTime());
			sendRequestToPassenger(PassengerList, ID, d);
			char c;
			cout << "\n <*> Your Request Has Been Sended to Passenger ID (" << ID << ")." << endl;
			cin >> c;
		}
		temp = temp->next;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Driver::DeclinePassengerRequest() {

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
