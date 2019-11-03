/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:58:23 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/01 14:43:19 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_find_line(char *s, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strcut_c(char *s, char c)
{
	int		i;
	int		n;
	int		size;
	char	*tmp;

	i = 0;
	n = 0;
	size = ft_strlen(s);
	while (s[i] != c && s[i])
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * (size - i + 1))))
		return (NULL);
	if (size - i == 0)
	{
		tmp[0] = '\0';
		return (tmp);
	}
	while (s[++i])
		tmp[n++] = s[i];
	tmp[n] = '\0';
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[n])
		dest[i++] = s1[n++];
	n = 0;
	while (s2[n])
		dest[i++] = s2[n++];
	dest[i] = '\0';
	return (dest);
}
