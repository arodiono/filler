/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:53:16 by arodiono          #+#    #+#             */
/*   Updated: 2017/05/12 15:53:18 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>																//delete

void	get_figure_coorditates(t_game **data)
{
	int	x;
	int	y;

	y = 0;
	while(MAP[y])
	{
		x = 0;
		while(MAP[y][x])
		{
			if(MAP[y][x] == (*data)->enemy_figure)
			{
				(*data)->enemy_y = y;
				(*data)->enemy_x = x;
			}
			if(MAP[y][x] == (*data)->my_figure)
			{
				(*data)->my_y = y;
				(*data)->my_x = x;
			}
			x++;
		}
		y++;
	}
	// printf("my__y_x\t%d %d\nri__y_x\t%d %d", (*data)->my_y, (*data)->my_x, (*data)->enemy_y, (*data)->enemy_x);
}

void	get_priority(t_game **data)
{
	int	x;
	int	y;

	y = 0;
	while(MAP[y])
	{
		x = 0;
		while(MAP[y][x])
		{
			x++;
		}
		y++;
	}
}
