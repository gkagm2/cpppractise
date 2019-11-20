#pragma once
// 동적배열.

template <typename T>
class CVectorNode {
private:
	CVectorNode() {

	}
	~CVectorNode() {

	}
private:
	template <typename T>
	friend class CVector;

private:
	T m_Data;
	int m_iIndex;
	CVectorNode<T>* m_pNext;
	CVectorNode<T>* m_pPrev;
};


template <typename T> 
class CVector
{
public:
	CVector()
	{
		m_iSize = 0;
		m_iCapasity = 2;

		m_pArray = new NODE[m_iCapasity];
	}
	~CVector()
	{
	}

private:
	typedef CVectorNode<T> NODE;
	typedef CVectorNode<T>* PNODE;

private:
	PNODE m_pArray;
	unsigned int m_iSize;
	unsigned int m_iCapasity;

};