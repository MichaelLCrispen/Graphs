#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"
#include "Queue.h"
#include <string>

class Graph
{
public:
	Graph(int numNodes, string labels, string verticies);
	~Graph();
	void AddEdge(int node1, int node2, int weight);
	void PrintNodes();
	void PrintEdges();
	void BFS(int rootNode);


private:
	LinkedList* AdjList;
	LinkedList Nodes;
	int numNodes;
};

#endif
