#pragma once
// 벡터 구현

template <typename T>
class CVectorNode {
private:
	T m_Data;
	int m_iIndex;
	CVectorNode<T>* m_pNext;
	CVectorNode<T>* m_pPrev;

private:
	CVectorNode() {

	}
	~CVectorNode() {

	}
private:
	template <typename T>
	friend class CVector;
};
 

template <typename T> 
class CVector
{
private:
	typedef CVectorNode<T> NODE;
	typedef CVectorNode<T>* PNODE;

private:
	PNODE m_pArray;
	unsigned int m_iSize;
	unsigned int m_iCapasity;

public:
	CVector()
	{
		m_iSize = 0;
		m_iCapasity = 2;

		m_pArray = new NODE[m_iCapasity + 2]; // end node, begin node추가로 2개 더 
	}
	CVector(int iSize) {
		m_pArray = new NODE[iSize + 2];
		m_iCapasity = iSize;
		m_iSize = 0;
	}
	~CVector()
	{
		delete[] m_pArray;
	}

public:
	void push_back(const T& data) {
		if (is_full()) {
			resize(m_iSize * 2);
		}

		m_pArray[m_iSize + 1].m_Data = data;
		// 0번은 begin이다. 1번 인덱스부터 노드가 추가되는데 처음 추가된 노드는 0번부터 인덱스를 주도록 한다.
		m_pArray[m_iSize + 1].m_iIndex = m_iSize;
		++m_iSize;
		
	}

	void clear() {
		delete[] m_pArray;
		m_iSize = 0;
		m_iCapasity = 2;
		m_pArray = new NODE[m_iCapasity + 2];
	}

	bool is_full() const {
		return m_iSize == m_iCapasity;
	}

	bool is_empty() const {
		return m_iSize == 0;
	}

	unsigned int size() const {
		return m_iSize;
	}

	unsigned int capacity() const {
		return m_iCapasity;
	}

	void resize(int iSize) {
		// +2를 해주는 이유는  begin, end 노드를 포함시키기 때문
		PNODE pArray = new NODE[iSize + 2];

		// 메모리 주소에 +1을 해준 이유는 0은 begin이다. 1번 인덱스부터 시작이여서 +1을 해줌.
		memcpy(pArray + 1, m_pArray + 1, sizeof(NODE) * m_iSize); // 기존 사이즈만큼 ,  m_pArray의 메모리를  pArray로 복사

		// 기존 노드를 삭제한다.
		delete[] m_pArray;
		m_pArray = pArray;

		m_iCapasity = iSize;
	}

	T operator [](int idx) {
		return m_pArray[idx + 1].m_Data;
	}

	// 공간 예약
	void reserve(int iSize) {
		m_iCapasity = iSize;
		delete[] m_pArray;
		m_pArray = new NODE[iSize + 2];
		m_iSize = 0;
	}
};