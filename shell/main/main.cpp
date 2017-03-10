#include "stdafx.h"
#include "include/modules/programs/programs_i.h"
#include <iostream>
#include <assert.h>
using namespace std;

int main()
{
	CoInitialize(NULL);

	list<Entry> entryList;
	GetProgramsInterface()->InitProgramsList();
	GetProgramsInterface()->FindProgram(L"¿´Í¼Íõ", entryList);
	entryList.clear();
	GetProgramsInterface()->FindProgram(L"wps", entryList);

#ifdef _DEBUG
	cout << "hello" << endl;
#endif
	system("pause");

	CoUninitialize();
	return 0;
}