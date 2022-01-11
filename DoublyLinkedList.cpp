#include <iostream>
#include "DoublyLinkedList.hpp"

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
	head = NULL;
}

void DoublyLinkedList::addNodeAtEnd(int data)
{
	Node *newNode = new Node; 
	newNode->data = data;	  
	newNode->next = NULL;	  

	Node *temp = head;

	//no existing list
	if (head == NULL)
	{
		newNode->prev = NULL;
		head = newNode;
		return;
	}

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = newNode;

	newNode->prev = temp;
}

void DoublyLinkedList::deleteNode(int data)
{
	//linked list exists
	if (head != NULL)
	{
		Node *currNode = head;
		//first node in the list contains the given data
		if (head->data == data)
		{
			head = head->next;
			delete currNode;
		}
		else
		{
			Node *prevNode = NULL;
			while (currNode != NULL && currNode->data != data)
			{
				prevNode = currNode;
				currNode = currNode->next;
			}

			//check if data was found from the list
			if (currNode != NULL)
				prevNode->next = currNode->next;
			delete currNode;
		}
	}
}

void DoublyLinkedList::deleteAllNodes()
{
	while (head != NULL)
	{
		Node *temp = head;
		head = head->next;
		delete(temp);
	}

	cout << "All nodes are deleted successfully.\n";
}

void DoublyLinkedList::searchNode(int data)
{
	Node *currNode = head;

	if (currNode == NULL)
		cout << "Empty list" << endl;
	else
	{
		while (currNode != NULL)
		{
			if (currNode->data == data)
			{
				cout << "Found data at location: " << currNode << endl;
			}
			else
			{
				Node *prevNode = NULL;

				while (currNode != NULL && currNode->data != data)
				{
					prevNode = currNode;
					currNode = currNode->next;
				}

				//check if node containing data is in the list
				if (currNode != NULL)
				{
					prevNode->next = currNode->next;
					cout << "Found data at location: " << currNode << endl;
				}
				else
				{
					cout << "Data not found in the list!" << endl;
				}
			}

			break;
		}
	}
}

void DoublyLinkedList::displayList()
{
	Node *currNode = head;
	while (currNode != NULL)
	{
		cout << currNode->data << " ";
		currNode = currNode->next;
	}

	cout << endl;
}

DoublyLinkedList::~DoublyLinkedList(){
	deleteAllNodes();
}