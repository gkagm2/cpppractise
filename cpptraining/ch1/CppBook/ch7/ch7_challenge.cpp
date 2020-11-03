#include <iostream>
#include <string>
using namespace std;

class Histogram {
	int alphabet[26];
	string song;
	int alphabetCount;
public:
	Histogram(string song);

	Histogram& operator<<(string str);
	Histogram& operator<<(char c);
	void operator!();
};

Histogram::Histogram(string song) {
	this->song = song;
	alphabetCount = 0;
}
//add string or character
// overloading
Histogram& Histogram::operator<<(string str) {
	song += str;
	return *this;
}
Histogram& Histogram::operator<<(char c) {
	song += c;
	return *this;
}
//draw histogram
void Histogram::operator!() {
	cout << song << endl << endl;
	cout << "총 알파벳 수";
	char c;
	for (int i = 0; i < song.length; i++) {
		c = song[i];
		//TODO : 여기부터 해야 함. 
		/*if (isalpha(c)) {
			++alphabetCount;
			c = tolower()
		}*/
	}
}


int main() {
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song << "falling" << " in love wiith you." << "- by "; //add string
	song << 'k' << 'i' << 't'; // add character
	!song; // draw histogram

	return 0;
}