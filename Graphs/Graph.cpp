#include "Graph.h"



Graph::Graph(int tempnumNodes, string labels, string verticies,string weights){
	numNodes = tempnumNodes;

	size_t pos = 0;
	int i = 0;
	while ((pos = labels.find(',')) != string::npos) {
		string label = labels.substr(0, pos);
		printf("Inserting : (%i , %s) \n", i, label.c_str());
		Nodes.Insert(i++, label, 1);
		labels.erase(0, pos + 1);
	}
	printf("Inserting : (%i , %s) \n", i, labels.c_str());
	Nodes.Insert(i++, labels, 1);


	AdjList = new LinkedList[numNodes];

	pos = 0;
	i = 0;
	while ((pos = labels.find(',')) != string::npos) {
		string label = labels.substr(0, pos);
		printf("Inserting : (%i , %s) \n", i, label.c_str());
		Nodes.Insert(i++, label, 1);
		labels.erase(0, pos + 1);
	}
	printf("Inserting : (%i , %s) \n", i, labels.c_str());
	Nodes.Insert(i++, labels, 1);

}


Graph::~Graph(){
}


void Graph::AddEdge(){
	// TODO: Add your implementation code here.
}

void Graph::PrintNodes() {
	printf("Nodes :");
	Nodes.PrintListName();

	return;
}
