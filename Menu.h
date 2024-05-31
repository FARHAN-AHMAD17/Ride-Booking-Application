#pragma once
#include<iostream>
#include<conio.h>
#include <iomanip>
#include "Admin.h"
#include "Driver.h"
#include "Passenger.h"
#include "Car.h"
#include "LinkedList.h"
#include "Queue.h"
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

using namespace std;

class Menu {
public:

	// MENU FUNCTIONS
	void Intro_Display(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList);
	void Main_Menu(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList);

	// ADMIN FUNCTIONS
	void Admin_Login();
	void Admin_Operations(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList);
	void Car_Portal(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList);
	void Driver_Portal(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList);
	void Passenger_Portal(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList);

	// DRIVER FUNCTIONS
	int Driver_Login(Linked_List<Driver>& DriverList);
	Driver& getDriverAccount(Linked_List<Driver>& DriverList, int Driverid);
	void Driver_Operations(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList, int Driverid);

	// PASSENGER FUNCTIONS
	int Passenger_Login(Linked_List<Passenger>& PassengerList);
	Passenger& getPassengerAccount(Linked_List<Passenger>& PassengerList, int Passengerid);
	void Passenger_Operations(Linked_List<Car>& CarList, Linked_List<Passenger>& PassengerList, Linked_List<Driver>& DriverList, int Passengerid);
	void SelectRideClass(Linked_List<Passenger>& PassengerList, Linked_List<Driver>& DriverList, int Passengerid, string rideClass);
	void RideBooking(Linked_List<Car>& CarList, Linked_List<Passenger>& PassengerList, Linked_List<Driver>& DriverList, int Passengerid);

};

//-------------------------------------- Memeber Functions Definition  -------------------------------------------------------------------------------------------------------

// Function to Display Welcome Screen
void Menu::Intro_Display(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList)
{
	cout <<LIGHT_CYAN<< "\n\n"  << "				 >>>>>>>>>>>>>>>>>>>>>>>> W E L C O M E <<<<<<<<<<<<<<<<<<<<<<< " << endl;
	cout <<BLUE<< "\n\n"  << "						  F A Q   R I D I N G   A P P " << endl;
	cout << "\n\n"  << "							_ M A D E   B Y _ " << endl;
	cout << "\n"  << "\t					     F A R H A N   A H M A D " << endl;
	cout <<LIGHT_CYAN<< "\n"  << "				 :-------------------------------------------------------------: " << endl;
	cout << "\n\n\n\n" << endl;

	char Key;
	cout <<YELLOW<<"\n\t <*> Press any key to Continue : ";
	cin >> Key;
	Main_Menu(CarList, DriverList, PassengerList);
	return;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Main Menu Function
void Menu::Main_Menu(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList) {
	system("CLS");
	int UserChoice1;
	cout <<LIGHT_CYAN<< "\n\n\t\t _ \" F A Q   R I D I N G   A P P \"  __ ";
	cout << BLUE<<"\n\n\n\n\t >>>>>>>> MAIN MENU <<<<<<< ";
	cout << "\n\n\t 1) ADMIN LOGIN ";
	cout << "\n\n\t 2) DRIVER LOGIN ";
	cout << "\n\n\t 3) PASSENGER LOGIN ";
	cout << "\n\n\t 4) EXIT " << endl;
	do {
		cout<<YELLOW << "\n\n\n\t~> Select One Option From Above By Pressing Any Key From (1 to 4) = ";
		cin >> UserChoice1;
	} while (UserChoice1 != 1 && UserChoice1 != 2 && UserChoice1 != 3 && UserChoice1 != 4);

	switch (UserChoice1)
	{
	case 1: {
		Admin_Login();
		Admin_Operations(CarList, DriverList, PassengerList);
		break;
	}
	case 2: {
		int Driverid = Driver_Login(DriverList);
		Driver_Operations(CarList, DriverList, PassengerList, Driverid);
		Main_Menu(CarList, DriverList, PassengerList);
		break;
	}
	case 3: {
		int Passengerid = Passenger_Login(PassengerList);
		Passenger_Operations(CarList, PassengerList, DriverList, Passengerid);
		Main_Menu(CarList, DriverList, PassengerList);
		break;
	}
	case 4: {
		exit(1);
		break;
	}
	default: {
		cout <<RED<< "Wrong Input" << endl;
	}
	}
	return;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Admin Login Function
void Menu::Admin_Login() {
	system("CLS");
	Admin admin;
	do {
		cout <<GREEN<< "\n\n\n\t" << "_ ADMIN LOGIN _ \n" << endl;
		admin.setValue();
		if (admin.getPass() != "a") {
			cout <<RED<< "\n<*> You have Entered Wrong Password. Please Enter Again ... \n" << endl;
		}
	} while (admin.getPass() != "a");
	cout <<RESET<< "\n\n\t <*> Account Login Successful ... " << endl;
	char key;
	cout <<YELLOW<< "\n\t ~> Press any key to continue : "; cin >> key;
	return;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Admin Operations Function
void Menu::Admin_Operations(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList) {
	system("CLS");
	cout <<LIGHT_CYAN<< "\n\n\t\t _ \" F A Q   R I D I N G   A P P \"  __ ";
	cout <<BLUE<< "\n\n\n\n\t >>>>>>>> ADMIN OPERATIONS <<<<<<< ";
	cout << "\n\n\t 1) CAR PORTAL ";
	cout << "\n\n\t 2) DRIVER PORTAL ";
	cout << "\n\n\t 3) PASSENGER PORTAL ";
	cout << "\n\n\t 4) RETURN TO MAIN MENU ";
	int choice;
	do {
		cout <<YELLOW<< "\n\n\n\t=> Select One Option From Above By Pressing Any Key From (1 to 4) = ";
		cin >> choice;
	} while (!(choice >= 1) && !(choice <= 5));

	switch (choice)
	{
	case 1: {
		Car_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 2: {
		Driver_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 3: {
		Passenger_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 4: {
		Main_Menu(CarList, DriverList, PassengerList);
		break;
	}
	default: {
		cerr <<RED<< " <*> Error! Wrong Input ... " << endl;
	}
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Menu::Car_Portal(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList) {
	system("CLS");
	cout <<LIGHT_CYAN<< "\n\n\t\t _ \" F A Q   R I D I N G   A P P \"  __ ";
	cout <<BLUE<< "\n\n\n\n\t >>>>>>>> CAR PORTAL <<<<<<< ";
	cout << "\n\n\t 1) CAR REGISTRATION ";
	cout << "\n\n\t 2) SEARCH CAR RECORD ";
	cout << "\n\n\t 3) DELETE CAR RECORD ";
	cout << "\n\n\t 4) VIEW ALL CAR RECORDS ";
	cout << "\n\n\t 5) RETURN BACK ";
	int choice;
	do {
		cout <<YELLOW<< "\n\n\n\t=> Select One Option From Above By Pressing Any Key From (1 to 5) = ";
		cin >> choice;
	} while (!(choice >= 1) && !(choice <= 5));

	switch (choice)
	{
	case 1: {
		char key;
		do {
			bool check = false;
			system("CLS");
			Car car;
			check = car.RegisterCar(CarList);
			if (check) {
				cout <<RESET<< "\n\" <*> Car Registered Successfully ...\" " << endl;
			}
			cout <<GREEN<< "\n~> Do you want to Register Another Car ? (y/n) : ";
			cin >> key;
		} while (key == 'y' || key == 'Y');
		Car_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 2: {
		system("CLS");
		Car car;
		car.SearchCarRecord(CarList);
		char key;
		cout <<YELLOW<< "\n <*> Press any to continue ... ";
		cin >> key;
		Car_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 3: {
		system("CLS");
		Car car;
		car.DeleteCarRecord(CarList);
		char key;
		cout <<YELLOW<< "\n <*> Press any to continue ... ";
		cin >> key;
		Car_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 4: {
		Car car;
		car.ViewCarRecord(CarList);
		char key;
		cout <<YELLOW<< "\n <*> Press any to continue ... ";
		cin >> key;
		Car_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 5: {
		Admin_Operations(CarList, DriverList, PassengerList);
		break;
	}
	default: {
		cerr <<RED<< " <*> Error! Wrong Input ... " << endl;
	}
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Menu::Driver_Portal(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList) {
	system("CLS");
	cout <<LIGHT_CYAN<< "\n\n\t\t _ \" F A Q   R I D I N G   A P P \"  __ ";
	cout <<BLUE<< "\n\n\n\n\t >>>>>>>> DRIVER PORTAL <<<<<<< ";
	cout << "\n\n\t 1) DRIVER REGISTRATION ";
	cout << "\n\n\t 2) SEARCH DRIVER RECORD ";
	cout << "\n\n\t 3) DELETE DRIVER RECORD ";
	cout << "\n\n\t 4) VIEW ALL DRIVER RECORDS ";
	cout << "\n\n\t 5) RETURN BACK ";
	int choice;
	do {
		cout <<YELLOW<< "\n\n\n\t=> Select One Option From Above By Pressing Any Key From (1 to 5) = ";
		cin >> choice;
	} while (!(choice >= 1) && !(choice <= 5));

	switch (choice)
	{
	case 1: {
		char key;
		do {
			bool check = false;
			system("CLS");
			Driver driver;
			check = driver.RegisterDriver(DriverList);
			if (check) {
				cout <<GREEN<< "\n\" <*> Driver Registered Successfully ...\" " << endl;
			}
			cout <<YELLOW<< "\n~> Do you want to Register Another Driver ? (y/n) : ";
			cin >> key;
		} while (key == 'y' || key == 'Y');
		Driver_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 2: {
		system("CLS");
		Driver driver;
		driver.SearchDriverRecord(DriverList);
		char key;
		cout <<YELLOW<< "\n <*> Press any to continue ... ";
		cin >> key;
		Driver_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 3: {
		system("CLS");
		Driver driver;
		driver.DeleteDriverRecord(DriverList);
		char key;
		cout <<YELLOW<< "\n <*> Press any to continue ... ";
		cin >> key;
		Driver_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 4: {
		Driver driver;
		driver.ViewDriverRecord(DriverList);
		char key;
		cout <<YELLOW<< "\n <*> Press any to continue ... ";
		cin >> key;
		Driver_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 5: {
		Admin_Operations(CarList, DriverList, PassengerList);
		break;
	}
	default: {
		cerr <<RED<< " <*> Error! Wrong Input ... " << endl;
	}
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Menu::Passenger_Portal(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList) {
	system("CLS");
	cout <<LIGHT_CYAN<< "\n\n\t\t _ \" F A Q   R I D I N G   A P P \"  __ ";
	cout <<BLUE<< "\n\n\n\n\t >>>>>>>> PASSENGER PORTAL <<<<<<< ";
	cout << "\n\n\t 1) PASSENGER REGISTRATION ";
	cout << "\n\n\t 2) SEARCH PASSENGER RECORD ";
	cout << "\n\n\t 3) DELETE PASSENGER RECORD ";
	cout << "\n\n\t 4) VIEW ALL PASSENGER RECORDS ";
	cout << "\n\n\t 5) RETURN BACK ";
	int choice;
	do {
		cout <<YELLOW<< "\n\n\n\t=> Select One Option From Above By Pressing Any Key From (1 to 5) = ";
		cin >> choice;
	} while (!(choice >= 1) && !(choice <= 5));

	switch (choice)
	{
	case 1: {
		char key;
		do {
			bool check = false;
			system("CLS");
			Passenger passenger;
			check = passenger.RegisterPassenger(PassengerList);
			if (check) {
				cout <<GREEN<< "\n\" <*> Passenger Registered Successfully ...\" " << endl;
			}
			cout <<YELLOW<< "\n~> Do you want to Register Another Passenger ? (y/n) : ";
			cin >> key;
		} while (key == 'y' || key == 'Y');
		Passenger_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 2: {
		system("CLS");
		Passenger passenger;
		passenger.SearchPassengerRecord(PassengerList);
		char key;
		cout <<YELLOW<< "\n <*> Press any to continue ... ";
		cin >> key;
		Passenger_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 3: {
		system("CLS");
		Passenger passenger;
		passenger.DeletePassengerRecord(PassengerList);
		char key;
		cout <<YELLOW<< "\n <*> Press any to continue ... ";
		cin >> key;
		Passenger_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 4: {
		Passenger passenger;
		passenger.ViewPassengerRecord(PassengerList);
		char key;
		cout <<YELLOW<< "\n <*> Press any to continue ... ";
		cin >> key;
		Passenger_Portal(CarList, DriverList, PassengerList);
		break;
	}
	case 5: {
		Admin_Operations(CarList, DriverList, PassengerList);
		break;
	}
	default: {
		cerr <<RED<< " <*> Error! Wrong Input ... " << endl;
	}
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

int Menu::Driver_Login(Linked_List<Driver>& DriverList) {
	system("CLS");
	int ID;
	string Password;
	do {
		cout <<LIGHT_CYAN<< "\n\n\n\t" << "_ DRIVER LOGIN _ \n" << endl;
		cout <<BLUE<< "=> Enter Your ID : ";
		cin >> ID;
		cout << "=> Enter Your Password : ";
		cin >> Password;
		if (Password != "d") {
			cout <<RED<< "\n<*> You have Entered Wrong Password. Please Enter Again ... \n" << endl;
		}
	} while (Password != "d");
	bool check = false;
	Node<Driver>* temp = DriverList.GetHead();
	while (temp != NULL) {
		if (ID == temp->data.getDriverID()) {
			check = true;
			break;
		}
		temp = temp->next;
	}
	if (check) {
		cout <<GREEN<< "\n\n\t <*> Account Login Successful ... " << endl;
	}
	else {
		cout <<GREEN<< "\n\n\t <*> No Account Found ... " << endl;
	}

	char key;
	cout <<YELLOW<< "\n\t ~> Press any key to continue : "; cin >> key;
	return ID;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

Driver& Menu::getDriverAccount(Linked_List<Driver>& DriverList, int Driverid) {
	Node<Driver>* realDriver = DriverList.GetHead();
	while (realDriver != NULL) {
		if (Driverid == realDriver->data.getDriverID()) {
			return realDriver->data;
			break;
		}
		realDriver = realDriver->next;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Menu::Driver_Operations(Linked_List<Car>& CarList, Linked_List<Driver>& DriverList, Linked_List<Passenger>& PassengerList, int Driverid) {
	system("CLS");
	cout <<LIGHT_CYAN<< "\n\n\t\t _ \" F A Q   R I D I N G   A P P \"  __ ";
	cout <<BLUE<< "\n\n\n\n\t >>>>>>>> DRIVER OPERATIONS <<<<<<< ";
	cout << "\n\n\t 1) RIDE REQUESTS ";
	cout << "\n\n\t 2) RECORD DISPLAY ";
	cout << "\n\n\t 3) SIGN OUT ";
	int choice;
	do {
		cout <<YELLOW<< "\n\n\n\t=> Select One Option From Above By Pressing Any Key From (1 to 3) = ";
		cin >> choice;
	} while (!(choice >= 1) && !(choice <= 5));

	switch (choice)
	{
	case 1: {
		bool check = false;
		check = getDriverAccount(DriverList, Driverid).ShowPassengerRequest();
		if (check) {
			getDriverAccount(DriverList, Driverid).AcceptPassengerRequest(PassengerList);
		}
		else {
			cout <<GREEN<< "\n <*> No Passenger Ride Request Found ... " << endl;
		}
		char key;
		cout <<YELLOW<< "\n\t ~> Press any key to continue : "; cin >> key;
		//Driver_Operations(CarList, DriverList, PassengerList, Driverid);
		break;
	}
	case 2: {
		getDriverAccount(DriverList, Driverid).RecordDisplay();
		char key;
		cout <<YELLOW<< "\n\t ~> Press any key to continue : "; cin >> key;
		break;
	}
	case 3: {
		Main_Menu(CarList, DriverList, PassengerList);
		break;
	}
	default: {
		cerr <<RED<< " <*> Error! Wrong Input ... " << endl;
	}
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Passenger Login Function

int Menu::Passenger_Login(Linked_List<Passenger>& PassengerList) {
	system("CLS");
	int ID;
	string Password;
	do {
		cout <<BLUE<< "\n\n\n\t" << "_ PASSENGER LOGIN _ \n" << endl;
		cout << YELLOW<<"=> Enter Your ID : ";
		cin >> ID;
		cout << YELLOW << "=> Enter Your Password : ";
		cin >> Password;
		if (Password != "p") {
			cout << RED<<"\n<*> You have Entered Wrong Password. Please Enter Again ... \n" << endl;
		}
	} while (Password != "p");
	bool check = false;
	Node<Passenger>* temp = PassengerList.GetHead();
	while (temp != NULL) {
		if (ID == temp->data.getPassengerID()) {
			check = true;
			break;
		}
		temp = temp->next;
	}
	if (check) {
		cout <<GREEN<< "\n\n\t <*> Account Login Successful ... " << endl;
	}
	else {
		cout <<GREEN<< "\n\n\t <*> No Account Found ... " << endl;
	}
	char key;
	cout <<YELLOW<< "\n\t ~> Press any key to continue : "; cin >> key;
	return ID;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

Passenger& Menu::getPassengerAccount(Linked_List<Passenger>& PassengerList, int Passengerid) {
	Node<Passenger>* realPassenger = PassengerList.GetHead();
	while (realPassenger != NULL) {
		if (Passengerid == realPassenger->data.getPassengerID()) {
			return realPassenger->data;
			break;
		}
		realPassenger = realPassenger->next;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Menu::Passenger_Operations(Linked_List<Car>& CarList, Linked_List<Passenger>& PassengerList, Linked_List<Driver>& DriverList, int Passengerid) {
	system("CLS");
	cout <<BLUE<< "\n\n\n\n\t >>>>>>>> PASSENGER OPERATIONS <<<<<<< ";
	cout << "\n\n\t 1) RIDE BOOKING ";
	cout << "\n\n\t 2) DRIVER REQUESTS ";
	cout << "\n\n\t 3) TRIP RECORD ";
	cout << "\n\n\t 4) SIGN OUT ";
	int choice;
	do {
		cout <<YELLOW<< "\n\n\n\t=> Select One Option From Above By Pressing Any Key From (1 to 4) = ";
		cin >> choice;
	} while (!(choice >= 1) && !(choice <= 5));

	switch (choice)
	{
	case 1: {
		RideBooking(CarList, PassengerList, DriverList, Passengerid);
		//Passenger_Operations(CarList, PassengerList, DriverList, Passengerid);
		break;
	}
	case 2: {
		bool check = false;
		check = getPassengerAccount(PassengerList, Passengerid).showDriverRequest();
		if (check) {
			getPassengerAccount(PassengerList, Passengerid).startRide();
		}
		else {
			cout <<GREEN<< "\n <*> No Passenger Ride Request Found ... " << endl;
		}
		char key;
		cout << YELLOW << "\n\t ~> Press any key to continue : "; cin >> key;
		break;
	}
	case 3: {
		getPassengerAccount(PassengerList, Passengerid).RecordDisplay();
		char key;
		cout << YELLOW << "\n\t ~> Press any key to continue : "; cin >> key;
		break;
	}
	case 4: {
		Main_Menu(CarList, DriverList, PassengerList);
		break;
	}
	default: {
		cerr <<RED<< " <*> Error! Wrong Input ... " << endl;
	}
	}
	return;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Menu::SelectRideClass(Linked_List<Passenger>& PassengerList, Linked_List<Driver>& DriverList, int Passengerid, string rideClass) {
	string pickup, dropoff;
	cout << YELLOW << "=> Enter Pickup Location : "; cin >> pickup;
	cout << YELLOW << "=> Enter Drop Location : "; cin >> dropoff;
	bool check = false;

	Node<Driver>* temp = DriverList.GetHead();
	int serial = 1;
	while (temp != NULL) {
		if (temp->data.getDriverVehicleClass() == rideClass) {
			getPassengerAccount(PassengerList, Passengerid).setPickup(pickup);
			getPassengerAccount(PassengerList, Passengerid).setDropOff(dropoff);
			temp->data.SetPassengerRequest(getPassengerAccount(PassengerList, Passengerid));
			cout <<BLUE<< serial << ") DRIVER ID: " << temp->data.getDriverID() << "   DRIVER NAME: " << temp->data.getDriverName() << endl;
			serial++;
			check = true;
		}
		temp = temp->next;
	}
	if (check) {
		cout << GREEN<<"=> Your Request has been sent to Nearby Drivers : \n\n";
		cout << "\n <*> Waiting For Driver's Response ... " << endl;
	}
	else {
		cout << "\n <*> No " << rideClass << " Driver Available At the Moment ... " << endl;
	}
	char key;
	cout << YELLOW << "\n\t ~> Press any key to continue : "; cin >> key;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void Menu::RideBooking(Linked_List<Car>& CarList, Linked_List<Passenger>& PassengerList, Linked_List<Driver>& DriverList, int Passengerid) {
	system("CLS");
	cout << LIGHT_CYAN<<"\n\n\t\t _ \" F A Q   R I D I N G   A P P \"  __ ";
	cout <<BLUE<< "\n\n\n\n\t >>>>>>>> RIDE BOOKING <<<<<<< ";
	cout << "\n\n\t 1) GO MINI ";
	cout << "\n\n\t 2) GO ";
	cout << "\n\n\t 3) LUXURY ";
	cout << "\n\n\t 4) RETURN BACK ";
	int choice;
	do {
		cout << YELLOW << "\n\n\n\t=> Select One Option From Above By Pressing Any Key From (1 to 4) = ";
		cin >> choice;
	} while (!(choice >= 1) && !(choice <= 5));

	switch (choice)
	{
	case 1: {
		system("CLS");
		cout << GREEN<<"\n\n\n\n\t >>>>>>>> GO MINI RIDE BOOKING <<<<<<< \n\n";
		SelectRideClass(PassengerList, DriverList, Passengerid, "GO MINI");
		break;
	}
	case 2: {
		system("CLS");
		cout <<GREEN<< "\n\n\n\n\t >>>>>>>> GO RIDE BOOKING <<<<<<< \n\n";
		SelectRideClass(PassengerList, DriverList, Passengerid, "GO");
		break;
	}
	case 3: {
		system("CLS");
		cout <<GREEN<< "\n\n\n\n\t >>>>>>>> LUXURY RIDE BOOKING <<<<<<< \n\n";
		SelectRideClass(PassengerList, DriverList, Passengerid, "LUXURY");
		break;
	}
	case 4: {
		Passenger_Operations(CarList, PassengerList, DriverList, Passengerid);
		break;
	}
	default: {
		cerr <<RED<< " <*> Error! Wrong Input ... " << endl;
	}
	}
	return;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------------------------------------------
