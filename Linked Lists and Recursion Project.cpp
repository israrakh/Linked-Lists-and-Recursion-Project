// Singly Linked List Implementation

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

public:
	SinglyLinkedList() {
		head = nullptr;
	}

	// Inserting at the beginning:
	void insertAtBeginning(int data) {
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
	}

	//Inserting at the end
	void insertAtEnd(int data) {
		Node* newNode = new Node(data);
		if (!head) {
			head = newNode;
			return;
		}

		Node* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	
	//Deleting the first node
	void deleteFirst() {
		if (!head) {
			cout << "List is empty!" << endl;
			return;
		}

		Node* temp = head;
		head = head->next;
		delete temp;
	}

	//Deleting the last node
	void deleteLast() {
		if (!head) {
			cout << "List is empty!" << endl;
			return;
		}
		if (!head->next) {
			delete head;
			head = nullptr;
			return;
		}

		Node* temp = head;
		while (temp->next->next) {
			temp = temp->next;
		}
		delete temp->next;
		temp->next = nullptr;
	}

	//Deleting a specific node by value
	void deleteValue(int value) {
		if (!head) {
			cout << "List is empty!" << endl;
			return;
		}
		if (head->data == value) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		
		Node* temp = head;
		while (temp->next && temp->next->data != value) {
			temp = temp->next;
		}
		if (temp->next) {
			Node* nodeToBeDelete = temp->next;
			temp->next = temp->next->next;
			delete nodeToBeDelete;
		}
	}

	//Displaying the linked list
	void display() {
		Node* temp = head;
		while (temp) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "nullptr" << endl;
	}
};

//Main Program for testing
int main() {
	SinglyLinkedList sList;

	cout << "Build a forward list" << endl;
	sList.insertAtBeginning(50);
	sList.insertAtBeginning(40);
	sList.insertAtBeginning(30);
	sList.insertAtBeginning(20);
	sList.insertAtBeginning(10);
	sList.display();

	cout << "\nDelete the first node" << endl;
	sList.deleteFirst();
	sList.display();

	cout << "\nDelete the last node" << endl;
	sList.deleteLast();
	sList.display();

	cout << "\nDelete the middle node (30)" << endl;
	sList.deleteValue(30);
	sList.display();

	cout << "\nBuild a backward list" << endl;
	SinglyLinkedList sListBackward;
	sListBackward.insertAtBeginning(10);
	sListBackward.insertAtBeginning(20);
	sListBackward.insertAtBeginning(30);
	sListBackward.insertAtBeginning(40);
	sListBackward.insertAtBeginning(50);
	sListBackward.display();

	cout << "\nDelete the first node" << endl;
	sListBackward.deleteFirst();
	sListBackward.display();

	cout << "\nDelete the last node" << endl;
	sListBackward.deleteLast();
	sListBackward.display();

	cout << "\nDelete the middle node" << endl;
	sListBackward.deleteValue(30);
	sListBackward.display();


	return 0;
}