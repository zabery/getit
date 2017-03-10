#include "stdafx.h"
#include "include/utility/pathhandler.h"
#include "filesystemprogramsource.h"
using namespace std;

void KyFileSystemProgramSource::LoadPrograms(std::list<Entry> &entryList)
{
	if (!m_sBaseDirectory.empty())
	{
		GetAppDirectoryPath(m_sBaseDirectory, entryList);
	}
}

void KyFileSystemProgramSource::GetAppDirectoryPath(std::wstring sBaseDirectory, std::list<Entry> &entryList)
{
	wstring sDir = sBaseDirectory;
	sDir.append(L"\\*.*");
	WIN32_FIND_DATA data;
	HANDLE hFile = FindFirstFile(sDir.c_str(), &data);
	if (hFile == INVALID_HANDLE_VALUE)
		return;

	while (1)
	{
		wstring sFileName = data.cFileName;

		// ȥ���ϲ�Ŀ¼
		if (sFileName != L"." && sFileName != L"..")
		{
			wstring sPath = sBaseDirectory;
			sPath.append(L"\\").append(sFileName);
			if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				GetAppDirectoryPath(sPath, entryList);
			}
			else
			{
				Entry entry = __super::CreateEntry(sPath);

				// ֻ������.exe(��Ҫ���Ǻ����Ѿ�ƴ���˲���)
				if (KyUtility::GetExtension(entry.sExecutePath) == L".exe")
					entryList.push_back(entry);
			}
		}
		
		if (!FindNextFile(hFile, &data))
			break;
	}

	FindClose(hFile);
}