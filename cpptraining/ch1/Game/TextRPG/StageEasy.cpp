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
	// 플레이어를 얻어온다.
	CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");

	// 몬스터를 복사한다.
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
			case BF_PLAYER_DIE: // 플레이어가 죽었을 때
				break;
			case BF_MONSTER_DIE: // 몬스터가 죽었을 때
				break;
			}

			break;
		case MENU_BACK:
			// 뒤로가기를 하기 전에 생성한 몬스터를 더이상 사용하지 않으므로 지워준다.
			// 매번 맵에 들어올때마다 새로 생성해주고 있다.
			SAFE_DELETE(pMonster);
			return;
		}
	}
}
