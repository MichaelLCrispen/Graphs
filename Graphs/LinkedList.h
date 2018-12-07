/*	The class that I am using here is slightly modified from 
	a version that we made earlier in the semester. As such I
	found it unnecessary to retest these methods.			  */

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
	int Length();

	void ResetCurrent();
	int  ReturnCurrent();
	void CurrentNext();

private:
	struct LLNode {
		int key;
		string name;
		int weight;
		NodePtr next;
	};

	NodePtr head;
	int length;
	NodePtr currentNode;
};

#endif
