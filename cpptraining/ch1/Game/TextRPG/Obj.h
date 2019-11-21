#pragma once

#include "value.h"

class CObj {
protected:
	CObj();
	CObj(const CObj& obj);
	virtual ~CObj() = 0;

private:
	friend class CObjectManager;

protected:
	string m_strName;
	OBJECT_TYPE m_eType;

public:
	OBJECT_TYPE GetObjectType() const;

public:
	void SetName(const char* pName) {
		m_strName = pName;
	}

public:
	virtual bool Init();
	virtual void Render();
	virtual CObj* Clone() = 0;
};