// title : �迭�� �̿��� ��, ����
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
		// �� �� ������ ��忡������ �ö󰡸� �ڱ� ��ġ�� ã�� �ٲ۴�.
		TYPE data = arr(_size);
		while (arr(_size / 2) < data && _size > 1) {
			arr(_size) = arr(_size / 2); // �θ����� �����͸� �������� �����ͷ� �ٲ�
			_size /= 2;
		}
		arr(_size) = data;
	}

	void DownHeap(int _k) {
		TYPE data = arr(_k);
		while (_k <= m_nHeapLen / 2) { // ���γ���� ��츸
			int childIdx = _k * 2; // ���� �ڽ�
			if (childIdx < m_nHeapLen)
				childIdx = arr(childIdx) > arr(childIdx + 1) ? childIdx : childIdx + 1; // �� �ڽ��� ū �� ����
			if (data >= arr(childIdx)) // �ڽ��� ������ ũ�� ����
				break;
			arr(_k) = arr(childIdx);
			_k *= childIdx;
		}
		arr(_k) = data;
	}

	// ����(Insert)
	void Insert(TYPE _data) {
		m_pArray[m_nHeapLen++] = _data; // ��� �߰�
		UpHeap(m_nHeapLen); // �߰��� ��� UpHeap
	}

	// ����(Exract)
	TYPE Extract() {
		TYPE data = arr(1); // �ֻ��� ��带 ����.
		arr(1) = arr(m_nHeapLen--); // �� ������ ��带 �ֻ��� ��忡 ������.
		DownHeap(1); // ��Ʈ ��带 DownHeap
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
