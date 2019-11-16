#include <iostream>
#include <string>
using namespace std;

class Morse {
	string alphabet[26];
	string digit[10];
	string slash, question, comma, period, plus, equal;
public:
	Morse();
	void text2Morse(string text, string& morse);                           
	bool morse2Text(string morse, string& text);	
};
Morse::Morse() {

}
void Morse::text2Morse(string text, string& morse) {

}
bool Morse::morse2Text(string morse, string& text) {
	//temp return.
	return true;
}


int main() {

	cout << "input english text than it will be changed to morse code." << endl;
	string text;
	string morseCode;
	getline(cin, text, '\n');

	Morse morse;
	morse.text2Morse(text, morseCode);
	cout << morseCode << endl;

	cout << endl;
	cout << "morse code will be changed to english text" << endl;
	if (morse.morse2Text(morseCode, text)) {
		cout << morseCode<<endl;
	}
	else {
		cout <<"fail to change text to morse code"<<endl;
	}




	return 0;
}