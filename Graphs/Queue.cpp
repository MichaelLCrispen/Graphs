#include "Queue.h"
#include <iostream>

Queue::Queue()
{
	arr = new int[100];
	capacity = 100;
	front = 0;
	rear = -1;
	count = 0;
}

// Utility function to remove front element from the queue
void Queue::dequeue()
{

	//std::cout << "Removing " << arr[front] << '\n';

	front = (front + 1) % capacity;
	count--;
}

int Queue::pop() {
	int temp = arr[front];
	dequeue();
	return temp;
}

// Utility function to add an item to the queue
void Queue::enqueue(int item)
{

	//std::cout << "Inserting " << item << '\n';

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

// Utility function to return front element in the queue
int Queue::peek()
{
	return arr[front];
}

// Utility function to return the size of the queue
int Queue::size()
{
	return count;
}

// Utility function to check if the queue is empty or not
bool Queue::isEmpty()
{
	return (size() == 0);
}

// Utility function to check if the queue is full or not
bool Queue::isFull()
{
	return (size() == capacity);
}