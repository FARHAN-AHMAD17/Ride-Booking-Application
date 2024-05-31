#pragma once
#include<iostream>
#include<iomanip>
#include<string>
//#include "Driver.h"
//#include "Passenger.h"

using namespace std;

// STACK NODE CLASS
template<class Type>
class NodeStack {
public:
	Type data;
	NodeStack<Type>* next;
	NodeStack() {
		next = NULL;
	}
};

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// LINKED LIST CLASS
template<class Type>
class Stack {
private:
	NodeStack<Type>* head;
public:
	Stack();
	NodeStack<Type>* GetNode();
	//void setHead(NodeStack<DataType>*);
	//NodeStack<DataType>* GetHead();
	bool IsEmpty();
	void push(Type);
	bool pop();
	bool peek();
	Type ShowSpecific(Type);
	bool dataValidity(Type);
	void Display();
};

// STACK CLASS FUNCTION DEFINITIONS
template<class Type>
Stack<Type>::Stack() {
	head = NULL;
}

template<class Type>
NodeStack<Type>* Stack<Type>::GetNode() { // CREATES A NODE
	NodeStack<Type>* Temp = new NodeStack<Type>;
	return Temp;
}

//template<class DataType>
//void Stack<DataType>::setHead(Node<DataType>* head) { // RETURNS HEAD POINTER
//	this->head = head;
//}
//
//template<class DataType>
//Node<DataType>* Stack<DataType>::GetHead() { // RETURNS HEAD POINTER
//	return head;
//}

template<class Type>
bool Stack<Type>::IsEmpty() {	// CHECKS IF LINKED LIST IS EMPTY
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template<class Type>
void Stack<Type>::push(Type x) {	// INSERTION IN THE BEGINNING
	NodeStack<Type>* n = GetNode();
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

template<class Type>
bool Stack<Type>::pop() { // REMOVAL FROM THE BEGINNING
	if (IsEmpty()) {
		return false;
	}
	else {
		NodeStack<Type>* ptr = head;
		head = ptr->next;
		ptr->next = NULL;
		delete ptr;
		return true;
	}
}

template<class Type>
bool Stack<Type>::peek() { // SHOW ALL DATA
	if (IsEmpty()) {
		return false;
	}
	else {
		NodeStack<Type>* ptr = head;
		while (ptr != NULL) {
			cout << ptr->data;
			ptr = ptr->next;
		}
		return true;
	}
}

template<class Type>
Type Stack<Type>::ShowSpecific(Type find) {	// SHOW SPECIFIC GIVEN NUMBER
	NodeStack<int>* temp = head;
	while (temp != NULL) {
		if (temp->data == find) {
			return temp->data;
		}
		temp = temp->next;
	}
	Type NotFound;
	return NotFound;
}

template<class Type>
bool Stack<Type>::dataValidity(Type find) {	// SHOW SPECIFIC GIVEN NUMBER
	NodeStack<Type>* temp = head;
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

template<class Type>
void Stack<Type>::Display() {	// PRINTING ALL NODES DATA
	NodeStack<Type>* ptr = head;
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



