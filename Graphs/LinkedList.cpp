#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
	length = 0;
	head = nullptr;
}


LinkedList::~LinkedList() {
	NodePtr temp;
	NodePtr curr = head;
	while (curr != nullptr) {
		temp = curr;
		curr = curr->next;
		delete temp;
	}
	head = nullptr;
	length = 0;
	return;
}



LinkedList::LinkedList(const LinkedList& otherLinkedList) {
	NodePtr from;
	NodePtr to;
	length = otherLinkedList.length;

	if (otherLinkedList.head == nullptr)
		head = nullptr;

	else {
		from = otherLinkedList.head;
		head = new LLNode;
		head->key = from->key;
		head->name = from->name;
		head->weight = from->weight;

		to = head;
		from = from->next;

		while (from != nullptr) {
			to->next = new LLNode;
			to = to->next;
			to->key = from->key;
			to->name = from->name;
			to->weight = from->weight;

			from = from->next;
		}

		to->next = nullptr;
	}

	return;
}

const LinkedList& LinkedList::operator=(const LinkedList& otherLinkedList) {
	NodePtr from;
	NodePtr to;
	length = otherLinkedList.length;

	if (otherLinkedList.head == nullptr)
		head = nullptr;

	else {
		from = otherLinkedList.head;
		head = new LLNode;
		head->key = from->key;
		head->name = from->name;
		head->weight = from->weight;

		to = head;
		from = from->next;

		while (from != nullptr) {
			to->next = new LLNode;
			to = to->next;
			to->key = from->key;
			to->name = from->name;
			to->weight = from->weight;

			from = from->next;
		}

		to->next = nullptr;
	}

	return *this;

}

void LinkedList::Insert(int data, string name, int weight) {
	//Narrative: Inserts a node into the linked list at the head
	//	Pre - condition : data has a value and list initialized
	//	Post - condition : a node with key = data inserted into list, length updated

	NodePtr temp = new LLNode;
	temp->key = data;
	temp->name = name;
	temp->weight = weight;
	temp->next = nullptr;
	//printf("Inserting %i, %s", temp->key, temp->name.c_str());
	length++;

	if (!head) {
		head = temp;
		return;
	}

	temp->next = head;
	head = temp;
	return;

}


bool LinkedList::SearchKey(int key) {
	//Narrative: Searches for a node with value of key
	//	Pre - condition : list initialized
	//	Post - condition : returns true if key found in list else return false

	NodePtr currPtr = head;
	int numCompares = 0;


	while (currPtr != nullptr && currPtr->key != key) {
		currPtr = currPtr->next;
	}

	return (currPtr);
}

bool LinkedList::SearchName(string name) {
	//Narrative: Searches for a node with value of key
	//	Pre - condition : list initialized
	//	Post - condition : returns true if key found in list else return false

	NodePtr currPtr = head;
	int numCompares = 0;


	while (currPtr != nullptr && currPtr->name != name) {
		currPtr = currPtr->next;
	}

	return (currPtr);
}

void LinkedList::PrintList() {
	//Narrative: Prints the contents of the list
	//	Pre - condition : list initialized
	//	Post - condition : values of each node printed to screen

	NodePtr currPtr = head;

	while (currPtr != nullptr) {

		std::printf("%i ", currPtr->key);
		currPtr = currPtr->next;

	}

	return;
}

void LinkedList::PrintListName() {
	//Narrative: Prints the contents of the list
	//	Pre - condition : list initialized
	//	Post - condition : values of each node printed to screen

	NodePtr currPtr = head;

	while (currPtr != nullptr) {

		std::printf("%s ", currPtr->name.c_str());
		currPtr = currPtr->next;

	}

	return;
}


string LinkedList::FindLabel(int nodeID) {

	NodePtr currPtr = head;

	while (currPtr != nullptr) {
		if (currPtr->key == nodeID)
			return currPtr->name;


		currPtr = currPtr->next;

	}

	return "NOTFOUND";
}