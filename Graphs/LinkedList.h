/*	The class that I am using here is slightly modified from 
	a version that we made earlier in the semester. As such I
	found it unnecessary to retest these methods.			  */

#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;
#include <string>
#include "LLnode.h"

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& otherlinkedlist);
	const LinkedList& operator=(const LinkedList& otherLinkedList);

	void Insert(int data, int dest, string name, int weight);
	bool SearchKey(int key);
	bool SearchName(string name);
	void PrintList();
	void PrintListName();
	string FindLabel(int nodeID);
	int Length();

	void ResetCurrent();
	int  ReturnCurrent();
	void CurrentNext();
	NodePtr ReturnHead();

private:
	NodePtr head;
	int length;
	NodePtr currentNode;
};

#endif
