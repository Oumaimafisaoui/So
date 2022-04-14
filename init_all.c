/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:42:56 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/14 23:11:53 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_all(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->player = 0;
	map->player_img = NULL;
	map->the_exit = 0;
	map->the_exit_img = NULL;
	map->collectable = 0;
	map->collectable_img = NULL;
	map->ceiling_img = NULL;
	map->floor_img = NULL;
	map->collectable_x = 0;
	map->collectable_y = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->the_exit_x = 0;
	map->the_exit_y = 0;
	map->steps = 0;
	map->mlx = NULL;
	map->win = NULL;
	map->enemy_img = NULL;
	map->enemy_x = 0;
	map->enemy_y = 0;
	map->enemy = 0;
	map->count_moves = 0;
}