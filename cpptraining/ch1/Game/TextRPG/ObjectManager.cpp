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

	CObj* pPlayer1 = pPlayer->Clone();

	// CreateObject �Լ��� ���͸� �����ϰ� CObj* Ÿ���� �����Ѵ�.
	// ������ �⺻ �������� ���� Ŭ������ character Ŭ������ ������ �����Ƿ�
	// ���� Ŭ������ ����ȯ�Ͽ� �����صΰ� ����� ����ϵ��� �Ѵ�.
	CMonster* pMonster1 = (CMonster*)CreateObject("Goblin", OT_MONSTER);
	pMonster1->SetName("���");
	pMonster1->SetCharacterInfo(5, 10, 3, 5, 100, 10, 1, 1000);
	pMonster1->SetGold(1000, 2000);

	CMonster* pMonster2 = (CMonster*)CreateObject("Troll", OT_MONSTER);
	pMonster2->SetName("Ʈ��");
	pMonster2->SetCharacterInfo(50, 80, 40, 60, 2000, 300, 5, 7000);
	pMonster2->SetGold(5000, 10000);

	CMonster* pMonster3 = (CMonster*)CreateObject("Dragon", OT_MONSTER);
	pMonster3->SetName("�巡��");
	pMonster3->SetCharacterInfo(150, 250, 150, 250, 10000, 10000, 10, 25000);
	pMonster3->SetGold(30000, 50000);

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
	// map�� find �Լ��� �������ش�. find�Լ��� key�� �־��ָ� �ش� Ű�� Ž���Ͽ�
	// ���� ��� �ش� Ű�� iterator�� ��ȯ�ϰ� ���� ��� end()�� ��ȯ�Ѵ�.
	unordered_map<string, CObj*>::iterator iter = m_mapObj.find(strKey);

	// end()�� ���� ã�� ����.
	if (iter == m_mapObj.end()) {
		return NULL; // NULL�� 0�̹Ƿ� ã�� ���ߴٴ� �ǹ�.
	}
	return iter->second;
}

// ���ڷ� ������ Ű�� �̿��ؼ� ��ü�� ã�� �� �ش� ��ü�� �����ؼ� ������ �� ��ȯ���ִ� �Լ�.
CObj * CObjectManager::CloneObject(const string & strKey)
{
	// ������ ������ü�� ã�´�.
	CObj* pOrigin = FindObject(strKey);

	// pOrigin �� NULL�̶�� ���� ã�� ���ߴٴ� ����.
	if (!pOrigin)
		return NULL; // ã�� ����.

	// ã�Ҵٸ� ���� ��ü�� ������ ���ο� ��ü�� ���� ��ȯ�Ѵ�. 
	return pOrigin->Clone();
}