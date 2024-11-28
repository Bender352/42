#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd;
	char *buf;

	fd = open("utilities/text.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while ((buf = get_next_line(fd)))
	{
		if (!buf)
			break ;
		printf("%s", buf);
	}
	free(buf);
	return (0);
}
