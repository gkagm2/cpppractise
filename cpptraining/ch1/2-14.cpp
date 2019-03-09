//Alphabet histogram.
#include <iostream>
using namespace std;

int main() {

	cout << "input English text" << endl;
	cout << "end of the text is ';' key. (max 1000 words)" << endl;
	char buf[1000];
	cin.getline(buf, 1000, ';');

	int count = 0;
	int alphabet[26] = { 0, };
	int total = 0;

	while (buf[count] != '\0') {
		//true -> alpha
		if (isalpha(buf[count])) {
			total++;
			buf[count] = tolower(buf[count]);
			alphabet[buf[count] - 97]++;
		}

		count++;
	}

	cout << "total alphabet count : " << total << endl << endl;
	for (int i = 0; i < sizeof(alphabet) / sizeof(int); i++) {
		cout << char(97 + i) << " (" << alphabet[i] << ")\t: ";
		for (int j = 0; j < alphabet[i]; j++) {
			cout << "*";
		}
		cout<<endl;
	}


	return 0;
}