#pragma once

#include "value.h"

class CObj {
protected:
	CObj();
	virtual ~CObj() = 0;

private:
	friend class CObjectManager;

public:
	virtual bool Init();
};