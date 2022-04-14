/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 04:24:10 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/14 05:20:00 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arguments(int argc, char **argv)
{
	if(argc < 2)
		error("no map at all !\n");
	else if(argc <= 2)
	{
		int size_map;
		size_map = ft_strlen(argv[1]);
		
		if (ft_strcmp(".ber", argv[1] + size_map - 4) != 0)
			error("No .ber in your map\n");
		else
			prepare_functions(argv[1]);
	}
	else
		error("too many arguments\n");
	return 0;
}

static void	init_all(t_map *map)
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

static void	check_width(t_map *map)
{
	int index;

	index = 0;
	map->width = ft_strlen(map->parse[0]);
	while (map->parse[index])
	{
		if (map->width != ft_strlen(map->parse[index]))
		{
			free_map(map, 1);
		}
		index++;
	}
}
void	prepare_functions(char *map_arg)
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	init_all(map);
	parsing_checking_map(map_arg, map);
	check_width(map);
	if(!check_walls(map) || !check_player(map)|| !(check_exit(map)) || !(check_collectables(map)) || !(check_enemy(map)))
		free_map(map, 4);
	if(map->the_exit == 0 || map->player == 0 || map->collectable == 0 )
		free_map(map, 2);
	start_window(map);
}

void	start_window(t_map *map)
{
	map->mlx = mlx_init();
	if(map->mlx == NULL)
		error("mlx_init failed\n");
	map->win = mlx_new_window(map->mlx, map->width * 50, map->height * 75, "so_long_project");
	if(map->win == NULL)
		error("mlx_new_window failed\n");
	add_images(map);	
	add_texture(map);
	mlx_hook(map->win, 17, 0, (void *)exit, 0);
	mlx_loop(map->mlx);
}


int	main(int argc, char **argv)
{
	check_arguments(argc, argv);
	return (0);
}
