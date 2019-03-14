#pragma once
#include <iostream>

class Player {
	std::string name;
public:
	void setName(std::string name);
	std::string getName();
};



class WordGame{
	bool firstStartFlag;
	std::string firstWord[3];
	std::string word;
public:
	WordGame();
	bool CompareWord(std::string word);
	std::string getStartWord();
	void setStartWord(std::string word);
};


