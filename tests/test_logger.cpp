#include "logger/logger.hpp"

int main()
{
    HelloLoggerInit(true, true, true, true);

    HELLO_LOGGER_TRACE("hello logger, {}", 2020);
    HELLO_LOGGER_DEBUG("hello logger, {}", 2020);
    HELLO_LOGGER_INFO("hello logger, {}", 2020);
    HELLO_LOGGER_WARN("hello logger, {}", 2020);
    HELLO_LOGGER_ERROR("hello logger, {}", 2020);
    HELLO_LOGGER_CRITICAL("hello logger, {}", 2020);

    HelloLoggerDrop();

    return 0;
}
