#include <stdio.h>
#include <string.h>

#include "logging.h"

void print_help();

int main(int argc, char *argv[]) {
    int i, verbose;

    verbose = 0;
    for (i = 1 ; i < argc ; i++) {
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0; // Exit after printing help
        } else {
            printf("Unknown option: %s\n", argv[i]);
            print_help();
            return 1; // Exit after printing help
        } // end if
    } // end for

    if (verbose) {
        log_message(INFO, "Verbose mode enabled");
    } // end if

    log_message(INFO, "Program started");

    log_message(INFO, "Hello, World!");

    log_message(INFO, "Program finished");

    return 0;
}

void print_help() {
    printf("Usage: program [-v|--verbose] [-h|--help]\n");
    printf("Options:\n");
    printf("\t-h, --help\t\tShow this help message\n");
    printf("\t-v, --verbose\t\tEnable verbose mode\n");
}
