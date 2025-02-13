// Singly Linked List & Recursion Implementation

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int value) {
		data = value;
		next = nullptr;
	}
};

class SinglyLinkedList {
private:
	Node* head;
	Node* tail;
	int count;

	//Helper function to print list in reverse using recursion
	void reversePrintHelper(Node* node) {
		if (node == nullptr) {
			cout << "nullptr";
			return;
		}
		reversePrintHelper(node->next);
		cout << " <- " << node->data;
	}

public:
	SinglyLinkedList() {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}

	//Inserting at the end
	void insertAtEnd(int data) {
		Node* newNode = new Node(data);
		if (!head) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		count++;
	}
	

	//Displaying the linked list
	void display() {
		cout << "Original list:\nHead -> ";
		Node* temp = head;
		while (temp) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "nullptr" << endl;
	}

	//Function to initiate reverse print
	void reversePrint() {
		cout << "Reverse list:" << endl;
		reversePrintHelper(head);
		cout << " <- Head" << endl;
	}
};


//Main Program for testing
int main() {
	SinglyLinkedList list;
	
	for (int i = 5; i <= 50; i += 5) {
		list.insertAtEnd(i);
	}

	list.display();

	//Display in reverse
	list.reversePrint();


	return 0;
}
