/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:26:13 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/01 15:36:57 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_is_c(char *storage_read, char c)
{
	int	i;

	i = 0;
	if (storage_read == NULL)
		return (0);
	while (storage_read[i])
	{
		if (storage_read[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_get_info(int fd, char **storage_read, char **line, char c)
{
	char	*tmp;

	*line = ft_find_line(storage_read[fd], '\n');
	tmp = storage_read[fd];
	storage_read[fd] = ft_strcut_c(storage_read[fd], '\n');
	free(tmp);
	if (c == '\n')
		return (GNL_LINE_READ);
	if (c == '\0')
		return (GNL_EOF);
	return (0);
}

int		ft_read_file(int fd, char **storage_read, char **line)
{
	int		ret_read;
	char	*tmp;
	char	*buf;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (GNL_ERROR);
	while ((ret_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (ret_read < 0)
			break ;
		tmp = storage_read[fd];
		buf[ret_read] = '\0';
		storage_read[fd] = ft_strjoin(storage_read[fd], buf);
		free(tmp);
		if (ft_is_c(storage_read[fd], '\n') == 1)
			break ;
	}
	free(buf);
	if (ret_read >= 0 && ft_is_c(storage_read[fd], '\n'))
		return (ft_get_info(fd, storage_read, line, '\n'));
	if (ret_read == 0)
		return (ft_get_info(fd, storage_read, line, '\0'));
	return (GNL_ERROR);
}

int		get_next_line(int fd, char **line)
{
	static char *storage_read[100000];
	
	if (line == NULL)
		return (GNL_ERROR);
	if (fd >= 0 && !(storage_read[fd]) && BUFFER_SIZE > 0)
	{
		if (!(storage_read[fd] = (char *)malloc(sizeof(char))))
			return (GNL_ERROR);
		storage_read[fd][0] = '\0';
	}
	if (fd >= 0 && ft_is_c(storage_read[fd], '\n') && BUFFER_SIZE > 0)
		return (ft_get_info(fd, storage_read, line, '\n'));
	if (fd >= 0 && storage_read[fd] != NULL)
		return (ft_read_file(fd, storage_read, line));
	return (GNL_ERROR);
}
