#include <iostream>
#include <cstdio>
#include <string>
#include "Graph.h"

using namespace std;

int main() {
	int numnodes = 0;
	string labels = "";
	string edges = "";

	/*Loading Values For the Graph*/
	printf("Would you like to use default values? (y/n) :");
	char temp;
	cin >> temp;
	if (temp == 'y') {
		numnodes = 9;
		labels = "A,B,C,D,E,F,G,H,I";
		edges = "(0,1,4)(0,7,8)(1,2,8)(1,7,11)(2,3,7)(2,5,4)(2,8,2)(3,4,9)(3,5,14)(4,5,10)(5,6,2)(6,7,1)(6,8,6)(7,8,7)";
	}


	else {
		printf("How many nodes will be in the graph :");
		cin >> numnodes;
		cin.ignore();
		printf("Please enter the labels for each node seperated by commas : ");
		getline(cin, labels);
		printf("Please enter edges (These must be in the form %s : ", "'(Node1,Node2,Weight)'");
		getline(cin, edges);
	}


	Graph graph(numnodes, labels, edges);

	printf("Printing List of Nodes and Edges: \n");
	graph.PrintNodes();
	printf("\n\n");
	graph.PrintEdges();
	printf("\n\n");


	printf("BFS using node 4 as root \n");
	graph.BFS(4);
	printf("\n\n");

	printf("Prims Algorithm : \n\n");
	graph.Prims(0);
	printf("\n\n");

	//printf("\n");
	//graph.PrintNodes();

	//Pause before Program Exits
	system("pause");
	return 0;
}
