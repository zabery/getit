#ifndef __GETIT_MODEL_ABSTRACTPROGRAMSOURCE_H__
#define __GETIT_MODEL_ABSTRACTPROGRAMSOURCE_H__

#include "include/modules/programs/programs_i.h"
class KyAbstractProgramSource
{
public:
	KyAbstractProgramSource();
	virtual ~KyAbstractProgramSource();
	virtual void LoadPrograms(std::list<Entry> &entryList) = 0;

protected:
	Entry CreateEntry(std::wstring sExecutePath);

private:
	std::shared_ptr<IShellLink> m_spShellLink;
	std::shared_ptr<IPersistFile> m_spPersistFile;
};

#endif
