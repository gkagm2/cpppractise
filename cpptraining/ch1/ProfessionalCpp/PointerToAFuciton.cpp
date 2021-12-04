#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Intro() {
	cout << "Input a and b\n";
}

int Plus(int a, int b) {
	return a + b;
}

int Minus(int a, int b) {
	return a - b;
}

int Mul(int a, int b) {
	return a * b;
}

int Div(int a, int b) {
	if (a == 0 || b == 0)
		return 0;
	return a / b;
}

int main() {
	void(*ffp)();
	int(*fp[4])(int, int) = { Plus, Minus, Mul, Div }; // �Լ� ������ �迭

	int select;
	int a, b;
	while (true) {
		system("cls");

		cout << "1.Plus 2.Minus, 3.Mul 4.Div 5.Exit\n";
		cin >> select;

		ffp = Intro;
		ffp();

		if (select == 5)
			return 0;
		if(select < 1 || select > 4)
			continue;


		cout << "input a : ";
		cin >> a;
		cout << "input b : ";
		cin >> b;

		int value = fp[select - 1](a, b); // �Լ� ������ �迭�� �̿��� ȣ��
		cout << "result : " << value << "\n";
		system("pause");
	}

	return 0;
}
/*
int main() {
	void(*ffp)();
	int(*fp)(int, int); // �Լ� ������ ���� // 

	int select;
	int a, b;
	while (true) {
		system("cls");

		cout << "1.Plus 2.Minus, 3.Mul 4.Div 5.Exit\n";
		cin >> select;

		ffp = Intro;
		ffp();

		switch (select) {
		case 1:
			fp = Plus;
			break;
		case 2:
			fp = Minus;
			break;
		case 3:
			fp = Mul;
			break;
		case 4:
			fp = Div;
			break;
		case 5:
			return 0;
		default:
			continue;
		}

		cout << "input a : ";
		cin >> a;
		cout << "input b : ";
		cin >> b;

		int value = fp(a, b);
		cout << "result : " << value << "\n";
		system("pause");
	}

	return 0;
}
*/

void Add() {
	cout << "add";
}
void Plus() {
	cout << "plus";
}

/*
// �Լ� �̿��ؼ� �����ϱ�
void ContextMenu(vector<pair<string,void(*)()>>& _vecList , string strOrder) {
	for (int i = 0; i < _vecList.size(); ++i) {
		if (strOrder == _vecList[i].first) {
			_vecList[i].second();
		}
	}
}

int main() {
	void (*fp[3])() = { Add, Plus };

	vector< pair<string, void(*)()>> vecfuncList;
	vecfuncList.push_back(make_pair("add", Add));
	vecfuncList.push_back(make_pair("plus",Plus));

	// context �Լ� ������ add ��ɾ� ����
	ContextMenu(vecfuncList, "add");
	return 0;
}
*/