/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:40:04 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/16 21:49:19 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_other(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->parse[i][j] != 'P' && map->parse[i][j] != '0' \
			&& map->parse[i][j] != '1' && map->parse[i][j] != 'C' \
			&& map->parse[i][j] != 'E' \
			&& map->parse[i][j] != 'N')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_strdup(char *str)
{
	size_t	l_str;
	char	*p;

	l_str = ft_strlen(str) + 1;
	p = ft_calloc(l_str, sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, str, l_str);
	return (p);
}

int	ft_intlen(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		++counter;
	while (n != 0)
	{
		++counter;
		n /= 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*s;
	int		l_s;

	nbr = n;
	l_s = ft_intlen(nbr);
	s = malloc(sizeof(char) * (l_s + 1));
	if (s == NULL)
		return (NULL);
	s[l_s--] = '\0';
	if (nbr == 0)
		s[0] = '0';
	else if (nbr < 0)
	{
		nbr *= -1;
		s[0] = '-';
	}
	while (nbr > 0)
	{
		s[l_s--] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (s);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	res;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		res = (n * (-1));
	}
	else
	{
		res = n;
	}
	if (res > 9)
	{
		ft_putnbr_fd(res / 10, fd);
	}
	ft_putchar_fd(res % 10 + '0', fd);
}
