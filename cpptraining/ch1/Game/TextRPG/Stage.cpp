#include "Stage.h"

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