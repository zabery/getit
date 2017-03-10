#ifndef __GETIT_COMMON_PATHHANDLER_H__
#define __GETIT_COMMON_PATHHANDLER_H__

#include <string>

namespace KyUtility
{
	typedef std::wstring wstring;

	inline
		wstring GetFileNameWithoutExtension(wstring sPath)
	{
		size_t nPos = sPath.find_last_of('\\');
		if (nPos != wstring::npos && nPos < sPath.length() - 1)
		{
			sPath = sPath.substr(nPos + 1);
			nPos = sPath.find_last_of('.');
			if (nPos != wstring::npos)
			{
				sPath = sPath.substr(0, nPos);
			}
		}
		return sPath;
	}

	inline
		wstring GetFileName(wstring sPath)
	{
		size_t nPos = sPath.find_last_of('\\');
		if (nPos != wstring::npos && nPos < sPath.length() - 1)
		{
			sPath = sPath.substr(nPos + 1);
		}
		return sPath;
	}

	inline
		wstring GetExtension(wstring sPath)
	{
		size_t nPos = sPath.find_last_of('\\');
		if (nPos != wstring::npos && nPos < sPath.length() - 1)
		{
			sPath = sPath.substr(nPos + 1);
			nPos = sPath.find_last_of('.');
			if (nPos != wstring::npos)
			{
				sPath = sPath.substr(nPos);
			}
		}
		return sPath;
	}

	inline
		wstring ToLower(wstring sText)
	{
		for (auto iter = sText.begin(); iter != sText.end(); ++iter)
		{
			*iter = tolower(*iter);
		}
		return sText;
	}
}

#endif