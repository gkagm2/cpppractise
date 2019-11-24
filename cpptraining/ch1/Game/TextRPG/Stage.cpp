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
	
	return BF_NONE;
}
