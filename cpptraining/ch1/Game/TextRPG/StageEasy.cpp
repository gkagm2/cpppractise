#include "StageEasy.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"

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
	CMonster* pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject(ST_EASY);

	while (true) {
		system("cls");
		OutputStageName("Easy");

		pPlayer->Render();
		cout << endl;
		pMonster->Render();
		cout << endl;

		switch (OutputMenu()) {
		case MENU_ATTACK:
			switch (BattleAttack(pPlayer, pMonster)) {
			case BF_PLAYER_DIE: // 플레이어가 죽었을 때
				pPlayer->DropExp();
				pPlayer->DropGold();

				pPlayer->FullHPMP();
				break;
			case BF_MONSTER_DIE: // 몬스터가 죽었을 때
				
				cout << pPlayer->GetName() << " 이 " << pMonster->GetCharacterInfo().iExp << "의 경험치를 획득하였습니다." << endl;
				int iDropGold;

				iDropGold = pMonster->GetDropGold();
				cout << pPlayer->GetName() << " 이 " << iDropGold << " Gold를 획득하였습니다." << endl;

				pPlayer->AddExp(pMonster->GetCharacterInfo().iExp); 
				pPlayer->AddGold(pMonster->GetDropGold());

				// 레벨업 조건을 만족했다면 true를 반환한다.
				if (pPlayer->CheckLevelUp()) {
					pPlayer->LevelUp();


					LEVELUPINFO _tLevelUpInfo = GET_SINGLE(CCore)->GetLevelUpInfo(pPlayer->GetJob());
					// 능력치 상승
					pPlayer->AddLevelUpStatus(_tLevelUpInfo);
					cout << "Level up " << endl;
				}
				
				// 몬스터를 삭제하고 다시 복사해서 생성해준다.
				SAFE_DELETE(pMonster);
				pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject(ST_EASY);
				break;
			}

			break;
		case MENU_BACK:
			// 뒤로가기를 하기 전에 생성한 몬스터를 더이상 사용하지 않으므로 지워준다.
			// 매번 맵에 들어올때마다 새로 생성해주고 있다.
			SAFE_DELETE(pMonster);
			return;
		}
		system("pause");
	}
}
