#include "Core.h"
#include "StageManager.h"
#include "ShapeManager.h"

CCore* CCore::m_pInst = NULL;

CCore::CCore()
{
	srand((unsigned int)time(0));
}


CCore::~CCore()
{
	CShapeManager::DestroyInst();
	CStageManager::DestroyInst();
}

bool CCore::Init()
{
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (m_hConsole == INVALID_HANDLE_VALUE) {
		return false;
	}

	// 스테이지 관리자 초기화
	if (!CStageManager::GetInst()->Init()) {
		return false;
	}

	return true;
}

void CCore::Run()
{
	while (true) {
		system("cls");
		CShapeManager::GetInst()->Update();
		CStageManager::GetInst()->Run();
		CShapeManager::GetInst()->Render();
		Sleep(1000);
	}
}

void CCore::SetConsolePos(int x, int y)
{
	// 한칸은 2byte를 사용하기 때문에 *2 를 해준다.
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(m_hConsole, pos);
}
