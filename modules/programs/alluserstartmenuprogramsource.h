#ifndef __GETIT_MODEL_ALLUSERSTARTPROGRAMSOURCE_H__
#define __GETIT_MODEL_ALLUSERSTARTPROGRAMSOURCE_H__

#include "filesystemprogramsource.h"

class KyAllUserStartMenuProgramSource : public KyFileSystemProgramSource
{
public:
	KyAllUserStartMenuProgramSource() : KyFileSystemProgramSource(GetAllUserProgramDirectory()) {}

private:
	std::wstring GetAllUserProgramDirectory();
};

#endif