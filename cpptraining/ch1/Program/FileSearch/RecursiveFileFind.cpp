// 시작 디렉토리부터 지정한 파일을 서브 디렉토리 모두를 뒤져 찾아내는 프로그램
// preorder나 postorder밖에 못함. inorder는 하지 못합니다.

#include <iostream>
#include <Windows.h>
#include <tchar.h>
using namespace std;

void FindFile(const TCHAR* szMask) {
	TCHAR szPath[MAX_PATH]; // 현재의 경로를 저장할 공간
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
	GetCurrentDirectory(sizeof(szCurDir), szCurDir); // 현재 작업 디렉터리를 가져옵니다.
	SetCurrentDirectory(argv[2]); // 현재 디렉터리를 설정한다.
	FindFile(argv[1]);
	SetCurrentDirectory(szCurDir); // 애플리케이션의 현재 작업 디렉터리를 지정된 디렉터리로 설정합니다.

	return 0;
}