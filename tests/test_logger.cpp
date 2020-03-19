#include <iostream>

#include "common/common.hpp"
#include "logger/logger.hpp"

void LoggerInit() {
    HelloAppSpdlogSetLevel(HELLO_APP_SPDLOG_LEVEL_TRACE);
    HelloAppSpdlogSetPattern(HELLO_APP_LOGGER_PATTERN);
    HelloAppSpdlogRotatingLoggerMt(HELLO_APP_LOGGER_NAME,
            HELLO_APP_LOGGER_LOGGER_TRACE_FILENAME,
            HELLO_APP_LOGGER_ROTATING_MAX_FILE_SIZE,
            HELLO_APP_LOGGER_ROTATING_MAX_FILE_NUM);
}

int main(int argc, char* argv[]) {
    // only for rotaing
    //LoggerInit();

    // creating loggers with multiple sinks
    // default level is trace
    HelloAppSpdlogCombinedLoggerInit(true, true, true, true);
    //HelloAppSpdlogCombinedLoggerSetLevel(HELLO_APP_SPDLOG_LEVEL_TRACE);
    auto file_logger = HelloAppSpdlogGet(HELLO_APP_LOGGER_NAME);

    // testing
    HELLO_APP_SPDLOG_LOGGER_TRACE(file_logger, "hello, world! {}", 2020);
    HELLO_APP_SPDLOG_LOGGER_DEBUG(file_logger, "hello, world! {}", 2020);
    HELLO_APP_SPDLOG_LOGGER_INFO(file_logger, "hello, world! {}", 2020);
    HELLO_APP_SPDLOG_LOGGER_WARN(file_logger, "hello, world! {}", 2020);
    HELLO_APP_SPDLOG_LOGGER_ERROR(file_logger, "hello, world! {}", 2020);
    // drop logger
    HelloAppSpdlogDrop();

    return 0;
}

