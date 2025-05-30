#include "c-logger.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static log_level_t current_log_level = LOG_LEVEL_DEBUG;

void log_init(log_level_t level)
{
  current_log_level = level;
}

void log_message(log_level_t level, const char *file, int line, const char *format, ...)
{
  if (level < current_log_level)
  {
    return;
  }

  const char *level_strings[] = {
      "\x1b[36mDEBUG\x1b[0m", // Cyan
      "\x1b[32mINFO\x1b[0m",  // Green
      "\x1b[33mWARN\x1b[0m",  // Yellow
      "\x1b[31mERROR\x1b[0m", // Red
      "\x1b[35mFATAL\x1b[0m"  // Magenta
  };

  // Extract base file name from path
  const char *basefile = file;
  if (file)
  {
    const char *slash = strrchr(file, '/');
#ifdef _WIN32
    const char *backslash = strrchr(file, '\\');
    if (!slash || (backslash && backslash > slash))
      slash = backslash;
#endif
    if (slash)
      basefile = slash + 1;
  }

  va_list args;
  va_start(args, format);

  fprintf(stderr, "[%s] %s:%d: ", level_strings[level],
          basefile ? basefile : "unknown", line);
  vfprintf(stderr, format, args);
  fprintf(stderr, "\n");

  va_end(args);
}