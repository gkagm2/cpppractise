#include <iostream>
using namespace std;

extern void ExternTestFunction(void);

namespace {
	float pi = 3.14f; // Unique identifier known only in thie file
}

void TestFunction() {
	cout << " pi pi : " << pi << "\n";
}

int main() {
	float pi = 0.1f;
	cout << "pi = " << pi << "\n";

	ExternTestFunction();
	TestFunction();

	return 0;
}