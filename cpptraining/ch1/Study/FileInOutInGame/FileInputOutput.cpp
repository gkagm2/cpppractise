#include <iostream>

using namespace std;
	
void ReadFile(FILE *pFile) {
	// =============== ���� �б� ===================
	fopen_s(&pFile, "studentList.txt", "rt");
	if (pFile) {
		char strText[5] = {};
		fread(strText, 1, 4, pFile);

		cout << strText << endl;

		fclose(pFile);
	}
}


void WriteFile(FILE *pFile) {
	// ================ ���� ���� =================

	// 1�� ���� : ������ �����������̴�
	// 2�� ���� : ���� ����̴�. ������ �����Ǵ� ���� ��δ� ���� ������Ʈ�� �ִ� ���� �����̴�. ���� �������Ϸ� �������� ��쿡��
	// �ش� exe������ �ִ� ��θ� �������� �������ش�.
	// 3�� ���� : ���� ����̴�. ���� ũ�� 2������ ���еȴ�.
	// ���� �б�, ����, ������ �ְ� ���� ����, �ؽ�Ʈ����, ���̳ʸ����� 2���� ��尡 �־ ���ļ� ����Ѵ�.
	// r : �б�, w : ����, a : ����		  t : �ؽ�Ʈ ����, b : ���̳ʸ� ����
	fopen_s(&pFile, "studentList.txt", "wt");

	if (pFile != NULL) {
		// fwrite, fread 2���� �Լ��� �����ȴ�.
		// fputs, fgets�� �����ȴ�.
		const char* pText = "abcd";

		// 1�����ڴ� �����ϰ��� �ϴ� ���� �޸� �ּҸ� �־��ش�.
		// 2�����ڴ� �����ϰ��� �ϴ� ���� ����Ÿ���� �޸� ũ�⸦ �־��ش�.
		// 3�����ڴ� �����ϰ��� �ϴ� ���� ������ �־��ش�.
		// 4�����ڴ� ������ ������ ��Ʈ���� �־��ش�.
		fwrite(pText, 1, 4, pFile);

		fclose(pFile);
	}
}

int main() {
	FILE* pFile = NULL;

	// C ����
	WriteFile(pFile);
	ReadFile(pFile);

	return 0;
}