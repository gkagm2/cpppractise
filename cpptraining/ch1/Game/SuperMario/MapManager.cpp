#include "MapManager.h"
#include "Stage.h"
#include <crtdbg.h>
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

	// �������� �޸� ����
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

void CMapManager::Run()
{
}

void CMapManager::Render()
{
	m_pStage[0]->Render();
}
