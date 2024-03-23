#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../include/clock.h"
#include "../include/logging.h"

// Function to log messages to a file with specified log level
int log_message(LogLevel level, const char* message) {
    const char* level_str;
    switch (level) {
        case INFO:
            level_str = "INFO";
            break;
        case WARNING:
            level_str = "WARNING";
            break;
        case ERROR:
            level_str = "ERROR";
            break;
        default:
            level_str = "UNKNOWN";
            break;
    }

    FILE* logfile = fopen("log.txt", "a"); // Open the log file in append mode
    if (logfile == NULL) {
        perror("Error opening log file");
        return 1;
    }

    // Get current timestamp
    char* timestamp = get_timestamp();

    // Write log message with timestamp and log level to the file
    fprintf(stdout, "[%s] [%s] %s\n", timestamp, level_str, message); // Print to stdout (console
    fprintf(logfile, "[%s] [%s] %s\n", timestamp, level_str, message);

    // Close the log file
    fclose(logfile);

    return 0;
}
