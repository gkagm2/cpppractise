//make generic biggest() function
#include <iostream>
using namespace std;

template<class T>
T biggest(T arr[], int size) {
	int temp = arr[0];
	for (int i = 1; i < size; i++) {
		if (temp < arr[i]) {
			temp = arr[i];
		}
	}
	return temp;
}


int main() {
	int x[] = { 1,10,100,5,4 };
	
	cout << biggest(x, sizeof(x) / sizeof(x[0])) << endl;

	return 0;
}