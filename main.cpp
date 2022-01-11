#include "DoublyLinkedList.hpp"

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

	List.searchNode(70); //prints memory location address of node with value = 70; value not in the list
	List.searchNode(10); 

	List.deleteAllNodes(); 

	List.displayList(); //none

	return 0;
}