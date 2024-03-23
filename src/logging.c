#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../include/logging.h"

char *get_timestamp();

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

// Function to get current timestamp
char* get_timestamp() {
    time_t rawtime;
    struct tm* timeinfo;
    char* timestamp = malloc(sizeof(char) * 26); // Allocate memory for timestamp string

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Format time into timestamp string
    strftime(timestamp, 26, "%a %b %d %H:%M:%S %Y", timeinfo);

    return timestamp;
}
