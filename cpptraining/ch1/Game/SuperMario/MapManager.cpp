#include "MapManager.h"
#include "Stage.h"
#include <crtdbg.h>
#include "Player.h"
#include "ObjectManager.h"

CMapManager* CMapManager::m_pInst = NULL;

CMapManager::CMapManager()
{
	for (int i = 0; i < STAGE_MAX_COUNT; ++i)
	{
		m_pStage[i] = NULL;
	}
}

CMapManager::~CMapManager()
{

	// 스테이지 메모리 해제
	for (int i = 0; i < STAGE_MAX_COUNT; ++i)
	{
		//_CrtDumpMemoryLeaks();
		SAFE_DELETE(m_pStage[i]);
	}
}

CMapManager * CMapManager::GetInst()
{
	if (!m_pInst)
		m_pInst = new CMapManager;

	return m_pInst;
}

void CMapManager::DestroyInst()
{
	SAFE_DELETE(m_pInst);
}

bool CMapManager::Init()
{
	const char *pStageFile[3] = { "Game/SuperMario/Stage1.txt", "Game/SuperMario/Stage2.txt","Game/SuperMario/Stage3.txt" };
	for (int i = 0; i < STAGE_MAX_COUNT; ++i)
	{
		m_pStage[i] = new CStage;

		if (!m_pStage[i]->Init(pStageFile[i]))
			return false;
	}

	return true;
}

void CMapManager::Run(int iStage)
{
	CPlayer* pPlayer = CObjectManager::GetInst()->GetPlayer();
	m_iEnableStage = iStage;

	pPlayer->SetPos(m_pStage[iStage]->GetStart().x, m_pStage[iStage]->GetStart().y);

	while (true) {
		system("cls");
		pPlayer->Update();
		m_pStage[iStage]->Render();
		Sleep(100);
	}
}

void CMapManager::Render()
{
	m_pStage[0]->Render();
}