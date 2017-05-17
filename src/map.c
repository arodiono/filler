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

int		check_consilience(t_game **data, int yy, int xx)
{
	int y;
	int x;
	int	en_eq;
	int	pi_eq;

	en_eq = 0;
	pi_eq = 0;
	y = 0;
	while (y < (*data)->piece_y)
	{
		x = 0;
		while (x < (*data)->piece_x)
		{
			if (PC[y][x] == '*' && (MAP[y + yy][x + xx] == (*data)->enemy_figure || MAP[y + yy][x + xx] == (*data)->enemy_figure + 32))
				en_eq++;
			if (PC[y][x] == '*' && MAP[y + yy][x + xx] == (*data)->my_figure)
				pi_eq++;
			x++;
		}
		y++;
	}
	if (en_eq == 0 && pi_eq == 1)
		return (1);
	return (0);
}

void	fill_map_cell(t_game **data, int y, int x, char v)
{
	if (y > 0 && MAPN[y - 1][x] && MAPN[y - 1][x] == '.')
		MAPN[y - 1][x] = v;
	if (x + 1 < (*data)->map_x && MAPN[y][x + 1] == '.')
		MAPN[y][x + 1] = v;
	if (y + 1 < (*data)->map_y && MAPN[y + 1][x] == '.')
		MAPN[y + 1][x] = v;
	if (x > 0 && MAPN[y][x - 1] == '.')
		MAPN[y][x - 1] = v;
	if (y > 0 && x > 0 && MAPN[y - 1][x - 1] == '.')
		MAPN[y - 1][x - 1] = v;
	if (x > 0 && y + 1 < (*data)->map_y && MAPN[y + 1][x - 1] == '.')
		MAPN[y + 1][x - 1] = v;
	if (y + 1 < (*data)->map_y && x + 1 < (*data)->map_x && MAPN[y + 1][x + 1] == '.')
		MAPN[y + 1][x + 1] = v;
	if (y > 0 && x + 1 < (*data)->map_x && MAPN[y - 1][x + 1] == '.')
		MAPN[y - 1][x + 1] = v;
}

void	fill_map(t_game **data)
{
	int		y;
	int		x;
	char	v;

	v = 48;
	map_copy(&*data);
	while (count_dots(&*data) > 0)
	{
		y = 0;
		while (y < (*data)->map_y)
		{
			x = 0;
			while(x < (*data)->map_x)
			{
				if (MAPN[y][x] == (*data)->my_figure)
					MAPN[y][x] = 126;
				if (MAPN[y][x] == (*data)->enemy_figure || MAPN[y][x] == ((*data)->enemy_figure + 32))
					MAPN[y][x] = v;
				if (MAPN[y][x] == v)
					fill_map_cell(&*data, y, x, v + 1);
				x++;
			}
			y++;
		}
		v++;
	}
}

int		get_distance(t_game **data, int my, int mx)
{
	int y;
	int x;
	int res;

	res = 0;
	y = 0;
	fill_map(&*data);
	while(y < (*data)->piece_y)
	{
		x = 0;
		while (x < (*data)->piece_x)
		{
			res += MAPN[y + my][x + mx];
			x++;
		}
		y++;
	}
	return (res);
}


int		check_free_space(t_game **data)
{
	int	x;
	int	y;
	int	distance;

	y = 0;
	distance = 10000;
	while(y < (*data)->map_y - (*data)->piece_y)
	{
		x = 0;
		while(x < (*data)->map_x - (*data)->piece_x)
		{
			if (check_consilience(&*data, y, x) > 0 && get_distance(&*data, y, x) < distance)
			{
				distance = get_distance(&*data, y, x);
				(*data)->return_y = y;
				(*data)->return_x = x;
			}
			x++;
		}
		y++;
	}
	return (1);
}
