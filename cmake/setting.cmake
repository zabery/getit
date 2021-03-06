set(GETIT_OUTPUT_ROOT_DIRECOTRY "${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${GETIT_OUTPUT_ROOT_DIRECOTRY}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${GETIT_OUTPUT_ROOT_DIRECOTRY}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${GETIT_OUTPUT_ROOT_DIRECOTRY}/bin")

if(CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
endif()