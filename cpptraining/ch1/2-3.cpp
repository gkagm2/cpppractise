// print maximum number
#include<iostream>>
using namespace std;

int main() {
	
	cout << " input two number >>";
	int a, b;
	
	//make code without exception handling
	cin >> a;
	cin >> b;
	
	if (a > b)
		cout << a;
	else if (a < b)
		cout << b;
	else
		cout << "!?!?!?? ^^";
	

	return 0;
}