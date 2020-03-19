#ifndef HELLO_APP_COMMON_COMMON_HPP_
#define HELLO_APP_COMMON_COMMON_HPP_

// logger setting
#define HELLO_APP_LOGGER_NAME "hello_app"

#define HELLO_APP_LOGGER_LOGGER_ERROR_FILENAME "logs/hello_app_error.log"
#define HELLO_APP_LOGGER_LOGGER_TRACE_FILENAME "logs/hello_app_trace.log"

#define HELLO_APP_LOGGER_PATTERN "[%Y-%m-%d %H:%M:%S.%e][%^%l%$][%t][%s:%#] %v"
#define HELLO_APP_LOGGER_ROTATING_MAX_FILE_SIZE (1024*1024)
#define HELLO_APP_LOGGER_ROTATING_MAX_FILE_NUM 5

#endif

