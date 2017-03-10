#ifndef __GETIT_INCLUDE_IPROGRAMS_H__
#define __GETIT_INCLUDE_IPROGRAMS_H__

#include "stdafx.h"
#include <list>
#include <string>

struct Entry
{
	std::wstring sTitle;			// ��ʾ��������������
	std::wstring sPinYinTitle;		// ƴ��������������
	std::wstring sAbbrTitle;		// ��д������������
	std::wstring sLnkPath;			// .lnk·��
	std::wstring sExecutePath;		// .exe·��(����������)
	std::wstring sExecuteName;		// .exe���ƣ�����������
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