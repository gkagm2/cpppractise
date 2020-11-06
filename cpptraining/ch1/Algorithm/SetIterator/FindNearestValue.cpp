#include <iostream>>
#include <set>
using namespace std;

int GetNearestValue(set<int> & _s, const int _value) {
	int value = 0;
	auto it = _s.lower_bound(_value);
	if (it == _s.begin()) {
		value = *it;
	}
	else if (it == _s.end()) {
		it--;
		value = *it;
	}
	else {
		int a = *it;
		--it;
		int b = *it;
		if (_value - b < a - _value)
			value = b;
		else
			value = a;
	}
	return value;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	set<int> s = { 1,2,3,99,6,7,8,9 };
	int num = GetNearestValue(s, 5);
	cout << num;
	return 0;
}