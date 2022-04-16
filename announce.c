/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   announce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:03:03 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/16 22:03:30 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	annouce_win(t_map *map)
{
	char	*moves;

	print_moves(map);
	moves = ft_itoa(map->count_moves);
	// ft_putstr_fd(moves, 1);
	mlx_string_put(map->mlx, map->win, 100, 100, 0x540786, "Moves:");
	mlx_string_put(map->mlx, map->win, 120, 150, 0x540786, moves);
	free(moves);
	return (0);
}
