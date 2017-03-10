#ifndef __GETIT_MODEL_FILESYSTEMPROGRAMSOURCE_H__
#define __GETIT_MODEL_FILESYSTEMPROGRAMSOURCE_H__

#include "abstractprogramsource.h"

class KyFileSystemProgramSource : public KyAbstractProgramSource
{
public:
	KyFileSystemProgramSource(std::wstring sDirectory) : m_sBaseDirectory(sDirectory) {}

	void LoadPrograms(std::list<Entry> &entryList);

private:
	void GetAppDirectoryPath(std::wstring sBaseDirectory, std::list<Entry> &entryList);

private:
	std::wstring m_sBaseDirectory;
};

#endif