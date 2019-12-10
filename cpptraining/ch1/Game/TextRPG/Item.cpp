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
	CObj::Save(pFile); 

	// string 형식으로 되어있어서 sizeof(ITEMINFO)를 이용하지 못함.

	pFile->Write(&m_tInfo.eType, 4);

	int iLength = m_tInfo.strTypeName.length();
	pFile->Write(&iLength, 4);
	pFile->Write((void*)m_tInfo.strTypeName.c_str(), iLength);

	pFile->Write(&m_tInfo.iPrice, 4);
	pFile->Write(&m_tInfo.iSell, 4);
	
	iLength = m_tInfo.strDesc.length();
	pFile->Write(&iLength, 4);
	pFile->Write((void*)m_tInfo.strDesc.c_str(), iLength);
}

void CItem::Load(CFileStream * pFile)
{
	CObj::Load(pFile);

	pFile->Read(&m_tInfo.eType, 4);

	// 이름 길이 읽기
	int iLength = 0;
	pFile->Read(&iLength, 4);

	char* pName = new char[iLength + 1];

	memset(pName, 0, iLength);

	pFile->Read(pName, iLength);
	pName[iLength] = 0;

	m_tInfo.strTypeName = pName;
	SAFE_DELETE_ARRAY(pName);

	pFile->Read(&m_tInfo.iPrice, 4); // price 일기
	pFile->Read(&m_tInfo.iSell, 4); // sell 읽기

	// 설명 읽어
	iLength = 0;
	pFile->Read(&iLength, 4);

	pName = new char[iLength + 1];

	memset(pName, 0, iLength);

	pFile->Read(pName, iLength);
	pName[iLength] = 0;

	m_tInfo.strDesc = pName;
	SAFE_DELETE_ARRAY(pName);

}
