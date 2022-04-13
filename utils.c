/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:07:11 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/13 21:38:56 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//error function

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
	size_t i;

	i = 0;
	while(i < n)
	{
		*(unsigned char *)(s + i++) = c; 
	}
	return (s);
}

char *ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	l_s;
	char	*res;


	l_s = ft_strlen(s);
	if(start > l_s || len <= 0)
		return (ft_strdup(""));
	if((start + len) > l_s)
	{
		res = (char *)ft_calloc(l_s - start + 1, sizeof(char));
		if(!res)
			return (NULL);
		ft_strlcpy(res, s + start, l_s - start + 1);
		return (res);

	}

	res = (char *) ft_calloc(len + 1, sizeof(char));
	if(!res)
		return (NULL);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}

void ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if(!s)
		return ;
	while(s[index])
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int ft_strcmp(const char *s1, const char *s2)
{
	size_t idx;

	idx = 0;
	while((s1[idx] != '\0' || s2[idx] != '\0'))
	{
		if(s1[idx] != s2[idx])
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		idx++;
	}
	return (0);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	p = malloc(num * size);
	if(p == 0)
		return (p);
	ft_bzero(p, num * size);
	return (p);
}
size_t ft_strlcpy(char *dest, char *src, size_t size)
{
    size_t index;
    
    if(!size)
        return (ft_strlen(src));
    index = 0;
    while(src[index] && index < size - 1)
    {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';
    return (ft_strlen(src));
}

char *ft_strdup(char *str)
{
	size_t l_str;
	char *p;
	
	l_str = ft_strlen(str) + 1;
	p = ft_calloc(l_str, sizeof(char));
	if(p == NULL)
		return (NULL);
	ft_strlcpy(p, str, l_str);
	return (p);
}
int	ft_intlen(int n)
{
	int counter;

	counter = 0;
	if(n <= 0)
		++counter;
	while(n !=  0)
	{
		++counter;
		n /= 10;
	}
	return (counter);
}



char *ft_itoa(int n)
{
	long	nbr;
	char	*s;
	int	l_s;

	nbr = n;
	l_s = ft_intlen(nbr);
	s = malloc(sizeof(char) * (l_s + 1));

	if(s == NULL)
		return (NULL);
	s[l_s--] = '\0';
	if(nbr == 0)
		s[0] = '0';
	else if(nbr < 0)
	{
		nbr *= -1;
		s[0] = '-';
	}
	while(nbr > 0)
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
