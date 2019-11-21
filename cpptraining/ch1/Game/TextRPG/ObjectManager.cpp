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

	CObj* pPlayer1 = pPlayer->Clone();

	// CreateObject 함수는 몬스터를 생성하고 CObj* 타입을 리턴한다.
	// 몬스터의 기본 변수들은 몬스터 클래스나 character 클래스가 가지고 있으므로
	// 몬스터 클래스로 형변환하여 저장해두고 기능을 사용하도록 한다.
	CMonster* pMonster1 = (CMonster*)CreateObject("Goblin", OT_MONSTER);
	pMonster1->SetName("고블린");
	pMonster1->SetCharacterInfo(5, 10, 3, 5, 100, 10, 1, 1000);
	pMonster1->SetGold(1000, 2000);

	CMonster* pMonster2 = (CMonster*)CreateObject("Troll", OT_MONSTER);
	pMonster2->SetName("트롤");
	pMonster2->SetCharacterInfo(50, 80, 40, 60, 2000, 300, 5, 7000);
	pMonster2->SetGold(5000, 10000);

	CMonster* pMonster3 = (CMonster*)CreateObject("Dragon", OT_MONSTER);
	pMonster3->SetName("드래곤");
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

	// 맵은 key와 value를 이용해서 데이터를 관리하기 때문에 make_pair를 이용해서
	// key와 value를 묶어서 맵에 insert한다.
	m_mapObj.insert(make_pair(strKey, pObj));

	return pObj;
}

CObj * CObjectManager::FindObject(const string & strKey)
{
	// map은 find 함수를 제공해준다. find함수에 key를 넣어주면 해당 키를 탐색하여
	// 있을 경우 해당 키의 iterator를 반환하고 없을 경우 end()를 반환한다.
	unordered_map<string, CObj*>::iterator iter = m_mapObj.find(strKey);

	// end()일 경우는 찾지 못함.
	if (iter == m_mapObj.end()) {
		return NULL; // NULL은 0이므로 찾지 못했다는 의미.
	}
	return iter->second;
}

// 인자로 들어오는 키를 이용해서 객체를 찾은 후 해당 객체를 복사해서 생상한 후 반환해주는 함수.
CObj * CObjectManager::CloneObject(const string & strKey)
{
	// 복사할 원복객체를 찾는다.
	CObj* pOrigin = FindObject(strKey);

	// pOrigin 이 NULL이라는 것은 찾지 못했다는 것임.
	if (!pOrigin)
		return NULL; // 찾지 못함.

	// 찾았다면 원본 객체를 복사한 새로운 객체를 만들어서 반환한다. 
	return pOrigin->Clone();
}