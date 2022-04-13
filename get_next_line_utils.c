/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:14:04 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/10 22:46:17 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char	*string)
{
	size_t	index;

	index = 0;
	if (!string)
		return (0);
	while (string[index] != '\0')
		index++;
	return (index);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	index;
	size_t	count;
	char	*result;

	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	result = malloc ((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	index = -1;
	count = 0;
	if (str1)
		while (str1[++index] != '\0')
			result[index] = str1[index];
	while (str2[count] != '\0')
		result[index++] = str2[count++];
	result[ft_strlen(str1) + ft_strlen(str2)] = '\0';
	free(str1);
	return (result);
}

char	*ft_strchr(char *string, int n)
{
	int	index;

	index = 0;
	if (!string)
		return (0);
	if (n == '\0')
		return ((char *)&string[ft_strlen(string)]);
	while (string[index] != '\0')
	{
		if (string[index] == (char)n)
			return ((char *)&string[index]);
		index++;
	}
	return (0);
}





































// int    ft_strlen(char *str)
// {
//     int    i;

//     i = 0;
//     while (str[i])
//     {
//         i++;
//     }
//     return (i);
// }

// char    *ft_strdup(char *s)
// {
//     int        i;
//     char    *dst;

//     if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
//         return (NULL);
//     i = 0;
//     while (s[i])
//     {
//         dst[i] = s[i];
//         i++;
//     }
//     dst[i] = '\0';
//     return (dst);
// }

// char    *ft_strjoin(char *s1, char *s2)
// {
//     int        i;
//     int        j;
//     char    *tab;

//     if (!s1 && !s2)
//         return (NULL);
//     if (!s1)
//         return (ft_strdup(s2));
//     i = ft_strlen(s1) + ft_strlen(s2) + 1;
//     if (!(tab = (char *)malloc(sizeof(char) * i)))
//         return (NULL);
//     i = -1;
//     while (s1[++i])
//         tab[i] = s1[i];
//     j = -1;
//     while (s2[++j])
//     {
//         tab[i] = s2[j];
//         i++;
//     }
//     tab[i] = '\0';
//     free(s1);
//     return (tab);
// }