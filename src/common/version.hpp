#pragma once

// for cmake
#define HELLO_VER_MAJOR 0
#define HELLO_VER_MINOR 1
#define HELLO_VER_PATCH 0

#define HELLO_VERSION (HELLO_VER_MAJOR * 10000 + HELLO_VER_MINOR * 100 + HELLO_VER_PATCH)

// for source code
#define _HELLO_STR(s) #s
#define HELLO_PROJECT_VERSION(major, minor, patch) "v" _HELLO_STR(major.minor.patch)
