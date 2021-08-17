#include <iostream>
#include <io.h>
#include <vector>
#include <tchar.h>
#include <string>
using namespace std;
using std::string;
using std::wstring;
#ifdef UNICODE
typedef wstring tstring;
#else
typedef string tstring;
#endif

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

#if defined(UNICODE) || defined(_UNICODE)
#define tcout std::wcout
#else
#define tcout std::cout
#endif

#ifdef ENVIRONMENT32
#define T_FIND_DATA _tfinddata_t
#define T_FIND_FIRST _tfindfirst
#define T_FIND_NEXT _tfindnext
#endif
#ifdef ENVIRONMENT64
#define T_FIND_DATA _tfinddata64_t
#define T_FIND_FIRST _tfindfirst64
#define T_FIND_NEXT _tfindnext64
#endif

vector<tstring> GetFilesInDirectory(const tstring& _absolutePath, const tstring& _filter)
{
	tstring searching = _absolutePath + _filter;
	vector<tstring> return_;

	T_FIND_DATA fd;
	const auto handle = T_FIND_FIRST(searching.c_str(), &fd);  //현재 폴더 내 모든 파일을 찾는다.

	if (handle == -1)
		return return_;

	auto result = 0;
	do
	{
		if (fd.attrib & _A_SUBDIR) { // 디렉토리면
			tstring dirName = fd.name;
			if (_T(".") != dirName && _T("..") != dirName) {
				tstring subPath = _absolutePath + dirName + _T("\\");
				vector<tstring> vec = GetFilesInDirectory(subPath, _filter);
				for (int i = 0; i < vec.size(); ++i)
					return_.push_back(vec[i]);
			}
		}
		else { // 파일이면
			tstring fileName = fd.name;
			return_.push_back(fileName);
		}

		result = T_FIND_NEXT(handle, &fd);
	} while (result != -1);

	_findclose(handle);

	return return_;
}

int main() {
	// 절대경로
	tstring path = _T("N:\\Project\\DirectX2019Game\\DirectX11Game\\OutputFile\\bin\\content\\texture\\");

	// 필터
	tstring filter = _T("*.*");

	vector<tstring> veclist = GetFilesInDirectory(path, filter);
	for (int i = 0; i < veclist.size(); ++i) {

		tcout << veclist[i].c_str() << _T("\n");
	}
	
	return 0;
}