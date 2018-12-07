/* DISCLAIMER: This is a modified class that I am using. Most of which I
	have found at the website listed below. It is my understanding that 
	The point of this exercise is based around graphs and as such I found
	it would be acceptible to use a generic queue class for this assignment
	I DID MODIFY THIS TO FIT THE NEEDS OF THE ASSIGNMENT.
   https://www.techiedelight.com/queue-implementation-cpp/              */


#pragma once
#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
public:
	Queue();		// constructor

	void dequeue();
	void enqueue(int x);
	int pop();
	int peek();
	int size();
	bool isEmpty();
	bool isFull();


private:
	int *arr;   	// array to store queue elements
	int capacity;   // maximum capacity of the queue
	int front;  	// front points to front element in the queue (if any)
	int rear;   	// rear points to last element in the queue
	int count;  	// current size of the queue
};

#endif
