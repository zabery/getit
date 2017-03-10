#include "stdafx.h"
#include "abstractprogramsource.h"
#include "include/utility/pathhandler.h"
#include "include/utility/spellhelper.h"

KyAbstractProgramSource::KyAbstractProgramSource()
{
	HRESULT hr = ::CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (LPVOID*)&m_spShellLink);
	hr = m_spShellLink->QueryInterface(IID_IPersistFile, (LPVOID*)&m_spPersistFile);
}

KyAbstractProgramSource::~KyAbstractProgramSource()
{
	m_spShellLink->Release();
	m_spPersistFile->Release();
}

Entry KyAbstractProgramSource::CreateEntry(std::wstring sPath)
{
	Entry entry;
	std::wstring sExtension = KyUtility::ToLower(KyUtility::GetExtension(sPath));
	if (sExtension == L".lnk")
	{
		SHFILEINFO info;
		SHGetFileInfo(sPath.c_str(), NULL, &info, sizeof(SHFILEINFO), SHGFI_ICON | SHGFI_DISPLAYNAME);
		entry.sTitle = info.szDisplayName;

		m_spPersistFile->Load(sPath.c_str(), STGM_READ);
		WIN32_FIND_DATA data;
		WCHAR szPath[MAX_PATH];
		m_spShellLink->GetPath(szPath, MAX_PATH, &data, SLGP_RAWPATH);
		DoEnvironmentSubst(szPath, MAX_PATH);

		WCHAR szArgs[MAX_PATH];
		m_spShellLink->GetArguments(szArgs, MAX_PATH);
		std::wstring sArgs = szArgs;

		WCHAR szIcoPath[MAX_PATH];
		int nIcoIndex;
		m_spShellLink->GetIconLocation(szIcoPath, MAX_PATH, &nIcoIndex);
		DoEnvironmentSubst(szIcoPath, MAX_PATH);

		entry.sTitle = KyUtility::GetFileNameWithoutExtension(sPath);
		entry.sLnkPath = sPath;
		entry.sExecutePath = szPath;
		entry.sIcoPath = szIcoPath;
		entry.nIcoIndex = nIcoIndex;
		entry.sExecuteName = KyUtility::GetFileNameWithoutExtension(entry.sExecutePath);
		WCHAR szPinyin[MAX_PATH];
		wcscpy(szPinyin, entry.sTitle.c_str());
		entry.sPinYinTitle = KyUtility::ConvertChineseToPinYin(szPinyin);
	}

	return entry;
}