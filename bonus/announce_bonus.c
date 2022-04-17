/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   announce_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:03:03 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/17 02:05:54 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	annouce_win(t_map *map)
{
	int	index1;
	int	index2;

	index1 = map->player_y;
	index2 = map->player_x;
	if (map->parse[index1][index2] == '1' && map->collectable != 0)
		return (0);
	else if (map->parse[index1][index2] == 'E' && map->collectable != 0)
		return (0);
	else
	{
		map->count_moves++;
	}
	return (1);
}

void	draw_in_screen(t_map *map)
{
	char	*moves;

	moves = ft_itoa(map->count_moves);
	mlx_string_put(map->mlx, map->win, 100, 100, 0x540786, "Moves:");
	mlx_string_put(map->mlx, map->win, 120, 150, 0x540786, moves);
	free(moves);
}
