#include "Graph.h"



Graph::Graph(int tempnumNodes, string labels, string verticies){
	numNodes = tempnumNodes;

	size_t pos = 0;
	int i = 0;
	while ((pos = labels.find(',')) != string::npos) {
		string label = labels.substr(0, pos);
		//printf("Inserting : (%i , %s) \n", i, label.c_str());
		Nodes.Insert(i++, label, 1);
		labels.erase(0, pos + 1);
	}
	//printf("Inserting : (%i , %s) \n", i, labels.c_str());
	Nodes.Insert(i++, labels, 1);


	AdjList = new LinkedList[numNodes];
	size_t found = verticies.find(")");
	while (verticies.length() > 0) {
		found = verticies.find(")");
		pos = 0;

		string temp = verticies.substr(0, found + 1);
		pos = temp.find(',');

		printf("Temp = %s \n", temp.c_str());
		printf("Node 1: %s", temp.substr(1, pos -1).c_str());
		int node1 = stoi(temp.substr(1, pos - 1));

		temp.erase(0, pos+1);
		pos = temp.find(',');
		//printf("Temp = %s \n", temp.c_str());
		printf("  Node 2: %s", temp.substr(0, pos).c_str());
		int node2 = stoi(temp.substr(0, pos));
		
		
		temp.erase(0, pos + 1);
		pos = temp.find(')');
		printf("  Weight: %s", temp.substr(0, pos).c_str());
		int weight = stoi(temp.substr(0, pos));
		printf("\n \n");
		

		//printf("NODE 1: %i , Node 2: %i, Weight : %i \n" , node1, node2, weight);

		verticies = verticies.substr(found + 1, verticies.length() - 1);
	}

}


Graph::~Graph(){
}


void Graph::AddEdge(int node1, int node2, int weight){
	AdjList[node1].Insert(node2, Nodes.FindLabel(node2), weight);
	AdjList[node2].Insert(node1, Nodes.FindLabel(node1), weight);

	return;
}

void Graph::PrintNodes() {
	printf("Nodes :");
	Nodes.PrintListName();

	return;
}
