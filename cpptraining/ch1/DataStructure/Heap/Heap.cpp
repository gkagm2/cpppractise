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

	while (idx != 1) { // heap에 데이터가 있으면
		//if(pHeap->heapArr[GetParent])
	}
}

HData HDelete(Heap * pHeap)
{
	HData retData = (pHeap->heapArr[1]).data; // 우선순위가 제일 높은 부모 노드 제거
	HeapElem lastElem = pHeap->heapArr[pHeap->numOfData]; // 가장 마지막 노드를 가져와서

	int parentIdx = 1;
	int childIdx;

	// 비교한다.
	//if (lastElem.priority > pHeap->heapArr[GetParentIdx(lastElem.priority]) {

	//}
	return HData();
}

// 부모 인덱스 반환
int GetParentIdx(int idx)
{
	return idx / 2;
}

// 왼쪽 자식 인덱스 반환
int GetLeftChildIdx(int idx)
{
	return idx*2;
}

// 오른쪽 자식 인덱스 반환
int GetRightChildIdx(int idx)
{
	return idx * 2 - 1;
}

// 두 개의 자식 노드를 비교하여 우선순위가 더 높은 자식 노드 인덱스 값을 반환
int GetHighPriorityChildIdx(Heap * pHeap, int idx)
{
	if (GetLeftChildIdx(idx) > pHeap->numOfData) {

	}
	return 0;
}
