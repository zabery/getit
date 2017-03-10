#include "stdafx.h"
#include "desktopprogramsource.h"

std::wstring KyDesktopProgramSource::GetDesktopDirectory()
{
	WCHAR szPath[MAX_PATH + 1];
	if (SHGetSpecialFolderPath(NULL, szPath, CSIDL_DESKTOP, FALSE))
	{
		return std::wstring(szPath);
	}
	return std::wstring();
}