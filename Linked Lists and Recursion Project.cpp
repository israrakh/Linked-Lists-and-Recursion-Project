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
protected:
	Node* head;
	Node* tail;
	int count;

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
	
	//Deleting the first node
	void deleteFirst() {
		if (!head) {
			cout << "List is empty!" << endl;
			return;
		}

		Node* temp = head;
		head = head->next;
		if (!head) {
			tail = nullptr;
		}
		delete temp;
		count--;
	}

	//Deleting the last node
	void deleteLast() {
		if (!head) {
			cout << "List is empty!" << endl;
			return;
		}
		if (!head->next) {
			delete head;
			head = tail = nullptr;
		}
		else {
			Node* temp = head;
			while (temp->next != tail) {
				temp = temp->next;
			}
			delete tail;
			tail = temp;
			tail->next = nullptr;
		}
		count--;
	}

	//Displaying the linked list
	void display(const string& listName) {
		cout << listName << " (" << count << "): ";
		Node* temp = head;
		while (temp) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "nullptr" << endl;
	}

	//Get the head of the list
	Node* getHead() {
		return head;
	}

	//Getting the count of nodes
	int getCount() {
		return count;
	}

	//Clear the list
	void clearList() {
		while (head) {
			deleteFirst();
		}
	}
};

//Deriving class for splitting the list
class SplitLinkedList : public SinglyLinkedList {
public:
	void splitEvenAndOdd(SinglyLinkedList& evensList, SinglyLinkedList& oddsList) {
		Node* temp = head;
		while (temp) {
			if (temp->data % 2 == 0) {
				evensList.insertAtEnd(temp->data);
			}
			else {
				oddsList.insertAtEnd(temp->data);
			}
			temp = temp->next;
		}
		clearList();
	}
};


//Main Program for testing
int main() {
	SplitLinkedList list;
	SinglyLinkedList evensList, oddsList;

	cout << "Enter integers ending with -999:\n";
	int num;
	while (cin >> num && num != -999) {
		list.insertAtEnd(num);
	}

	//Displaying the original list
	list.display("List");

	//Splitting the list into evens and odds
	list.splitEvenAndOdd(evensList, oddsList);

	//Displaying the resulting lists
	evensList.display("evensList");
	oddsList.display("oddsList");

	//Displaying the cleared original list
	list.display("List");

	return 0;
}
