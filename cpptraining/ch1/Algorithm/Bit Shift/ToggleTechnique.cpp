#include <iostream>
using namespace std;

// ��� ��ũ�� 
void ToggleEx3() {
	// ����ǥ(Look up tagble)�� �̿��� ������ �ڵ�
	char table[][7] = { // 
		"��޴�",
		"���޴�",
		"���޴�",
		"�ݸ޴�"
	};
	// 0 : ��޴�, 1 : ���޴�, 2 : ���޴�, 3 :�ݸ޴�

	// ��� ��ũ��
	int i;
	int bWork = 1, bLove = 1;
	i = (bWork << 1) | bLove;
	cout << table[i] << "\n";


	/* ���� �ڵ�
	int bWork = 0, bLove = 0;
	int i;
	if (bWork == 1 && bLove == 1) i = 0;
	else if (bWork == 0 && bLove == 1) i = 1;
	else if (bWork == 1 && bLove == 0) i = 2;
	else if (bWork == 1 && bLove == 1) i = 3;

	if (i == 0) cout << "��޴�\n";
	else if (i == 1) cout << "���޴�\n";
	else if (i == 2) cout << "���޴�\n";
	else if (i == 3)cout << "�ݸ޴�\n";
	*/
}

void ToggleEx2() {
	int toggle[] = { 10,20,30,40 }; // �ұ�Ģ�� ��ȣ�� 10 -> 20 ->30 -> 40 -> 10 ������ζ�� 
	int i, j = 3;
	i = (j + 1) % 4; // j���� ���� ������� ��� ��.
	cout << i << "\n";
	j = toggle[i];

	cout << j;
}


void ToggleEx() {
	int toggle[] = { 512, 1024, 2222, 3333, 9090, 2020 };
	int i = 5, j;
	i ^= 1; // �̷��� �ϸ� i�� 0�ϰ�� 1, 1�ϰ�� 0, 2�ϰ�� 3, 3�ϰ�� 2, 4�ϰ�� 5, 5�ϰ�� 4��.
	j = toggle[i];

	cout << j;
}

int main() {
	ToggleEx3();
	ToggleEx2();
	ToggleEx();

	return 0;
}
