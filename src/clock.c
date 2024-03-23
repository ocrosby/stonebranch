#include <stdlib.h>
#include <time.h>

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
