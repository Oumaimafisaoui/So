/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:22:16 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/17 02:52:37 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_the_enemy(t_map *map, int index1, int index2)
{
	if (map->parse[index1][index2] == 'N')
		mlx_put_image_to_window(map->mlx, \
		map->win, map->enemy_img, index2 * 50, index1 * 75);
	map->enemy_x = index2;
	map->enemy_y = index1;
}
