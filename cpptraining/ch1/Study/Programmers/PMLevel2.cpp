// STACK/QUEUE
// 프로그래머스 Level2 쇠막대기 풀이

#include <iostream>
#include <string>
using namespace std;

string str;

class Stack{
private:
	char *elements;
	int length;
	int maxSize;

public:
	Stack() : maxSize(10), length(0){
		elements = new  char[maxSize]();
	}
	~Stack() {
		delete[] elements;
	}

public:
	int Lenght() const {
		return length;
	}

	int Size() const {
		return length;
	}

	void Push(const char _str) {
		if (isFull()) {
			IncreaseSize(5);
		}
		this->elements[length];
		elements[length++] = _str;
	}

	char Pop() {
		if (length == 0) {
			return NULL; // error 발생 조심
		}
		return elements[--length];
	}

private:
	int isFull() {
		if (maxSize == length) {
			return 1;
		}
		return 0;
	}

	void IncreaseSize(int _size) {
		int newMaxSize = maxSize + _size;
		char *pTempArr = new char[newMaxSize]();
		memset(pTempArr, 0, sizeof(char) * newMaxSize);

		// all data copy
		for (int i = 0; i < maxSize; ++i) {
			pTempArr[i] = elements[i];
		}

		delete[] elements;
		elements = pTempArr;
		maxSize = newMaxSize;
	}
};

int pipe(const string& str) {
	int result = 0;
	Stack st;

	char cBefore;
	for (int loopi = 0; loopi < str.size(); ++loopi) {

		if (str[loopi] == '(') {
			st.Push(str[loopi]);
		}
		else if (str[loopi] == ')' && cBefore == '(') {
			st.Pop();
			result += st.Lenght();
		}
		//else if()str[loopi] == ''
		cBefore = str[loopi];



		st.Push(cBefore);


	}

	return result;
}

int main() {
	cin >> str;

	cout << pipe(str);
}