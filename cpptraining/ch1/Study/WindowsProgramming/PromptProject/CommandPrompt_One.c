// ���ڱ� �ý��� ���α׷���
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <locale.h>
#include <windows.h>

#define STR_LEN 256
#define CMD_TOKEN_NUM 10

TCHAR ERROR_CMD[] = _T("'%s'��(��) ������ �� �ִ� ���α׷��� �ƴմϴ�.\n");

int CmdProcessing();
TCHAR* StrLower(TCHAR *);

int _tmain(int argc, TCHAR *argv[]) {
	// �ѱ� �Է��� ������ �ϱ�����
	_tsetlocale(LC_ALL, _T("Korean"));

	DWORD isExit;
	while (1) {
		isExit = CmdProcessing();
		if (isExit == TRUE) {
			_fputts(_T("��ɾ� ó���� �����մϴ�.\n"), stdout);
			break;
		}
		return 0;
	}
}

TCHAR cmdString[STR_LEN];
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");


// ��ɾ �Է¹޾� �ش� ��ɾ �����Ǿ� �ִ� ����� ����.
// return : exit�Է½� true ��ȯ.
int CmdProcessing() {
	_fputts(_T("Best Command prompt>> "), stdout);
	_fgetts(cmdString,1024, stdin); // 20210101 fixed: original code -> _getts(cmdString);

	TCHAR *token = _tcstok(cmdString, seps);
	int tokenNum = 0;
	while (token != NULL) {
		_tcscpy(cmdTokenList[tokenNum++], StrLower(token));
		token = _tcstok(NULL, seps);
	}

	if (!_tcscmp(cmdTokenList[0], _T("exit")))
		return TRUE;
	else if (!_tcscmp(cmdTokenList[0], _T("�߰� �Ǵ� ��ɾ� 1"))) {

	}
	else if (!_tcscmp(cmdTokenList[0], _T("�߰� �Ǵ� ��ɾ� 2"))) {

	}
	else {
		_tprintf(ERROR_CMD, cmdTokenList[0]);
	}
	return FALSE;
}

// ���ڿ��� ���� �����ϴ� ��� �빮�ڸ� �ҹ��ڷ� �����Ѵ�.
// return : ����� ���ڿ��� �����͸� ��ȯ.
TCHAR* StrLower(TCHAR *pStr) {
	TCHAR *ret = pStr;
	while (*pStr != '\0') {
		if (_istupper(*pStr))
			*pStr = _totlower(*pStr);
		++pStr;
	}
	return ret;
}