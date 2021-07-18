#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <stack>
#include <typeinfo>
using namespace std;

// using uncode (wstring)

struct DataType {
	int a;
	float b;
};

UINT a = 6;
UINT b = 66;
DataType d = { 10, 30.f };
wstring str = L"Hello world";


// data write, read
template<typename T>
size_t FWrite(T& _data, FILE* _pFile, UINT _iElementCount = 1) {
	return fwrite(&_data, sizeof(T), _iElementCount, _pFile);
}

template<typename T>
size_t FRead(T& _data, FILE* _pFile, UINT _iElementCount = 1) {
	return fread(&_data, sizeof(T), _iElementCount, _pFile);
}

// string write, read
void SaveStringToFile(const wstring& _str, FILE* _pFile)
{
	size_t iLen = _str.length();
	fwrite(&iLen, sizeof(size_t), 1, _pFile);
	fwrite(_str.data(), sizeof(wchar_t), iLen, _pFile);
}

void LoadStringFromFile(wstring& _str, FILE* _pFile)
{
	wchar_t szBuffer[255] = {};
	size_t iLen = 0;
	fread(&iLen, sizeof(size_t), 1, _pFile);
	fread(szBuffer, sizeof(wchar_t), iLen, _pFile);
	_str = szBuffer;
}

void save() {
	errno_t err;
	wstring path = L"N:\\scene.txt";
	FILE* pFile = nullptr;
	err = _wfopen_s(&pFile, path.c_str(), L"wb");
	if (err) {
		wcout << L" err\n";
		fclose(pFile);
		return;
	}

	FWrite(a, pFile);
	//fwrite(&a, sizeof(UINT), 1, pFile);
	FWrite(b, pFile);
	//fwrite(&b, sizeof(UINT), 1, pFile);
	FWrite(d, pFile);
	//fwrite(&d, sizeof(DataType), 1, pFile);

	SaveStringToFile(str, pFile);

	fclose(pFile);
}
void load() {
	errno_t err;
	wstring path = L"N:\\scene.txt";
	FILE* pFile = nullptr;
	err = _wfopen_s(&pFile, path.c_str(), L"rb");
	if (err) {
		wcout << L" err\n";
		fclose(pFile);
		return;
	}

	FRead(a, pFile);
	//fread(&a, sizeof(UINT), 1, pFile);
	FRead(b, pFile);
	//fread(&b, sizeof(UINT), 1, pFile);
	FRead(d, pFile);
	//fread(&d, sizeof(DataType), 1, pFile);

	LoadStringFromFile(str, pFile);

	fclose(pFile);
}

int main() {
	save();

	a = 1, b = 1;
	d.a = 1;
	d.b = 1.f;
	str = L"";

	load();

	wcout << str << L"\n";

	return 0;
}