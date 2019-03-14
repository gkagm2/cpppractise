#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Player {
	string name;
public:
	void setName(string name){ this->name = name; }
	string getName() { return name; }
};

class GamblingGame {
	int dice[3];
public:
	GamblingGame();
	void rollDice();
	bool isMatchDice();
	void showDice();
};

GamblingGame::GamblingGame() {
	srand((unsigned)time(NULL));
}
void GamblingGame::rollDice() {
	for (int i = 0; i < sizeof(dice)/sizeof(int); i++) {
		dice[i] = rand() % 3; // 0~2
	}
}
bool GamblingGame::isMatchDice() {
	int tcard = dice[0];
	bool match = true;
	for (int i = 1; i < sizeof(dice)/sizeof(int); i++) {
		if (tcard != dice[i]){
			match = false;
			break;
		}
	}
	return match;
}
void GamblingGame::showDice() {
	for (int i = 0; i < sizeof(dice) / sizeof(int); i++) {
		cout << '\t' << dice[i] <<'\t';
	}
}

int main() {
	
	int playerCount = 2;
	cout << " Start Gambling game" << endl;
	Player *player = new Player[playerCount];
	string name;
	cout << "first player name : ";
	getline(cin, name, '\n');
	player[0].setName(name);

	cout << "second player name : ";
	getline(cin, name, '\n');
	player[1].setName(name);

	GamblingGame ggame;
	char startGame;
	
	for (int playerTurn = 0;; playerTurn++) {

			cout << player[playerTurn % playerCount].getName() << ":<Enter>";
			cin.get(startGame);
			//start game
			if (startGame == '\n') {
				ggame.rollDice();
				ggame.showDice();
				if (ggame.isMatchDice()) {
					cout << "all of dice matched!!  " << player[playerTurn % playerCount].getName() << " win!!!" << endl;
					break;
				}
				else {
					cout << "fail!" << endl;
				}
			}
	}
	delete[] player;
	return 0;
}