// PROGRAM : 학생관리 프로그램
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
		// 메뉴 출력
		cout << "1. 학생등록" << endl;
		cout << "2. 학생삭제" << endl;
		cout << "3. 학생탐색" << endl;
		cout << "4. 학생출력" << endl;
		cout << "5. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;

		// 정수가 아닌 문자 입력시 예외처리
		if (cin.fail()) { // cin.fail() : 입력에러 발생 시 true 리턴
			cin.clear(); // 에러버퍼 비우기

			cin.ignore(1024, '\n'); // 파라미터1 : 검색하고자 하는 버퍼 크기(1024 byte 지정), 파라미터2 : 찾고자 하는 문자
			continue;
		}
		
		if (iMenu == MENU_EXIT) {
			break;
		}

		switch (iMenu) {
		case MENU_INSERT:
			system("cls");
			cout << "==========  학생 추가 ==========" << endl;
			// 학생정보 추가.
			// 국, 영, 수 점수는 입력받고  학번, 총점, 평군은 연산을 통해 계산.
			cin.ignore(1024, '\n');
			cout << "이름 : ";
			cin >> tStudentArr[iStudentCount].strName;

			cin.ignore(1024, '\n');

			cout << "주소 : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

			cout << "전화번호 : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

			cout << "학번 : ";
			cin >> tStudentArr[iStudentCount].iNumber;

			cout << "국어 : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "영어 : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "수학 : ";
			cin >> tStudentArr[iStudentCount].iMath;
			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3.f;

			tStudentArr[iStudentCount].iNumber = iStdNumber;

			++iStdNumber;
			++iStudentCount;

			cout << "학생 추가 완료" << endl;
			break;
		case MENU_DELETE:
			system("cls");

			cout << "========== 학생삭제 ==========" << endl;
			cin.ignore(1024, '\n');
			cout << "삭제할 이름을 입력하세요 : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iStudentCount; ++i) {
				// 학생을 찾았을 경우
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					for (int j = i; j < iStudentCount - 1; ++j) {
						tStudentArr[j] = tStudentArr[j + 1];
					}
					--iStudentCount;
					cout << "학생을 삭제하였습니다." << endl;
					break;
				}
			}



			break;
		case MENU_SEARCH:
			system("cls");

			cout << "========== 학생탐색 ==========" << endl;
			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요 : ";
			cin.getline(strName, NAME_SIZE);

			// Search
			for (int i = 0; i < STUDENT_MAX; ++i) {
				//같으면
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					cout << "이름 : " << tStudentArr[i].strName << endl;
					cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
					cout << "주소 : " << tStudentArr[i].strAddress << endl;
					cout << "학번 : " << tStudentArr[i].iNumber << endl;
					cout << "국어 : " << tStudentArr[i].iKor << endl;
					cout << "영어 : " << tStudentArr[i].iEng << endl;
					cout << "수학 : " << tStudentArr[i].iMath << endl;
					cout << "총점 : " << tStudentArr[i].iTotal << endl;
					cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
					break;
				}
			}

			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "========== 학생출력 ==========" << endl;

			// 등록된 학생이 등록할 수 있는 최대치일 경우 더이상 등록이 안되게 막는다.
			if(iStudentCount == STUDENT_MAX) {
				break;
			}

			// 등록된 학생 수만큼 반복하여 학생정보를 출력한다.
			for (int i = 0; i < iStudentCount; ++i) {
				cout << "이름 : " << tStudentArr[i].strName << endl;
				cout << "전화번호 : " << tStudentArr[i].strPhoneNumber<< endl;
				cout << "주소 : " << tStudentArr[i].strAddress << endl;
				cout << "학번 : " << tStudentArr[i].iNumber << endl;
				cout << "국어 : " << tStudentArr[i].iKor << endl;
				cout << "영어 : " << tStudentArr[i].iEng << endl;
				cout << "수학 : " << tStudentArr[i].iMath << endl;
				cout << "총점 : " << tStudentArr[i].iTotal << endl;
				cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
			}
			break;
		default:
			cout << "메뉴를 잘못 선택했습니다." << endl;
			break;
		}
		system("pause");
	}

	return 0;
}