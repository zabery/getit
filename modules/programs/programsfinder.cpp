#include "programsfinder.h"
#include "alluserstartmenuprogramsource.h"
#include "currentuserstartmenuprogramsource.h"
#include "desktopprogramsource.h"
#include "abstractprogramsource.h"
#include "include/utility/pathhandler.h"
#include <algorithm>
using namespace std;

IKyPrograms* __stdcall GetProgramsInterface()
{
	static KyProgramsFinder programFinder;
	return &programFinder;
}

KyProgramsFinder::KyProgramsFinder()
{
	m_entryList.clear();
}

void KyProgramsFinder::InitProgramsList()
{
	GetAllPrograms(m_entryList);
}

void KyProgramsFinder::RefreshProgramsList()
{
	list<Entry> tempEntryList;
	GetAllPrograms(tempEntryList);

	for (auto tmpIter = tempEntryList.begin(); tmpIter != tempEntryList.end(); ++tmpIter)
	{
		for (auto iter = m_entryList.begin(); iter != m_entryList.end(); ++iter)
		{
			if (iter->sLnkPath != tmpIter->sLnkPath)
			{
				m_entryList.push_back(*tmpIter);
			}
		}
	}
}

void KyProgramsFinder::FindProgram(std::wstring skeyword, std::list<Entry> &entryResult)
{
	auto iter = m_entryList.begin();
	std::wstring sLowerKeyWord = KyUtility::ToLower(skeyword);
	while (iter != m_entryList.end())
	{
		if (KyUtility::ToLower(iter->sTitle).find(sLowerKeyWord) != std::wstring::npos
			|| KyUtility::ToLower(iter->sExecuteName).find(sLowerKeyWord) != std::wstring::npos)
		{
			entryResult.push_back(*iter);
		}
		++iter;
	}
}

void KyProgramsFinder::IncreaseWeight(std::wstring sLnkPath, int nInc)
{
	auto iter = find_if(m_entryList.begin(), m_entryList.end(), [sLnkPath](Entry entry)->bool{
		return entry.sLnkPath == sLnkPath;
	});

	if (iter != m_entryList.end())
	{
		iter->nScore += nInc;
	}
}

void KyProgramsFinder::GetAllPrograms(std::list<Entry> &entryList)
{
	shared_ptr<KyAbstractProgramSource> spCurUserPrograms(new KyCurrentUserStartMenuProgramSource());
	spCurUserPrograms->LoadPrograms(entryList);
	shared_ptr<KyAbstractProgramSource> spAllUserPrograms(new KyAllUserStartMenuProgramSource());
	spAllUserPrograms->LoadPrograms(entryList);
	shared_ptr<KyAbstractProgramSource> spDesktopPrograms(new KyDesktopProgramSource());
	spDesktopPrograms->LoadPrograms(entryList);

	entryList.sort([](Entry lhs, Entry rhs)->bool{
		return lhs.sLnkPath < rhs.sLnkPath;
	});

	entryList.unique([](Entry lhs, Entry rhs)->bool{
		return lhs.sLnkPath == rhs.sLnkPath;
	});
}