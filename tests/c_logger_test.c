#include "c-logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(void)
{
    printf("Running c-logger test...\n");
    // Initialize the logger with DEBUG level
    log_init(LOG_LEVEL_DEBUG);
    LOG_DEBUG("This is a debug message");
    LOG_INFO("This is an info message");
    LOG_WARN("This is a warning message");
    LOG_ERROR("This is an error message");
    LOG_FATAL("This is a fatal message");
    return 0;
}