#include <iostream>
using namespace std;

// catch 파라미터에 ...을 적으면 아무 에러가 나면 catch(...)구문 쪽으로 흘러가게 한다.
void Ex1() {
	int i = 5, j = 2, k = 0;

	try {
		if (j == 100 || j == 0)
			throw j;
		if (k == 100 || k == 0)
			throw k;
		cout << i / k << "\n";
	}
	catch (...) { // ...은 아무거나 잡는다.
		cout << "Catch anything!" << "\n";
	}
}

// Try문 안에 Try
void Ex2() {
	int i = 5, j = 2, k = 0;

	try {
		if (j == 100 || j == 0)
			throw "exception: j is 100 or 0";
		
		try {
			if (k == 0)
				throw k;
		}
		catch (int k) {
			cout << "nested catch block\n";
		}
		cout << i / k << "\n";
		cout << "end of try block";
	}
	catch (char e) {
		cout << "char catch\n";
	}
	catch (int e) {
		cout << "int catch\n";
	}
	catch (char* e) {
		cout << e << "\n";
	}
	catch (...) { // ...은 아무거나 잡는다.
		cout << "Catch anything!\n";
	}

}


int main() {

	Ex2();
	
	return 0;
}