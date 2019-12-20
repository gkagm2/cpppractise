#include "ShapeManager.h"
#include "Rectangle.h"
#include "StageManager.h"
#include "Stage.h"

CShapeManager* CShapeManager::m_pInst = NULL;

CShapeManager::CShapeManager() : m_pCurShape(NULL), m_pNextShape(NULL)
{
	m_pCurShape =  CreateRandomShape();
	m_iSpeed = 0;
}


CShapeManager::~CShapeManager()
{
	list<CShape*>::iterator iter = m_pShapeList.begin();
	list<CShape*>::iterator iterEnd = m_pShapeList.end();
	for (iter; iter != iterEnd; ++iter) {
		SAFE_DELETE(*iter);
	}
	SAFE_DELETE(m_pCurShape);
	SAFE_DELETE(m_pNextShape);
}

void CShapeManager::Update()
{
	CStage* pStage = CStageManager::GetInst()->GetCurrentStage();
	++m_iSpeed;

	if (pStage->GetSpeed() == m_iSpeed) {
		m_pCurShape->MoveDown();
		m_iSpeed = 0;
	}
}

void CShapeManager::Render()
{
	list<CShape*>::iterator iter = m_pShapeList.begin();
	list<CShape*>::iterator iterEnd = m_pShapeList.end();
	for (iter; iter != iterEnd; ++iter) {
		(*iter)->Render();
	}

	m_pCurShape->Render();
}

CShape * CShapeManager::CreateRandomShape()
{
	int iType = rand() % ST_END;

	return CreateShape((SHAPE_TYPE)iType);
}

CShape * CShapeManager::CreateShape(SHAPE_TYPE eType)
{
	CShape* pShape = NULL;

	switch (eType) {
	case ST_RECT:
		pShape = new CRectangle;
		break;
	}

	if (!pShape->Init()) {
		SAFE_DELETE(pShape);
		return NULL;
	}
	return pShape;
}
