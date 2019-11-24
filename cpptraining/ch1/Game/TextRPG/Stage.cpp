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
	cout << "1. ����" << endl;
	cout << "2. �ڷΰ���" << endl;
	cout << "�޴��� �����ϼ��� : ";
	int iMenu = Input<int>();

	if(iMenu <= MENU_NONE || iMenu > MENU_BACK){
		return MENU_NONE;
	}

	return iMenu;
}

CStage::BATTLE_FLAG CStage::BattleAttack(CPlayer * pPlayer, CMonster * pMonster)
{
	// �÷��̾��� ���̸̹� ���ؿ´�.
	int iDamage = pPlayer->GetDamage() - pMonster->GetArmor();
	iDamage = iDamage < 1 ? 1 : iDamage;
	

	cout << pMonster->GetName

	// ��ȯ�� true��� ���Ͱ� �������̴�.
	if (pMonster->Damage(iDamage)) {
		return BF_MONSTER_DIE;
	}


	return BF_NONE;
}
