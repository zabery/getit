set(_INCLUDE_LIST
	../..
)

set(_LINK_LIST 
	programs
)

set(_SRC_LIST 
	main.cpp
	stdafx.h
)

include_directories(${_INCLUDE_LIST})
add_executable(GetIt ${_SRC_LIST})
target_link_libraries(GetIt ${_LINK_LIST})