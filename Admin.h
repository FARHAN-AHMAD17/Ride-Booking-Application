#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<string>
#include<cstring>

using namespace std;

// Admin Class //

class Admin { //
private:
	// Data Members
	string id;
	string password;
public:
	// Constructors
	Admin();
	Admin(string, string);
	// Memeber Functions
	void setValue();
	string getID();
	string getPass();
};

// Constructors Defintion
Admin::Admin() : id(""), password("") {}
Admin::Admin(string iD, string pass) : id(iD), password(pass) {}

//-------------------------------------- Memeber Functions Definition --------------------------------------------------------------------------------------------------------------

// Set Data Function
void Admin::setValue() {
	cout << "=> Enter Your ID : ";
	cin >> id;
	cout << "=> Enter Your Password : ";
	cin >> password;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Admin ID Function
string Admin::getID() {
	return id;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Get Admin Password Function
string Admin::getPass() {
	return password;
}
