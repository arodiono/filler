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

#include "../include/filler.h"

void	fill_map_cell(t_game **data, int y, int x, char v)
{
	if (y > 0 && MAP[y - 1][x] && MAP[y - 1][x] == '.')
		MAP[y - 1][x] = v;
	if (x + 1 < MAPX && MAP[y][x + 1] == '.')
		MAP[y][x + 1] = v;
	if (y + 1 < MAPY && MAP[y + 1][x] == '.')
		MAP[y + 1][x] = v;
	if (x > 0 && MAP[y][x - 1] == '.')
		MAP[y][x - 1] = v;
	if (y > 0 && x > 0 && MAP[y - 1][x - 1] == '.')
		MAP[y - 1][x - 1] = v;
	if (x > 0 && y + 1 < MAPY && MAP[y + 1][x - 1] == '.')
		MAP[y + 1][x - 1] = v;
	if (y + 1 < MAPY && x + 1 < MAPX && MAP[y + 1][x + 1] == '.')
		MAP[y + 1][x + 1] = v;
	if (y > 0 && x + 1 < MAPX && MAP[y - 1][x + 1] == '.')
		MAP[y - 1][x + 1] = v;
}

void	fill_map(t_game **data)
{
	int		y;
	int		x;
	char	v;

	v = 1;
	while (count_dots(&*data) > 0)
	{
		y = 0;
		while (y < MAPY)
		{
			x = 0;
			while (x < MAPX)
			{
				if (MAP[y][x] == MF)
					MAP[y][x] = 126;
				if (MAP[y][x] == EF || MAP[y][x] == (EF + 32))
					MAP[y][x] = 1;
				if (MAP[y][x] == v)
					fill_map_cell(&*data, y, x, v + 1);
				x++;
			}
			y++;
		}
		v++;
	}
}

int		check_consilience(t_game **data, int yy, int xx)
{
	int y;
	int x;
	int	en_eq;
	int	pi_eq;

	en_eq = 0;
	pi_eq = 0;
	y = 0;
	while (y < PY)
	{
		x = 0;
		while (x < PX)
		{
			if (PC[y][x] == '*' && (MAP[y + yy][x + xx] == 1))
				en_eq++;
			if (PC[y][x] == '*' && MAP[y + yy][x + xx] == 126)
				pi_eq++;
			x++;
		}
		y++;
	}
	return ((en_eq == 0 && pi_eq == 1) ? CR += (int)MAP[y + yy][x + xx] : 0);
}

void	check_free_space(t_game **data)
{
	int	x;
	int	y;
	int best;

	y = 0;
	best = 10000;
	fill_map(&*data);
	while (y < MAPY - PY)
	{
		x = 0;
		while (x < MAPX - PX)
		{
			CR = 0;
			if (check_consilience(&*data, y, x))
				if (CR < best)
				{
					RY = y;
					RX = x;
					best = CR;
				}
			x++;
		}
		y++;
	}
}
