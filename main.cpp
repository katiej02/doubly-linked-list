#include <iostream>
#include "DoublyLinkedList.hpp"
#include "gtest/gtest.h"

using namespace std;

int main()
{
	DoublyLinkedList List; //start out as empty list
	List.addNodeAtEnd(10);
	List.addNodeAtEnd(20);
	List.addNodeAtEnd(30);
	List.addNodeAtEnd(40);
	List.addNodeAtEnd(50);
	List.addNodeAtEnd(60);

	List.displayList(); //10 20 30 40 50 60
	List.deleteNode(40);
	List.displayList(); //10 20 30 50 60

	Node *searchedNode{nullptr};
	searchedNode = List.searchNode(70); 
	cout << "search node result: " << searchedNode << endl; 
	searchedNode = List.searchNode(50);
	cout << "search node result: " << searchedNode << endl;

	List.displayList(); //10 20 30 50 60
	List.addNodeAtEnd(100);
	List.displayList(); //10 20 30 50 60 100
	List.deleteNode(150); //deleting node that does not exist
	List.displayList(); //10 20 30 50 60 100
	List.deleteNode(10); 
	List.displayList(); //20 30 50 60 100
	List.deleteNode(50);
	List.displayList(); //20 30 60 100

	return 0;
}