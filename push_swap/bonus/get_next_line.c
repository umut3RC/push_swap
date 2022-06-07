/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.t>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:55:22 by uercan            #+#    #+#             */
/*   Updated: 2022/02/28 12:05:53 by uercan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

char	*buffer_size_kadar_oku(int fd, char *add_next)
{
	int		i;
	char	*buf;

	i = 1;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while (!ft_strchr(add_next, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		add_next = ft_strjoin(add_next, buf);
	}
	free(buf);
	return (add_next);
}

char	*n_oncesi(char *add_next)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!add_next[0])
		return (NULL);
	while (add_next[i] != '\0' && add_next[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	while (add_next[j] != '\0' && add_next[j] != '\n')
	{
		str[j] = add_next[j];
		j++;
	}
	if (add_next[j] == '\n')
	{
		str[j] = '\n';
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*n_sonrasi(char *add_next)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (add_next[i] != '\0' && add_next[i] != '\n')
		i++;
	if (!add_next[i])
	{
		free(add_next);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(add_next) - i));
	if (!str)
		return (NULL);
	i++;
	while (add_next[i + j] != '\0')
	{
		str[j] = add_next[i + j];
		j++;
	}
	str[j] = '\0';
	free(add_next);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*add_next;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	add_next = buffer_size_kadar_oku(fd, add_next);
	if (!add_next)
		return (NULL);
	line = n_oncesi(add_next);
	add_next = n_sonrasi(add_next);
	return (line);
}
