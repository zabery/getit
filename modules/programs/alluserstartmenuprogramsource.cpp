#include "stdafx.h"
#include "alluserstartmenuprogramsource.h"

std::wstring KyAllUserStartMenuProgramSource::GetAllUserProgramDirectory()
{
	WCHAR szPath[MAX_PATH + 1];
	if (SHGetSpecialFolderPath(NULL, szPath, CSIDL_COMMON_STARTMENU, FALSE))
	{
		return std::wstring(szPath);
	}
	return std::wstring();
}