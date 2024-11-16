/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:29:52 by ien-niou          #+#    #+#             */
/*   Updated: 2024/11/16 16:45:52 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*storage, buffer);
		free(*storage);
		*storage = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	bytes_read = read_to_storage(fd, &storage);
	if (bytes_read < 0 || (!storage && bytes_read == 0))
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	line = extract_line(&storage);
	if (!line || !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
