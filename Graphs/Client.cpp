
#include <iostream>
#include <cstdio>
#include <string>
#include "Graph.h"

using namespace std;

int main() {
	int numnodes = 0;
	string labels = "";
	string edges = "";

	printf("How many nodes will be in the graph :");
	cin >> numnodes;
	cin.ignore();
	printf("Please enter the labels for each node seperated by commas : ");
	getline(cin, labels);
	printf("Please enter edges (These must be in the form %s : " , "'(0,1)(10,12)'");
	getline(cin, edges);

	size_t found = edges.find(")");
	while (edges.length() > 0) {
		found = edges.find(")");
		string temp = edges.substr(0, found+1);
		printf("%s \n", temp.c_str());

		edges = edges.substr(found+1, edges.length() - 1);
	}

	Graph graph(numnodes, labels, edges);
	printf("\n");
	graph.PrintNodes();
	
	//Pause before Program Exits
	system("pause");
	return 0;
}