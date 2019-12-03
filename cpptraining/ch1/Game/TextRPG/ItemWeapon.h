#pragma once
#include "Item.h"

class CItemWeapon : public CItem
{
protected:
	CItemWeapon();
	CItemWeapon(const CItemWeapon& item);
	virtual ~CItemWeapon();

private:
	friend class CStore;
	friend class CStoreWeapon;

private:
	int m_iAttackMin;
	int m_iAttackMax;
	float m_fCritical;

public:
	void SetWeaponInfo(int iMin, int iMax, float fCritical);

public:
	virtual bool Init();
	virtual void Render();
	virtual CItemWeapon* Clone();
};

