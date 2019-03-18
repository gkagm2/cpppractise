#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Person {
	string name;
public:
	Person(string name = "") {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
};
class UpAndDownGame {	
public:
	static int answer;
	static void showHint();
	static int min, max;
	static void minAndMaxSetting(int answer);
};
int UpAndDownGame::answer;
int UpAndDownGame::min = 0;
int UpAndDownGame::max = 99;

void UpAndDownGame::showHint() {
	cout << "There is an answer between " << UpAndDownGame::min << " and " << UpAndDownGame::max << "." << endl;
}
void UpAndDownGame::minAndMaxSetting(int answer) {
	if (UpAndDownGame::answer > answer)
		UpAndDownGame::min = answer;
	else if (UpAndDownGame::answer < answer)
		UpAndDownGame::max = answer;
}
int main() {
	srand((unsigned)time(NULL));


	Person person[2];
	person[0].setName("류현진");
	person[1].setName("손연재");
	cout << "Up & Down game start" << endl;
	int myAnswer;
	int playerTurn;

	UpAndDownGame::answer = rand() % UpAndDownGame::max - UpAndDownGame::min + 1;
	
	for(int i=0;;i++){
		UpAndDownGame::showHint();

		//Player turn
		playerTurn = i % 2 == 0 ? 0 : 1;
		cout << person[playerTurn].getName() << ">>";
		//input answer
		cin >> myAnswer;

		if (myAnswer == UpAndDownGame::answer) {
			cout << person[playerTurn].getName() << "is win " << endl;
			break;
		}
		else
			UpAndDownGame::minAndMaxSetting(myAnswer);
	}
	
	return 0;
}