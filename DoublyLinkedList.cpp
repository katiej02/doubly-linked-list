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

	//linked list not existing yet - first ever node
	if (head == NULL)
	{
		newNode->prev = NULL;
		head = newNode;
	}
	else
	{ //append new node to last existing node (tail)
		tail->next = newNode;
		newNode->prev = tail;
	}

	tail = newNode;
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
		delete (temp);
	}

	cout << "All nodes are deleted successfully.\n";
}

Node *DoublyLinkedList::searchNode(int data)
{
	Node *currNode = head;

	if (currNode == NULL)
	{
		cout << "Empty list" << endl;
	}
	else
	{
		Node *prevNode = NULL;

		while (currNode != NULL && currNode->data != data)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}

		if (currNode == NULL)
			cout << "Data not found in the list!" << endl;
	}

	return currNode;
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

DoublyLinkedList::~DoublyLinkedList()
{
	deleteAllNodes();
}