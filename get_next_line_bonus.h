/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:17:21 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/14 18:27:54 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*read_and_store(int fd, char *stored);
char	*extract_line(char *stored);
char	*clean_last_line(char *stored);
char	*ft_strjoin(char *stored, char *buffer);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);

#endif