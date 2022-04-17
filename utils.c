/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:07:11 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/17 02:36:29 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, '\0', n);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i++) = c;
	}
	return (s);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	l_s;
	char	*res;

	l_s = ft_strlen(s);
	if (start > l_s || len <= 0)
		return (ft_strdup(""));
	if ((start + len) > l_s)
	{
		res = (char *)ft_calloc(l_s - start + 1, sizeof(char));
		if (!res)
			return (NULL);
		ft_strlcpy(res, s + start, l_s - start + 1);
		return (res);
	}
	res = (char *) ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s + start, len + 1);
	free(s);
	return (res);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (!s)
		return ;
	while (s[index])
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
}
