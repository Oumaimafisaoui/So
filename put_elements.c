/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:29:23 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/12 22:50:55 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_the_floor(t_map *map, int index1, int index2)
{
	if (map->parse[index1][index2] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->floor_img, index2 * 50, index1 * 75);
}

void	put_the_ceiling(t_map *map, int index1, int index2)
{
	if (map->parse[index1][index2] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->ceiling_img, index2 * 50, index1 * 75);
}


void	put_the_exit(t_map *map, int index1, int index2)
{
	if (map->parse[index1][index2] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->the_exit_img, index2 * 50, index1 * 75);
}


void	put_the_player(t_map *map, int index1, int index2)
{
	if (map->parse[index1][index2] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->player_img, index2 * 50, index1 * 75);
	map->player_x = index2;
	map->player_y = index1;
}

void	put_the_collectable(t_map *map, int index1, int index2)
{
	if (map->parse[index1][index2] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->collectable_img, index2 * 50, index1 * 75);
	map->collectable++;
}
