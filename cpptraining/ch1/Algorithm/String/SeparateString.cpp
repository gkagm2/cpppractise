// Ư���� ���ؿ� ���� ���ڿ� ������
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <tchar.h>

int _tmain(int argc, TCHAR* argv[]) {
	TCHAR str[] = _T("Hello world nice to meet you\nwow\tthis\tnice"); // ���ڿ�
	TCHAR sep[] = _T("\t\n"); // �и� �� ���� ' '�� '\t'�� '\n'�� ���� �и��Ѵ�.

	TCHAR* token;
	token = _tcstok(str, sep); // ���ڿ��� ���ؿ� ���� token�� �ӽ� ����.
	while (token != NULL) {
		_tprintf(_T("%s\n"), token); // ���ؿ� ���� ���� ���ڿ� ���.
		token = _tcstok(NULL, sep); // ���� ���ڿ��� ����.
	}

	return 0;
}

/*
#include <string.h>
#include <stdio.h>

char string[] = "A string\tof ,,tokens\nand some  more tokens";
char seps[]   = " ,\t\n";
char *token;

int main( void )
{
   printf( "Tokens:\n" );

   // Establish string and get the first token:
   token = strtok( string, seps ); // C4996
   // Note: strtok is deprecated; consider using strtok_s instead
   while( token != NULL )
   {
	  // While there are tokens in "string"
	  printf( " %s\n", token );

	  // Get next token:
	  token = strtok( NULL, seps ); // C4996
   }
}
*/