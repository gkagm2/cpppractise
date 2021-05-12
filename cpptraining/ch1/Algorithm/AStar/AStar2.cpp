#include <iostream>

#include <functional>

#include <map>
#include <queue>


using namespace std;

typedef struct _tagNode
{
	_tagNode*	pPrevNode;   // 이전 노드
	float		fFromParent; // 이전 노드에서 현재 노드까지의 거리
	float		fToDest;	 // 현재 노드에서 목적지 까지의 거리
	float		fFinal;		 // 위에 두 값을 합친 값(우선순위 기준)

	int			iIdxX;
	int			iIdxY;
	bool		bMove;   // 이동 가능 불가능
	bool		bOpen;   // OpenList 에 들어갔는지
	bool		bClosed; // ClostList 에 들어있는지

	bool		bPath;
}tNode;


const int g_iXCount = 10;
const int g_iYCount = 10;

// 시작 위치
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
				cout << "·";
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
	// 현재 지점에서 갈 수 있는 곳을 OpenList 에 넣는다.
	// 노드 범위를 벗어난 경우
	if (_iXIdx < 0 || _iXIdx >= g_iXCount || _iYIdx < 0 || _iYIdx >= g_iYCount
		|| !arrNode[_iYIdx][_iXIdx].bMove)
		return;
	
	// 해당 길이 Clost List 에 있는 경우, Open List 에 넣지 않는다.
	if (arrNode[_iYIdx][_iXIdx].bClosed)
		return;

	// Open List 에 비용을 계산해서 넣는다.
	if (false == arrNode[_iYIdx][_iXIdx].bOpen) 
	{		
		CalculateCost(&arrNode[_iYIdx][_iXIdx], _pOrigin);
		// Open List 에 넣는다.
		arrNode[_iYIdx][_iXIdx].bOpen = true;
		g_OpenList.push(&arrNode[_iYIdx][_iXIdx]);
	}
	else // 이미 OpenList 에 있는 경우,
	{
		//비용을 계산해서 더 효율이 좋은 것으로 대체한다.
		tNode node = arrNode[_iYIdx][_iXIdx];
		CalculateCost(&node, _pOrigin);

		if (arrNode[_iYIdx][_iXIdx].fFinal > node.fFinal)
		{
			arrNode[_iYIdx][_iXIdx] = node;

			// 오픈리스트(우선순위큐) 재설정
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
		// 현재 지점에서 4방향의 노드를 OpenList 에 넣는다.
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

		// 2. Open List 에서 가장 효율이 좋은 노드를 꺼낸다.
		//  - 해당 노드는 ClostList 에 넣는다.
		pCurNode = g_OpenList.top();
		pCurNode->bClosed = true;

		g_OpenList.pop();

		// 목적지에 도착한 경우 Astar 종료
		if (pCurNode->iIdxX == g_iDestPosX && pCurNode->iIdxY == g_iDestPosY)
		{
			break;
		}
	}

	// 길 표시
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

	// 길 출력
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
				cout << "·";
			else
				cout << " |";

			cout << " ";
		}
		cout << endl;
	}
}