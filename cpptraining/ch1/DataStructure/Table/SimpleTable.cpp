
// ���̺� ���� ������ ����

#include <iostream>
using namespace std;
typedef struct t_stduentInfo{
	int iNum;
	int iAge;
}StudentInfo;

int main() {
	// algorithm ������ Ǯ ���. �ӵ��� ���� ���
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	/////////////////////////////
	
	StudentInfo studentInfoArr[1000] = {};
	StudentInfo student;
	int iStudentNum;

	while (true) {
		system("cls");
		cout << "�л� ��ȣ, ���� �Է� : ";
		cin >> student.iNum;
		cin >> student.iAge;
		if (student.iNum < 0 || student.iNum >= 1000) {
			cout << "�л� ��ȣ ������ 0 ~ 1000���� �Դϴ�." << endl;
			system("pause");
			continue; 
		}
		break;
	}
	
	studentInfoArr[student.iNum] = student; // �ٷ� �ε��������� ����

	cout << "Ȯ���ϰ��� �ϴ� �л��� ��ȣ �Է� : ";
	cin >> iStudentNum;

	student = studentInfoArr[iStudentNum]; // �л� ��ȣ�� �ε������̹Ƿ� �ٷ� Ž��
	cout << student.iNum << "�� ��ȣ�� ���� �л��� ���̴� " << student.iAge << "�Դϴ�." << endl;

	return 0;
}