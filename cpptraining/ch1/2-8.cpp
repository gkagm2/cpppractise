//input 5 names and separate among names with ';' ex) A;B;C;D;E;
#include <iostream>
#include <string>
using namespace std;

int main() {

	cout << "input 5 names and separate among names with ';' ex) A; B; C; D; E; >> ";
	
	string name[5];

	string sentence;
	getline(cin, sentence);
	int i = 0,name_count=0;
	
	while (i < sentence.length()) {
		if (sentence[i] == ';') {
			name_count++;
			if (name_count >= 5)
				break;
		}
		else
			name[name_count] += sentence[i];
		i++;
	}

	for (int i = 0; i< sizeof(name) / sizeof(string); i++) {


		cout << i + 1 << " : " << name[i]<<endl;
	}

	return 0;
}
