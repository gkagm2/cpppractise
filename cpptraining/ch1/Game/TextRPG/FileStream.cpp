#include "FileStream.h"

CFileStream::CFileStream() : m_pFile(NULL), m_bOpen(false), m_iFileSize(0), m_iCurrent(0)
{
	
}

CFileStream::CFileStream(const char * pFileName, const char * pMode)
{
	Open(pFileName, pMode);
}

CFileStream::~CFileStream()
{
	Close();
}

bool CFileStream::Open(const char * pFileName, const char * pMode)
{
	fopen_s(&m_pFile, pFileName, pMode);
	if (!m_pFile) {
		return false;
	}
	m_bOpen = true;

	if (pMode[0] == 'r' || pMode[0] == 'R') {
		m_eMode = FM_READ;
	}
	else if (pMode[0] == 'w' || pMode[0] == 'W') {
		m_eMode = FM_WRITE;
	}

	fseek(m_pFile, 0, SEEK_END);
	m_iFileSize = ftell(m_pFile);
	fseek(m_pFile, 0, SEEK_SET); // 처음으로 돌려놓음

	return true;
}

bool CFileStream::Close()
{
	if (!m_bOpen) {
		return false;
	}

	fclose(m_pFile);
	m_pFile = NULL;
	m_bOpen = false;
	m_iFileSize = 0;
		
	return true;
}

bool CFileStream::Read(void * pData, int iSize)
{
	return false;
}

bool CFileStream::ReadLine(void * pData, int pSize)
{
	return false;
}

bool CFileStream::Write(void * pData, int iSize)
{
	return false;
}
