#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;
#include <string>

class LinkedList
{

private:
	struct LLNode;
	typedef LLNode* NodePtr;

public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& otherlinkedlist);
	const LinkedList& operator=(const LinkedList& otherLinkedList);

	void Insert(int data, string name, int weight);
	bool SearchKey(int key);
	bool SearchName(string name);
	void PrintList();
	void PrintListName();
	string FindLabel(int nodeID);

private:
	struct LLNode {
		int key;
		string name;
		int weight;
		NodePtr next;
	};

	NodePtr head;
	int length;
};

#endif
