#include <iostream>
using namespace std;

////Hashing
//typedef int element;
//
//class Node {
//public:
//	element m_tData;
//	Node *m_pNext;
//};
//
//class LinkedList {
//public:
//	Node *m_pBegin;
//	int m_iSize;
//
//	LinkedList() : m_pBegin(NULL){
//	}
//	~LinkedList() {
//		delete m_pBegin;
//	}
//
//	void Insert(element data) {
//		Node *newNode = new Node();
//		newNode->m_tData = data;
//		newNode->m_pNext = NULL;
//
//		
//		// �ƹ��͵� ���� ���.
//		if (m_iSize == 0) {
//			m_pBegin = newNode;
//			
//		}
//		// �Ѱ� �̻��� ���
//		else {
//			Node *iterNode = m_pBegin; // �� ������ ��忡 �߰��Ѵ�.
//			while (iterNode->m_pNext != NULL) {
//				iterNode = iterNode->m_pNext;
//			}
//			iterNode->m_pNext = newNode;
//		}
//		++m_iSize;
//	}
//
//	element Delete(element data) {
//	}
//};

typedef struct tStudent {
	char name[20];
	int age;
	int number;
	tStudent *next;
}STUDENT, *PSTUDENT;

#define HASHTABLE_SIZE 30
STUDENT *hashTable[HASHTABLE_SIZE];

enum E_MENU{
	e_exit,
	e_insert,
	e_delete,
	e_find,
	e_list
};

int HashFunction(char *str) {
	// ���ڰ��� ��� ����.
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
	strcpy(curNode->name, name);
	curNode->age = age;
	curNode->number = number;
	curNode->next = NULL;

	idx = HashFunction(name);

	// collision�� �ƴ� ���
	if (hashTable[idx] == 0) {
		hashTable[idx] = curNode;
		return;
	}

	// collision ������ ���
	// chaining
	STUDENT *iter = hashTable[idx];
	while (iter->next != NULL) { // �� ������ ��带 ã��.
		iter = iter->next;
	}
	iter->next = curNode; // ����� �� ���� ����
}

void Delete() {

}

void Find() {

}

void ShowList() {

}


// �ؽ��� �̿��� �л� ������ ����
int main() {
	while (true) {
		system("cls");

		cout << "1. ����, 2. ����, 3. ��ȸ, 4. ���, 0. ����" << endl;
		int iMenu;
		cin >> iMenu;
		if (iMenu == e_exit) {
			break;
		}
		switch (iMenu) {
		case e_insert:
			Insert();
			break;
		case e_delete:
			Delete();
			break;
		case e_find:
			Find();
			break;
		case e_list:
			ShowList();
			break;
		}
	}
	return 0;
}