#pragma once
#include "Item.h"
class CItemArmor : public CItem
{
protected:
	CItemArmor();
	CItemArmor(const CItemArmor& item);
	virtual ~CItemArmor();

private:
	int m_iArmorMin;
	int m_iArmorMax;
	float m_fCritical;

public:
	virtual bool Init();
	virtual void Render();
	virtual CItemArmor* Clone();
};

