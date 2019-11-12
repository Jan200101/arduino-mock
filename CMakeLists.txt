cmake_minimum_required(VERSION 3.0)
project(libarduino)

option(STATIC "Build static library" 0)
option(ARDUINO "Set Arduino type" OFF)
option(LIB_INSTALL_DIR "Set directory the library will be installed in" ${CMAKE_INSTALL_LIBDIR})
option(INC_INSTALL_DIR "Set directory the headers will be installed in" ${CMAKE_INSTALL_INCDIR})

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

if (NOT ARDUINO)
	set(ARDUINO "UNO")
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/source/libarduino/)

