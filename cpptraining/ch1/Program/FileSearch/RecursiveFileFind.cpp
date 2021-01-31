// ���� ���丮���� ������ ������ ���� ���丮 ��θ� ���� ã�Ƴ��� ���α׷�
// preorder�� postorder�ۿ� ����. inorder�� ���� ���մϴ�.

#include <iostream>
#include <Windows.h>
#include <tchar.h>
using namespace std;

void FindFile(const TCHAR* szMask) {
	TCHAR szPath[MAX_PATH]; // ������ ��θ� ������ ����
	WIN32_FIND_DATA fd;
	HANDLE hFile;
	hFile = FindFirstFile(szMask, &fd);
	if (hFile != INVALID_HANDLE_VALUE) {
		do {
			GetCurrentDirectory(sizeof(szPath), szPath);
			cout << szPath << "\\" << fd.cFileName;
		} while (FindNextFile(hFile, &fd));
		FindClose(hFile);
	}
	hFile = FindFirstFile(_T("*.*"), &fd);
	if (hFile != INVALID_HANDLE_VALUE) {
		do {
			if (fd.cFileName[0] == '.' || (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
				continue;
			SetCurrentDirectory(_T(".."));
			FindFile(szMask);
		} while (FindNextFile(hFile, &fd));
		FindClose(hFile);
	}
}

int _tmain(int argc, TCHAR* argv[]) {
	if (argc < 3) {
		cout << "Usage : RecursiveFileFind [File Mask] [From Directory]\n";
		exit(0);
	}

	TCHAR szCurDir[MAX_PATH];
	GetCurrentDirectory(sizeof(szCurDir), szCurDir); // ���� �۾� ���͸��� �����ɴϴ�.
	SetCurrentDirectory(argv[2]); // ���� ���͸��� �����Ѵ�.
	FindFile(argv[1]);
	SetCurrentDirectory(szCurDir); // ���ø����̼��� ���� �۾� ���͸��� ������ ���͸��� �����մϴ�.

	return 0;
}