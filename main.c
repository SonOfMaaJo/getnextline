#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int	fd;

	fd = 0;
	printf("%s", (char *)av[0]);
	if (ac > 1)
	{
		printf("%s", get_next_line(fd));
		return (0);
	}
	fd = open("test", O_RDONLY);
	if (fd == -1)
		return (0);
    printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
    return (0);
}

