#pragma once
#include "Obj.h"
class CItem : public CObj
{
protected:
	CItem();
	CItem(const CItem& item);
	virtual ~CItem();

protected:
	ITEMINFO m_tInfo;

public:
	void SetItemInfo(ITEM_TYPE eType, int iPrice, int iSell, char* pDesc);
public:
	ITEMINFO GetItemInfo() const {
		return m_tInfo;
	}

public:
	virtual bool Init();
	virtual void Render();
	virtual CItem* Clone() = 0;
};

