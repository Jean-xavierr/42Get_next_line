/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_tester.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:06:35 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/04 16:20:03 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int		main(void)
{
	int		i;
	int		n;
	int		fd;
	char	*line;

	
	printf("\n==========================================\n");
	printf("============= TEST 1 : Empty File ========\n");
	printf("==========================================\n\n");
	
	n = 1;
	if (!(fd = open("test_files/01_empty_file", O_RDONLY)))
	{
		printf("error open()\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) == 1)
	{
		printf("ret[%d] == ", i);
		printf("|%s|\n", line);
		free(line);
		n++;
	}
	printf("ret[%d] == ", i);
	printf("|%s|\n\n", line);
	free(line);
	if (BUFFER_SIZE == 0 && i == -1)
		printf("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (n == 1)
		printf ("Well done\n");
	else if (n != 1)
		printf("Wrong number of lines\n");

	printf("\n==========================================\n");
	printf("=== TEST 2 : Line without no nl at end ===\n");
	printf("==========================================\n\n");
	
	n = 1;
	if (!(fd = open("test_files/02_file_without_nl_at_end", O_RDONLY)))
	{
		printf("error open()\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) == 1)
	{
		printf("ret[%d] == ", i);
		printf("|%s|\n", line);
		free(line);
		n++;
	}
	printf("ret[%d] == ", i);
	printf("|%s|\n\n", line);
	free(line);
	if (BUFFER_SIZE == 0 && i == -1)
		printf("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (n == 1)
		printf ("Well done\n");
	else if (n != 1)
		printf("Wrong number of lines\n");

	printf("\n==========================================\n");
	printf("========== TEST 3 : File Short Line ======\n");
	printf("==========================================\n\n");
	
	n = 1;
	if (!(fd = open("test_files/03_file_short_line", O_RDONLY)))
	{
		printf("error open()\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) == 1)
	{
		printf("ret[%d] == ", i);
		printf("|%s|\n", line);
		free(line);
		n++;
	}
	printf("ret[%d] == ", i);
	printf("|%s|\n\n", line);
	free(line);
	if (BUFFER_SIZE == 0 && i == -1)
		printf("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (n == 2)
		printf ("Well done\n");
	else if (n != 2)
		printf("Wrong number of lines\n");

	printf("\n==========================================\n");
	printf("========= TEST 4 : File Short Lines ======\n");
	printf("==========================================\n\n");

	n = 1;
	if (!(fd = open("test_files/04_file_short_lines", O_RDONLY)))
	{
		printf("error open()\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) == 1)
	{
		printf("ret[%d] == ", i);
		printf("|%s|\n", line);
		free(line);
		n++;
	}
	printf("ret[%d] == ", i);
	printf("|%s|\n\n", line);
	free(line);
	if (BUFFER_SIZE == 0 && i == -1)
		printf("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (n == 17)
		printf ("Well done\n");
	else if (n != 17)
		printf("Wrong number of lines\n");

	printf("\n==========================================\n");
	printf("== TEST 5 : File Short Lines without nl ==\n");
	printf("==========================================\n\n");

	n = 1;
	if (!(fd = open("test_files/05_file_short_lines_without_nl_at_end", O_RDONLY)))
	{
		printf("error open()\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) == 1)
	{
		printf("ret[%d] == ", i);
		printf("|%s|\n", line);
		free(line);
		n++;
	}
	printf("ret[%d] == ", i);
	printf("|%s|\n\n", line);
	free(line);
	if (BUFFER_SIZE == 0 && i == -1)
		printf("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (n == 12)
		printf ("Well done\n");
	else if (n != 12)
		printf("Wrong number of lines\n");

	printf("\n==========================================\n");
	printf("== TEST 6 : File Long Line ==\n");
	printf("==========================================\n\n");

	n = 1;
	if (!(fd = open("test_files/06_file_long_line", O_RDONLY)))
	{
		printf("error open()\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) == 1)
	{
		printf("ret[%d] == ", i);
		printf("|%s|\n", line);
		free(line);
		n++;
	}
	printf("ret[%d] == ", i);
	printf("|%s|\n\n", line);
	free(line);
	if (BUFFER_SIZE == 0 && i == -1)
		printf("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (n == 2)
		printf ("Well done\n");
	else if (n != 2)
		printf("Wrong number of lines\n");

	printf("\n==========================================\n");
	printf("======== TEST 7 : File Long Lines ========\n");
	printf("==========================================\n\n");

	n = 1;
	if (!(fd = open("test_files/07_file_long_lines", O_RDONLY)))
	{
		printf("error open()\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) == 1)
	{
		printf("ret[%d] == ", i);
		printf("|%s|\n", line);
		free(line);
		n++;
	}
	printf("ret[%d] == ", i);
	printf("|%s|\n\n", line);
	free(line);
	if (BUFFER_SIZE == 0 && i == -1)
		printf("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (n == 22)
		printf ("Well done\n");
	else if (n != 22)
		printf("Wrong number of lines\n");

	return (0);
}
