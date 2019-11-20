#pragma once

template <typename T>
class CStackNode {
private:
	CStackNode() {
	}
	~CStackNode() {
	}

private:
	template <typename T>
	friend class CStack;

private:
	T m_Data;
	CStackNode<T>* m_pNext;
};

template <typename T>
class CStack
{
public:
	CStack() {
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		m_pBegin->m_pNext = m_pEnd;

		m_iSize = 0;

	}
	~CStack() {
		PNODE pNode = m_pBegin;

		while (pNode) {
			PNODE pNext = pNode->m_pNext;
			delete pNode;
			pNode = pNext;
		}
	}

private:
	typedef CStackNode<T> NODE;
	typedef CStackNode<T>* PNODE;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	unsigned int m_iSize;

public:
	void push(const T& data) {
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		PNODE pNext = m_pBegin->m_pNext;
		pNode->m_Data = data;
		pNode->m_pNext = pNext;
		m_pBegin->m_pNext = pNode;

		++m_iSize;
	}

	T pop() {
		if (is_empty()) {
			return 0;
		}
		PNODE pNode = m_pBegin->m_pNext;
		PNODE pNext = pNode->m_pNext;

		T data = pNode->m_Data;

		m_pBegin->m_pNext = pNext;

		delete pNode;
		
		--m_iSize;
		return data;
	}

	T top() {
		if (is_empty()) {
			return 0;
		}
		return m_pBegin->m_pNext->m_Data;
	}

	bool is_empty() {
		return m_iSize == 0;
	}

	void clear() {
		while (m_pBegin->m_pNext != m_pEnd) {
			
			PNODE pNextNode = m_pBegin->m_pNext;
			m_pBegin->m_pNext = pNextNode->m_pNext;
			delete pNextNode;
		}
		m_iSize = 0;
	}
};