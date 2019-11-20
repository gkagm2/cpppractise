#pragma once
// ���� ����

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

		m_pArray = new NODE[m_iCapasity + 2]; // end node, begin node�߰��� 2�� �� 
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
		// 0���� begin�̴�. 1�� �ε������� ��尡 �߰��Ǵµ� ó�� �߰��� ���� 0������ �ε����� �ֵ��� �Ѵ�.
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
		// +2�� ���ִ� ������  begin, end ��带 ���Խ�Ű�� ����
		PNODE pArray = new NODE[iSize + 2];

		// �޸� �ּҿ� +1�� ���� ������ 0�� begin�̴�. 1�� �ε������� �����̿��� +1�� ����.
		memcpy(pArray + 1, m_pArray + 1, sizeof(NODE) * m_iSize); // ���� �����ŭ ,  m_pArray�� �޸𸮸�  pArray�� ����

		// ���� ��带 �����Ѵ�.
		delete[] m_pArray;
		m_pArray = pArray;

		m_iCapasity = iSize;
	}

	T operator [](int idx) {
		return m_pArray[idx + 1].m_Data;
	}

	// ���� ����
	void reserve(int iSize) {
		m_iCapasity = iSize;
		delete[] m_pArray;
		m_pArray = new NODE[iSize + 2];
		m_iSize = 0;
	}
};