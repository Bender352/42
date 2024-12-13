#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    char *line;

    // Open the file
    fd = open("text.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return (1);
    }

    // Read and print lines until EOF
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    // Close the file descriptor
    if (close(fd) < 0) {
        perror("Error closing file");
        return (1);
    }

    return (0);
}