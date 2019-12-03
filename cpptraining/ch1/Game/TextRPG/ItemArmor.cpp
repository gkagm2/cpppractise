#include "ItemArmor.h"



CItemArmor::CItemArmor()
{
}

CItemArmor::CItemArmor(const CItemArmor & item) : CItem(item)
{
	m_iArmorMin = item.m_iArmorMin;
	m_iArmorMax = item.m_iArmorMax;
}


CItemArmor::~CItemArmor()
{
}

void CItemArmor::SetArmorInfo(int iMin, int iMax)
{
	m_iArmorMin = iMin;
	m_iArmorMax = iMax;
}

bool CItemArmor::Init()
{
	return true;
}

void CItemArmor::Render()
{
	cout << "�̸� : " << m_strName << "\t���� : " << m_tInfo.strTypeName << endl;
	cout << "���� : " << m_iArmorMin << " ~ " << m_iArmorMax<< endl;
	cout << "Price : " << m_tInfo.iPrice << "\tSell : " << m_tInfo.iSell << endl;
	cout << "���� : " << m_tInfo.strDesc << endl;
}

CItemArmor * CItemArmor::Clone()
{
	return new CItemArmor(*this);
}
