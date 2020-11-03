#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "wordGame.h"
using namespace std;

WordGame::WordGame() {
	firstWord[0] = "아버지";
	firstWord[1] = "어머니";
	firstWord[2] = "누나";
	firstStartFlag = true;
	srand((unsigned)time(NULL));
}

bool WordGame::CompareWord(string word) {
	if (this->word[this->word.length()-2] == word[0] && this->word[this->word.length()-1] == word[1]){
		return true;
	}
	else
		return false;
}

string WordGame::getStartWord() {
	if (firstStartFlag == true) {
		int random = rand() % 3;
		word = firstWord[random];
		firstStartFlag = false;
	}

	return word;
}
void WordGame::setStartWord(string word) {
	this->word = word;
}