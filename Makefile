CC=g++

linked_list: main.cpp DoublyLinkedList.cpp
	$(CC) -g -o linked_list main.cpp DoublyLinkedList.cpp
