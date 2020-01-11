#include <iostream>
#include "Heap.h"
using namespace std;

int main() {
	Heap heap;
	HeapInit(&heap);
	return 0;
}

void HeapInit(Heap * pHeap) 
{
	pHeap->numOfData = 0;
}

bool HIsEmpty(Heap * pHeap)
{
	if (pHeap->numOfData == 0) {
		return true;
	}
	return false;
}

void HInsert(Heap * pHeap, HData data, Priority priority)
{
	int idx = pHeap->numOfData + 1;
	HeapElem newElem;
	newElem.priority = idx;
	newElem.data = data;

	while (idx != 1) { // heap�� �����Ͱ� ������
		//if(pHeap->heapArr[GetParent])
	}
}

HData HDelete(Heap * pHeap)
{
	HData retData = (pHeap->heapArr[1]).data; // �켱������ ���� ���� �θ� ��� ����
	HeapElem lastElem = pHeap->heapArr[pHeap->numOfData]; // ���� ������ ��带 �����ͼ�

	int parentIdx = 1;
	int childIdx;

	// ���Ѵ�.
	//if (lastElem.priority > pHeap->heapArr[GetParentIdx(lastElem.priority]) {

	//}
	return HData();
}

// �θ� �ε��� ��ȯ
int GetParentIdx(int idx)
{
	return idx / 2;
}

// ���� �ڽ� �ε��� ��ȯ
int GetLeftChildIdx(int idx)
{
	return idx*2;
}

// ������ �ڽ� �ε��� ��ȯ
int GetRightChildIdx(int idx)
{
	return idx * 2 - 1;
}

// �� ���� �ڽ� ��带 ���Ͽ� �켱������ �� ���� �ڽ� ��� �ε��� ���� ��ȯ
int GetHighPriorityChildIdx(Heap * pHeap, int idx)
{
	if (GetLeftChildIdx(idx) > pHeap->numOfData) {

	}
	return 0;
}
