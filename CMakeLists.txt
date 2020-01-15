cmake_minimum_required(VERSION 3.0)
project(libarduino VERSION 0.0.2)

option(STATIC "Build static library" 0)
option(ARDUINO "Set Arduino type" OFF)
option(LIB_INSTALL_DIR "Set directory the library will be installed in" OFF)
option(INC_INSTALL_DIR "Set directory the headers will be installed in" OFF)

include(GNUInstallDirs)

set(LIBARDUINO_DESCRIPTION "A Arduino mockup library")
set(LIBARDUINO_URL "https://github.com/Jan200101/arduino-mock")

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

if (NOT ARDUINO)
	set(ARDUINO "UNO")
endif()

if (NOT LIB_INSTALL_DIR)
	set(LIB_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
endif()

if (NOT INC_INSTALL_DIR)
    set(INC_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}")
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/source/libarduino/)

configure_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/arduino.pc.cmake.in"
	"${CMAKE_CURRENT_BINARY_DIR}/arduino.pc"
	@ONLY
)
install(FILES
	"${CMAKE_CURRENT_BINARY_DIR}/arduino.pc"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig"
)
