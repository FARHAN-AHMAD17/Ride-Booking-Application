#pragma once
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Menu.h"
#include <fstream>
#include "Driver.h"
using namespace std;
#define RESET   "\033[0m"      // GREEN to default text color
#define RED     "\033[31m"     // Red text color
#define GREEN   "\033[32m"     // Green text color
#define YELLOW  "\033[33m"     // LIGHT_CYAN text color
#define BLUE    "\033[34m"     // GRAY text color
#define MAGENTA "\033[35m"     // GRAY text color
#define CYAN    "\033[36m"     // Cyan text color
#define WHITE   "\033[37m"     // White text color
#define GRAY    "\033[90m"     // Gray text color
#define LIGHT_RED     "\033[91m"     // Light Red text color
#define LIGHT_GREEN   "\033[92m"     // Light Green text color
#define LIGHT_LIGHT_CYAN  "\033[93m"     // Light LIGHT_CYAN text color
#define LIGHT_GRA    "\033[94m"     // Light GRAY text color
#define LIGHT_GRAY "\033[95m"     // Light GRAY text color
#define LIGHT_CYAN    "\033[96m"     // Light Cyan text color

// Passenger Class //

class DriverRequest {
private:
	int id;
	string name;
	string contactNo;
	string vehicle;
	string vehicleClass;
	int arrivalTime;
	int fare;
public:
	DriverRequest() : id(0), name(""), contactNo(""), vehicle(""), vehicleClass(""), arrivalTime(0), fare(0) {}
	void setRequest(int i, string n, string c, string v, string vc, int f, int at) {
		id = i;
		name = n;
		contactNo = c;
		vehicle = v;
		vehicleClass = vc;
		fare = f;
		arrivalTime = at;
	}
	int getDriverID() {
		return id;
	}
	string getDriverName() {
		return name;
	}
	string getDriverContactNo() {
		return contactNo;
	}
	string getDriverVehicle() {
		return vehicle;
	}
	string getDriverVehicleClass() {
		return vehicleClass;
	}
	int getDriverFare() {
		return fare;
	}
	int getDriverArrivalTime() {
		return arrivalTime;
	}
	friend ostream& operator<<(ostream& output, DriverRequest d) {
		output << GREEN<<"\n => Driver ID : " << d.id;
		output << "\n => Driver Name : " << d.name;
		output << "\n => Driver Contact No : " << d.contactNo;
		output << "\n => Driver Vehicle : " << d.vehicle;
		output << "\n => Driver Vehicle Class : " << d.vehicleClass;
		output << "\n => Driver Arrival Time : " << d.arrivalTime;
		output << "\n => Ride Fare : " << d.fare;
		output << "\n-----------------------------------------\n" << endl;
		return output;
	}
};

class Passenger {
private:
	// Data Members
	int id;
	string password;
	string name;
	string contactNo;
	int wallet;
	string pickup;
	string dropoff;
	string complaint;
	int acceptedDriverID;
	Stack<DriverRequest> rideHistory;
	Queue<DriverRequest> Request;
public:

	// Constructors
	Passenger();
	// Member Functions
	void setValue();
	bool setPassengerData(Linked_List<Passenger>& PassengerList);
	void setPickup(string pickup);
	void setDropOff(string dropoff);
	int getPassengerID();
	string getPassengerPass();
	string getPassengerName();
	string getPassengerContactNo();
	string getPassengerPassword();
	int getPassengerWallet();
	string getPassengerPickUp();
	string getPassengerDropOFf();
	string getPassengerComplaint();
	bool RegisterPassenger(Linked_List<Passenger>& PassengerList);
	void SearchPassengerRecord(Linked_List<Passenger>& PassengerList);
	void DeletePassengerRecord(Linked_List<Passenger>& PassengerList);
	void RecordDisplay();
	void ViewPassengerRecord(Linked_List<Passenger> PassengerList);
	bool operator==(Passenger p2) {
		if (id == p2.id) {
			return true;
		}
		else {
			return false;
		}
	}
	friend ostream& operator<<(ostream& output, Passenger p) {
		output <<GREEN<< "\n => Passenger ID : " << p.id;
		output << "\n => Passenger Name : " << p.name;
		output << "\n => Passenger Email: " << p.contactNo;
		output << "\n => Passenger Pickup Location: " << p.pickup;
		output << "\n => Passenger Dropoff Location: " << p.dropoff;
		output << "\n-----------------------------------------\n" << endl;
		return output;
	}
	void setName(string n) {
		name = n;
	}
	void Wallet();
	void YourTrips();
	void ComplaintPortal();
	void setDriverRequest(DriverRequest x) {
		Request.InsertRear(x);
	}
	bool showDriverRequest() {
		return Request.CheckFront();
	}
	void startRide();
	void showTripsHistory();
};

// Constructors Defintion

Passenger::Passenger() : id(0), name(""), contactNo(""), wallet(0), pickup(""), dropoff(""), complaint(""), acceptedDriverID(0) {}

//-------------------------------------- Memeber Functions Definition  -------------------------------------------------------------------------------------------------------

// Set Data Function
void Passenger::setValue() {
	cout <<YELLOW<< "=> Enter Your ID : ";
	cin >> id;
	cout << "=> Enter Your Password : ";
	cin >> password;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Set Data Function
bool Passenger::setPassengerData(Linked_List<Passenger>& PassengerList) {
	bool check = false;
	do {
		cout <<BLUE<< "\n\n\n\n\t >>>>>>>> PASSENGER REGISTRATION <<<<<<< \n\n";
		cout <<YELLOW<< "=> Enter Passenger ID : ";
		cin >> id;
		if (id <= 0) {
			cerr <<RED<< " <*> Error! Wrong Input ... " << endl;
			Sleep(1000);
			system("CLS");
		}
	} while (id <= 0);

	check = PassengerList.dataValidity(*this);
	if (!check) {
		cout <<GREEN<< "\n\" <*> Passenger Already Registered ... \" " << endl;
		Sleep(1000);
		return false;
	}
	cout << GREEN<<"=> Enter Passenger Name : ";
	cin >> name;
	cout << GREEN << "=> Enter Passenger Contact: ";
	cin >> contactNo;
	cout << GREEN << "=> Enter Passenger Wallet Amount: ";
	cin >> wallet;
	return true;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Passenger::setPickup(string pickup) {
	this->pickup = pickup;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Passenger::setDropOff(string dropoff) {
	this->dropoff = dropoff;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Passenger ID Function
int Passenger::getPassengerID() {
	return id;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Passenger Password Function
string Passenger::getPassengerPass() {
	return password;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Passenger Name Function
string Passenger::getPassengerName() {
	return name;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Passenger Contact No Function
string Passenger::getPassengerContactNo() {
	return contactNo;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Passenger Password Function
string Passenger::getPassengerPassword() {
	return password;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

int Passenger::getPassengerWallet() {
	return wallet;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

string Passenger::getPassengerPickUp() {
	return pickup;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

string Passenger::getPassengerDropOFf() {
	return dropoff;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

string Passenger::getPassengerComplaint() {
	return complaint;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

bool Passenger::RegisterPassenger(Linked_List<Passenger>& PassengerList) {
	bool check = false;
	check = setPassengerData(PassengerList);
	if (check) {
		PassengerList.InsertEnd(*this);
		return true;
	}
	return check;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Passenger::SearchPassengerRecord(Linked_List<Passenger>& PassengerList) {
	system("CLS");
	int ID;
	do {
		cout <<LIGHT_CYAN<< "\n\n\n\n\t >>>>>>>> PASSENGER RECORD SEARCH <<<<<<< \n\n";
		cout << GREEN << "=> Enter PASSENGER ID to Search its Record : ";
		cin >> ID;
		if (ID <= 0) {
			cerr <<RED<< " <*> Error! Wrong Input ... " << endl;
			Sleep(1000);
			system("CLS");
		}
	} while (ID <= 0);

	Node<Passenger>* temp = PassengerList.GetHead();
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
		cout << GREEN << "\n\" <*> Passenger Record Search Successfully ...\" " << endl;
	}
	else {
		cout <<RED<< "\n\" <*> No Passenger Record Found ...\" " << endl;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Passenger::DeletePassengerRecord(Linked_List<Passenger>& PassengerList) {
	system("CLS");
	int ID;
	do {
		cout <<LIGHT_CYAN<< "\n\n\n\n\t >>>>>>>> PASSENGER RECORD DELETION <<<<<<< \n\n";
		cout <<BLUE<< "=> Enter Passenger ID to Delete its Record : ";
		cin >> ID;
		if (ID <= 0) {
			cerr <<RED<< " <*> Error! Wrong Input ... " << endl;
			Sleep(1000);
			system("CLS");
		}
	} while (ID <= 0);

	Node<Passenger>* temp = PassengerList.GetHead();
	Node<Passenger>* prev = PassengerList.GetHead();
	bool check = false;

	if (temp != NULL) {
		if (ID == temp->data.id) {
			PassengerList.SetHead(temp->next);
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
				PassengerList.RemoveEnd();
				check = true;
			}
		}
	}

	if (check) {
		cout << "\n\" <*> Passenger Record Deleted Successfully ...\" " << endl;
	}
	else {
		cout <<GREEN<< "\n\" <*> No Passenger Record Found ...\" " << endl;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Record Display Function
void Passenger::RecordDisplay() {
	cout <<BLUE<< "\n => Passenger ID : " << id;
	cout << "\n => Passenger Name : " << name;
	cout << "\n => Passenger Email: " << contactNo;
	cout << "\n => Passenger Pickup Location: " << pickup;
	cout << "\n => Passenger Dropoff Location: " << dropoff;
	cout << "\n-----------------------------------------\n" << endl;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

 // VIEW RECORD FUNCTION
void Passenger::ViewPassengerRecord(Linked_List<Passenger> PassengerList) {
	system("CLS");
	cout <<LIGHT_CYAN<< "\n\n\n\n\t >>>>>>>> PASSENGER ALL RECORDS <<<<<<< \n\n";
	Node<Passenger>* temp = PassengerList.GetHead();
	if (temp == NULL) {
		cout <<GREEN<< "\n No Car Record Found" << endl;
	}
	else {
		while (temp != NULL) {
			temp->data.RecordDisplay();
			temp = temp->next;
		}
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Passenger::Wallet() {

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Passenger::YourTrips() {

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Passenger::ComplaintPortal() {

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Passenger::startRide() {
	int ID;
	do {
		cout <<BLUE<< "\n\n\n\n\t >>>>>>>> DRIVER REQUESTS <<<<<<< \n\n";
		cout << "=> Enter DRIVER ID to START the Ride : ";
		cin >> ID;
		if (ID <= 0) {
			cerr << " <*> Error! Wrong Input ... " << endl;
			Sleep(1000);
			system("CLS");
		}
	} while (ID <= 0);
	acceptedDriverID = ID;

	NodeQueue<DriverRequest>* temp = Request.getHead();
	while (temp != NULL) {
		if (ID == temp->data.getDriverID()) {
			rideHistory.push(temp->data);
			//Request.RemoveAll();
			char c;
			cout <<GREEN<< "\n <*> Your Ride Has Been Started with Driver ID (" << ID << ")." << endl;
			cin >> c;
		}
		temp = temp->next;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Passenger::showTripsHistory() {
	rideHistory.peek();
	return;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

