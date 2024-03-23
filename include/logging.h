#ifndef _LOGGING_H_
#define _LOGGING_H_

// Define log levels
typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

int log_message(LogLevel level, const char *message);

#endif // _LOGGING_H_
// Path: logging.h