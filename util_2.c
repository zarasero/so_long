/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:21:13 by zserobia          #+#    #+#             */
/*   Updated: 2024/08/24 11:39:41 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*new_rest(char *rest, char *line)
{
	int		len_rest;
	int		len_line;
	int		i;
	char	*str;

	i = 0;
	len_rest = ft_strlen(rest);
	len_line = ft_strlen(line);
	if (len_rest <= len_line)
	{
		free(rest);
		return (NULL);
	}
	str = malloc(sizeof(char) * (len_rest - len_line + 1));
	if (!str)
		return (NULL);
	while (i < len_rest - len_line)
	{
		str[i] = rest[len_line + i];
		i++;
	}
	str[len_rest - len_line] = '\0';
	free(rest);
	return (str);
}

char	*read_line(char *rest)
{
	int		i;
	char	*str;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		str[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		str[i] = rest[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_tous_line(int fd, char *rest)
{
	char	*buffer;
	char	*temp;
	int		byte_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0 && (!rest || !ft_strchr(rest, '\n')))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		temp = rest;
		rest = ft_strjoin(rest, buffer);
		free(temp);
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest = read_tous_line(fd, rest);
	if (!rest)
		return (NULL);
	line = read_line(rest);
	rest = new_rest(rest, line);
	return (line);
}
