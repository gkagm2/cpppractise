#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

// TODO (Sagacity Jang) : ���̳ʸ� ���Ϸ� ó���غ���


// C++  fstream�� ����� �̿��Ͽ� CRUD �غ���

enum MENU {
	M_NONE,
	M_ADD,
	M_SHOW,
	M_DELETE,
	M_SAVE,
	M_END
};

#define NAME_SIZE 30

struct _tagData {
	char strName[NAME_SIZE];
	int iNumber;
};

int InputInt() {
	int iInput;
	cin >> iInput;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return iInput;
}

void InputString(char* strString, int iSize) {
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(strString, iSize - 1);
}

// ����
void Show(_tagData* pData, int maxSize) {
	system("cls");
	cout << "========== ���� ==========" << endl;
	for (int i = 0; i < maxSize; ++i) {
		cout << "�̸� : " << pData[i].strName << "\t���� : " << pData[i].iNumber << endl;
	}
	system("pause");
}

class Crud{
private:
	string strFilePath;

	list<_tagData> dataList;
public:
	Crud() {
		strFilePath = "Study/FileInOut/FileTest.txt"; // ���� ��� ����
		Load();
	}
	void Create();
	void Show();
	void Delete();

	void Save();
	void Load();
};

void Crud::Create() {
	_tagData tData;
	while (true) {
		system("cls");
		cout << "========== �߰� ========" << endl;

		cout << " �̸��� �Է��ϼ��� : ";
		InputString(tData.strName, NAME_SIZE);

		cout << "���ڸ� �Է��ϼ��� : ";
		tData.iNumber = InputInt();
		if (tData.iNumber == INT_MAX) { // �߸� �Է� ��
			continue;
		}
		break;
	}
	dataList.push_back(tData);
	cout << "�����͸� �߰��Ͽ����ϴ�." << endl;
	system("pause");
}

void Crud::Show() {
	system("cls");
	cout << "============= ���� ============" << endl;
	list<_tagData>::iterator iter = dataList.begin();
	for (iter; iter != dataList.end(); ++iter) {
		_tagData &tData = *iter;
		cout << "�̸� : "<< tData.strName << "\t���� : " << tData.iNumber << endl;
	}
	system("pause");
}

void Crud::Delete() {
	system("cls");
	cout << "=========== ���� ===========" << endl;
	cout << "������ �̸��� �Է��ϼ��� : ";

	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);
	list<_tagData>::iterator iter = dataList.begin();
	for (iter; iter != dataList.end(); ++iter) {
		_tagData &tData = *iter;
		if (strcmp(tData.strName, strName) == 0) {
			dataList.erase(iter);
			cout << strName << " �� �����߽��ϴ�." << endl;
			system("pause");
			return;
		}
	}
	cout << "������ �����͸� ã�� ���߽��ϴ�." << endl;
	system("pause");
}

void Crud::Save() {
	ofstream fout; // ���� ����
	
	fout.open(strFilePath, ios_base::out);
	if (!fout.is_open()) {
		cout << "������ �� �� �����ϴ�." << endl;
		fout.close();
		return;
		system("pause");
	}
	else {
		list<_tagData>::iterator iter = dataList.begin();
		for (iter; iter != dataList.end(); ++iter) {
			_tagData tData = *iter;
			fout << tData.strName;
			fout << tData.iNumber;
		}
		cout << "������ �Ϸ��߽��ϴ�." << endl;
		system("pause");
	}
}
void Crud::Load() {
	// c++ type
	ifstream fin; // ���� �б�
	
	fin.open(strFilePath, ios_base::in); //only read
	if (!fin.is_open()) {
		cout << "���� ������ �� �� �����ϴ�. ���� �����մϴ�." << endl;
		fin.open(strFilePath, ios_base::out || ios_base::trunc);
		if (!fin.is_open()) {
			cout << strFilePath << " ��ο� ������ �����Ͽ����ϴ�." << endl;
		}
		fin.close();
		system("pause");
	}
	else {
		cout << "���Ͽ� �ִ� �����͵��� �ҷ��ɴϴ�." << endl;
		

		// TODO (Sagacity Jang) : �Է� �κ� ��ġ��
		_tagData tData;
		fin >> tData.strName;
		fin >> tData.iNumber;
		dataList.push_back(tData);
		cout << "�ҷ��� ������ �̸� : " << tData.strName << " ���� : " << tData.iNumber << endl;
		fin.close();
		system("pause");
	}
}

int main() {
	ifstream ifs;
	ifs.open("", ios_base::in || ios_base::trunc);

	Crud crud;

	while (true) {
		system("cls");
		cout << "========== ���� ==========" << endl;
		cout << "�޴��� �Է��ϼ���" << endl;
		cout << "1. �߰�" << endl;
		cout << "2. ����" << endl;
		cout << "3. �����ϱ�" << endl;
		cout << "4. ����" << endl;
		cout << "5. ������" << endl;
		
		int iMenu = InputInt();
		if (iMenu == INT_MAX) {
			continue;
		}
		switch (iMenu) {
		case M_ADD:
			crud.Create();
			break;
		case M_DELETE:
			crud.Delete();
			break;
		case M_SHOW:
			crud.Show();
			break;
		case M_SAVE:
			crud.Save();
			break;
		case M_END:
			exit(1);
			break;
		}
	}

	return 0;
}