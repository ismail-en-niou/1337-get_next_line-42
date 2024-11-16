/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:29:52 by ien-niou          #+#    #+#             */
/*   Updated: 2024/11/16 16:49:41 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char **storage)
{
	char	*line;
	char	*newline_ptr;
	char	*temp;

	newline_ptr = ft_strchr(*storage, '\n');
	if (newline_ptr)
	{
		line = ft_substr(*storage, 0, newline_ptr - *storage + 1);
		temp = ft_strdup(newline_ptr + 1);
		free(*storage);
		*storage = temp;
	}
	else
	{
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
	}
	return (line);
}

static int	read_to_storage(int fd, char **storage)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*storage, buffer);
		free(*storage);
		*storage = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*storage[10240];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage[fd])
		storage[fd] = ft_strdup("");
	bytes_read = read_to_storage(fd, &storage[fd]);
	if (bytes_read < 0 || (!storage[fd] && bytes_read == 0))
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	line = extract_line(&storage[fd]);
	if (!line || !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
