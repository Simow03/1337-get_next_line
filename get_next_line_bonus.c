/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:17:03 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/15 19:35:50 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*stored[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0
		|| BUFFER_SIZE >= INT_MAX)
	{
		free(stored[fd]);
		stored[fd] = NULL;
		return (NULL);
	}
	stored[fd] = read_and_store(fd, stored[fd]);
	if (!stored[fd])
		return (NULL);
	line = extract_line(stored[fd]);
	stored[fd] = clean_last_line(stored[fd]);
	return (line);
}
