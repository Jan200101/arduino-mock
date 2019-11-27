cmake_minimum_required(VERSION 3.0)
project(libarduino)

option(STATIC "Build static library" 0)
option(ARDUINO "Set Arduino type" OFF)
option(LIB_INSTALL_DIR "Set directory the library will be installed in" OFF)
option(INC_INSTALL_DIR "Set directory the headers will be installed in" OFF)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

if (NOT ARDUINO)
	set(ARDUINO "UNO")
endif()

if (NOT LIB_INSTALL_DIR)
	set(LIB_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR})
endif()

if (NOT INC_INSTALL_DIR)
	set(INC_INSTALL_DIR ${CMAKE_INSTALL_INCDIR})
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/source/libarduino/)

