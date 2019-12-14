#pragma once
#include "value.h"

class CCore
{
public:
	CCore();
	~CCore();

private:
	static CCore* m_pInst;

public:
	static CCore* GetInst() {
		if (!m_pInst) { // null¿Ã∂Û∏È
			m_pInst = new CCore();
			return m_pInst;
		}
	}

	static void DestroyInst() {
		SAFE_DELETE(m_pInst);
	}

public:
	bool Init();
	bool Run();
};

