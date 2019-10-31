// PROGRAM : �л����� ���α׷�
// DEVELOPER : Sagacity Jang
// DATE : 2019.10.31

#include <iostream>
#include "StudentManager.h"

using namespace std;

#define NAME_SIZE 32
#define ADDRESS_SIZE CHAR_MAX	
#define PHONE_SIZE 14
#define STUDENT_MAX 10

struct _tagStudent {
	char strName[NAME_SIZE];
	char strAddress[ADDRESS_SIZE];
	char strPhoneNumber[PHONE_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	int fAvg;
};

enum MENU {
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main() {

	system("pause");

	_tagStudent tStudentArr[STUDENT_MAX] = {};
	
	int iStudentCount = 0;
	int iStdNumber = 1;

	char strName[NAME_SIZE] = {};

	while (true) {
		system("cls");
		// �޴� ���
		cout << "1. �л����" << endl;
		cout << "2. �л�����" << endl;
		cout << "3. �л�Ž��" << endl;
		cout << "4. �л����" << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		int iMenu;
		cin >> iMenu;

		// ������ �ƴ� ���� �Է½� ����ó��
		if (cin.fail()) { // cin.fail() : �Է¿��� �߻� �� true ����
			cin.clear(); // �������� ����

			cin.ignore(1024, '\n'); // �Ķ����1 : �˻��ϰ��� �ϴ� ���� ũ��(1024 byte ����), �Ķ����2 : ã���� �ϴ� ����
			continue;
		}
		
		if (iMenu == MENU_EXIT) {
			break;
		}

		switch (iMenu) {
		case MENU_INSERT:
			system("cls");
			cout << "==========  �л� �߰� ==========" << endl;
			// �л����� �߰�.
			// ��, ��, �� ������ �Է¹ް�  �й�, ����, ���� ������ ���� ���.
			cin.ignore(1024, '\n');
			cout << "�̸� : ";
			cin >> tStudentArr[iStudentCount].strName;

			cin.ignore(1024, '\n');

			cout << "�ּ� : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

			cout << "��ȭ��ȣ : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

			cout << "�й� : ";
			cin >> tStudentArr[iStudentCount].iNumber;

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iMath;
			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3.f;

			tStudentArr[iStudentCount].iNumber = iStdNumber;

			++iStdNumber;
			++iStudentCount;

			cout << "�л� �߰� �Ϸ�" << endl;
			break;
		case MENU_DELETE:
			system("cls");

			cout << "========== �л����� ==========" << endl;
			cin.ignore(1024, '\n');
			cout << "������ �̸��� �Է��ϼ��� : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iStudentCount; ++i) {
				// �л��� ã���� ���
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					for (int j = i; j < iStudentCount - 1; ++j) {
						tStudentArr[j] = tStudentArr[j + 1];
					}
					--iStudentCount;
					cout << "�л��� �����Ͽ����ϴ�." << endl;
					break;
				}
			}



			break;
		case MENU_SEARCH:
			system("cls");

			cout << "========== �л�Ž�� ==========" << endl;
			cin.ignore(1024, '\n');
			cout << "Ž���� �̸��� �Է��ϼ��� : ";
			cin.getline(strName, NAME_SIZE);

			// Search
			for (int i = 0; i < STUDENT_MAX; ++i) {
				//������
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					cout << "�̸� : " << tStudentArr[i].strName << endl;
					cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber << endl;
					cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
					cout << "�й� : " << tStudentArr[i].iNumber << endl;
					cout << "���� : " << tStudentArr[i].iKor << endl;
					cout << "���� : " << tStudentArr[i].iEng << endl;
					cout << "���� : " << tStudentArr[i].iMath << endl;
					cout << "���� : " << tStudentArr[i].iTotal << endl;
					cout << "��� : " << tStudentArr[i].fAvg << endl << endl;
					break;
				}
			}

			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "========== �л���� ==========" << endl;

			// ��ϵ� �л��� ����� �� �ִ� �ִ�ġ�� ��� ���̻� ����� �ȵǰ� ���´�.
			if(iStudentCount == STUDENT_MAX) {
				break;
			}

			// ��ϵ� �л� ����ŭ �ݺ��Ͽ� �л������� ����Ѵ�.
			for (int i = 0; i < iStudentCount; ++i) {
				cout << "�̸� : " << tStudentArr[i].strName << endl;
				cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber<< endl;
				cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
				cout << "�й� : " << tStudentArr[i].iNumber << endl;
				cout << "���� : " << tStudentArr[i].iKor << endl;
				cout << "���� : " << tStudentArr[i].iEng << endl;
				cout << "���� : " << tStudentArr[i].iMath << endl;
				cout << "���� : " << tStudentArr[i].iTotal << endl;
				cout << "��� : " << tStudentArr[i].fAvg << endl << endl;
			}
			break;
		default:
			cout << "�޴��� �߸� �����߽��ϴ�." << endl;
			break;
		}
		system("pause");
	}

	return 0;
}