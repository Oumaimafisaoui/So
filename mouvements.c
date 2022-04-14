/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:56:58 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/14 23:43:47 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//handle the events:

int	event_up_down(t_map *map, int key)
{
	int index1;
	int index2;

	index1 = map->player_y;
	index2 = map->player_x;
	if(key == 13)
	{
		index1 = index1 - 1;
		if(!do_moves(map, index1, index2) || !do_moves2(map, index1, index2))
			return (0);
		map->parse[index1 + 1][index2] = '0';	
	}
	if(key == 1)
	{
		index1 = index1 + 1;
		if(!do_moves(map, index1, index2) || !do_moves2(map, index1, index2))
			return (0);
		map->parse[index1 - 1][index2] = '0';
	}
	return (1);
}

int event_left_right(t_map *map, int key)
{
	int index1;
	int index2;

	index1 = map->player_y;
	index2 = map->player_x;
	
	if(key == 0)
	{
		index2 = index2 - 1;
		if(!do_moves(map, index1, index2) || !do_moves2(map, index1, index2))
			return (0);
		map->parse[index1][index2 + 1] = '0';		
	}
	if(key == 2)
	{
		index2 = index2 + 1;
		if(!do_moves(map, index1, index2) || !do_moves2(map, index1, index2))
			return (0);
		map->parse[index1][index2 - 1] = '0';
	}
	return (1);
}

int do_moves(t_map *map, int index1, int index2)
{
	if(map->parse[index1][index2] == '0')
	{
		map->parse[index1][index2] = 'P';
		map->player_y = index1;
		map->player_x = index2;
	}
	else if(map->parse[index1][index2] == 'C')
	{
		map->parse[index1][index2] = 'P';
		map->player_y = index1;
		map->player_x = index2;
		map->collectable--;
	}
	return (1);
}

int do_moves2(t_map *map, int index1, int index2)
{
	if (map->parse[index1][index2] == 'E')
	{
		if(map->collectable != 0)
			return (0);
		exit_program(map);
	}
	else if(map->parse[index1][index2] == 'N')
		exit_program(map);
	else if(map->parse[index1][index2] == '1')
		return (0);
	return (1);
}

int	mouvements(int key, t_map *map)
{
	int event;
	if(key == 13 || key == 1)
		event = event_up_down(map, key);
	else if(key == 2 || key == 0)
		event = event_left_right(map, key);
	else if(key == 53)
		exit_program(map);
	else
		error("invalid move\n");
	mlx_clear_window(map->mlx, map->win);
	add_texture(map);
	annouce_win(map);
	return(1);
}


int		annouce_win(t_map *map)
{
	char *moves;
	
	print_moves(map);
	moves = ft_itoa(map->count_moves);
	printf("%s\n",moves);
	mlx_string_put(map->mlx, map->win, 100, 100, 16711680, "Moves:");
	mlx_string_put(map->mlx, map->win, 120, 150, 16711680, moves);
	free(moves);
	return (0);
}
