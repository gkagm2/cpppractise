#include "ItemArmor.h"



CItemArmor::CItemArmor()
{
}

CItemArmor::CItemArmor(const CItemArmor & item)
{
}


CItemArmor::~CItemArmor()
{
}

bool CItemArmor::Init()
{
	return true;
}

void CItemArmor::Render()
{
}

CItemArmor * CItemArmor::Clone()
{
	return new CItemArmor(*this);
}
