/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:17:40 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/12 22:18:43 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *stored, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!stored)
	{
		stored = (char *)malloc(1);
		stored[0] = '\0';
	}
	if (!stored || !buffer)
		return (NULL);
	str = (char *)malloc(ft_strlen(stored) + ft_strlen(buffer) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (stored)
		while (stored[++i] != '\0')
			str[i] = stored[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(stored) + ft_strlen(buffer)] = '\0';
	free(stored);
	return (str);
}

char	*extract_line(char *stored)
{
	int		i;
	char	*str;

	i = 0;
	if (!stored[i])
		return (NULL);
	while (stored[i] && stored[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (stored[i] && stored[i] != '\n')
	{
		str[i] = stored[i];
		i++;
	}
	if (stored[i] == '\n')
	{
		str[i] = stored[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*clean_last_line(char *stored)
{
	int		i;
	int		j;
	char	*clean;

	i = 0;
	while (stored[i] && stored[i] != '\n')
		i++;
	if (!stored[i])
	{
		free(stored);
		return (NULL);
	}
	clean = (char *)malloc(ft_strlen(stored) - i + 1);
	if (!clean)
		return (NULL);
	i++;
	j = 0;
	while (stored[i])
		clean[j++] = stored[i++];
	clean[j] = '\0';
	free(stored);
	return (clean);
}
