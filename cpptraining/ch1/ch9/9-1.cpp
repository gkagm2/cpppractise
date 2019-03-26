#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << "Change " << getSourceString() << "to " << getDestString();
		cout << "input " << getSourceString() << " >> ";
		cin >> src;
		cout << "result : " << convert(src) << getDestString() << endl;
	}
};
class WonToDollar : public Converter {
public:
	WonToDollar(int won) : Converter(won) {}
	double convert(double src) {
		double dollar = src / 1010;
		return dollar;
	}
	string getSourceString() { return "won"; }
	string getDestString() { return "dollar"; }
};

int main() {
	WonToDollar wd(1010); // 1 dollar = 1010 won
	wd.run();
	return 0;
}