/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:56:58 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/14 00:38:58 by oufisaou         ###   ########.fr       */
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
		if(!do_moves(map, index1, index2))
			return (0);
		map->parse[index1 + 1][index2] = '0';		
	}
	// if(key == 1)
	// {
		
	// }
	// print_score(map);
	return (1);
}

int do_moves(t_map *map, int index1, int index2)
{
	if(map->parse[index1][index2] == '0')
	{
		map->parse[index1][index2] = 'P';
		map->player_y = index1;
		map->player_x = index2;
		print_moves(map);
	}
	else if(map->parse[index1][index2] == 'C')
	{
		map->parse[index1][index2] = 'P';
		map->player_y = index1;
		map->player_x = index2;
		map->collectable--;
		print_moves(map);
	}
	else if (map->parse[index1][index2] == 'E')
	{
		if(map->collectable != 0)
			return (0);
		print_moves(map);
		annouce_win(map);
		exit_program(map);
	}
	else if(map->parse[index1][index2] == 'N')
	{
		exit_program(map);
		printf("you lost\n");
	}
	else if(map->parse[index1][index2] == '1')
	{
		return (0);
	}
	return (1);
}

int		annouce_win(t_map *map)
{
	char *moves;
	
	moves = ft_itoa(map->count_moves);
	printf("%s", moves);
	mlx_string_put(map->mlx, map->win, 2, 4, 0xFF0000, "Your score is :");
	mlx_string_put(map->mlx, map->win, 2, 4, 0xFF0000, moves);
	free(moves);
	return (0);
}

void	print_moves(t_map *map)
{
	map->count_moves++;
	printf("move: %d\n", map->count_moves);
}

int	mouvements(int key, t_map *map)
{
	int event;

	if(key == 13)
		event = event_up_down(map, key);
	// if(key == 2 || key == 0 && map->parse[map->height - 1][map->width - 1] != '1')
	// 	event = event_left_right(map, key);
	else if(key == 53)
		exit_program(map);
	add_texture(map);
	return(1);
}
//&& map->parse[map->player_y - 1][map->player_x] != '1'