#include "Obj.h"

CObj::CObj()
{
}

CObj::CObj(const CObj & obj)
{
	m_strName = obj.m_strName;
	m_eType = obj.m_eType;
}

CObj::~CObj()
{
}

OBJECT_TYPE CObj::GetObjectType() const
{
	return m_eType;
}

bool CObj::Init()
{
	return true;
}

void CObj::Render()
{
}

CObj * CObj::Clone()
{
	return nullptr;
}
