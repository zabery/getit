#ifndef __GETIT_SRC_PROGRAMSFINDER_H__
#define __GETIT_SRC_PROGRAMSFINDER_H__

#include "include/modules/programs/programs_i.h"
class KyProgramsFinder : public IKyPrograms
{
public:
	KyProgramsFinder();
	void InitProgramsList();
	void RefreshProgramsList();
	void FindProgram(std::wstring skeyword, std::list<Entry> &entryResult);
	void IncreaseWeight(std::wstring sLnkPath, int nInc);

private:
	void GetAllPrograms(std::list<Entry> &entryList);
	void ReadWeightFromDb();
	void WriteWeightToDb();

private:
	std::list<Entry> m_entryList;
};

#endif