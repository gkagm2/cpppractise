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
	// 파일이 이미 열려서 사용하고 있다면 다시 열지 못하게 한다..
	if (m_bOpen) {
		return false;
	}
	fopen_s(&m_pFile, pFileName, pMode);

	if (!m_pFile) {
		return false;
	}

	// 파일 커서를 가장 뒤로 이동시킨다.
	// fseek 함수는 파일 커서를 원하는 위치로 이동시킬 수 있는 함수이다.
	// 3번째 인자는 3종류가 있다.
	// SEEK_SET : 파일의 제일 처음을 의미한다.
	// SEEK_CUR : 현재 가리키고 있는 파일 커서의 위치를 의미한다.
	// SEEK_END : 파일의 가장 마지막을 의미한다.
	// 2번째 인자인 offset 들어가는 바이트 수만큼 3번째 인자에서 지정한 위치로 이동하게 된다.
	fseek(m_pFile, 0, SEEK_END);
	// ftell : 파일 커서의 위치를 얻어오는 함수이다. 위에서 파일 커서를 가장 마지막으로
	// 이동시켰기 때문에 ftell을 이용해서 파일 커서의 위치를 얻어오면 곧 파일 크기가 된다.
	m_iFileSize = ftell(m_pFile);

	// 파일 크기를 구한 후에 가장 앞으로 다시 이동시켜준다.
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
