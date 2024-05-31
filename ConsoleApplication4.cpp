//// HEADER FILES ////
#include<iostream>
#include<conio.h>
#include <iomanip>
#include "Menu.h"
#include "Admin.h"
#include "Driver.h"
#include "Passenger.h"
#include "Car.h"

//#include <fstream>
//#include "LinkedList.h"
//#include<math.h>
//#include<cstring>
//#include "Stack.h"
#include "Queue.h"
//#include "Deque.h"
//#include "PriorityQueue.h"
#include "LinkedList.h"
//#include "DoublyLinkedList.h"
//#include "BinaryTree.h"
//#include "BinarySearchTree.h"
//#include "Graphs.h"
#include <queue>

using namespace std;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// DRIVER CODE
int main() {

	Linked_List<Car> CarList;
	Linked_List<Driver> DriverList;
	Linked_List<Passenger> PassengerList;

	Menu m;
	m.Intro_Display(CarList, DriverList, PassengerList);

	_getch();
	return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
