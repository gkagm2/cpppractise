// title : 배열을 이용한 힙
// Date : 20210218
// Developer : Sagacity Jang

#include <iostream>
using namespace std;

typedef int Data;
// Full binary tree 사용

void UpHeap(Data _a[], int _idx) {
	// 맨 밑 마지막 노드에서부터 올라가며 자기 위치를 찾아 바꾼다.
	Data data = _a[_idx];
	while (_a[_idx / 2] <= data && _idx > 1) {
		_a[_idx] = _a[_idx / 2]; // 부모노드의 데이터를 현재노드의 데이터로 바꿈
		_idx /= 2;
	}

	_a[_idx] = data;
}

void DownHeap(Data _a[], int _lastIdx, int _idx) {
	Data data = _a[_idx];
	while (_idx <= (_lastIdx + 1) / 2) { // 내부노드일 경우만
		int childIdx = _idx * 2; // 왼쪽 자식
		if (childIdx < _lastIdx) {
			int leftChild = _a[childIdx];
			int rightChild = _a[childIdx + 1];
			childIdx = leftChild < rightChild ? childIdx : childIdx + 1; // 두 자식중 큰 것 선택
			++childIdx;
		}
		if (data > _a[childIdx]) // 자식의 값보다 크면 종료
			break;
		_a[_idx] = _a[childIdx];
		_idx *= childIdx;
	}
}

///////////// Operations //////////////
// 생성(Construct)
void Construct() {

}
// 삽입(Insert)
void Insert(Data _a[], int& _Idx, Data _data) {
	_a[++_Idx] = _data; // 노드 추가
	UpHeap(_a, _Idx); // 추가된 노드 UpHeap
}
// 제거(Remove)
void Remove() {

}
// 대치(Replace)
void Replace(){
	 
}
// 변경(Change)
void Change() {

}
// 삭제(Delete)
void Delete() {

}
// 결합(Join)
void Join() {

}
// 추출(Exract)
Data Extract(Data _a[], int& _idx) {
	Data data = _a[1]; // 최상위 노드를 뽑음.
	_a[1] = _a[_idx--]; // 맨 마지막 노드를 최상위 노드에 넣으줌.
	DownHeap(_a, _idx, 1); // 루트 노드를 DownHeap

	return data;
}



int main() {
	Data heapArr[200]{};
	int lastIdx = 1;
	Insert(heapArr, lastIdx, 30);
	Insert(heapArr, lastIdx, 10);
	Insert(heapArr, lastIdx, 60);
	Insert(heapArr, lastIdx, 7);
	Insert(heapArr, lastIdx, 15);
	Insert(heapArr, lastIdx, 8);

	int data;
	data = Extract(heapArr, lastIdx);
	cout << data << " ";
	data = Extract(heapArr, lastIdx);
	cout << data << " ";
	data = Extract(heapArr, lastIdx);
	cout << data << " ";
	data = Extract(heapArr, lastIdx);
	cout << data << " ";
	data = Extract(heapArr, lastIdx);
	cout << data << " ";
	data = Extract(heapArr, lastIdx);
	return 0;
}
