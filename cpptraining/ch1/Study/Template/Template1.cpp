#include <iostream>
using namespace std;

template <typename T>
void OutputType() {
	cout << typeid(T).name() << endl;
}

template <typename T>
void OutputData(T data) {
	cout << "Output Data" << endl;
	cout << typeid(T).name() << endl;
	cout << data << endl;
}

typedef struct _tagStudent {

}STUDENT, *PSTUDENT;

class CCar {
public:
	CCar() {
	}
	~CCar() {
	}
};

enum TEST {

};

class CTemplate {
public:
	CTemplate() {
	}
	~CTemplate() {
	}
public:
	template <class T1, class T2, class T3>
	void Output(T1 a, T2 b, T3 c) {
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
	}
};

template <typename T>
class CTemplate1 {
public:
	CTemplate1() {
		cout << "Template1 class Type : " << typeid(T).name() << endl;
	}
	~CTemplate1() {

	}
private:
	T m_Data;
public:
	void Output() {
		cout << typeid(T).name() << endl;
	}
};

int main() {
	OutputType<int>();
	OutputType<float>();
	OutputType<STUDENT>();
	OutputType<CCar>();
	OutputType<TEST>();
	OutputData(10);
	OutputData(3.1);
	OutputData(382.333f);
	OutputData('a');
	OutputData("zzz");
	CTemplate tem;
	tem.Output(10, 2.2f, "s");
	tem.Output(244.34, 100, 'c');

	CTemplate1<int> tem1;
	
	tem1.Output();

	CTemplate1<CTemplate> tem2;

	return 0;
}