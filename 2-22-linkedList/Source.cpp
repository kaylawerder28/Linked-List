#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node() {}
	Node(int val) {
		data = val;
		next = nullptr;
		prev = nullptr;
	}
};

class LinkedList {
public:
	Node* head;
	Node* tail;
	LinkedList() { head = nullptr; tail = nullptr; }

	void InsertAtHead(int x) {
		Node* node = new Node(x);
		if (head)
			head->prev = node;
		node->next = head;
		head = node;
		if (tail == nullptr) {
			tail = node;
		}

	}
	void InsertAtEnd(int x) {
		Node* node = new Node(x);
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = node;
		node->next = nullptr;
		node->prev = temp;
		tail = node;
	}
	void InsertAtPosition(int x, int p) {
		Node* node = new Node(x);
		Node* temp = head;
		if (p == 1) { InsertAtHead(x); return; }
		for (int i = 1; i < p - 1; i++) { temp = temp->next; }
		node->next = temp->next;
		temp->next = node;
		node->next->prev = node;
		node->prev = temp;
		Node* temp2 = head;
		while (temp2->next != nullptr) {
			temp2 = temp2->next;
		}
		tail = temp2;
	}

	void DeleteAtHead() {
		if (head == tail) {
			tail = nullptr;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
		if (head) {
			head->prev = nullptr;
		}
	}
	void DeleteAtEnd() {
		Node* temp = head;
		if (temp->next == nullptr) {
			DeleteAtHead();
			return;
		}
		while (temp->next && temp->next->next) {
			temp = temp->next;
		}
		Node* dNode = temp->next;
		temp->next = nullptr;
		dNode->prev = tail;
		delete dNode;
	}
	void DeleteAtPosition(int p) {
		if (p == 1) { DeleteAtHead(); return; }
		Node* temp = head;
		for (int i = 1; i < p - 1; i++) { temp = temp->next; }
		Node* dnode = temp->next;
		temp->next = nullptr;
		delete dnode;
		tail = temp;
	}

	void UpdateAtPosition(int x, int p) {
		Node* temp = head;
		for (int i = 1; i < p; i++) { temp = temp->next; }
		temp->data = x;
	}

	void UpdateByValue(int x, int y) {
		int p = Search(y);
		UpdateAtPosition(x, p);
	}
	void DeleteByValue(int y) {
		int p = Search(y);
		DeleteAtPosition(p);
	}

	int Search(int x) { //returns the position of the x int the list
		Node* temp = head;
		int pos = 1;
		while (temp) {
			if (temp->data == x) { return pos; }
			temp = temp->next;
			pos++;
		}
		return 0;
	}

	void PrintForward() {
		Node* temp = head;
		//temp==nullptr  is equal to saying !temp
		if (!temp) { cout << "List is empty" << endl; return; }

		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void PrintBackward() {
		Node* temp = tail;
		//temp==nullptr  is equal to saying !temp
		if (!temp) { cout << "List is empty" << endl; return; }

		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->prev;
		}
		cout << endl;
	}
};

int main() {

	LinkedList* list = new LinkedList();
	list->InsertAtHead(2);               list->PrintForward(); //2
	list->InsertAtHead(4);               list->PrintForward(); //4 2
	list->InsertAtHead(6);               list->PrintForward(); //6 4 2


	list->PrintBackward(); // 2 4 6 

	list->InsertAtEnd(8);   list->PrintForward(); //6 4 2 8
	list->InsertAtEnd(1);   list->PrintForward(); //6 4 2 8 1

	list->PrintBackward(); //1 8 2 4 6 

	list->DeleteAtHead();   list->PrintForward(); // 4 2 8 1
	list->DeleteAtHead();   list->PrintForward(); // 2 8 1

	list->PrintBackward(); // 1 8 2

	list->InsertAtPosition(5, 2); list->PrintForward();// 2 5 8 1
	list->InsertAtPosition(7, 3); list->PrintForward();// 2 5 7 8 1

	list->PrintBackward();// 1 8 7 5 2

	list->DeleteByValue(1); list->PrintForward();


	list->DeleteAtPosition(4); list->PrintForward(); // 2 5 7 
	list->DeleteAtPosition(1); list->PrintForward(); // 5 7 

	list->PrintBackward();//  7 5

	cout << " The position is " << list->Search(7) << endl;

	list->UpdateAtPosition(4, 2); list->PrintForward();// 5 4

	list->PrintBackward(); // 4 5

	list->UpdateByValue(9, 5); list->PrintForward(); // 9 4

	list->PrintBackward(); // 4 9

	list->DeleteByValue(4);   list->PrintForward(); //9 


	getchar();
	return 0;
}



