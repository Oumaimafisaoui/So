/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:14:04 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/16 21:15:24 by oufisaou         ###   ########.fr       */
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
