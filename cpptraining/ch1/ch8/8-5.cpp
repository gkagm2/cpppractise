#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity;
	int *mem; //The memory pointer to make integer array
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() {
		delete[] mem;
	}
	void put(int index, int val) {
		mem[index] = val;
	}
	int get(int index) {
		return mem[index];
	}
	int getCapacity() {
		return capacity;
	}

};

class MyQueue : public BaseArray {
public:
	MyQueue(int capacity) : BaseArray(capacity) {

	}

};
int main() {
	MyQueue mQ(100);
	int n;
	cout << "input five numbers  to insert in the Queue >>";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // inset in the Queue
	}
	cout << "capacity of queue : " << mQ.capacity() << ", queue size : " << mQ.length() << endl;
	cout << "remove elemental of queue and print>>";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // remove from the queue and print
	}
	cout << endl << "current queue size : " << mQ.length() << endl;
	return 0;
}