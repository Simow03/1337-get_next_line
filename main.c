/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:02:30 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/13 19:04:16 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char	*line;

	int fd1 = open("tests/test1.txt", O_RDONLY);
	int fd2 = open("tests/test2.txt", O_RDONLY);
	int fd3 = open("tests/test3.txt", O_RDONLY);

	int i = 1;
	printf("\n-------------------------------------\n");
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("test1/line[%d] : %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);

	i = 1;
	printf("\n-------------------------------------\n");
	while (i < 7)
	{
		line = get_next_line(fd2);
		printf("test2/line[%d] : %s\n", i, line);
		free(line);
		i++;
	}
	close(fd2);

	i = 1;
	printf("\n-------------------------------------\n");
	while (i < 7)
	{
		line = get_next_line(fd3);
		printf("test3/line[%d] : %s\n", i, line);
		free(line);
		i++;
	}
	close(fd3);

	return (0);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
// ./a.out | cat -e