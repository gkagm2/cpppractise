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
	// �÷��̾ �����Ѵ�.
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

	// ���� key�� value�� �̿��ؼ� �����͸� �����ϱ� ������ make_pair�� �̿��ؼ�
	// key�� value�� ��� �ʿ� insert�Ѵ�.
	m_mapObj.insert(make_pair(strKey, pObj));

	return pObj;
}

CObj * CObjectManager::FindObject(const string & strKey)
{
	unordered_map<string, CObj*>::iterator iter = m_mapObj.find(strKey);

	// end()�� ���� ã�� ����.
	if (iter == m_mapObj.end()) {
		return NULL;
	}
	return iter->second;
}
