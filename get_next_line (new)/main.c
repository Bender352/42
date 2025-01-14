#include "get_next_line.h"

int main (void)
{
    char    *buf;
    int fd = open("text.txt", O_RDONLY);
    while (buf = get_next_line(fd))
        printf("%s", buf);
    free(buf);
}