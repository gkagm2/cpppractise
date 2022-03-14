#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <time.h>

using namespace std;
#ifdef WIN32
#pragma warning(disable:4786)
#endif
#include <iostream>
using namespace std;

#define CONSOLE_COLOR_RED 4
#define CONSOLE_COLOR_GREEN 2
#define CONSOLE_COLOR_WHITE 7


#pragma once

#ifdef _DEBUG
#define PM_START(strLog) CPerformanceMonitor::TimeStart(strLog)
#define PM_END() CPerformanceMonitor::TimeEnd()
#else
#define PM_START(strLog) 
#define PM_END() 
#endif

class CPerformanceMonitor
{
private:
	static clock_t m_start;
	static clock_t m_end;
	static double m_fms;
	static string m_strLog;
public:
	static void TimeStart(const string& _log);
	static void TimeEnd();
};

clock_t CPerformanceMonitor::m_start = {};
clock_t CPerformanceMonitor::m_end = {};
double CPerformanceMonitor::m_fms = {};
string CPerformanceMonitor::m_strLog = {};

void CPerformanceMonitor::TimeStart(const string& _log)
{
	m_strLog = _log;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_COLOR_GREEN);
	printf("[performance monitoring start] %s\n", m_strLog.c_str());
	m_start = clock();
}

void CPerformanceMonitor::TimeEnd()
{
	m_end = clock();
	m_fms = (double)(m_end - m_start);
	double timeInSecond = (double)(m_fms / CLOCKS_PER_SEC);
	printf("[delay time] ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_COLOR_RED);
	printf("%lf\n", timeInSecond);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_COLOR_WHITE);
}

int main() {

	CPerformanceMonitor::TimeStart("start");


	CPerformanceMonitor::TimeEnd();

	return 0;
}
