#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

// TODO (Sagacity Jang) : 바이너리 파일로 처리해보기


// C++  fstream의 기능을 이용하여 CRUD 해보기

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

// 보기
void Show(_tagData* pData, int maxSize) {
	system("cls");
	cout << "========== 보기 ==========" << endl;
	for (int i = 0; i < maxSize; ++i) {
		cout << "이름 : " << pData[i].strName << "\t숫자 : " << pData[i].iNumber << endl;
	}
	system("pause");
}

class Crud{
private:
	string strFilePath;

	list<_tagData> dataList;
public:
	Crud() {
		strFilePath = "Study/FileInOut/FileTest.txt"; // 저장 경로 설정
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
		cout << "========== 추가 ========" << endl;

		cout << " 이름을 입력하세요 : ";
		InputString(tData.strName, NAME_SIZE);

		cout << "숫자를 입력하세요 : ";
		tData.iNumber = InputInt();
		if (tData.iNumber == INT_MAX) { // 잘못 입력 시
			continue;
		}
		break;
	}
	dataList.push_back(tData);
	cout << "데이터를 추가하였습니다." << endl;
	system("pause");
}

void Crud::Show() {
	system("cls");
	cout << "============= 보기 ============" << endl;
	list<_tagData>::iterator iter = dataList.begin();
	for (iter; iter != dataList.end(); ++iter) {
		_tagData &tData = *iter;
		cout << "이름 : "<< tData.strName << "\t숫자 : " << tData.iNumber << endl;
	}
	system("pause");
}

void Crud::Delete() {
	system("cls");
	cout << "=========== 삭제 ===========" << endl;
	cout << "삭제할 이름을 입력하세요 : ";

	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);
	list<_tagData>::iterator iter = dataList.begin();
	for (iter; iter != dataList.end(); ++iter) {
		_tagData &tData = *iter;
		if (strcmp(tData.strName, strName) == 0) {
			dataList.erase(iter);
			cout << strName << " 을 삭제했습니다." << endl;
			system("pause");
			return;
		}
	}
	cout << "삭제할 데이터를 찾지 못했습니다." << endl;
	system("pause");
}

void Crud::Save() {
	ofstream fout; // 파일 쓰기
	
	fout.open(strFilePath, ios_base::out);
	if (!fout.is_open()) {
		cout << "파일을 쓸 수 없습니다." << endl;
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
		cout << "저장을 완료했습니다." << endl;
		system("pause");
	}
}
void Crud::Load() {
	// c++ type
	ifstream fin; // 파일 읽기
	
	fin.open(strFilePath, ios_base::in); //only read
	if (!fin.is_open()) {
		cout << "저장 파일을 열 수 없습니다. 새로 생성합니다." << endl;
		fin.open(strFilePath, ios_base::out || ios_base::trunc);
		if (!fin.is_open()) {
			cout << strFilePath << " 경로에 파일을 생성하였습니다." << endl;
		}
		fin.close();
		system("pause");
	}
	else {
		cout << "파일에 있는 데이터들을 불러옵니다." << endl;
		

		// TODO (Sagacity Jang) : 입력 부분 고치기
		_tagData tData;
		fin >> tData.strName;
		fin >> tData.iNumber;
		dataList.push_back(tData);
		cout << "불러온 데이터 이름 : " << tData.strName << " 숫자 : " << tData.iNumber << endl;
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
		cout << "========== 메인 ==========" << endl;
		cout << "메뉴를 입력하세요" << endl;
		cout << "1. 추가" << endl;
		cout << "2. 보기" << endl;
		cout << "3. 삭제하기" << endl;
		cout << "4. 저장" << endl;
		cout << "5. 끝내기" << endl;
		
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