#include "Core.h"
#include "MapManager.h"
#include "ObjectManager.h"
#include "Player.h"

CCore* CCore::m_pInst = NULL;

// cpp ���Ͽ��� Ŭ������ �����κ��� �ִ�.
CCore::CCore()
{
}

CCore::~CCore()
{
	CMapManager::DestroyInst();
	CObjectManager::DestroyInst();
}

CCore* CCore::GetInst()
{
	if (!m_pInst)
		m_pInst = new CCore;
	
	return m_pInst;
}

void CCore::DestroyInst()
{
	SAFE_DELETE(m_pInst);
}

bool CCore::Init()
{
	// �� �����ڸ� �ʱ�ȭ�Ѵ�. ���н� false�� �����Ѵ�.
	if (!CMapManager::GetInst()->Init())
		return false;

	// ������Ʈ ������ �ʱ�ȭ�Ѵ�. ���н� false�� �����Ѵ�.
	if (!CObjectManager::GetInst()->Init())
		return false;

	return true;
}

void CCore::Run()
{
	//CMapManager::GetInst()->Render();

	while (true) {
		int iStage = OutputMenu();

		if (iStage == STAGE_MAX_COUNT + 1)
			break;
		else if (iStage == 0)
			continue;

		CMapManager::GetInst()->Run(iStage - 1);
	}
}

int CCore::OutputMenu()
{
	system("cls");
	int i;
	for (i = 0; i < STAGE_MAX_COUNT; ++i) {
		cout << i + 1 << ". Stage" << i + 1 << endl;

	}
	cout << i + 1 << ". Exit" << endl;

	int iInput = InputInt();
	if (iInput < 1 || iInput > STAGE_MAX_COUNT + 1) {
		return 0;
	}

	return iInput;
}