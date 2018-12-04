#pragma once
#include "LinkedList.h"
#include <string>

class Graph
{
public:
	Graph(int numNodes, string labels, string verticies);
	~Graph();
	void AddEdge();
	void PrintNodes();

private:
	LinkedList* AdjList;
	LinkedList Nodes;
	int numNodes;
};

