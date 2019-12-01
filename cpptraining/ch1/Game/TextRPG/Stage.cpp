#include "Stage.h"
#include "Player.h"
#include "Monster.h"


CStage::CStage()
{
}

CStage::~CStage()
{
}

void CStage::OutputStageName(const char * pName)
{
	cout << "================ " << pName << " ================" << endl;
}

int CStage::OutputMenu()
{
	cout << "1. 공격" << endl;
	cout << "2. 뒤로가기" << endl;
	cout << "메뉴를 선택하세요 : ";
	int iMenu = Input<int>();

	if(iMenu <= MENU_NONE || iMenu > MENU_BACK){
		return MENU_NONE;
	}

	return iMenu;
}

CStage::BATTLE_FLAG CStage::BattleAttack(CPlayer * pPlayer, CMonster * pMonster)
{
	// 플레이어의 데이미를 구해온다.
	int iDamage = pPlayer->GetDamage() - pMonster->GetArmor();
	iDamage = iDamage < 1 ? 1 : iDamage;
	
	cout << pPlayer->GetName() << " 가 " << pMonster->GetName() << " 에게 " << iDamage << "피해를 주었습니다." << endl;

	// 반환이 true라면 몬스터가 죽은것이다.
	if (pMonster->Damage(iDamage)) {
		return BF_MONSTER_DIE;
	}

	// 몬스터가 플레이어를 공격한다.
	iDamage = pMonster->GetDamage() - pPlayer->GetArmor();
	iDamage = iDamage < 1 ? 1 : iDamage;

	cout << pMonster->GetName() << " 가 " << pPlayer->GetName() << " 에게 " << iDamage << "피해를 주었습니다." << endl;

	if (pPlayer->Damage(iDamage)) {
		return BF_PLAYER_DIE;
	}

	return BF_NONE;
}
