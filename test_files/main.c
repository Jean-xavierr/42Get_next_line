#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	argc = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error open()");
		return (0);
	}
	while ((i = get_next_line(fd, &line) == 1))
	{
		printf("ret[%d] = ", i);
		printf("|%s|\n", line);
		free(line);
	}
	printf("ret[%d] = ", i);
	printf("|%s|\n", line);
	free(line);
	return (0);
}
