#include "stdafx.h"
#include "currentuserstartmenuprogramsource.h"

std::wstring KyCurrentUserStartMenuProgramSource::GetCurrentUserStartMenuDirectory()
{
	WCHAR szPath[MAX_PATH + 1];
	if (SHGetSpecialFolderPath(NULL, szPath, CSIDL_STARTMENU, FALSE))
	{
		return std::wstring(szPath);
	}
	return std::wstring();
}