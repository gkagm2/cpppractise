#include "StageManager.h"
#include "Stage.h"

CStageManager* CStageManager::m_pInst = NULL;

CStageManager::CStageManager() : m_pCurStage(NULL)
{
}


CStageManager::~CStageManager()
{

}

bool CStageManager::Init()
{
	// 기본 스테이지를 생성한다.
	m_pCurStage = new CStage;
	if (!m_pCurStage->Init()) {
		return false;
	}

	return true;
}

bool CStageManager::Run()
{
	m_pCurStage->Render();

	return true;
}
