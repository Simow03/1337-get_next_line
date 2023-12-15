/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 05:52:38 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/15 19:36:22 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_store(int fd, char *stored)
{
	char	*buffer;
	int		readed;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_strchr(stored, '\n') && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		stored = ft_strjoin(stored, buffer);
	}
	free(buffer);
	return (stored);
}

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0
		|| BUFFER_SIZE >= INT_MAX)
	{
		free(stored);
		stored = NULL;
		return (NULL);
	}
	stored = read_and_store(fd, stored);
	if (!stored)
		return (NULL);
	line = extract_line(stored);
	stored = clean_last_line(stored);
	return (line);
}
