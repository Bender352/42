#include "get_next_line.h"

int main(void)
{
    int fd;
    char    *buf;

    fd = open("utilities/text.txt", O_RDONLY);
    while ((buf = get_next_line(fd)))
    {
        printf("%s", buf);
    }
    return (0);
}