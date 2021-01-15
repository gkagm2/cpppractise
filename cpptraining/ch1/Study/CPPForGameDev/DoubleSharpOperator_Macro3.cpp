#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>

#pragma region RTTI macros
#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)
#define DECLARE_DYNAMIC(class_name) static\
	CRuntimeClass class##class_name;
#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass\
	class_name::class##class_name = {\
	(#class_name),\
	sizeof(class_name),\
	class_name::CreateObject };
#define DECLARE_DYNCREATE(class_name) static CObject* CreateObject();
#define IMPLEMENT_DYNCREATE(class_name) CObject*\
	class_name::CreateObject() {\
	return new class_name; };  
#pragma endregion


class CObject; // forward declaration of CObject

#pragma region struct CRuntimeClass
struct CRuntimeClass {
	CObject* (*pfnCreateObject)();
	CObject* CreateObject();

	int m_nObjectSize;
	char m_lpszClassName[21];
};
CObject* CRuntimeClass::CreateObject() {
	return (*pfnCreateObject)(); // �Լ� �����͸� �̿��Ͽ� ���������� �Լ��� ȣ���Ѵ�.
}
#pragma endregion

#pragma region class CObject
class CObject {
	// CObject�� ���� �����Լ��� �������� �����Ƿ� �߻� Ŭ������ �ƴϴ�. ������, �����ڰ� protected�� �����Ǿ����Ƿ�, CObject��ü�� ������ �� ����.
public:
	// �Ļ� Ŭ�������� �ݵ�� ������ �ʿ䰡 �����Ƿ� ���������Լ��� �ƴϴ�.
	virtual CRuntimeClass* GetRuntimeClass() const {
		return nullptr;
	}
	DECLARE_DYNAMIC(CObject) // static CRuntimeClass classObject;
	virtual ~CObject() {}
protected:
	CObject() {
		printf("CObject constructor\n");
	}
};
#pragma endregion

#pragma region class CAlpha
class CAlpha : public CObject {
public:
	virtual CRuntimeClass* GetRuntimeClass() const {
		return &classCAlpha;
	}
	DECLARE_DYNAMIC(CAlpha) // static CRuntimeClass classCAlpha;
	DECLARE_DYNCREATE(CAlpha) // static CObject* CreateObject();
protected:
	CAlpha() {
		printf("CAlpha constructor\n");
	}
};

IMPLEMENT_DYNAMIC(CAlpha) //CRuntimeClass CAlpha::classCAlpha = { "CAlpha", sizeof(CAlpha), CAlpha::CreateObject };
IMPLEMENT_DYNCREATE(CAlpha) //CObject* CAlpha::CreateObject() { return new CAlpha; }
#pragma endregion


#pragma region class CBeta
class CBeta : public CObject {
public:
	virtual CRuntimeClass* GetRuntimeClass() const {
		return &classCBeta;
	}
	DECLARE_DYNAMIC(CBeta) // static CRuntimeClass classCBeta;
	DECLARE_DYNCREATE(CBeta) // static CObject* CreateObject();
protected:
	CBeta() {
		printf("CBeta constructor\n");
	}
};

IMPLEMENT_DYNAMIC(CBeta) // CRuntimeClass  CBeta::classCBeta = { "CBeta", sizeof(CBeta),  Beta::CreateObject };
IMPLEMENT_DYNCREATE(CBeta) //CObject* CBeta::CreateObject() { return new CBeta; }

#pragma endregion

int main() {
	// Create CAlpha
	CRuntimeClass* pRTCAlpha = RUNTIME_CLASS(CAlpha);
	CObject* pObj1;

	pObj1 = pRTCAlpha->CreateObject();
	// struct RuntimeClass�� CreateObject()�� ȣ������� IMPLEMENT_DYNCREATE ��ũ�ο� ���� CAlpha�� &OnCreate()�� ���ԵǾ� �����Ƿ�, �ᱹ�� CAlpha�� OnCreate()�� ȣ��Ǿ� �������� ��ü�� �����ϰ� �ȴ�.
	// ������ Ǫ�� ����� �ٷ� '�Լ� ������'�̴�.
	printf("CAplha class=%s\n", pObj1->GetRuntimeClass()->m_lpszClassName);

	// Create CBeta
	CRuntimeClass* pRTCBeta = RUNTIME_CLASS(CBeta);
	CObject* pObj2;

	pObj2 = pRTCBeta->CreateObject();
	printf("CBeta class=%s\n", pObj2->GetRuntimeClass()->m_lpszClassName); // �ϰ��� ������� Ŭ������ ����� ������.

	delete pObj1;
	delete pObj2;
	return 0;
}
