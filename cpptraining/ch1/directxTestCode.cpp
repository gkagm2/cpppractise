#include "TestTest.h"
int gnObjects;	// 게임 객체의 개수

class CObject
{
public:
	CMesh *pMesh;
	float PositionX;
	float PositionY;
	float PositionZ;
	float RotationX;
	float RotationY;
	float RotationZ;
}

class CVertex
{
	float x;
	float y;
	float z;
}



class CPolygon
{
	UNIT nVerticles;
	Vertex *pVertexList;
}
class CMesh
{
	UNIT nFaces;
	Polygon *pFaceList;
}

int gnObjects;		// 게임 객체의 개수
CObject *gpObjects;	// 게임 객체 배열
CCamera *gpCamera;	// 게임 카메라

void DrawObjects() {
	for (int i = 0; i < gnObjects; i++)
	{
		Draw(&gpObjects[i]);
	}

}

void Draw(CObject *pObject) 
{
	static CVertex vtxPrevious;
	CMesh *pMesh = pObject->pMesh;
	for (int i = 0; i < pMesh->nFaces; i++)
	{
		CPolygon *pPolygon = &pMesh->pFaceList[i];
		for (int j = 0; j < pPolygon->nVertices; j++)
		{
			CVertex v = Transform(pPolygon->pVertexList[i], pObject);
			if (j != 0)
			{
				Draw2DLine(vtxPrevious.x, vtxprevious.y, v.x, v.y);
//				vtxPrevious = v;
//			}
//		}
//	}
//}
//CVertex Transform(CVertex vtxModel, CObject *pObject)
//{
//	CVertex vtxWorld = WorldTransform(vtxModel, pObject);
//	CVertex vtxCamera = CameraTransform(vtxWorld, gpCamera);
//	CVertex vtxProject = ProjectionTransform(vtxCamera);
//	CVertex vtxScreen = ScreenTransform(vtxProject);
//	return (vtxScreen);
//}
//
//CVertex WorldTransform(CVertex vtxModel, CObject *pObject)
//{
//	CVertex vtxWorld;
//	vtxWorld.x = vtxModel.x + pObject->PositionX;
//	vtxWorld.y = vtxModel.y + pObject->PositionY;
//	vtxWorld.z = vtxModel.z + pObject->PositionZ;
//	return (vtxWorld);
//}
//
//void Draw2DLine(int x1, int y1, int x2, int y2)
//{
//	HDC hDC = GetDC(ghWnd);
//	MoveToEx(hDC, x1, y1, NULL);
//	LineTo(hDC, x2, y2);
//	ReleaseDC(ghWnd, hDC);
//}

CVertex WorldTransform(CVertex vtxModel, CObject *pObject) {
	float fPitch = pObject->RotationX,
		  fYaw   = pObject->RotationY,
		  fRoll  = pObject->RotationZ;
	CVertex vtxWorld = vtxModel, vtxRotated;
	if (fPitch) { // x axis
		vtxRotated.y = vtxWorld.y * cos(fPitch) - vtxWorld.z * sin(fPitch);
		vtxRotated.z = vtxWorld.z * sin(fPitch) + vtxWorld.z * cos(fPitch);
		vtxWorld = vtxRotated;
	}
	if (fYaw) { // y axis
		vtxRotated.x = vtxWorld.x * cos(fYaw) + vtxWorld.z * sin(fYaw);
		vtxRotated.z = -vtxWorld.x * sin(fYaw) + vtxWorld.z * cos(fYaw);	
		vtxWorld = vtxRotated;
	}
	if (fRoll) { // z axis
		vtxRotated.x = vtxWorld.x * cos(fRoll) + vtxWorld.y * sin(fRoll);
		vtxRotated.y = vtxWorld.x * sin(fRoll) + vtxWorld.y * cos(fRoll);
		vtxWorld = vtxRotated;
	}

	vtxWorld.x += pObject->PositionX;
	vtxWorld.y += pObject->PositionY;
	vtxWorld.z += pObject->PositionZ;
	return (vtxWorld);
}