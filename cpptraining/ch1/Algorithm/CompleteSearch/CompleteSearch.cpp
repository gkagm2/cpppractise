#include <iostream>
#include <vector>
using namespace std;

vector<int> vv;
vector<int> v{ 1,2, 3};

// Recursion
void CompleteSearch1(int k, const int n) {
	if (k == n) {
		for (int i = 0; i < vv.size(); ++i) {
			cout << vv[i] << " ";
		}
		cout << "\n";
		return;
	}

	CompleteSearch1(k + 1, n);
	vv.push_back(v[k]);
	CompleteSearch1(k + 1, n);
	vv.pop_back();

}

// Exploit the bit representation integer
void CompleteSearch2(int m) {
	cout << (1 << m);
	for (int b = 0; b < (1 << m); b++) {
		vector<int> subset;
		for (int i = 0; i < m; i++) {
			if (b&(1 << i)) subset.push_back(v[i]);
		}
		for (int i = 0; i < subset.size(); ++i) {
			cout << subset[i] << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	//CompleteSearch1(0, v.size());
	CompleteSearch2( v.size());

	return 0;
}