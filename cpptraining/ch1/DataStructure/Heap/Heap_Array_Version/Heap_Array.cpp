// title : 배열을 이용한 힙, 정렬
// Date : 20210218
// Developer : Sagacity Jang

#include <iostream>
using namespace std;

template<typename TYPE>
class Heap {
private:
	TYPE *m_pArray;
	int m_nArrayLen;
	int m_nHeapLen;

public:
	Heap() :
		m_pArray(0),
		m_nArrayLen(0),
		m_nHeapLen(0)
	{}
	Heap(TYPE _a[], int _n) :
		m_pArray(_a),
		m_nArrayLen(_n),
		m_nHeapLen(0)
	{}
	
	TYPE& a(int k) {
		return m_pArray[k - 1];
	}
	int GetHeapLen() { return m_nHeapLen; }
	int SetHeapLen(int _n) { m_nHeapLen = _n; }
	TYPE& arr(TYPE _idx) { return m_pArray[_idx - 1]; }

	void UpHeap(int _size) {
		// 맨 밑 마지막 노드에서부터 올라가며 자기 위치를 찾아 바꾼다.
		TYPE data = arr(_size);
		while (arr(_size / 2) < data && _size > 1) {
			arr(_size) = arr(_size / 2); // 부모노드의 데이터를 현재노드의 데이터로 바꿈
			_size /= 2;
		}
		arr(_size) = data;
	}

	void DownHeap(int _k) {
		TYPE data = arr(_k);
		while (_k <= m_nHeapLen / 2) { // 내부노드일 경우만
			int childIdx = _k * 2; // 왼쪽 자식
			if (childIdx < m_nHeapLen)
				childIdx = arr(childIdx) > arr(childIdx + 1) ? childIdx : childIdx + 1; // 두 자식중 큰 것 선택
			if (data >= arr(childIdx)) // 자식의 값보다 크면 종료
				break;
			arr(_k) = arr(childIdx);
			_k *= childIdx;
		}
		arr(_k) = data;
	}

	// 삽입(Insert)
	void Insert(TYPE _data) {
		m_pArray[m_nHeapLen++] = _data; // 노드 추가
		UpHeap(m_nHeapLen); // 추가된 노드 UpHeap
	}

	// 추출(Exract)
	TYPE Extract() {
		TYPE data = arr(1); // 최상위 노드를 뽑음.
		arr(1) = arr(m_nHeapLen--); // 맨 마지막 노드를 최상위 노드에 넣으줌.
		DownHeap(1); // 루트 노드를 DownHeap
		return data;
	}
};

int main() {
	int arr[10]{};

	Heap<int> heap(arr, 11);

	heap.Insert(3);
	heap.Insert(2);
	heap.Insert(4);
	heap.Insert(1);
	heap.Insert(6);

	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	cout << heap.Extract() << "\n";
	cout << heap.Extract() << "\n";
	cout << heap.Extract() << "\n";
	cout << heap.Extract() << "\n";
	cout << heap.Extract() << "\n";
	
	cout << "\n";

	return 0;
}
