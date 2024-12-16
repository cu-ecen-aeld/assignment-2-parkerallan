#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>

int main(int argc, char *argv[]) {

    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    // Check the formatting
    if (argc != 3) {
        syslog(LOG_ERR, "Error: Must pass in two arguments: Write file and the string");
        fprintf(stderr, "Format: %s <file> <string>\n", argv[0]);
        closelog();
        return EXIT_FAILURE;
    }

    const char *filePath = argv[1];
    const char *string = argv[2];

    // Open file
    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error: Cannot open file %s: %s", filePath, strerror(errno));
        perror("fopen");
        closelog();
        return EXIT_FAILURE;
    }

    // Write to file
    if (fprintf(file, "%s", string) < 0) {
        syslog(LOG_ERR, "Error: Cannot write to file %s: %s", filePath, strerror(errno));
        perror("fprintf");
        fclose(file);
        closelog();
        return EXIT_FAILURE;
    }

    syslog(LOG_DEBUG, "Success: Write '%s' to %s", string, filePath);

    fclose(file);
    closelog();

    return EXIT_SUCCESS;
}