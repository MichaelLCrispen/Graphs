#include "Graph.h"
#include "LinkedList.h"
#include<iostream>


Graph::Graph(int tempnumNodes, string labels, string verticies){
	//  Narrative: This is the constructor for the graph class. This is the only way i allow to construct a graph
	//	Pre - condition :  The number of nodes, Labels for each node, And the verticies are defined
	//	Post - condition : The Graph will be constructed with the values entered

	numNodes = tempnumNodes;
	numVerticies = 0;

	size_t pos = 0;
	int i = 0;
	while ((pos = labels.find(',')) != string::npos) {
		string label = labels.substr(0, pos);
		//printf("Inserting : (%i , %s) \n", i, label.c_str());
		Nodes.Insert(i++,0, label, 1);
		labels.erase(0, pos + 1);
	}
	//printf("Inserting : (%i , %s) \n", i, labels.c_str());
	Nodes.Insert(i++, 0, labels, 1);


	AdjList = new LinkedList[numNodes];
	size_t found = verticies.find(")");
	while (verticies.length() > 0) {
		found = verticies.find(")");
		pos = 0;

		string temp = verticies.substr(0, found + 1);
		pos = temp.find(',');

		//printf("Temp = %s \n", temp.c_str());
		//printf("Node 1: %s", temp.substr(1, pos -1).c_str());
		int node1 = stoi(temp.substr(1, pos - 1));

		temp.erase(0, pos+1);
		pos = temp.find(',');
		//printf("Temp = %s \n", temp.c_str());
		//printf("  Node 2: %s", temp.substr(0, pos).c_str());
		int node2 = stoi(temp.substr(0, pos));
		
		
		temp.erase(0, pos + 1);
		pos = temp.find(')');
		//printf("  Weight: %s", temp.substr(0, pos).c_str());
		int weight = stoi(temp.substr(0, pos));
		//printf("\n \n");
		
		AddEdge(node1, node2, weight);
		//printf("NODE 1: %i , Node 2: %i, Weight : %i \n" , node1, node2, weight);

		verticies = verticies.substr(found + 1, verticies.length() - 1);
		numVerticies++;
	}

}


Graph::~Graph(){
	delete [] AdjList;
	AdjList = NULL;
}


void Graph::AddEdge(int node1, int node2,  int weight){
	//  Narrative: This will add an edge to the graph, This is a undirected approach
	//	Pre - condition : Node1 and Node2 are nodes in the graph
	//	Post - condition : A Edge will be added between node1 and node2 with weight of weight

	AdjList[node1].Insert(node2,node1, Nodes.FindLabel(node2), weight);
	AdjList[node2].Insert(node1,node2, Nodes.FindLabel(node1), weight);

	return;
}

void Graph::PrintNodes() {
	//  Narrative: This allows the user to print the nodes in the graph 
	//	Pre - condition : Class has been initialized
	//	Post - condition : Nodes in the class will be printed to the screen

	printf("Nodes :");
	Nodes.PrintListName();

	return;
}

void Graph::PrintEdges() {
	//  Narrative: This will print all of the edges between nodes
	//	Pre - condition : Class has been initialized
	//	Post - condition : Edges of the nodes will be printed to the screen

	for (int i = 0; i < numNodes; i++) {
		printf("Node %i Labeled '%s'  is connected to nodes : ", i, Nodes.FindLabel(i).c_str());
		AdjList[i].PrintList();
		printf("\n");
	}
	return;
}


void Graph::BFS(int rootNode) {
	//  Narrative: The breadth First Search for a graph traverses the tree starting at the tree root 
	//             (or some arbitrary node of a graph, sometimes referred to as a 'search key'[1]), 
	//             and explores all of the neighbor nodes at the present depth prior to moving on to 
	//             the nodes at the next depth level.  (Wikipedia)
	//	Pre - condition : Tree initalized
	//	Post - condition : Each Node is visited and printed to the screen

	bool * visited = new bool[numNodes];
	for (int i = 0; i < numNodes; i++)
		visited[i] = false;

	Queue queue;
	queue.enqueue(rootNode);

	visited[rootNode] = true;
	while (!queue.isEmpty()) {
		int v = queue.pop();
		printf("%i ", v);

		for (int i = 0; i < AdjList[v].Length() - 1; i++) {
			if (!visited[AdjList[v].ReturnCurrent()]){
				queue.enqueue(AdjList[v].ReturnCurrent());
				visited[AdjList[v].ReturnCurrent()] = true;
			}
			AdjList[v].CurrentNext();
		}
		AdjList[v].ResetCurrent();
	}
	delete[] visited;
	return;
}


void Graph::Prims(int x) {

	int V = numVerticies; // Get the number of vertices in graph 
	int* parent = new int[V]; // Array to store constructed MST 
	int* key = new int[V]; // Key values used to pick minimum weight edge in cut 

	//Could not get this funtion working. 

}
