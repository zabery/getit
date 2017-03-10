set(_INCLUDE_LIST
	../..
)
set(_SRC_LIST 
	abstractprogramsource.cpp
	abstractprogramsource.h
	alluserstartmenuprogramsource.cpp
	alluserstartmenuprogramsource.h
	currentuserstartmenuprogramsource.cpp
	currentuserstartmenuprogramsource.h
	desktopprogramsource.cpp
	desktopprogramsource.h
	filesystemprogramsource.cpp
	filesystemprogramsource.h
	programsfinder.cpp
	programsfinder.h
	stdafx.h
)

include_directories(${_INCLUDE_LIST})
add_library(programs SHARED ${_SRC_LIST})


