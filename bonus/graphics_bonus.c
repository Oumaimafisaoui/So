/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:20:55 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/17 02:04:17 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_images(t_map *map)
{
	int	index1;
	int	index2;

	map->player_img = mlx_xpm_file_to_image(map->mlx, \
	"./images/mefinal.xpm", &index1, &index2);
	map->the_exit_img = mlx_xpm_file_to_image(map->mlx, \
	"./images/exit.xpm", &index1, &index2);
	map->collectable_img = mlx_xpm_file_to_image(map->mlx, \
	"./images/coinfinal.xpm", &index1, &index2);
	map->floor_img = mlx_xpm_file_to_image(map->mlx, \
	"./images/ground.xpm", &index1, &index2);
	map->ceiling_img = mlx_xpm_file_to_image(map->mlx, \
	"./images/mac.xpm", &index1, &index2);
	map->enemy_img = mlx_xpm_file_to_image(map->mlx, \
	"./images/final-black-hole.xpm", &index1, &index2);
}

void	add_texture(t_map *map)
{
	int	index1;
	int	index2;

	index1 = -1;
	map->collectable = 0;
	while (++index1 < map->height)
	{
		index2 = -1;
		while (++index2 <= map->width)
		{
			if (map->parse[index1][index2] == '0')
				put_the_floor(map, index1, index2);
			else if (map->parse[index1][index2] == '1')
				put_the_ceiling(map, index1, index2);
			else if (map->parse[index1][index2] == 'E')
				put_the_exit(map, index1, index2);
			else if (map->parse[index1][index2] == 'P')
				put_the_player(map, index1, index2);
			else if (map->parse[index1][index2] == 'C')
				put_the_collectable(map, index1, index2);
			else if (map->parse[index1][index2] == 'N')
				put_the_enemy(map, index1, index2);
		}
	}
	draw_in_screen(map);
}
