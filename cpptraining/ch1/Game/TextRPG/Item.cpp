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

void CItem::Save(CFileStream * pFile)
{
	// �ڽ� ���� ���� �� 
	CObj::Save(pFile); 

	// �θ�����
	pFile->Write(&m_tInfo, sizeof(m_tInfo));
}

void CItem::Load(CFileStream * pFile)
{
	CObj::Load(pFile);
	pFile->Read(&m_tInfo, sizeof(m_tInfo));
}
