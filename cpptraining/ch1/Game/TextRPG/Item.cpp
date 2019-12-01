#include "Item.h"



CItem::CItem()
{
}

CItem::CItem(const CItem & item) : CObj(item)
{
}


CItem::~CItem()
{
}

void CItem::SetItemInfo(ITEM_TYPE eType, int iPrice, int iSell,const  char* pDesc)
{
	m_tInfo.eType = eType;
	switch (eType) {
	case IT_WEAPON:
		m_tInfo.strTypeName = "����";
		break;
	case IT_ARMOR:
		m_tInfo.strTypeName = "��";
		break;
	}

	m_tInfo.iPrice = iPrice;
	m_tInfo.iSell = iSell;
	m_tInfo.strDesc = pDesc;
}

bool CItem::Init()
{
	return false;
}

void CItem::Render()
{
}
