#include <iostream>
using namespace std;

class C {
private:
	int mData;
	float mData2;
public:
	C();
};

// �����ڿ� try-catch ����
C::C() try : mData(0), mData2(0) {
	// ������ �ٵ�
	cout << "Constructor\n";
}
catch (const exception& e) {
	cout << "Constructor error :" << e.what();
}

// �Լ��� try-catch ����
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