/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:49:05 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/16 21:14:58 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->parse[i][j] == 'P')
			{
				if (map->player >= 1)
					return (0);
				map->player = 1;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_exit(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->parse[i][j] == 'E')
			{
				map->the_exit++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_collectables(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->parse[i][j] == 'C')
			{
				map->collectable++;
			}
			j++;
		}
		i++;
	}
	if (map->collectable == 0)
		return (0);
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i <= map->height - 1)
	{
		j = 0;
		while (map->parse[i][j])
		{
			if (map->parse[i][0] != '1' || map->parse[i][map->width - 1] != '1')
				return (0);
			if (map->parse[0][j] != '1' \
			|| map->parse[map->height - 1][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_enemy(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->parse[i][j] == 'N')
			{
				map->enemy = 1;
			}
			j++;
		}
		i++;
	}
	return (1);
}
