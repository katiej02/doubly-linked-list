#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

//node structure
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

class DoublyLinkedList
{
public:
	Node *head;
	Node *tail;
	
	//initialize empty linked list
	DoublyLinkedList();

	//doubly linked list operations - add, delete, search, display
	void addNodeAtEnd(int data);
	void deleteNode(int data);
	void deleteAllNodes();
	Node *searchNode(int data);
	void displayList();

	~DoublyLinkedList();
};

#endif