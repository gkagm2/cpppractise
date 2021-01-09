#include "GameEngine.cpp"

int main()
{
	Vec3 v1(0.3, 1, 0);
	Vec3 v2(-1, 0, 0);
	float scale = GetDotVector3(v1, v2);
	cout << scale << "\n";

	Vec3 v3(1, 2, 3);
	cout << v3.GetLength() << "\n";

	Vec3 v4(1, 1, 0);
	cout << v4.GetLength() << "\n";
	Vec3 v01(1, 0, -1), v02(0, 1, 1);
	cout << " distance : " << GetDistance(v01, v02) << "\n";
	

	
	// 평면의 법선벡터 구하기
	Vec3 v5(3, 5, 3);
	Vec3 v6(21, 1, 0);
	v5 = v5.GetNormalized();
	v5.PrintPosition();
	v6 = v6.GetNormalized();
	v6.PrintPosition();
	Vec3 resultV = GetCross(v5, v6);
	cout << "cross : ";
	resultV.PrintPosition();
	
}
