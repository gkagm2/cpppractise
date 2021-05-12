#include <iostream>

#include <functional>

#include <map>
#include <queue>


using namespace std;

typedef struct _tagNode
{
	_tagNode*	pPrevNode;   // ���� ���
	float		fFromParent; // ���� ��忡�� ���� �������� �Ÿ�
	float		fToDest;	 // ���� ��忡�� ������ ������ �Ÿ�
	float		fFinal;		 // ���� �� ���� ��ģ ��(�켱���� ����)

	int			iIdxX;
	int			iIdxY;
	bool		bMove;   // �̵� ���� �Ұ���
	bool		bOpen;   // OpenList �� ������
	bool		bClosed; // ClostList �� ����ִ���

	bool		bPath;
}tNode;


const int g_iXCount = 10;
const int g_iYCount = 10;

// ���� ��ġ
int g_iCurPosX = 0;
int g_iCurPosY = 5;

int g_iDestPosX = 9;
int g_iDestPosY = 5;

tNode arrNode[g_iXCount][g_iYCount] = {};

// Open List
class Compare
{
public:
	bool operator() (tNode* _pLeft, tNode* _pRight)
	{
		return _pLeft->fFinal > _pRight->fFinal;
	}
};


void Rebuild(priority_queue<tNode*, vector<tNode*>, Compare>& _queue)
{
	priority_queue<tNode*, vector<tNode*>, Compare> tempQueue;

	while (!_queue.empty())
	{
		tempQueue.push(_queue.top());
		_queue.pop();
	}

	_queue.swap(tempQueue);
}

priority_queue<tNode*, vector<tNode*>, Compare>	g_OpenList;

void FindPath();

int main()
{
	for (int i = 0; i < g_iYCount; ++i)
	{
		for (int j = 0; j < g_iXCount; ++j)
		{
			arrNode[i][j].iIdxX = j;
			arrNode[i][j].iIdxY = i;

			if (j == 4 && i != 0 && i != 9)
				arrNode[i][j].bMove = false;
			else
				arrNode[i][j].bMove = true;
		}
	}

	// arrNode[1][3].bMove = false;
	// arrNode[9][4].bMove = false;
	
	for (int i = 0; i < g_iYCount; ++i)
	{
		for (int j = 0; j < g_iXCount; ++j)
		{
			if (j == g_iCurPosX && i == g_iCurPosY)
				cout << " !";
			else if (j == g_iDestPosX && i == g_iDestPosY)
				cout << " ?";

			else if (arrNode[i][j].bMove)
				cout << "��";
			else
				cout << " |";

			cout << " ";
		}
		cout << endl;
	}
		
	FindPath();


	return 0;
}

void CalculateCost(tNode* _pCurNode, tNode* _pOrigin)
{
	_pCurNode->pPrevNode = _pOrigin;
	_pCurNode->fFromParent = 10.f + _pOrigin->fFromParent;
	_pCurNode->fToDest = abs(g_iDestPosX - _pCurNode->iIdxX) * 10.f + abs(g_iDestPosY - _pCurNode->iIdxY) * 10;
	_pCurNode->fFinal = _pCurNode->fFromParent + _pCurNode->fToDest;
};

void AddOpenList(int _iXIdx, int _iYIdx, tNode* _pOrigin)
{
	// ���� �������� �� �� �ִ� ���� OpenList �� �ִ´�.
	// ��� ������ ��� ���
	if (_iXIdx < 0 || _iXIdx >= g_iXCount || _iYIdx < 0 || _iYIdx >= g_iYCount
		|| !arrNode[_iYIdx][_iXIdx].bMove)
		return;
	
	// �ش� ���� Clost List �� �ִ� ���, Open List �� ���� �ʴ´�.
	if (arrNode[_iYIdx][_iXIdx].bClosed)
		return;

	// Open List �� ����� ����ؼ� �ִ´�.
	if (false == arrNode[_iYIdx][_iXIdx].bOpen) 
	{		
		CalculateCost(&arrNode[_iYIdx][_iXIdx], _pOrigin);
		// Open List �� �ִ´�.
		arrNode[_iYIdx][_iXIdx].bOpen = true;
		g_OpenList.push(&arrNode[_iYIdx][_iXIdx]);
	}
	else // �̹� OpenList �� �ִ� ���,
	{
		//����� ����ؼ� �� ȿ���� ���� ������ ��ü�Ѵ�.
		tNode node = arrNode[_iYIdx][_iXIdx];
		CalculateCost(&node, _pOrigin);

		if (arrNode[_iYIdx][_iXIdx].fFinal > node.fFinal)
		{
			arrNode[_iYIdx][_iXIdx] = node;

			// ���¸���Ʈ(�켱����ť) �缳��
			Rebuild(g_OpenList);
		}		
	}
}

void FindPath()
{
	int iCurX = g_iCurPosX;
	int iCurY = g_iCurPosY;

	tNode* pCurNode = &arrNode[iCurY][iCurX];
	pCurNode->bClosed = true;
	
	while (true)
	{
		// ���� �������� 4������ ��带 OpenList �� �ִ´�.
		// UP
		AddOpenList(pCurNode->iIdxX
				  , pCurNode->iIdxY - 1, pCurNode);

		// RIGHT		
		AddOpenList(pCurNode->iIdxX + 1
			, pCurNode->iIdxY, pCurNode);

		// DOWN		
		AddOpenList(pCurNode->iIdxX
			, pCurNode->iIdxY + 1, pCurNode);

		// LEFT		
		AddOpenList(pCurNode->iIdxX - 1
			, pCurNode->iIdxY, pCurNode);

		// 2. Open List ���� ���� ȿ���� ���� ��带 ������.
		//  - �ش� ���� ClostList �� �ִ´�.
		pCurNode = g_OpenList.top();
		pCurNode->bClosed = true;

		g_OpenList.pop();

		// �������� ������ ��� Astar ����
		if (pCurNode->iIdxX == g_iDestPosX && pCurNode->iIdxY == g_iDestPosY)
		{
			break;
		}
	}

	// �� ǥ��
	while (true)
	{
		arrNode[pCurNode->iIdxY][pCurNode->iIdxX].bPath = true;
		pCurNode = pCurNode->pPrevNode;

		if (pCurNode->iIdxX == g_iCurPosX && pCurNode->iIdxY == g_iCurPosY)
		{
			pCurNode->bPath = true;
			break;
		}
	}

	// �� ���
	cout << endl;
	cout << endl;

	for (int i = 0; i < g_iYCount; ++i)
	{
		for (int j = 0; j < g_iXCount; ++j)
		{
			if (j == g_iCurPosX && i == g_iCurPosY)
				cout << " !";
			else if (j == g_iDestPosX && i == g_iDestPosY)
				cout << " ?";
			else if (arrNode[i][j].bPath)
				cout << " !";
			else if (arrNode[i][j].bMove)
				cout << "��";
			else
				cout << " |";

			cout << " ";
		}
		cout << endl;
	}
}