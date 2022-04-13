/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:56:58 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/13 23:07:53 by oufisaou         ###   ########.fr       */
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
	
	printf("%d\n %d\n", index1, index2);
	if(key == 13)
	{
		if(map->parse[index1 - 1][index2] == '1' || !do_moves(map, index1, index2))
			return (0);
		map->parse[index1][index2] = '0';		
	}
	// if(key == 1)
	// {
		
	// }
	// print_score(map);
	return (1);
}

int do_moves(t_map *map, int index1, int index2)
{
	if(map->parse[index1 - 1][index2] == '0')
	{
		map->parse[index1 - 1][index2] = 'P';
		map->player_y = index1 - 1;
		map->player_x = index2;
		map->count_moves++;
	}
	else if(map->parse[index1 - 1][index2] == 'C')
	{
		map->parse[index1][index2] = 'P';
		map->player_y = index1;
		map->player_x = index2;
		map->collectable--;
		map->count_moves++;
	}
	else if (map->parse[index1 - 1][index2] == 'E')
	{
		if(map->collectable != 0)
			return (0);
		//annouce_win(map);
		printf("you won\n");
	}
	else if(map->parse[index1 - 1][index2] == 'N')
	{
		exit_program(map);
		printf("you lost\n");
	}
	printf("move: %d\n", map->count_moves);
	printf("collectables left:%d\n", map->collectable);
	return (1);
}

// int		annouce_win(t_map *map)
// {
// 	char *result;
// 	char *score;
	
// 	result = ft_itoa(map->collectable);
// 	mlx_string_put(map->mlx, map->win, 10, 10, 0xFFFFFF, "You win !");
// 	mlx_string_put(map->mlx, map->win, 10, 30, 0xFFFFFF, result);
// 	free(result);
// 	score = ft_itoa(map->count_moves);
// 	mlx_string_put(map->mlx, map->win, 10, 50, 0xFFFFFF, "Your score is :");
// 	mlx_string_put(map->mlx, map->win, 10, 70, 0xFFFFFF, score);
// 	free(score);
// 	return (0);
// }


// void print_score(t_map *map)
// {
// 	ft_putstr_fd("Score: ", 1);
// 	ft_putnbr_fd(map->count_moves, 1);
// 	ft_putstr_fd("\n", 1);
// }

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