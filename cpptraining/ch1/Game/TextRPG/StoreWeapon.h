#pragma once
#include "Store.h"

class CStoreWeapon : public CStore
{
public:
	CStoreWeapon();
	~CStoreWeapon();

private:
	friend class CStoreManager;

public:
	virtual bool Init();
	virtual void Run();
};

