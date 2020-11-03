#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {
public:
	static void seed() { srand((unsigned)time(0)); }
	static int nextInt(int min = 0, int max = 32767);
	static char nextAlphabet();
	static double nextDouble();
};
int Random::nextInt(int min, int max) {
	
	int a = max - min;
	int num;
	while (true) {
		num = (rand() % (a + 1)) + min; 
		if (num >= min && num <= max)
			return num;
	}
}
char Random::nextAlphabet() {
	if (rand() % 2 == 0) { // big
		return (rand() % 26) + 65;
	}
	else { // small
		return (rand() % 26) + 97;
	}
}
double Random::nextDouble() {
	return (double)rand() / RAND_MAX;
}

int main() {
	int num = 10;
	cout << "Print 10 random integers from 1 to 100." << endl;
	Random::seed();
	for (int i = 0; i < num; i++) {
		cout << Random::nextInt(70, 100) << ' ';
	}
	cout << endl;
	cout << "Print 10 random alphabets" << endl;
	for (int i = 0; i < num; i++) {
		cout << Random::nextAlphabet() << ' ';
	}
	cout << endl;
	cout << "Print 10 random double type number from 0 to 1." << endl;
	for (int i = 0; i < num; i++) {
		cout << Random::nextDouble() << ' ' ;
	}
	cout << endl;


	return 0;
}