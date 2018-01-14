#include "BST.h"
#include <iostream>
#include <stack>
#include <exception>
#include <algorithm>

BST::BST() { root = nullptr; };

BST::~BST()
{
	Destructor(root);
};

void BST::Destructor(Node *node)
{
	if (node != nullptr)
	{
		Destructor(node->left);
		Destructor(node->right);

		try
		{
			delete node;
			node = nullptr;
		}
		catch(std::exception e)
		{
			std::cout << "Coudln't do try\n";
			std::cout << e.what()<<"\n";
		}
		
	}
};

Node*  BST::Search(int key)
{
	return Search(root, key);
};


Node * BST::Search(Node* node, int key)
{

	// Base Cases: root is null or key is present at root
	if (node == nullptr) { return node; };
	if (node->key == key) { return node; };

	// Key is greater than root's key
	if (node->key < key) { return Search(node->right, key); }

	// Key is smaller than root's key
	return Search(node->left, key);
};

void BST::Insert(int key)
{
	return Insert(&root, key);
};

void BST::Insert(Node** node, int key)
{
	if (*node == nullptr)
		*node = new Node(key);
	else
	{
		//key is smaller than key in current node
		if (key < (*node)->key)
			Insert(&((*node)->left), key);
		else
		{   //key is greater than key in current node
			if (key >(*node)->key)
				Insert(&((*node)->right), key);
			//key duplicate ignored

		}
	}
}



void BST::PreOrder()
{
	PreOrder(root);
}

void BST::InOrder()
{
	InOrder(root);
}

void BST::PostOrder()
{
	PostOrder(root);
}


void BST::PreOrder(Node *node)
{
	if (node != nullptr)
	{
		std::cout << node->key << " ";
		PreOrder(node->left);
		PreOrder(node->right);
	}
}

void BST::InOrder(Node *node)
{
	if (node != nullptr)
	{
		InOrder(node->left);
		std::cout << node->key << " ";
		InOrder(node->right);

	}
}

void BST::PostOrder(Node *node)
{
	if (node != nullptr)
	{

		PostOrder(node->left);
		PostOrder(node->right);
		std::cout << node->key << " ";

	}
}

bool BST::Exist(int key)
{

	return !(Search(key) == nullptr);

};

int BST::GetNumberNodes()
{
	return GetNumberNodes4(root);
}

int BST::GetNumberNodes(Node *node)
{
	if (node != nullptr)
	{
		GetNumberNodes(node->left);
		GetNumberNodes(node->right);

		numberNodes++;
	}

	return numberNodes;
}

int BST::GetNumberNodes2(Node *node)
{
	int count = 1;
	if (node->left != nullptr)
	{
		count += GetNumberNodes2(node->left);
	}
	if (node->right != nullptr)
	{
		count += GetNumberNodes2(node->right);
	}
	return count;
}

int BST::GetNumberNodes3(Node *node)//aquest no funciona
{
	if (!node->left && !node->right)//leaf
	{
		return 1;
	}
	if (node->left)
	{
		return GetNumberNodes3(node->left)+1;
	}
	if (node->right)
	{
		return GetNumberNodes3(node->right)+1;
	}
}

int BST::GetNumberNodes4(Node *node)//MILLOR OPCIÓ
{
	if (!node) return 0;
	else return 1 + GetNumberNodes4(node->left) + GetNumberNodes4(node->right);
}

int BST::GetNumberNodesI()
{
	return GetNumberNodesI(root);
}

int BST::GetNumberNodesI(Node *node)//implementació no recursiva
{
	std::stack<Node*> myStack;//STACK on tenim els pendents de lectura
	myStack.push(node);
	int count = 0;
	Node* aux;
	while (!myStack.empty())
	{
		aux = myStack.top();
		myStack.pop();
		if (aux)
		{
			count++;
			if(aux->left)
				myStack.push(aux->left);
			if(aux->right)
				myStack.push(aux->right);
		}
	}
	return count;
}

void BST::PreOrderI()
{
	PreOrderI(root);
}

void BST::PreOrderI(Node *node)
{
	std::stack<Node*> m_stack;
	m_stack.push(node);
	Node* aux;

	while (!m_stack.empty())
	{
		aux = m_stack.top();
		std::cout << m_stack.top()->key << " ";
		m_stack.pop();
		if (aux)
		{
			if (aux->right)
				m_stack.push(aux->right);
			if (aux->left)
				m_stack.push(aux->left);	
		}
	}
}

int BST::Height()
{
	return Height(root);
}

int BST::Height(Node* node)
{
	if (!node)
		return 0;
	else
	{
		return 1 + std::max(Height(node->left), Height(node->right));
		//return 1 + (Height(node->left) < Height(node->right) ? Height(node->left): Height(node->right));
		/*if (Height(node->left) < Height(node->right))
		{
			return 1 + Height(node->left);
		}
		else
		{
			return 1 + Height(node->right);
		}*/
	}	
}



