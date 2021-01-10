// 특정한 기준에 따라 문자열 나누기
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <tchar.h>

int _tmain(int argc, TCHAR* argv[]) {
	TCHAR str[] = _T("Hello world nice to meet you\nwow\tthis\tnice"); // 문자열
	TCHAR sep[] = _T("\t\n"); // 분리 할 문자 ' '나 '\t'나 '\n'이 오면 분리한다.

	TCHAR* token;
	token = _tcstok(str, sep); // 문자열을 기준에 따라 token에 임시 저장.
	while (token != NULL) {
		_tprintf(_T("%s\n"), token); // 기준에 의해 나누 문자열 출력.
		token = _tcstok(NULL, sep); // 다음 문자열을 구함.
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