#include "Item.h"
#include "FileStream.h"


CItem::CItem()
{
}

CItem::CItem(const CItem & item) : CObj(item)
{
	m_tInfo = item.m_tInfo;
}


CItem::~CItem()
{
}

void CItem::SetItemInfo(ITEM_TYPE eType, int iPrice, int iSell,const  char* pDesc)
{
	m_tInfo.eType = eType;
	switch (eType) {
	case IT_WEAPON:
		m_tInfo.strTypeName = "무기";
		break;
	case IT_ARMOR:
		m_tInfo.strTypeName = "방어구";
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

void CItem::Save(CFileStream * pFile)
{
	// 자식 먼저 저장 후 
	CObj::Save(pFile); 

	// 부모저장
	pFile->Write(&m_tInfo, sizeof(m_tInfo));
}

void CItem::Load(CFileStream * pFile)
{
	CObj::Load(pFile);
	pFile->Read(&m_tInfo, sizeof(m_tInfo));
}
