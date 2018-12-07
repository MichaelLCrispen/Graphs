#include <string>
#ifndef LLNODE_H
#define LLNODE_H


struct LLNode;
typedef LLNode* NodePtr;

struct LLNode {
	int key;
	std::string name;
	int weight;
	NodePtr next;
	int dest;
};

#endif