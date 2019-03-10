//Make random numbers
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {

public:
	Random();
	int next();
	int nextInRange(int a, int b);
};
Random::Random() {
	// RANDOM INTEGER 
	srand((unsigned)time(NULL));
}
int Random::next() {
	return rand();
}
int Random::nextInRange(int a, int b) {
	return rand() % (b - a + 1) + a;
}
int main() {

	
	
	Random r;
	cout << "10 random numbers " << "from 0 to " << RAND_MAX << endl; //RAND_MAX -> 32767(max)
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}

	cout << endl << endl << "10 random numbers from 2 to 4" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}