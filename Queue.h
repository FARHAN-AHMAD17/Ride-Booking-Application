#pragma once
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string>
//#include "Driver.h"
//#include "Passenger.h"

using namespace std;

// QUEUE NODE CLASS
template<class DataType>
class NodeQueue {
public:
	DataType data;
	NodeQueue<DataType>* next;
	NodeQueue() {
		next = NULL;
	}
};

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// QUEUE CLASS
template<class DataType>
class Queue {
private:
	NodeQueue<DataType>* head;
public:
	Queue();
	NodeQueue<DataType>* GetNode();
	void setHead(NodeQueue<DataType>*);
	NodeQueue<DataType>* getHead();
	DataType freeNode(NodeQueue<DataType>*);
	bool IsEmpty();
	void InsertRear(DataType);
	bool RemoveFront();
	bool RemoveAll();
	bool CheckFront();
	DataType ShowSpecific(DataType);
	void Display();
};

// QUEUE CLASS FUNCTION DEFINITIONS
template<class DataType>
Queue<DataType>::Queue() {
	head = NULL;
}

template<class DataType>
NodeQueue<DataType>* Queue<DataType>::GetNode() { // CREATES A NODE
	NodeQueue<DataType>* Temp = new NodeQueue<DataType>;
	return Temp;
}

template<class DataType>
void Queue<DataType>::setHead(NodeQueue<DataType>* head) { // RETURNS HEAD POINTER
	this->head = head;
}

template<class DataType>
NodeQueue<DataType>* Queue<DataType>::getHead() { // RETURNS HEAD POINTER
	return head;
}

template<class DataType>
DataType Queue<DataType>::freeNode(NodeQueue<DataType>* p) { // DELETES AN NODE
	DataType x = p->data;
	delete p;
	return x;
}

template<class DataType>
bool Queue<DataType>::IsEmpty() {	// CHECKS IF QUEUE IS EMPTY
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template<class DataType>
void Queue<DataType>::InsertRear(DataType x) {	// INSERTION AT THE END
	NodeQueue<DataType>* n = GetNode();
	n->data = x;
	n->next = NULL;
	if (head == NULL) {
		head = n;
	}
	else {
		NodeQueue<DataType>* ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = n;
	}
}

template<class DataType>
bool Queue<DataType>::RemoveFront() { // REMOVAL FROM THE BEGINNING
	if (IsEmpty()) {
		return false;
	}
	else {
		NodeQueue<DataType>* ptr = head;
		head = ptr->next;
		ptr->next = NULL;
		delete ptr;
		return true;
	}
}

template<class DataType>
bool Queue<DataType>::RemoveAll() { // REMOVAL ALL FROM THE BEGINNING
	if (IsEmpty()) {
		return false;
	}
	else {
		NodeQueue<DataType>* ptr = head;
		while (ptr != NULL) {
			delete ptr;
			ptr = ptr->next;
		}
		head = NULL;
		return true;
	}
}

template<class DataType>
bool Queue<DataType>::CheckFront() { // CHECK FRONT
	if (IsEmpty()) {
		return false;
	}
	else {
		NodeQueue<DataType>* ptr = head;
		while (ptr != NULL) {
			cout << ptr->data;
			ptr = ptr->next;
		}
		return true;
	}
}

template<class DataType>
DataType Queue<DataType>::ShowSpecific(DataType find) {	// SHOW SPECIFIC GIVEN NUMBER
	Node<DataType>* temp = head;
	while (temp != NULL) {
		if (temp->data == find) {
			return temp->data;
		}
		temp = temp->next;
	}
	DataType NotFound;
	return NotFound;
}

template<class DataType>
void Queue<DataType>::Display() {	// PRINTING ALL NODES DATA
	NodeQueue<DataType>* ptr = head;
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

