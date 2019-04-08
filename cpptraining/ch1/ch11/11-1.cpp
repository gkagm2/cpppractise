#include<iostream>
using namespace std;


int main() {
	int ch;
	int aCount =0 ;

	while ((ch = cin.get()) != EOF) {
		cout.put(ch);
		if (ch == 'a')
			++aCount;
		if (ch == '\n')
			break;
	}
	cout << "Count : " << aCount << endl;
	return 0;
}