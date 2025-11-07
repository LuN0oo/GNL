/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:08:31 by analaphi          #+#    #+#             */
/*   Updated: 2025/11/07 16:23:25 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *res, char *buf)
{
	char	*tmp;

	if (!res || !buf)
		return (NULL);
	tmp = ft_strjoin(res, buf);
	free(res);
	return (tmp);
}

char	*find_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*find_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (!res)
		res = ft_calloc(1, 1);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(res, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(res);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		res = ft_free(res, buffer);
		if (!res)
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = read_file(fd, buffer);
	if (!tmp)
	{
		buffer = NULL;
		return (NULL);
	}
	buffer = tmp;
	if (buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = find_line(buffer);
	buffer = find_next_line(buffer);
	return (line);
}

// #include <stdio.h>
// #include "get_next_line.h"
// #include <fcntl.h>

// int main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	char *line;

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Line: %s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
