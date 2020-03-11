#include <iostream>
#include <string>
using namespace std;

//  <-[next-data-prev]-> link <-[next-data-prev]->

typedef struct Node {
	int data;
	Node *prev;
	Node *next;
	Node(int _data) : prev(NULL), next(NULL), data(_data) {
	}
};

class Deck {
private:
	Node *head;
	Node *tail;
	int size;

public:
	Deck() : size(0), head(NULL), tail(NULL) {
	}
	~Deck() {
		while (size--) {
			Node *node = head;
			head = head->prev;
			delete node;
		}
	}

	void Push_front(int _data) {
		Node *newNode = new Node(_data);

		if (Empty()) {
			head = newNode;
			tail = newNode;
		}
		else {
			head->next = newNode;
			newNode->prev = head;
			head = newNode;
		}
		++size;
	}

	void Push_back(int _data) {
		Node *newNode = new Node(_data);

		if (Empty()) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->prev = newNode;
			newNode->next = tail;
			tail = newNode;
		}
		++size;
	}

	int Pop_front() {
		if (Empty()) {
			return -1;
		}
		int data = head->data;
		Node *node = head;
		head = head->prev;
		delete node;
		--size;

		return data;
	}

	int Pop_back() {
		if (Empty()) {
			return -1;
		}

		int data = tail->data;
		Node *node = tail;
		tail = tail->next;
		delete node;
		--size;
		return data;
	}

	int Size() {
		return size;
	}

	int Empty() {
		if (!size) {
			return 1;
		}
		return 0;
	}

	int Front() {
		if (Empty()) {
			return -1;
		}
		return head->data;
	}

	int Back() {
		if (Empty()) {
			return -1;
		}
		return tail->data;
	}
};


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Deck deck;
	int cnt;
	cin >> cnt;

	while (cnt--) {
		string command;
		int num;

		cin >> command;

		if (command.compare("push_back") == 0) {
			cin >> num;
			deck.Push_back(num);
		}
		else if (command.compare("push_front") == 0) {
			cin >> num;
			deck.Push_front(num);
		}
		else if (command.compare("pop_back") == 0) {
			cout << deck.Pop_back() << '\n';
		}
		else if (command.compare("pop_front") == 0) {
			cout << deck.Pop_front() << '\n';
		}
		else if (command.compare("front") == 0) {
			cout << deck.Front() << '\n';
		}
		else if (command.compare("back") == 0) {
			cout << deck.Back() << '\n';
		}
		else if (command.compare("size") == 0) {
			cout << deck.Size() << '\n';
		}
		else if (command.compare("empty") == 0) {
			cout << deck.Empty() << '\n';
		}
	}

	return 0;
}