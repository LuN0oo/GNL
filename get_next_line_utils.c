/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:08:50 by analaphi          #+#    #+#             */
/*   Updated: 2025/11/03 18:29:17 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_charset(char c)
{
	if (c == '\n' || c == '\0')
		return (1);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof (char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = 0;
	return (str);
}