#pragma once

// for cmake
#define HELLO_APP_VER_MAJOR 0
#define HELLO_APP_VER_MINOR 1
#define HELLO_APP_VER_PATCH 0

#define HELLO_APP_VERSION (HELLO_APP_VER_MAJOR * 10000 + HELLO_APP_VER_MINOR * 100 + HELLO_APP_VER_PATCH)

// for source code
#define _HELLO_APP_STR(s) #s
#define HELLO_PROJECT_VERSION(major, minor, patch) "v" _HELLO_APP_STR(major.minor.patch)
