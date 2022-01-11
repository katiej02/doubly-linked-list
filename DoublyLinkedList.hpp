#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

class DoublyLinkedList
{
	private:
		//node structure
		struct Node
		{
			int data;
			struct Node *next;
			struct Node *prev;
		};

		Node *head;
		Node *tail;

	public:
		//initialize empty linked list
		DoublyLinkedList();

		//doubly linked list operations - add, delete, search, display
		void addNodeAtEnd(int data);
		void deleteNode(int data);
		void deleteAllNodes();
		void searchNode(int data);
		void displayList();

		~DoublyLinkedList();
};

#endif 