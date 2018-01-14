#pragma once
#include "Node.h"

class BST
{
public:
	BST();
	~BST();
	Node* Search(int key);
	void Insert(int key);
	void PreOrder();
	void InOrder();
	void PostOrder();
	bool Exist(int key);
	int GetNumberNodes();
	int GetNumberNodesI();
	void PreOrderI();
	int Height();

private:
	Node * root;
	int numberNodes;
	Node* Search(Node* node, int key);
	void Insert(Node** node, int key);
	void PreOrder(Node *node);
	void InOrder(Node *node);
	void PostOrder(Node *node);
	void Destructor(Node *node);
	int GetNumberNodes(Node *node);
	int GetNumberNodes2(Node *node);
	int GetNumberNodes3(Node *node);//no funciona
	int GetNumberNodes4(Node *node);//MILLOR OPCIÓ
	int GetNumberNodesI(Node *node);
	void PreOrderI(Node *node);
	int Height(Node* node);

};

