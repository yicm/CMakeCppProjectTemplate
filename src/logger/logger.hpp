#ifndef _HELLO_CORE_LOGGER_LOGGER_HPP_
#define _HELLO_CORE_LOGGER_LOGGER_HPP_


#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

// You can define SPDLOG_ACTIVE_LEVEL to the desired log level before including "spdlog.h".
// This will turn on/off logging statements at compile time
#include "spdlog/spdlog.h"


// logger setting
#define HELLO_LOGGER_NAME "hello"
#define HELLO_LOGGER_LOGGER_ERROR_FILENAME "logs/hello_error.log"
#define HELLO_LOGGER_LOGGER_TRACE_FILENAME "logs/hello_trace.log"
#define HELLO_LOGGER_PATTERN "[%Y-%m-%d %H:%M:%S.%e][%^%l%$][%t][%s:%#] %v"
#define HELLO_LOGGER_ROTATING_MAX_FILE_SIZE (1024*1024)
#define HELLO_LOGGER_ROTATING_MAX_FILE_NUM 5


#define _TRACE 0
#define _DEBUG 1
#define _INFO 2
#define _WARN 3
#define _ERROR 4
#define _CRITI 5
#define _OFF 6

#define HELLO_LOGGER_TRACE(...) HelloLoggerOut(_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define HELLO_LOGGER_DEBUG(...) HelloLoggerOut(_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define HELLO_LOGGER_INFO(...) HelloLoggerOut(_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define HELLO_LOGGER_WARN(...) HelloLoggerOut(_WARN, __FILE__, __LINE__, __VA_ARGS__)
#define HELLO_LOGGER_ERROR(...) HelloLoggerOut(_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define HELLO_LOGGER_CRITICAL(...) HelloLoggerOut(_CRITI, __FILE__, __LINE__, __VA_ARGS__)


#ifdef __cplusplus
    extern "C" {
#endif


void HelloLoggerInit(
        const bool with_color_console,
        const bool with_console,
        const bool with_error,
        const bool with_trace);

void HelloLoggerSetLevel(const int level);

void HelloLoggerSetPattern(const char* format);

void HelloLoggerSetFlushEvery(const int interval);

void HelloLoggerDrop();


#ifdef __cplusplus
    }
#endif

template<typename... T>
void HelloLoggerOut(const int level,
        const char* filename,
        const int line,
        const T &...msg) {
    // Note: sdplog::get is a thread safe function
    std::shared_ptr<spdlog::logger> logger_ptr = spdlog::get(HELLO_LOGGER_NAME);
    if (!logger_ptr) {
        fprintf(stderr, "Failed to get logger, Please init logger firstly.\n");
    }
    logger_ptr.get()->log(spdlog::source_loc{filename, line,
            SPDLOG_FUNCTION},
            static_cast<spdlog::level::level_enum>(level),
            msg...);
}


#endif
