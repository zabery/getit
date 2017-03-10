#ifndef __GETIT_MODEL_CURRENTUSERSTARTMENUPROGRAMSOURCE_H__
#define __GETIT_MODEL_CURRENTUSERSTARTMENUPROGRAMSOURCE_H__

#include "filesystemprogramsource.h"
class KyCurrentUserStartMenuProgramSource : public KyFileSystemProgramSource
{
public:
	KyCurrentUserStartMenuProgramSource() : KyFileSystemProgramSource(GetCurrentUserStartMenuDirectory()) {}

private:
	std::wstring GetCurrentUserStartMenuDirectory();
};

#endif