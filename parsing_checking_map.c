/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checking_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:41:51 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/14 05:21:20 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 
	
int	count_width(char *map)
{
	int		index;
	int		width;

	index = 0;
	width = 0;
	while (map[index] != '\0')
	{
		if (map[index] == '\n')
			width++;
		index++;
	}
	return (width);
}


void	free_map(t_map *map, int flag)
{
	int index;

	index = 0;
	while (index < map->height)
	{
		free(map->parse[index]);
		index++;
	}
	free(map->parse);
	if(flag == 1)
		error("Invalid map width or height\n");
	else if(flag == 2)
		error("Invalid map's objects\n");
	else if(flag == 3)
		error("Invalisd map walls in width\n");
	else if(flag == 4)
		error("Invalid map walls in height or objects\n");
}


int	parsing_checking_map(char *map_arg, t_map *map)
{
	char	*array;
	int fd;

	int index;
	
	index = 0;
	fd = open(map_arg, O_RDONLY);
	if(fd == -1)
		error("map couldn't be found\n");
	array = get_next_line(fd);
	while(1)
	{
		if(array == NULL)
			break;
		array = get_next_line(fd);
		map->height++;
		free(array);
	 }
	 close(fd);
	 parsing_checking_map_2(map_arg, map, array);
	 return(1);
}


int		parsing_checking_map_2(char *map_arg, t_map *map, char *array)
{
	int f;
	int index;
	int tmp;
	int i;
	
	index = 0;
	i = 0;
	tmp = map->height;
	
	map->parse = (char **)malloc(sizeof(char *) * (map->height + 1));
	if(!map->parse)
		error("malloc error\n");
	f = open(map_arg, O_RDONLY);
	array = get_next_line(f);
	while(1)
	{
		if(array == NULL)
			break;
		map->parse[index++] = array;
		array = get_next_line(f);
	}
	map->parse[index] = NULL;
	while(tmp - 1 > 0)
	{
		map->parse[i] = ft_substr(map->parse[i], 0, ft_strlen(map->parse[i]) - 1);
		i++;
		tmp--;
	}
	close(f);
	return 1;
}