#include <iostream>
using namespace std;

#define NAME_SIZE 20

// hash
#define HASHTABLE_SIZE 30

typedef struct tStudent {
	char name[NAME_SIZE];
	int age;
	int number;
	tStudent *next;
}STUDENT, *PSTUDENT;

STUDENT *hashTable[HASHTABLE_SIZE];

enum E_MENU{
	e_none,
	e_insert,
	e_delete,
	e_find,
	e_list,
	e_exit
};

int HashFunction(char *str) {
	// 문자값을 모두 더함.
	int sum = 0;
	int length = strlen(str);

	for (int i = 0; i < length; ++i) {
		sum += str[i];
	}
	return sum % HASHTABLE_SIZE;
}

void Insert(char *name, int age, int number) {
	PSTUDENT curNode;
	int idx;

	curNode = new STUDENT();
	strcpy_s(curNode->name, name);
	curNode->age = age;
	curNode->number = number;
	curNode->next = NULL;

	idx = HashFunction(name);

	// collision이 아닐 경우
	if (hashTable[idx] == 0) {
		hashTable[idx] = curNode;
		return;
	}

	// collision 생겼을 경우

	// chaining
	STUDENT *iter = hashTable[idx]; // 첫번째 노드르 불러온다.
	curNode->next = iter; // 새로운 노드의 next를 첫번째 노드로 연결
	hashTable[idx] = curNode; // 노드의 맨 앞에 삽입
}

void Delete() {

}

void Find(char *name) {
	// 이름을 찾는다.
	int idx;
	idx = HashFunction(name);

	STUDENT *cur;
	cur = hashTable[idx];
	
	// 없으면
	if (cur == 0) {
		cout << "데이터가 없습니다." << endl;
		system("pause");
		return;
	}
	
	while (strcmp(cur->name, name) != 0) { // 같지 않으면
		cur = cur->next;
		if (cur == 0) {
			cout << "데이터가 없습니다." << endl;
			system("pause");
			return;
		}
	}

	// 이름에 해당하는 데이터가 있으면 출력한다.
	cout << "학생 이름 : " << cur->name << "\t 나이 : " << cur->age << "\t 번호 : " << cur->number << endl;
	system("pause");
}

void ShowList() {

}

template <typename T>
T Input() {
	T data;
	cin >> data;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return 0;
	}
	return data;
}


void InputString(char *pString, int iSize) {
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);
}


// 해싱을 이용한 학생 데이터 관리
int main() {
	while (true) {
		system("cls");

		cout << "1. 삽입, 2. 삭제, 3. 조회, 4. 목록, 5. 종료" << endl;
		int iMenu;
		cin >> iMenu;
		if (iMenu == e_exit) {
			break;
		}
		switch (iMenu) {
		case e_insert: 
			{
			char name[NAME_SIZE];
			int age;
			int number;
			cout << "이름 : ";
			InputString(name, NAME_SIZE);
			cout << "나이 : ";
			age = Input<int>();
			cout << "학생 번호 : ";
			number = Input<int>();

			Insert(name, age, number);

			cout << "삽입 완료" << endl;
			system("pause");
			}
			
			break;
		case e_delete:
			Delete();
			break;
		case e_find: 
			{
			cout << " 찾은 데이터 이름을 입력하세요 : ";
			char name[NAME_SIZE];
			InputString(name, NAME_SIZE);
			Find(name);
			}
			
			break;
		case e_list:
			ShowList();
			break;
		}
	}
	return 0;
}