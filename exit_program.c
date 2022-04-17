/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 02:06:17 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/17 02:51:23 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_program(t_map *map)
{
	int	index;

	index = 0;
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	while (index < map->height)
	{
		free(map->parse[index]);
		index++;
	}
	free(map->parse);
	exit(0);
}
