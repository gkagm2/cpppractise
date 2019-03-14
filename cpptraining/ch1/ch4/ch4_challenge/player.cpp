#include <iostream>
#include <string>
#include "wordGame.h"

// TODO : why "string" word doesn't work? even have include string header file.. It has to write only std::string.
//        I have no idea..


/*  Doesn't work.
void Player::setName(string name) { 
	this->name = name; 
}
string Player::getName() { 
	return name;
}
*/

//  Work.
void Player::setName(std::string name) {
	this->name = name;
}
std::string Player::getName() {
	return name;
}