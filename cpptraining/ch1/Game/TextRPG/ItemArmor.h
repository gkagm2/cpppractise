#pragma once
#include "Item.h"
class CItemArmor : public CItem
{
protected:
	CItemArmor();
	CItemArmor(const CItemArmor& item);
	virtual ~CItemArmor();

private:
	friend class CStoreArmor;
	friend class CStore;

private:
	int m_iArmorMin;
	int m_iArmorMax;

public:
	void SetArmorInfo(int iMin, int iMax);

public:
	virtual bool Init();
	virtual void Render();
	virtual CItemArmor* Clone();
};