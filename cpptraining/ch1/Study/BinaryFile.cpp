#include <iostream>

using namespace std;

#define NAME_SIZE 32
#define STUDENT_MAX 3

typedef struct _tagStudent {
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
}STUDENT, *PSTUDENT;

void InsertStudent();
void OutputStudent();

int main() {
	//InsertStudent();
	OutputStudent();

	return 0;
}

void OutputStudent()
{
	STUDENT tStudent[STUDENT_MAX] = {};
	FILE *pFile = NULL;
	fopen_s(&pFile, "Study/Student.std", "rb");

	int iStudentCount = 0;
	if (pFile) {
		// �����Ҷ� �л����� ���� ���� �����߱� ������ �л� ���� ���� �о�´�.

		fread(&iStudentCount, 4, 1, pFile);

		for (int i = 0; i < iStudentCount; ++i) {
			fread(&tStudent[i], sizeof(STUDENT), 1, pFile);
		}
		fclose(pFile);
	}
	// �о�� �л��� ����Ѵ�.
	for (int i = 0; i < iStudentCount; ++i) {
		cout << "�̸� : " << tStudent[i].strName << endl;
		cout << "�й� : " << tStudent[i].iNumber << endl;
		cout << "���� : " << tStudent[i].iKor << endl;
		cout << "���� : " << tStudent[i].iEng << endl;
		cout << "���� : " << tStudent[i].iMath << endl;
		cout << "���� : " << tStudent[i].iTotal << endl;
		cout << "��� : " << tStudent[i].fAvg << endl << endl;
	}
}

void InsertStudent()
{
	STUDENT tStudent[STUDENT_MAX] = {};
	for (int i = 0; i < STUDENT_MAX; ++i) {
		cout << "�̸� : ";

		cin.getline(tStudent[i].strName, NAME_SIZE - 1);
		cin.clear();

		tStudent[i].iNumber = i + 1;
		cout << "���� : ";
		cin >> tStudent[i].iKor;

		cin.clear();
		cin.ignore(1024, '\n');

		cout << "���� : ";
		cin >> tStudent[i].iEng;
		cin.clear();
		cin.ignore(1024, '\n');

		cout << "���� : ";
		cin >> tStudent[i].iMath;
		cin.clear();
		cin.ignore(1024, '\n');

		tStudent[i].iTotal = tStudent[i].iKor + tStudent[i].iEng + tStudent[i].iMath;
		tStudent[i].fAvg = tStudent[i].iTotal / 3.f;
	}

	// �л� ������ ���Ͽ� �����Ѵ�.
	int iStudentCount = STUDENT_MAX;
	FILE * pFile = NULL;

	fopen_s(&pFile, "Study/Student.std", "wb"); // b : binary file

	if (pFile) {
		// �л� �� ����
		fwrite(&iStudentCount, 4, 1, pFile);

		for (int i = 0; i < iStudentCount; ++i) {
			// �л� ����ü�� ������ �����Ѵ�.
			fwrite(&tStudent[i], sizeof(STUDENT), 1, pFile);
		}
		fclose(pFile);
	}
}
