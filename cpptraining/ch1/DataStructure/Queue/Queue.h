#pragma once

template <typename T>
class CQueneNode {
private:
	CQueneNode() : 
		m_pNext(NULL){}
	~CQueneNode(){}

private:
	template <typename T>
	friend class CQueue;

private:
	T m_Data;
	CQueneNode<T>* m_pNext; // 쉽게 접근하기 위해 double linked list로 구현 해봅세
	CQueneNode<T>* m_pPrev;
};


template <typename T>
class CQueue
{
public:
	CQueue(){
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;
	}
	~CQueue(){}

private:
	typedef CQueneNode<T> NODE;
	typedef CQueneNode<T>* PNODE;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	unsigned int m_iSize;

public:
	void push(const T& data) {
		PNODE pNode = new NODE;

		pNode->m_Data = data;

		PNODE pPrev = m_pEnd->m_pPrev;

		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	T pop() {
		if (is_empty()) {
			return 0;
		}

		PNODE pNode = m_pBegin->m_pNext;
		T data = pNode->m_Data;

		m_pBegin->m_pNext = pNode->m_pNext;
		pNode->m_pNext->m_pPrev = m_pBegin;

		delete pNode;
		--m_iSize;

		return  data;
	}

	bool is_empty() {
		return m_iSize == 0;
	}
};