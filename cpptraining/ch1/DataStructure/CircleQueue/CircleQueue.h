#pragma once

// ¼øÈ¯ Å¥
template <typename T, int SIZE = 100>
class CCircleQueue {
public:
	CCircleQueue() {
		m_iSize = 0;
		m_iHead = 0;
		m_iTail = 0;
	}
	~CCircleQueue() {
	}

private:
	T m_Data[SIZE + 1];
	unsigned int m_iSize;
	unsigned int m_iHead;
	unsigned int m_iTail;

public:
	void push(const T& data) {
		if (is_full())
			return;

		int idx = (m_iTail + 1) % (SIZE + 1);
		m_Data[idx] = data;

		m_iTail = idx;

		++m_iSize;
	}

	T pop() {
		if (is_empty())
			return 0;

		int idx = (m_iHead + 1) % (SIZE + 1);

		T data = m_Data[idx];

		m_iHead = idx;
		--m_iSize;

		return data;
	}

	bool is_full() {
		return m_iSize == SIZE;
	}

	bool is_empty() {
		return m_iSize == 0;
	}
};