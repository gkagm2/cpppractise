#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
	//int pages;
public:
};
class InkJetPrinter : public Printer {
	int availableInk;
	int availableToner;
public:
	void printInkJet();
};
class LaserPrinter : public Printer {
	int availableToner;
public:
	void printLaser();
};


// inkjet
void InkJetPrinter::printInkJet() {

}

// laser
void LaserPrinter::printLaser() {

}

int main() {


	return 0;
}