#include "FileStream.h"



CFileStream::CFileStream() :
	m_pFile(NULL),
	m_iFileSize(0),
	m_bOpen(false)
{
	
}


CFileStream::~CFileStream()
{
}

bool CFileStream::Open(char * pFileName, char * pMode)
{
	// ������ �̹� ������ ����ϰ� �ִٸ� �ٽ� ���� ���ϰ� �Ѵ�..
	if (m_bOpen) {
		return false;
	}
	fopen_s(&m_pFile, pFileName, pMode);

	if (!m_pFile) {
		return false;
	}

	// ���� Ŀ���� ���� �ڷ� �̵���Ų��.
	// fseek �Լ��� ���� Ŀ���� ���ϴ� ��ġ�� �̵���ų �� �ִ� �Լ��̴�.
	// 3��° ���ڴ� 3������ �ִ�.
	// SEEK_SET : ������ ���� ó���� �ǹ��Ѵ�.
	// SEEK_CUR : ���� ����Ű�� �ִ� ���� Ŀ���� ��ġ�� �ǹ��Ѵ�.
	// SEEK_END : ������ ���� �������� �ǹ��Ѵ�.
	// 2��° ������ offset ���� ����Ʈ ����ŭ 3��° ���ڿ��� ������ ��ġ�� �̵��ϰ� �ȴ�.
	fseek(m_pFile, 0, SEEK_END);
	// ftell : ���� Ŀ���� ��ġ�� ������ �Լ��̴�. ������ ���� Ŀ���� ���� ����������
	// �̵����ױ� ������ ftell�� �̿��ؼ� ���� Ŀ���� ��ġ�� ������ �� ���� ũ�Ⱑ �ȴ�.
	m_iFileSize = ftell(m_pFile);

	// ���� ũ�⸦ ���� �Ŀ� ���� ������ �ٽ� �̵������ش�.
	fseek(m_pFile, 0, SEEK_SET);

	m_bOpen = true;

	return true;
}

bool CFileStream::Close()
{
	if (!m_bOpen)
		return false;

	m_bOpen = false;
	fclose(m_pFile);

	m_pFile = NULL;
	return true;
}

void CFileStream::Read(void * pData, int iSize)
{
	if (!m_bOpen) {
		return;
	}
}

void CFileStream::Write(void * pData, int iSize)
{
}
