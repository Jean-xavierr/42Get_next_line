#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	int		i;
	int		n;
	int		c;
	char	*line;

	i = 1;
	n = 1;
	c = 1;
	argc = 0;
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		printf("error open()");
		return (0);
	}
	fd2 = open(argv[2], O_RDONLY);
	if (fd1 == -1)
	{
		printf("error open()");
		return (0);
	}
	while (i != 0 && n != 0 && c != 0)
	{
		printf("ret fd1 [%d] = ", (i = get_next_line(fd1, &line)));
		printf("|%s|\n", line);
		free(line);
		printf("ret fd2 [%d] = ", (n = get_next_line(fd2, &line)));
		printf("|%s|\n", line);
		free(line);
		printf("ret stand [%d] = ", (c = get_next_line(0, &line)));
		printf("|%s|\n", line);
		free(line);
	}
	return (0);
}
