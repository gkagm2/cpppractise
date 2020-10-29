#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define WIDTH_SIZE 5
#define HEIGHT_SIZE 5

// 보드를 출력한다.
void PrintBoard(int *arr, int widthSize, int heightSize) {
	int x;
	int y;

	printf("============ 보드 출력 ===========\n");
	for (y = 0; y < heightSize; ++y) {
		for (x = 0; x < widthSize; ++x) {
			printf("%d\t", arr[y * WIDTH_SIZE + x]);
		}
		printf("\n");
	}
}

// 보드를 초기화 한다.
void InitBoard(int *arr, int size) {
	int i;

	for (i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}
}

// 숫자를 대입한다.
void InsertNumber(int *arr, int iX, int iY, int iNum) {
	arr[iY * WIDTH_SIZE + iX] = iNum;
}

int main() {
	int arr[WIDTH_SIZE * HEIGHT_SIZE];
	int iInputX;
	int iInputY;
	int iNum;

	InitBoard(arr, WIDTH_SIZE * HEIGHT_SIZE);
	
	while(TRUE) {
		system("cls");
		PrintBoard(arr, WIDTH_SIZE, HEIGHT_SIZE);

		printf("x값, y값, 바꿀 숫자를 입력하세요>");
		scanf_s("%d %d %d", &iInputX, &iInputY, &iNum);

		InsertNumber(arr, iInputX, iInputY, iNum);

	    system("pause");
	}
}