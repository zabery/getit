cmake_minimum_required(VERSION 2.8.0)

include("cmake/precheck.cmake")

project(GetIt)

include("cmake/setting.cmake")

add_subdirectory(3rdparty)
add_subdirectory(modules)
add_subdirectory(shell)