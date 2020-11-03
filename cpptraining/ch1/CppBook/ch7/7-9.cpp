// 
#include <iostream>
using namespace std;

class Statistics {
	int *data;
	int pos;
	int indexSize;
public:
	Statistics();
	~Statistics();
	Statistics& operator<<(int value);
	// TODO : This code occur error
	//friend Statistics operator<<(Statistics& op1, int value);
	
	friend bool operator!(Statistics& op1);
	friend void operator~(Statistics& op1);
	friend void operator>>(Statistics& op1, int& average);
};
Statistics::Statistics() {
	data = new int[5];
	indexSize = 5;
	pos = 0;
}
Statistics::~Statistics() {
	delete[] data;
}

// TODO : This code occur error. I don't know how to make the code on the line of 42.
//Statistics operator<<(Statistics& op1, int value) {
//	if (op1.pos >= op1.indexSize) {
//		int *temp = new int[op1.indexSize + 5];
//		for (int i = 0; i < op1.pos; i++) {
//			temp[i] = op1.data[i];
//		}
//		delete[] op1.data;
//		op1.data = temp;
//		op1.indexSize += 5;
//	}
//	op1.data[op1.pos] = value;
//	op1.pos++;
//	return op1;
//
//}

Statistics& Statistics::operator<<(int value) {
	if (pos >= indexSize) {
		int *temp = new int[indexSize + 5];
		for (int i = 0; i < pos; i++) {
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
		indexSize += 5;
	}
	data[pos] = value;
	pos++;
	return *this;

}

//  Important !!!!!!!!!! prefer to make code member function than friend function except "2 + a" case

// Important !!!!!!!!!! have to & on the first parameter, because if not attach &, Statistics's destructor function will start when this function return. 
void operator>>(Statistics& op1, int& average) {
	int sum=0;
	for (int i = 0; i < op1.pos; i++) {
		sum += op1.data[i];
	}
	average = sum / op1.pos;
}
//have to & on the first parameter, because if not attach &, Statistics's destructor function will start when this function return. 
bool operator!(Statistics& op1) {
	return	!(op1.pos);
}
//have to & on the first parameter, because if not attach &, Statistics's destructor function will start when this function return. 
void operator~(Statistics& op1){
	for (int i = 0; i < op1.pos; i++) {
		cout << op1.data[i] << ' ';
	}
}

int main() {
	Statistics stat;
	if (!stat) cout << "There is noting current statistics data " << endl;

	int x[5];
	cout << "input 5 number >>";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < 5; i++) {
		stat << x[i];
	}
	stat << 100 << 200;
	~stat;
	
	int avg;
	stat >> avg;
	cout << "avg=" << avg << endl;
	return 0;
}