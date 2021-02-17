#include <iostream>
#include "TestTemplateHeader.h"
using namespace std;

int main() {
	CTempTest<int> t(3,5);
	t.data = 3;
	cout << t.data;
	cout << t.GetData();
	return 0;
}