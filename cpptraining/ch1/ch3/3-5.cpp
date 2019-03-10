//make class that print even and odd random number; 
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Random {
	int max;
public:
	Random();
	int evenRandom();
	int evenInRandom(int a, int b);
	int oddRandom();
	int oddInRandom(int a, int b);
};
Random::Random() {
	max = 10;
	srand((unsigned)time(NULL));
}
int Random::evenRandom() {
	int num;
	for (int i = 0; i < max; i++) {
		num = rand();
		if (num % 2 == 0)
			return num;
	}
}
int Random::evenInRandom(int a, int b) {
	int num;
	for (int i = 0; i < max; i++) {
		num = rand() % (b - a + 1) + a;
		if (num % 2 == 0)
			return num;
	}
}
int Random::oddRandom() {
	int num;
	for (int i = 0; i < max; i++) {
		num = rand();
		if (num % 2 != 0)
			return num;
	}

}
int Random::oddInRandom(int a, int b) {
	int num;
	for (int i = 0; i < max; i++) {
		num = rand() % (b - a + 1) + a;
		if (num % 2 != 0)
			return num;
	}
}





int main() {

	Random r;

	cout << "10 even random numbers from 0 to " << RAND_MAX << endl;
	for (int i = 0; i < 10; i++) {
		cout << r.evenRandom() << ' ';
	}
	cout << endl << endl;
	cout << "10 even random numbers from 2 to 10" << endl;
	for (int i = 0; i < 10; i++) {
		cout << r.evenInRandom(2, 10) << ' ';

	}
	cout << endl << endl;
	cout << "10 odd random numbers from 0 to " << RAND_MAX << endl;
	for (int i = 0; i < 10; i++) {
		cout << r.oddRandom() << ' ';


	}
	cout << endl << endl;
	cout << "10 odd random numbers from 2 to 10" << endl;
	for (int i = 0; i < 10; i++) {
		cout << r.oddInRandom(2, 10) << ' ';

	}


	return 0;
}