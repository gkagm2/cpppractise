#include "Stage.h"



CStage::CStage() : m_iSpeed(10) // 1�ʿ� 10�� �ݺ�
{
}


CStage::~CStage()
{
}

bool CStage::Init()
{
	memset(m_Stage, 0, STAGE_HEIGHT * STAGE_WIDTH);
	return true;
}

void CStage::Render()
{
	for (int h = 0; h < STAGE_HEIGHT + 2; ++h) {
		for (int w = 0; w < STAGE_WIDTH + 2; ++w) {
			if (h == 0) { // �ٱ��� ���̸�
				cout << "��";
			}
			else if (w == 0) {
				cout << "��";
			}
			else if (h == STAGE_HEIGHT + 1) {
				cout << "��";
			}
			else if (w == STAGE_WIDTH + 1) {
				cout << "��";
			}
			else { // ����� �׿����� �����̶��
				cout << "  ";
			}

		}
		cout << endl;
	}
}