#ifndef __GETIT_INCLUDE_IPROGRAMS_H__
#define __GETIT_INCLUDE_IPROGRAMS_H__

#include "stdafx.h"
#include <list>
#include <string>

struct Entry
{
	std::wstring sTitle;			// 显示名（用于搜索）
	std::wstring sPinYinTitle;		// 拼音（用于搜索）
	std::wstring sAbbrTitle;		// 简写（用于搜索）
	std::wstring sLnkPath;			// .lnk路径
	std::wstring sExecutePath;		// .exe路径(不包括参数)
	std::wstring sExecuteName;		// .exe名称（用于搜索）
	std::wstring sIcoPath;
	int			 nIcoIndex;
	int			 nScore;
};

interface IKyPrograms
{
	virtual void InitProgramsList() = 0;
	virtual void RefreshProgramsList() = 0;
	virtual void FindProgram(std::wstring skeyword, std::list<Entry> &entryResult) = 0;
	virtual void IncreaseWeight(std::wstring sLnkPath, int nInc) = 0;
};

__declspec(dllexport) IKyPrograms* __stdcall GetProgramsInterface();

#endif