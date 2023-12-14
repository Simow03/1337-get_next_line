/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 05:53:38 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/14 18:28:01 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
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