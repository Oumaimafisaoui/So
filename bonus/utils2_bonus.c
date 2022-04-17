/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 23:13:09 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/16 23:04:35 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	idx;

	idx = 0;
	while ((s1[idx] != '\0' || s2[idx] != '\0'))
	{
		if (s1[idx] != s2[idx])
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		idx++;
	}
	return (0);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	p = malloc(num * size);
	if (p == 0)
		return (p);
	ft_bzero(p, num * size);
	return (p);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	index;

	if (!size)
		return (ft_strlen(src));
	index = 0;
	while (src[index] && index < size - 1)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (ft_strlen(src));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
