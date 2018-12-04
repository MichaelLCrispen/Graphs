#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"
#include <string>

class Graph
{
public:
	Graph(int numNodes, string labels, string verticies,string weights);
	~Graph();
	void AddEdge();
	void PrintNodes();

private:
	LinkedList* AdjList;
	LinkedList Nodes;
	int numNodes;
};

#endif
