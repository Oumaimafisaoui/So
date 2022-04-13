/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 02:06:17 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/13 02:09:12 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_program(t_map *map)
{
	int height;
	int index;

	index = 0;
	height = map->height - 1;
	if(map->win)
		mlx_destroy_window(map->mlx, map->win);
	while(index < height)
	{
		free(map->parse[index]);
		index++;
	}
	free(map);
	exit(0);
}