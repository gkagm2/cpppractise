// Word Chain Game;
#include <iostream>
#include <string>
#include "wordGame.h"
using namespace std;


int main() {

	cout << "Start word chain game"<<endl;
	cout << "How many people join the game? ";
	string bn;
	int  numberOfPeople;
	cin >> numberOfPeople;
	cin.ignore(); // important!

	cout << numberOfPeople << endl;
	string name;
	Player *player = new Player[numberOfPeople];
	
	int playerNumber;
	//set players name
	for (playerNumber = 0; playerNumber < numberOfPeople; playerNumber++) {
		cout << "input participant name : ";
		getline(cin, name);
		player[playerNumber].setName(name);
	}
	WordGame game; 
	string word;
	cout << "Start word is " << game.getStartWord() << endl;
	for(playerNumber=0;; playerNumber++) {		
		if (playerNumber == numberOfPeople)
			playerNumber = 0;
		cout << "player : " << player[playerNumber].getName() << endl;
		cout << player[playerNumber].getName() << ">> ";
		getline(cin, word);
		if (!game.CompareWord(word)) {
			cout << player[playerNumber].getName() << "가 졌습니다." << endl;
			break;
		}
		game.setStartWord(word);
	}
	delete[] player;

	return 0;
}