#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int 	i;

	i = 0;
	while(str[i++])
		;
	return (i - 1);
}

void	process_test(char *file)
{
	int	fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		printf("n_line :\n%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("%s", line);
}
int	main(void)
{
    printf("-------test de fichier 1----\n");
	process_test("test/test1");
    printf("\n\n----end-----");

	printf("\n\n\n-------test de fichier 2------\n");
	process_test("test/test2");
	printf("\n\n----end-----");

	printf("\n\n\n-------test de fichier 3------\n");
	process_test("test/test3");
	printf("\n\n----end-----");

	printf("\n\n\n-------test de fichier 4------\n");
	process_test("test/test4");
	printf("\n\n----end-----");

	printf("\n\n\n-------test de fichier 5------\n");
	process_test("test/test5");
	printf("\n\n----end-----");

	printf("\n\n\n-------test de fichier 6------\n");
	process_test("test/test7");
	printf("\n\n----end-----");
	return (0);
}
