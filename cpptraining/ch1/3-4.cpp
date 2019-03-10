#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Random {
public:
	Random();
	int next();
	int nextInRange(int a, int b);
	int EvenRandom();
	int EvenRandom(int a, int b);
};
Random::Random() {
	//RANDOM
	srand((unsigned)time(NULL));
}

int Random::next() {
	return rand();
}
int Random::nextInRange(int a, int b) {
	return rand() % (b - a + 1) + a;
}
int Random::EvenRandom() {
	int num;
	while (true) {
		num = rand();
		if (num % 2 ==0) {
			return num;
		}
	}
	
}int Random::EvenRandom(int a, int b) {
	int num;
	while (true) {
		num = rand() % (b - a + 1) + a;
		if (num % 2 == 0) {
			return num;
		}
	}
	
}

int main() {
	Random r;
	
	cout << "10 even random numbers from 0 to " << RAND_MAX << endl;
	for (int i = 0; i < 10; i++) {
		cout << r.EvenRandom() << ' ';
	}
	cout << endl << endl;
	cout << "10 even random numbers from 2 to 4" << endl;
	for (int i = 0; i < 10; i++) {
		cout << r.EvenRandom(2,4) << ' ';

	}


	return 0;
}