#include <iostream>
using namespace std;

// 토글 테크닉 
void ToggleEx3() {
	// 참조표(Look up tagble)를 이용한 개선된 코드
	char table[][7] = { // 
		"목메달",
		"동메달",
		"은메달",
		"금메달"
	};
	// 0 : 목메달, 1 : 동메달, 2 : 은메달, 3 :금메달

	// 토글 테크닉
	int i;
	int bWork = 1, bLove = 1;
	i = (bWork << 1) | bLove;
	cout << table[i] << "\n";


	/* 보통 코드
	int bWork = 0, bLove = 0;
	int i;
	if (bWork == 1 && bLove == 1) i = 0;
	else if (bWork == 0 && bLove == 1) i = 1;
	else if (bWork == 1 && bLove == 0) i = 2;
	else if (bWork == 1 && bLove == 1) i = 3;

	if (i == 0) cout << "목메달\n";
	else if (i == 1) cout << "동메달\n";
	else if (i == 2) cout << "은메달\n";
	else if (i == 3)cout << "금메달\n";
	*/
}

void ToggleEx2() {
	int toggle[] = { 10,20,30,40 }; // 불규칙한 번호에 10 -> 20 ->30 -> 40 -> 10 순서대로라면 
	int i, j = 3;
	i = (j + 1) % 4; // j값에 따라 순서대로 토글 됨.
	cout << i << "\n";
	j = toggle[i];

	cout << j;
}


void ToggleEx() {
	int toggle[] = { 512, 1024, 2222, 3333, 9090, 2020 };
	int i = 5, j;
	i ^= 1; // 이렇게 하면 i가 0일경우 1, 1일경우 0, 2일경우 3, 3일경우 2, 4일경우 5, 5일경우 4임.
	j = toggle[i];

	cout << j;
}

int main() {
	ToggleEx3();
	ToggleEx2();
	ToggleEx();

	return 0;
}
