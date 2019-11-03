#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line.h"

int		main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("./test_files/08_file_crash_test", O_RDONLY);
	if (fd == -1)
	{
		printf("error open()");
		return (0);
	}
	while ((i = get_next_line(fd, &line)))
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
