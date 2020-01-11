#pragma once

#define HEAP_LEN 100

typedef char HData; // 데이터
typedef int Priority; // 우선순위

typedef struct _tHeapElem {
	Priority priority; // 값이 작을수록 높은 우선순위
	HData data;
}HeapElem;

typedef struct _heap {
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* pHeap);
bool HIsEmpty(Heap* pHeap);

void HInsert(Heap* pHeap, HData data, Priority priority);
HData HDelete(Heap *pHeap);

int GetParentIdx(int idx);
int GetLeftChildIdx(int idx);
int GetRightChildIdx(int idx);

int GetHighPriorityChildIdx(Heap* pHeap, int idx);