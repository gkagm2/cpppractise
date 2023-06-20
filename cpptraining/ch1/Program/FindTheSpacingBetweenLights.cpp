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
		cout << "전등 사이의 간격을 구하는 프로그램\n";
		cout << "정보 입력 : 1, 피봇 입력 : 2, 정보 보기 : 3, 현재 입력 상태 보기 : 4\n";

		cout << "메뉴 입력 : ";
		int iMenuInput;
		cin >> iMenuInput;
		switch (iMenuInput) {
		case 1: {
			// 입력부분.
			cout << "전체 길이 입력 : ";
			float fTotalLen;
			cin >> fTotalLen;

			cout << "등 개수 입력 : ";
			float iLightCount;
			cin >> iLightCount;

			cout << "등 길이 입력 : ";
			float fLightLen;
			cin >> fLightLen;

			cout << "끝부분 여백 길이 입력 : ";
			float fMargin;
			cin >> fMargin;

			clas.SetTotalLen(fTotalLen);
			clas.SetLightCount(iLightCount);
			clas.SetLightLen(fLightLen);
			clas.SetMargin(fMargin);
		}
			break;
		case 2: {
			cout << "피봇값을 어디로 맞출까\n";
			cout << "왼쪽 : 1, 중앙 : 2, 오른쪽 : 3\n";
			cout << "입력 :\n";
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

		// 종료 문구
		cout << "\n계속 1 , 끝 0\n";
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
	cout << "등 사이 간격 : " << m_fSpacingBetweenLights << "\n";

	float fLightHalfLen = m_fLightLen * 0.5f;

	float fLightStartPosition = m_fMargin + fLightHalfLen;
	cout << "등 시작 위치 : " << fLightStartPosition << "\n";

	float fStartPos = fLightStartPosition;
	int iLightCnt = m_iLightCount;

	float m_fPivotValue = 0.f;
	string strPivotState = "";
	switch (m_ePivotType) {
	case E_Pivot::left:
		strPivotState = "왼쪽";
		m_fPivotValue -= fLightHalfLen;
		break;
	case E_Pivot::middle:
		strPivotState = "중앙";
		m_fPivotValue = 0.f;
		break;
	case E_Pivot::right:
		strPivotState = "오른쪽";
		m_fPivotValue += fLightHalfLen;
		break;
	default:
		break;
	}
	cout << "피봇 상태 : " << strPivotState << "\n";
	cout << "==등 위치 조회==\n";
	while (0 < iLightCnt) {
		cout << "[" << fStartPos + m_fPivotValue << "]";

		fStartPos += m_fSpacingBetweenLights;
		--iLightCnt;
	}
}