#include <iostream>
#include <string>
using namespace std;

enum class E_Pivot{
	left = 1,
	middle,
	right,
};

class CClass {
private:
	float	m_fTotalLen;
	float	m_fLightLen;
	int		m_iLightCount;
	float	m_fMargin;
	E_Pivot m_ePivotType;

private:
	float	m_fSpacingBetweenLights;

public:
	float GetTotalLen() { return m_fTotalLen; }
	void SetTotalLen(float _fTotalLen) { m_fTotalLen = _fTotalLen; }
	float GetLightLen() { return m_fLightLen; }
	void SetLightLen(float _fLightLen) { m_fLightLen = _fLightLen; }
	int GetLightCount() {return m_iLightCount;}
	void SetLightCount(int _iLightCount) { m_iLightCount = _iLightCount; }
	float GetMargin() { return m_fMargin; }
	void SetMargin(float _fMargin) { m_fMargin = _fMargin; }
	E_Pivot GetPivot() { return m_ePivotType; }
	void SetPivotType(E_Pivot _ePivotType) { m_ePivotType = _ePivotType; }

public:
	void Render();
public:
	CClass(){
		m_fTotalLen = 0.f;
		m_fLightLen = 0.f;
		m_iLightCount = 0;
		m_fMargin = 0.f;
		m_ePivotType = E_Pivot::middle;

		m_fSpacingBetweenLights = 0.f;
	}
};

int main() {
	
	int iTotalLen;

	CClass clas;

	while (1) {
		cout << "���� ������ ������ ���ϴ� ���α׷�\n";
		cout << "���� �Է� : 1, �Ǻ� �Է� : 2, ���� ���� : 3, ���� �Է� ���� ���� : 4\n";

		cout << "�޴� �Է� : ";
		int iMenuInput;
		cin >> iMenuInput;
		switch (iMenuInput) {
		case 1: {
			// �Էºκ�.
			cout << "��ü ���� �Է� : ";
			float fTotalLen;
			cin >> fTotalLen;

			cout << "�� ���� �Է� : ";
			float iLightCount;
			cin >> iLightCount;

			cout << "�� ���� �Է� : ";
			float fLightLen;
			cin >> fLightLen;

			cout << "���κ� ���� ���� �Է� : ";
			float fMargin;
			cin >> fMargin;

			clas.SetTotalLen(fTotalLen);
			clas.SetLightCount(iLightCount);
			clas.SetLightLen(fLightLen);
			clas.SetMargin(fMargin);
		}
			break;
		case 2: {
			cout << "�Ǻ����� ���� �����\n";
			cout << "���� : 1, �߾� : 2, ������ : 3\n";
			cout << "�Է� :\n";
			int iPivotType;
			cin >> iPivotType;

			clas.SetPivotType((E_Pivot)iPivotType);
		}
			break;
		case 3: {
			clas.Render();
		}
		case 4: {
			
		}
			break;
		default:
			break;
		}

		// ���� ����
		cout << "\n��� 1 , �� 0\n";
		int input;
		cin >> input;
		if (0 == input)
			break;

		/*system("cls");*/
	}
	
	return 0;
}

void CClass::Render()
{
	m_fSpacingBetweenLights = (m_fTotalLen - m_fMargin * 2.f - m_fLightLen) / (m_iLightCount - 1);
	cout << "�� ���� ���� : " << m_fSpacingBetweenLights << "\n";

	float fLightHalfLen = m_fLightLen * 0.5f;

	float fLightStartPosition = m_fMargin + fLightHalfLen;
	cout << "�� ���� ��ġ : " << fLightStartPosition << "\n";

	float fStartPos = fLightStartPosition;
	int iLightCnt = m_iLightCount;

	float m_fPivotValue = 0.f;
	string strPivotState = "";
	switch (m_ePivotType) {
	case E_Pivot::left:
		strPivotState = "����";
		m_fPivotValue -= fLightHalfLen;
		break;
	case E_Pivot::middle:
		strPivotState = "�߾�";
		m_fPivotValue = 0.f;
		break;
	case E_Pivot::right:
		strPivotState = "������";
		m_fPivotValue += fLightHalfLen;
		break;
	default:
		break;
	}
	cout << "�Ǻ� ���� : " << strPivotState << "\n";
	cout << "==�� ��ġ ��ȸ==\n";
	while (0 < iLightCnt) {
		cout << "[" << fStartPos + m_fPivotValue << "]";

		fStartPos += m_fSpacingBetweenLights;
		--iLightCnt;
	}
}