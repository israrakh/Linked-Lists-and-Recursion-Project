// Singly Linked List Implementation: Split Evens/Odds

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

	//Set the head of the list
	void setHead(Node* newHead) {
		head = newHead;
	}

	//Get the head of the list
	Node* getHead() {
		return head;
	}

	//Set the tail
	void setTail(Node* newTail) {
		tail = newTail;
	}

	//Getter for tail
	Node* getTail() {
		return tail;
	}

	//Set the count of the list
	void setCount(int nCount) {
		count = nCount;
	}

	//Getting the count of nodes
	int getCount() {
		return count;
	}

	//Clear the list
	void clearList() {
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		tail = nullptr;
		count = 0;
	}
};

//Deriving class for splitting the list
class SplitLinkedList : public SinglyLinkedList {
public:
	void splitEvenAndOdd(SinglyLinkedList& evensList, SinglyLinkedList& oddsList) {
		Node* current = head;
		Node* evenTail = nullptr; //For tracking the last node of evens list
		Node* oddTail = nullptr; //For tracking the last node of odds list
		int evenCount = 0, oddCount = 0; //Tracking count separately

		while (current) {

			Node* nextNode = current->next; //Store next node before detaching

			if (current->data % 2 == 0) {
				if (evenTail) {
					evenTail->next = current; //Append to evensList
				}
				else {
					evensList.setHead(current); //First even node
				}
				evenTail = current;
				evenCount++;
			}
			else {
				if (oddTail) {
					oddTail->next = current; //Append to the oddsList
				}
				else {
					oddsList.setHead(current); //First odd node
				}
				oddTail = current;
				oddCount++;
			}
			current->next = nullptr;
			current = nextNode;
		}

		//Checking for last nodes next pointers are null
		if (evenTail) { 
			evenTail->next = nullptr;
		}
		if (oddTail) {
			oddTail->next = nullptr;
		}
		evensList.setTail(evenTail);
		oddsList.setTail(oddTail);

		evensList.setCount(evenCount);
		oddsList.setCount(oddCount);

		//Clearing the list after splitting
		head = tail = nullptr;
		count = 0;
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
