#ifndef __GETIT_MODEL_DESKTOPPROGRAMSOURCE_H__
#define __GETIT_MODEL_DESKTOPPROGRAMSOURCE_H__

#include "filesystemprogramsource.h"
class KyDesktopProgramSource : public KyFileSystemProgramSource
{
public:
	KyDesktopProgramSource() : KyFileSystemProgramSource(GetDesktopDirectory()) {}

private:
	std::wstring GetDesktopDirectory();
};

#endif