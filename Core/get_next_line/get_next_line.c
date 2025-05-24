/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:35:18 by amho              #+#    #+#             */
/*   Updated: 2025/05/25 02:29:39 by amho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*init_str(char **stored)
{
	*stored = (char *)malloc(sizeof(char) * 1);
	if (!*stored)
		return (NULL);
	(*stored)[0] = '\0';
	return (*stored);
}

static char	*read_line(int fd, char *buffer, char *stored)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!stored && !init_str(&stored))
			return (NULL);
		temp = stored;
		stored = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(stored, '\n'))
			break ;
	}
	return (stored);
}

static char	*extract_line(char *line)
{
	size_t	i;
	char	*stored;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	stored = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*stored == '\0')
	{
		free(stored);
		stored = NULL;
	}
	line[i + 1] = '\0';
	return (stored);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stored;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, stored);
	free(buffer);
	if (!line)
	{
		free(stored);
		stored = NULL;
		return (NULL);
	}
	stored = extract_line(line);
	return (line);
}
