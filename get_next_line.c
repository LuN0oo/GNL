/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:08:31 by analaphi          #+#    #+#             */
/*   Updated: 2025/11/03 18:29:12 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// read mon texte jusqu'a trouver un charset (\n || \0) et le stocker dans mon stash A MALLOC

char	*read_line(int fd, char *s)
{
	static char	*stash;
	char		*buf;
	int			i;

	i = 0;
	stash = malloc(sizeof(BUFFER_SIZE));
	if (!stash)
		return (NULL);
	while (buf[i] && ft_is_charset(buf[i]))
	{
		read(fd, buf, BUFFER_SIZE);
		i++;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char *line;
	
	return (line);
}

#include <stdio.h>

int	main(void)
{
	int	fd = "text.txt";
	get_next_line(fd);
}