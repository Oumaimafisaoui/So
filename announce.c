/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   announce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:03:03 by oufisaou          #+#    #+#             */
/*   Updated: 2022/04/16 22:45:49 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	annouce_win(t_map *map)
{
	int index1;
	int index2;

	
	index1 = map->player_y;
	index2 = map->player_x;
	if(map->parse[index1][index2] == '1' && map->collectable != 0)
		return 0;
	else if(map->parse[index1][index2] == 'E' && map->collectable != 0)
		return 0;
	else
	{
		map->count_moves++;
		ft_putstr_fd("Moves:", 1);
		ft_putnbr_fd(map->count_moves, 1);
		ft_putstr_fd("\n", 1);
	}
	return(1);
}
