#include <iostream>
#include <string>
using namespace std;



class Trace {
	static string tag[100];
	static string inform[100];
	static int pos;
	static int historySize;
public:
	static void put(string tag, string inform) {

		//cout <<"----------"<< tag << ":" << inform <<"----------"<< endl;
		Trace::tag[pos] = tag;
		Trace::inform[pos] = inform;
		Trace::pos++;
	}
	static void print(string tag = "") {
		if (tag == "") {
			//search
			cout << "-------Print all Trace information.-------" << endl;
			for (int i = 0; i < pos; i++) {
				cout << Trace::tag[i] << ":" << Trace::inform[i] << endl;
			}
		}
		else {
			//search
			cout << "-------" << tag << "Print the tag's trace information." << "-------" << endl;
			for (int i = 0; i < pos; i++) {
				if (Trace::tag[i] == tag) {
					cout << Trace::tag[i] << ":" << Trace::inform[i] << endl;
				}
			}
		}
	}
};
//initialized.
int Trace::historySize = 100;
int Trace::pos = 0;
string Trace::tag[100] = {};
string Trace::inform[100] = {};



void f() {
	int a, b, c;
	cout << "input two number>>";
	cin >> a >> b;
	Trace::put("f()", "integer is inputted ");
	c = a + b;
	Trace::put("f()", "sum calculation");
	cout << "sum is " << c << endl;
}

int main() {
	Trace::put("main()", "program started");
	f();
	Trace::put("main()", "Program exited");

	Trace::print("f()");
	Trace::print();

	return 0;
}