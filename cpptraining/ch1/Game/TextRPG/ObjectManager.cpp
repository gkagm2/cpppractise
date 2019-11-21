#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"

DEFINITION_SINGLE(CObjectManager)

CObjectManager::CObjectManager()
{
}

CObjectManager::~CObjectManager()
{
}

bool CObjectManager::Init()
{
	// 플레이어를 생성한다.
	CObj* pPlayer = CreateObject("Player", OT_PLAYER);
	return true;
}

CObj * CObjectManager::CreateObject(const string& strKey, OBJECT_TYPE eType)
{
	CObj* pObj = NULL;

	switch (eType) {
	case OT_PLAYER:
		pObj = new CPlayer;
		break;
	case OT_MONSTER:
		pObj = new CMonster;
		break;
	}

	if (!pObj->Init()) {
		SAFE_DELETE(pObj);
		return NULL;
	}

	// 맵은 key와 value를 이용해서 데이터를 관리하기 때문에 make_pair를 이용해서
	// key와 value를 묶어서 맵에 insert한다.
	m_mapObj.insert(make_pair(strKey, pObj));

	return pObj;
}

CObj * CObjectManager::FindObject(const string & strKey)
{
	unordered_map<string, CObj*>::iterator iter = m_mapObj.find(strKey);

	// end()일 경우는 찾지 못함.
	if (iter == m_mapObj.end()) {
		return NULL;
	}
	return iter->second;
}
