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
class KmToMile : public Converter {
public:
	KmToMile(double n) : Converter(n) {

	}
	double convert(double src) {
		return src / 1.609344;
	}
	string getSourceString() {
		return "Km";
	}
	string getDestString() {
		return "Mile";
	}
};

int main() {
	KmToMile toMile(1.609344); // 1 mile -> 1.609344 km
	toMile.run();

	return 0;
}