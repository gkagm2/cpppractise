//make concat function with tempate
#include <iostream>
using namespace std;
template<class T>
T * concat(T a[], int sizea, T b[], int sizeb) {
	int size = sizea + sizeb;
	T *newArray = new T[size];
	for (int i = 0; i < size; i++) {
		if (i < sizea) {
			newArray[i] = a[i];
		}
		else
			newArray[i] = b[i-sizea];
	}
	return newArray;
}

int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };

	int *temp = concat(a, 5, b, 5);
	for (int i = 0; i < 10; i++) {
		cout << temp[i] << ' ';
	}


	return 0;
}