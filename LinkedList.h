#pragma once
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string>
//#include "Driver.h"
//#include "Passenger.h"

using namespace std;

// LINKED LIST NODE CLASS
template<class DataType>
class Node {
public:
	DataType data;
	Node<DataType>* next;
	Node() {
		next = NULL;
	}
};

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// LINKED LIST CLASS
template<class DataType>
class Linked_List {
private:
	Node<DataType>* head;
public:
	Linked_List();
	Node<DataType>* GetNode();
	void SetHead(Node<DataType>*);
	Node<DataType>* GetHead();
	DataType FreeNode(Node<DataType>*);
	bool IsEmpty();
	void InsertBeg(DataType);
	void InsertAfter(DataType, DataType);
	void InsertEnd(DataType);
	bool RemoveBeg();
	bool RemoveAfter(DataType);
	bool RemoveSpecific(DataType);
	bool RemoveEnd();
	DataType ShowSpecific(DataType);
	bool dataValidity(DataType);
	void Display();
};

// LINKED LIST CLASS FUNCTION DEFINITIONS
template<class DataType>
Linked_List<DataType>::Linked_List() {
	head = NULL;
}

template<class DataType>
Node<DataType>* Linked_List<DataType>::GetNode() { // CREATES A NODE
	Node<DataType>* Temp = new Node<DataType>;
	return Temp;
}

template<class DataType>
void Linked_List<DataType>::SetHead(Node<DataType>* head) { // RETURNS HEAD POINTER
	this->head = head;
}

template<class DataType>
Node<DataType>* Linked_List<DataType>::GetHead() { // RETURNS HEAD POINTER
	return head;
}

template<class DataType>
DataType Linked_List<DataType>::FreeNode(Node<DataType>* p) { // DELETES AN NODE
	DataType x = p->data;
	delete p;
	return x;
}

template<class DataType>
bool Linked_List<DataType>::IsEmpty() {	// CHECKS IF LINKED LIST IS EMPTY
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template<class DataType>
void Linked_List<DataType>::InsertBeg(DataType x) {	// INSERTION IN THE BEGINNING
	Node<DataType>* n = GetNode();
	n->data = x;
	if (head == NULL) {
		n->next = NULL;
		head = n;
	}
	else {
		n->next = head;
		head = n;
	}
}

template<class DataType>
void Linked_List<DataType>::InsertAfter(DataType x, DataType find) {	// INSERTION AFTER A NUMBER
	Node<DataType>* n = GetNode();
	n->data = x;
	Node<DataType>* ptr1 = head;
	Node<DataType>* ptr2 = NULL;
	while (ptr1->data != find) {
		ptr1 = ptr1->next;
	}
	ptr2 = ptr1->next;
	ptr1->next = n;
	n->next = ptr2;
}

template<class DataType>
void Linked_List<DataType>::InsertEnd(DataType x) {	// INSERTION AT THE END
	Node<DataType>* n = GetNode();
	n->data = x;
	n->next = NULL;
	if (head == NULL) {
		head = n;
	}
	else {
		Node<DataType>* ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = n;
	}
}

template<class DataType>
bool Linked_List<DataType>::RemoveBeg() { // REMOVAL FROM THE BEGINNING
	if (IsEmpty()) {
		return false;
	}
	else {
		Node<DataType>* ptr = head;
		head = ptr->next;
		ptr->next = NULL;
		delete ptr;
		return true;
	}
}

template<class DataType>
bool Linked_List<DataType>::RemoveAfter(DataType find) {	// REMOVAL AFTER A NUMBER
	if (IsEmpty()) {
		return false;
	}
	else {
		Node<DataType>* ptr1 = head;
		Node<DataType>* ptr2 = NULL;
		while (!(ptr1->data == find)) {
			ptr1 = ptr1->next;
		}
		ptr2 = ptr1->next;
		ptr1->next = ptr2->next;
		ptr2->next = NULL;
		delete ptr2;
		return true;
	}
}

template<class DataType>
bool Linked_List<DataType>::RemoveSpecific(DataType find) {	// REMOVAL ON SPECIFIC GIVEN NUMBER
	if (IsEmpty()) {
		return false;
	}
	else {
		Node<DataType>* ptr1 = head;
		Node<DataType>* ptr2 = NULL;
		while (!(ptr1->data == find)) {
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		}
		ptr2->next = ptr1->next;
		ptr1->next = NULL;
		delete ptr1;
		return true;
	}
}

template<class DataType>
bool Linked_List<DataType>::RemoveEnd() {	// REMOVAL AT THE END
	if (IsEmpty()) {
		return false;
	}
	else {
		Node<DataType>* ptr1 = head;
		Node<DataType>* ptr2 = NULL;
		while (ptr1->next != NULL) {
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		}
		ptr2->next = NULL;
		delete ptr1;
		return true;
	}
}


template<class DataType>
DataType Linked_List<DataType>::ShowSpecific(DataType find) {	// SHOW SPECIFIC GIVEN NUMBER
	Node<int>* temp = head;
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
bool Linked_List<DataType>::dataValidity(DataType find) {	// SHOW SPECIFIC GIVEN NUMBER
	Node<DataType>* temp = head;
	if (temp == NULL) {
		return true;
	}
	else {
		while (temp != NULL) {
			if (temp->data == find) {
				return false;
			}
			temp = temp->next;
		}
	}
	return true;
}

template<class DataType>
void Linked_List<DataType>::Display() {	// PRINTING ALL NODES DATA
	Node<DataType>* ptr = head;
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


