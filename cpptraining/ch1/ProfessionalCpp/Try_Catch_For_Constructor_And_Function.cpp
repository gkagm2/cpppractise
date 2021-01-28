#include <iostream>
using namespace std;

class C {
private:
	int mData;
	float mData2;
public:
	C();
};

// 생성자에 try-catch 쓰기
C::C() try : mData(0), mData2(0) {
	// 생성자 바디
	cout << "Constructor\n";
}
catch (const exception& e) {
	cout << "Constructor error :" << e.what();
}

// 함수에 try-catch 쓰기
void Func() try {
	cout << "Call function\n";
}
catch (const exception& e) {
	cout << "Function error : " << e.what();
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	C c;

	Func();

	return 0;
}	