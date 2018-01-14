#pragma once
class Node
{
public:
	Node() :key(-1), left(nullptr), right(nullptr) {};
	Node(int akey) :key(akey), left(nullptr), right(nullptr) {};
	int key;
	Node *left;
	Node *right;
};

