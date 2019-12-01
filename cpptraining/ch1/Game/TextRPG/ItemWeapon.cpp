#include "ItemWeapon.h"



CItemWeapon::CItemWeapon()
{
}

CItemWeapon::CItemWeapon(const CItemWeapon & item) : CItem(item)
{
}


CItemWeapon::~CItemWeapon()
{
}

bool CItemWeapon::Init()
{
	return true;
}

void CItemWeapon::Render()
{
}

CItemWeapon * CItemWeapon::Clone()
{
	return new CItemWeapon(*this);
}
