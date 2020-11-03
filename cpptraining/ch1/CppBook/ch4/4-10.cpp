//Histogram class
#include <iostream>
#include <string>
#include <locale>
using namespace std;

class Histogram {
	string sentance;
	int alphabetCount[26];
	int totalAlphabetCount;
public:
	Histogram(string sentance);
	void put(string sentance);
	void putc(char ch);
	void print();
};
Histogram::Histogram(string sentance) {
	for (int i = 0; i < 26; i++) {
		alphabetCount[i] = 0;
	}
	totalAlphabetCount=0;

	this->sentance = sentance + '\n';

}
void Histogram::put(string sentance) {
	this->sentance += sentance;
}
void Histogram::putc(char ch) {
	this->sentance += ch;
}
void Histogram::print() {
	cout << sentance;

	string text = sentance;

	//count alphabet
	for (int i = 0; i < sentance.length(); i++) {
		if (isalpha(sentance[i])) {
			text[i] = tolower(sentance[i]);
			alphabetCount[text[i] - 97]++;
			totalAlphabetCount++;
		}
	}

	cout << endl <<endl << "total alphabet count : " << totalAlphabetCount <<  endl;

	int c = 0;
	cout << endl;
	for (int j = 0; j < 26; j++) {
		cout <<char(97+j) <<" ("<< alphabetCount[j] << ")   : ";
		for (int i = 0; i < alphabetCount[j]; i++) {
			cout << "*";
			
		}
		cout << endl;
	}

}

int main() {
	Histogram elvishisto("wise men say, only fools rush in but i can't help, ");
	elvishisto.put("falling in love with you");
	elvishisto.putc('-');
	elvishisto.put("elvis presley");
	elvishisto.print();

	return 0;
}