// Make treverseArray function with template
#include <iostream>
using namespace std;
template<class T>
void reverseArray(T *array, int size) {
	T temp;
	for (int i = 0; i < size / 2; i++) {
		temp = array[i];
		array[i] = array[size - (i + 1)];
		array[size - (i + 1)] = temp;
	}
}

int main() {
	int x[] = { 1,10,100,5,4 };
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++) {
		cout << x[i] << ' ';
	}


	return 0;
}