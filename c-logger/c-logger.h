#ifndef C_LOGGER_H
#define C_LOGGER_H

#include <stdio.h>

typedef enum
{
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL
} log_level_t;

void log_init(log_level_t level);
void log_message(log_level_t level, const char *file, int line, const char *format, ...);

#define LOG_DEBUG(format, ...) log_message(LOG_LEVEL_DEBUG, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_INFO(format, ...) log_message(LOG_LEVEL_INFO, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_WARN(format, ...) log_message(LOG_LEVEL_WARN, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...) log_message(LOG_LEVEL_ERROR, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define LOG_FATAL(format, ...) log_message(LOG_LEVEL_FATAL, __FILE__, __LINE__, format, ##__VA_ARGS__)

void test_logger(void);

#endif // C_LOGGER_H