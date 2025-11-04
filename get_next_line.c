/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:08:31 by analaphi          #+#    #+#             */
/*   Updated: 2025/11/04 12:17:54 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// read mon texte jusqu'a trouver un charset (\n || \0) et le stocker dans mon stash A MALLOC

char	*read_line(int fd, char *s)
{
	static char	*stash;
	char		*rest;
	char		buf[BUFFER_SIZE + 1];
	int			i;

	i = 0;
	stash = malloc(BUFFER_SIZE + 1);
	if (!stash)
		return (NULL);
	while (s[i] && ft_strchr(s, '\n'))
	{
		read(fd, buf, BUFFER_SIZE);
	}
	stash = buf;
	return (stash);
}

char	*get_next_line(int fd)
{
	char *line;
	
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	printf("Line : %s\n", get_next_line(fd));
	printf("Line : %s\n", get_next_line(fd));
	printf("Line : %s\n", get_next_line(fd));
	printf("Line : %s\n", get_next_line(fd));
	printf("Line : %s\n", get_next_line(fd));
	return (0);
}