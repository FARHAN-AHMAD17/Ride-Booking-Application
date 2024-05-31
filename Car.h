#pragma once
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

// Car Class //

class Car {
private:
	// Data Members
	int id;
	string name;
	string model;
	string engineCC;
	string regNo;
public:
	// Constructors
	Car();
	// Member Functions
	bool setCarData(Linked_List<Car>& CarList);
	int getCarID();
	string getCarName();
	string getCarModel();
	string getCarEngineCC();
	string getCarRegNo();
	bool RegisterCar(Linked_List<Car>& CarList);
	void SearchCarRecord(Linked_List<Car>& CarList);
	void DeleteCarRecord(Linked_List<Car>& CarList);
	void RecordDisplay();
	void ViewCarRecord(Linked_List<Car> CarList);
	bool operator==(Car c2) {
		if (id == c2.id) {
			return true;
		}
		else {
			return false;
		}
	}
	friend ostream& operator<<(ostream& output, Car c) {
		output << "\n => Car ID : " << c.id;
		output << "\n => Car Name : " << c.name;
		output << "\n => Car Model: " << c.model;
		output << "\n => Car Engine CC: " << c.engineCC;
		output << "\n => Car Registration Number: " << c.regNo;
		output << "\n-----------------------------------------\n" << endl;
		return output;
	}
};

// Constructors Defintion

Car::Car() : id(0), name(""), model(""), engineCC(""), regNo("") {}

//-------------------------------------- Memeber Functions Definition  -------------------------------------------------------------------------------------------------------

// Set Data Function
bool Car::setCarData(Linked_List<Car>& CarList) {
	bool check = false;
	do {
		cout << "\n\n\n\n\t >>>>>>>> CAR REGISTRATION <<<<<<< \n\n";
		cout << "=> Enter Car ID : ";
		cin >> id;
		if (id <= 0) {
			cerr << " <*> Error! Wrong Input ... " << endl;
			Sleep(1000);
			system("CLS");
		}
	} while (id <= 0);

	check = CarList.dataValidity(*this);
	if (!check) {
		cout << "\n\" <*> Car Already Registered ...\" " << endl;
		Sleep(1000);
		return false;
	}
	cout << "=> Enter Car Name : ";
	cin >> name;
	cout << "=> Enter Car Model: ";
	cin >> model;
	cout << "=> Enter Car Engine CC: ";
	cin >> engineCC;
	cout << "=> Enter Car Registration Number: ";
	cin >> regNo;
	return true;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Car ID Function
int Car::getCarID() {
	return id;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Car Name Function
string Car::getCarName() {
	return name;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Car Model Function
string Car::getCarModel() {
	return model;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Car EngineCC Function
string Car::getCarEngineCC() {
	return engineCC;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Car RegNo Function
string Car::getCarRegNo() {
	return regNo;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

bool Car::RegisterCar(Linked_List<Car>& CarList) {
	bool check = false;
	check = setCarData(CarList);
	if (check) {
		CarList.InsertEnd(*this);
		return true;
	}
	return check;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Car::SearchCarRecord(Linked_List<Car>& CarList) {
	system("CLS");
	int ID;
	do {
		cout << "\n\n\n\n\t >>>>>>>> CAR RECORD SEARCH <<<<<<< \n\n";
		cout << "=> Enter Car ID to Search its Record : ";
		cin >> ID;
		if (ID <= 0) {
			cerr << " <*> Error! Wrong Input ... " << endl;
			Sleep(1000);
			system("CLS");
		}
	} while (ID <= 0);

	Node<Car>* temp = CarList.GetHead();
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
		cout << "\n\" <*> Car Record Search Successfully ...\" " << endl;
	}
	else {
		cout << "\n\" <*> No Car Record Found ...\" " << endl;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Car::DeleteCarRecord(Linked_List<Car>& CarList) {
	system("CLS");
	int ID;
	do {
		cout << "\n\n\n\n\t >>>>>>>> CAR RECORD DELETION <<<<<<< \n\n";
		cout << "=> Enter Car ID to Delete its Record : ";
		cin >> ID;
		if (ID <= 0) {
			cerr << " <*> Error! Wrong Input ... " << endl;
			Sleep(1000);
			system("CLS");
		}
	} while (ID <= 0);

	Node<Car>* temp = CarList.GetHead();
	Node<Car>* prev = CarList.GetHead();
	bool check = false;

	if (temp != NULL) {
		if (ID == temp->data.id) {
			CarList.SetHead(temp->next);
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
				CarList.RemoveEnd();
				check = true;
			}
		}
	}

	if (check) {
		cout << "\n\" <*> Car Record Deleted Successfully ...\" " << endl;
	}
	else {
		cout << "\n\" <*> No Car Record Found ...\" " << endl;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Record Display Function
void Car::RecordDisplay() {
	cout << "\n => Car ID : " << id;
	cout << "\n => Car Name : " << name;
	cout << "\n => Car Model: " << model;
	cout << "\n => Car Engine CC: " << engineCC;
	cout << "\n => Car Registration Number: " << regNo;
	cout << "\n-----------------------------------------\n" << endl;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

 // VIEW RECORD FUNCTION
void Car::ViewCarRecord(Linked_List<Car> CarList) {
	system("CLS");
	cout << "\n\n\n\n\t >>>>>>>> CAR ALL RECORDS <<<<<<< \n\n";
	Node<Car>* temp = CarList.GetHead();
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
