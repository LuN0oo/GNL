/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:09:12 by analaphi          #+#    #+#             */
/*   Updated: 2025/11/03 17:40:21 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 5
#endif

char	*get_next_line(int ft);
int		ft_is_charset(char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif