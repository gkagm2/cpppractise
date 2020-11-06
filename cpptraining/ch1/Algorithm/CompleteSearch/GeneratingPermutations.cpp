#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> permutation;
vector<int> v = { 1,2,3 };
bool chosen[5];

// Recursion
void Search1(int n) {
	if (permutation.size() == n) {
		for (int i = 0; i < n; ++i) {
			cout << permutation[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (chosen[i]) continue;

		chosen[i] = true;
		permutation.push_back(v[i]);
		Search1(n);
		chosen[i] = false;
		permutation.pop_back();
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// Type 1
	// Search1(v.size());


	// Type 2
	// need to include algorithm header 
	do {
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}