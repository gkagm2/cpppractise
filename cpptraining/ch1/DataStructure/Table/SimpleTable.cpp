
// 테이블에 관한 간단한 예제

#include <iostream>
using namespace std;
typedef struct t_stduentInfo{
	int iNum;
	int iAge;
}StudentInfo;

int main() {
	// algorithm 문제를 풀 경우. 속도를 위해 사용
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	/////////////////////////////
	
	StudentInfo studentInfoArr[1000] = {};
	StudentInfo student;
	int iStudentNum;

	while (true) {
		system("cls");
		cout << "학생 번호, 나이 입력 : ";
		cin >> student.iNum;
		cin >> student.iAge;
		if (student.iNum < 0 || student.iNum >= 1000) {
			cout << "학생 번호 범위는 0 ~ 1000까지 입니다." << endl;
			system("pause");
			continue; 
		}
		break;
	}
	
	studentInfoArr[student.iNum] = student; // 바로 인덱스값으로 저장

	cout << "확인하고자 하는 학생의 번호 입력 : ";
	cin >> iStudentNum;

	student = studentInfoArr[iStudentNum]; // 학생 번호가 인덱스값이므로 바로 탐색
	cout << student.iNum << "의 번호를 가진 학생의 나이는 " << student.iAge << "입니다." << endl;

	return 0;
}