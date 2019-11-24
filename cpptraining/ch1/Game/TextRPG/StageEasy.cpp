#include "StageEasy.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"

CStageEasy::CStageEasy()
{
}

CStageEasy::~CStageEasy()
{
}

bool CStageEasy::Init()
{
	return true;
}

void CStageEasy::Run()
{
	// �÷��̾ ���´�.
	CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");

	// ���͸� �����Ѵ�.
	CMonster* pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject("Goblin");

	while (true) {
		system("cls");
		OutputStageName("Easy");

		pPlayer->Render();
		cout << endl;
		pMonster->Render();
		cout << endl;

		OutputMenu();
		switch (OutputMenu()) {
		case MENU_ATTACK:
			switch (BattleAttack(pPlayer, pMonster)) {
			case BF_PLAYER_DIE: // �÷��̾ �׾��� ��
				break;
			case BF_MONSTER_DIE: // ���Ͱ� �׾��� ��
				break;
			}

			break;
		case MENU_BACK:
			// �ڷΰ��⸦ �ϱ� ���� ������ ���͸� ���̻� ������� �����Ƿ� �����ش�.
			// �Ź� �ʿ� ���ö����� ���� �������ְ� �ִ�.
			SAFE_DELETE(pMonster);
			return;
		}
	}
}
