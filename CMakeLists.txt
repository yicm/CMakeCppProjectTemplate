CMAKE_MINIMUM_REQUIRED(VERSION 3.4)

#--------------------------------------------
# Project setting
#--------------------------------------------
INCLUDE(cmake/messagecolor.cmake)
INCLUDE(cmake/utils.cmake)
HELLO_APP_EXTRACT_VERSION()

PROJECT(HelloApp VERSION ${HELLO_APP_VERSION} LANGUAGES CXX)

OPTION(BUILD_TESTS "Build with tests" ON)

MESSAGE(INFO "--------------------------------")
MESSAGE(STATUS "Build HelloApp: ${HELLO_APP_VERSION}")
MESSAGE(STATUS "Build with tests: ${BUILD_TESTS}")
IF (NOT CMAKE_TOOLCHAIN_FILE)
    MESSAGE(STATUS "CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
ENDIF()

#--------------------------------------------
# Set compilation options
#--------------------------------------------
MESSAGE(INFO "--------------------------------")
INCLUDE(cmake/toolchain_options.cmake)
INCLUDE(cmake/load_3rdparty.cmake)

IF(NOT YOUR_TARGET_OS)
    SET(YOUR_TARGET_OS linux)
ENDIF()
IF(NOT YOUR_TARGET_ARCH)
    SET(YOUR_TARGET_ARCH x86-64)
ENDIF()
MESSAGE(STATUS "Your target os : ${YOUR_TARGET_OS}")
MESSAGE(STATUS "Your target arch : ${YOUR_TARGET_ARCH}")

LOAD_LIBSPDLOG(YOUR_TARGET_OS YOUR_TARGET_ARCH)

#--------------------------------------------
# Build 3rdparty
#--------------------------------------------
MESSAGE(INFO "--------------------------------")
#--------------------------------------------
ADD_SUBDIRECTORY(3rdparty)

# Build application
#--------------------------------------------
MESSAGE(INFO "--------------------------------")
ADD_SUBDIRECTORY(src)

IF(BUILD_TESTS)
    MESSAGE(INFO "--------------------------------")
    ADD_SUBDIRECTORY(tests)
ENDIF()


