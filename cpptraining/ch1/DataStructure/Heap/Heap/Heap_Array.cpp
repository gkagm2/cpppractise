// title : �迭�� �̿��� ��
// Date : 20210218
// Developer : Sagacity Jang

#include <iostream>
using namespace std;

typedef int Data;
// Full binary tree ���

void UpHeap(Data _a[], int _idx) {
	// �� �� ������ ��忡������ �ö󰡸� �ڱ� ��ġ�� ã�� �ٲ۴�.
	Data data = _a[_idx];
	while (_a[_idx / 2] <= data && _idx > 1) {
		_a[_idx] = _a[_idx / 2]; // �θ����� �����͸� �������� �����ͷ� �ٲ�
		_idx /= 2;
	}

	_a[_idx] = data;
}

void DownHeap(Data _a[], int _lastIdx, int _idx) {
	Data data = _a[_idx];
	while (_idx <= (_lastIdx + 1) / 2) { // ���γ���� ��츸
		int childIdx = _idx * 2; // ���� �ڽ�
		if (childIdx < _lastIdx) {
			int leftChild = _a[childIdx];
			int rightChild = _a[childIdx + 1];
			childIdx = leftChild < rightChild ? childIdx : childIdx + 1; // �� �ڽ��� ū �� ����
			++childIdx;
		}
		if (data > _a[childIdx]) // �ڽ��� ������ ũ�� ����
			break;
		_a[_idx] = _a[childIdx];
		_idx *= childIdx;
	}
}

///////////// Operations //////////////
// ����(Construct)
void Construct() {

}
// ����(Insert)
void Insert(Data _a[], int& _Idx, Data _data) {
	_a[++_Idx] = _data; // ��� �߰�
	UpHeap(_a, _Idx); // �߰��� ��� UpHeap
}
// ����(Remove)
void Remove() {

}
// ��ġ(Replace)
void Replace(){
	 
}
// ����(Change)
void Change() {

}
// ����(Delete)
void Delete() {

}
// ����(Join)
void Join() {

}
// ����(Exract)
Data Extract(Data _a[], int& _idx) {
	Data data = _a[1]; // �ֻ��� ��带 ����.
	_a[1] = _a[_idx--]; // �� ������ ��带 �ֻ��� ��忡 ������.
	DownHeap(_a, _idx, 1); // ��Ʈ ��带 DownHeap

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
