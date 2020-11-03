//Make search function with template
#include <iostream>
using namespace std;

template<class T>
bool search(int value, T arr, int size) {
	for (int i = 0; i < size; i++) {
		if (value == arr[i])
			return true; // include
	}
	// not include
	return false;
}

int main() {
	int x[] = { 1,10,100,5,4 };
	if (search(100, x, 5))
		cout << "100 is included in array" << endl;
	else
		cout << "100 isn't included in array" << endl;

	return 0;
}