#include <iostream>
#include "BST.h"

int main()
{
	//1
	BST myBST;

	//2
	myBST.Insert(8);
	myBST.Insert(3);
	myBST.Insert(1);
	myBST.Insert(6);
	myBST.Insert(4);
	myBST.Insert(7);
	myBST.Insert(10);
	myBST.Insert(14);
	myBST.Insert(13);
	
	/*myBST.Insert(50);
	myBST.Insert(25);
	myBST.Insert(75);
	myBST.Insert(12);
	myBST.Insert(33);
	myBST.Insert(67);
	myBST.Insert(88);
	myBST.Insert(6);
	myBST.Insert(13);
	myBST.Insert(68);*/

	//3
	std::cout << "PostOrder: " << std::endl;
	myBST.PostOrder();
	std::cout << std::endl;

	//4
	std::cout << "InOrder: " << std::endl;
	myBST.InOrder();
	std::cout << std::endl;

	//5
	std::cout << "PreOrder: " << std::endl;
	myBST.PreOrder();

	std::cout << std::endl;
	//destructor:
	//std::cout << "Destructor:\n";
	//delete &myBST;

	//Get Number Nodes:
	std::cout << "Number of nodes: "<<myBST.GetNumberNodes() << std::endl;

	//Get Number Nodes:
	std::cout << "[NON-RECURSIVE] Number of nodes: " << myBST.GetNumberNodesI() << std::endl;

	//PreOrderI
	std::cout << "PreOrderI:\n";
	myBST.PreOrderI();
	std::cout << std::endl;

	//Height
	std::cout << "Height:\n";
	std::cout<<myBST.Height();
	std::cout << std::endl;

	//prova:
	//std::cout << myBST.Search(13)->key << std::endl;

	

	system("pause");
	return 0;
}