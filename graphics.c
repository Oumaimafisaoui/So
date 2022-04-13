/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:20:55 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/13 22:22:43 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_images(t_map *map)
{
	int index1;
	int index2;

	map->player_img = mlx_xpm_file_to_image(map->mlx, "./images/me.xpm", &index1, &index2);
	map->the_exit_img = mlx_xpm_file_to_image(map->mlx, "./images/exit.xpm", &index1, &index2);
	map->collectable_img = mlx_xpm_file_to_image(map->mlx, "./images/cool1.xpm", &index1, &index2);
	map->floor_img = mlx_xpm_file_to_image(map->mlx, "./images/ground.xpm", &index1, &index2);
	map->ceiling_img = mlx_xpm_file_to_image(map->mlx, "./images/Imac.xpm", &index1, &index2);
	map->enemy_img = mlx_xpm_file_to_image(map->mlx, "./images/balck.xpm", &index1, &index2);
}

void	add_texture(t_map *map)
{
	int index1;
	int index2;

	index1 = -1;
	map->collectable = 0;
	while(++index1 < map->height)
	{
		index2 = -1;
		while(++index2 <= map->width)
		{
			if(map->parse[index1][index2] == '0')
				put_the_floor(map, index1, index2);
			else if(map->parse[index1][index2] == '1')
				put_the_ceiling(map, index1, index2);
			else if(map->parse[index1][index2] == 'E')
				put_the_exit(map, index1, index2);
			else if(map->parse[index1][index2] == 'P')
			 	put_the_player(map, index1, index2);
			else if(map->parse[index1][index2] == 'C')
			 	put_the_collectable(map, index1, index2);
			else if(map->parse[index1][index2] == 'N')
			 	put_the_enemy(map, index1, index2);
		}
	}
	mlx_key_hook(map->win, mouvements, map);
}


// void	add_texture(t_map *map)
// {
// 	int index1;
// 	int index2;
	
// 	index1 = 0;
// 	while(index1 < map->height)
// 	{
// 		index2 = 0;
// 		while(index2 <= map->width)
// 		{
// 			if(map->parse[index1][index2] == '0')
// 				mlx_put_image_to_window(map->mlx, map->win, map->floor_img, index2 * 50, index1 * 75);
// 			if(map->parse[index1][index2] == '1')
// 				mlx_put_image_to_window(map->mlx, map->win, map->ceiling_img, index2 * 50, index1 * 75);
// 			if(map->parse[index1][index2] == 'E')
// 				mlx_put_image_to_window(map->mlx, map->win, map->the_exit_img, index2 * 50, index1 * 75);
// 			if(map->parse[index1][index2] == 'P')
// 			 	mlx_put_image_to_window(map->mlx, map->win, map->player_img, index2 * 50, index1 * 75);
// 			if(map->parse[index1][index2] == 'C' || map->parse[index1][index2] == 'N')
// 					put_c_or_n(map, index1, index2);
// 			index2++;
// 		}
// 		index1++;
// 	}
// }

// void	put_c_or_n(t_map *map, int index1, int index2)
// {
// 	if(map->parse[index1][index2] == 'C')
// 		mlx_put_image_to_window(map->mlx, map->win, map->collectable_img, index2 * 50, index1 * 75);
// 	else if(map->parse[index1][index2] == 'N')
// 		mlx_put_image_to_window(map->mlx, map->win, map->enemy_img, index2 * 50, index1 * 75);
// }