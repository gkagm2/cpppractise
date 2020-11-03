#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size) {
		int *z = new int[size];
		for(int i = 0; i < size / 2; i++) {
			z[i] = s1[i];
			//cout << z[i] << ' ';
		}
		for (int i = size/2, j=0 ; i < size; i++,j++) {
			z[i] = s2[j];
			//cout << z[i] << ' ';
		}
		return z;
	}
	static int* remove(int s1[], int s2[], int size, int& reSize) {
		int length=0;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (s1[i] == s2[j]) {
					length++;
					break;
				}
			}
		}
		reSize = size - length;
		int count = 0;
		bool isThere = false;
		int *z = new int[length];
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (s1[i] == s2[j]) {
					isThere = true;
					break;
				}
			}
			if (isThere == false) {
				z[count] = s1[i];
				count++;
			}
			isThere = false;
		}
		return z;
	}
};

int main() {
	int x[5];
	int y[5];
	
	
	cout << "input five int type number >>";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}
	cout << "input five int type number >>";
	for (int i = 0; i < 5; i++) {
		cin >> y[i];
	}


	int *z;
	z = ArrayUtility2::concat(x, y, 10); // x[] -> y[]
	for (int i = 0; i < 10; i++) {
		cout << z[i] << ' ';
	}
	cout << endl;
	delete[] z;

	int size;
	z = ArrayUtility2::remove(x, y, 5 ,size); // z[] -> x[]
	for (int i = 0; i < size; i++) {
		cout << z[i] << ' ';
	}
	cout << endl;

	delete[] z;
	return 0;
}