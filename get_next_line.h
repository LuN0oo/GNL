/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:09:12 by analaphi          #+#    #+#             */
/*   Updated: 2025/11/06 16:21:21 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1000000
# endif

char	*ft_free(char *res, char *buf);
char	*find_line(char *buffer);
char	*find_next_line(char *buffer);
char	*read_file(int fd, char *res);
char	*get_next_line(int ft);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t count, size_t size);

#endif