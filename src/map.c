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
#include <stdio.h>																//delete

int		check_consilience(t_game **data, int yy, int xx)
{
	int y;
	int x;
	int	my_eq;
	int	en_eq;
	int	pi_eq;

	my_eq = 0;
	en_eq = 0;
	pi_eq = 0;
	y = 0;
	while (y < (*data)->piece_y)
	{
		x = 0;
		while (x < (*data)->piece_x)
		{
			// printf("%c %c\t", PIECE[y][x], MAP[y + yy][x + xx]);
			if (PIECE[y][x] == '*' && (MAP[y + yy][x + xx] == (*data)->enemy_figure || MAP[y + yy][x + xx] == (*data)->enemy_figure + 32))
				en_eq++;
			if (PIECE[y][x] == '*' && MAP[y + yy][x + xx] == (*data)->my_figure)
				pi_eq++;
			// printf("MAP[%d][%d]\ten=%d pi=%d\t %d %d\n", y+yy, x+xx, en_eq, pi_eq, (*data)->piece_y, (*data)->piece_x);
			x++;
		}
		y++;

	}
	if (en_eq == 0 && pi_eq == 1)
	{
		// printf("%d %d\n", en_eq, pi_eq);
		return (1);
	}
	return (0);
}

void	fill_map_cell(t_game **data, int y, int x, char v)
{
	if (y > 0 && MAPNEW[y - 1][x] && MAPNEW[y - 1][x] == '.')
		MAPNEW[y - 1][x] = v;
	if (x + 1 < (*data)->map_x && MAPNEW[y][x + 1] == '.')
		MAPNEW[y][x + 1] = v;
	if (y + 1 < (*data)->map_y && MAPNEW[y + 1][x] == '.')
		MAPNEW[y + 1][x] = v;
	if (x > 0 && MAPNEW[y][x - 1] == '.')
		MAPNEW[y][x - 1] = v;
	if (y > 0 && x > 0 && MAPNEW[y - 1][x - 1] == '.')
		MAPNEW[y - 1][x - 1] = v;
	if (x > 0 && y + 1 < (*data)->map_y && MAPNEW[y + 1][x - 1] == '.')
		MAPNEW[y + 1][x - 1] = v;
	if (y + 1 < (*data)->map_y && x + 1 < (*data)->map_x && MAPNEW[y + 1][x + 1] == '.')
		MAPNEW[y + 1][x + 1] = v;
	if (y > 0 && x + 1 < (*data)->map_x && MAPNEW[y - 1][x + 1] == '.')
		MAPNEW[y - 1][x + 1] = v;
}

int		count_dots(t_game **data)
{
	int	y;
	int	x;
	int	res;

	res = 0;
	y = 0;
	while (y < (*data)->map_y)
	{
		x = 0;
		while(x < (*data)->map_x)
		{
			if (MAPNEW[y][x] == '.')
				res++;
			x++;
		}
		y++;
	}
	return (res);
}

void map_copy(t_game **data)
{
	int i;

	i = 0;
	MAPNEW = (char **)malloc(sizeof(char *) * (*data)->map_y);
	while (i < (*data)->map_y)
	{
		MAPNEW[i] = ft_strsub(MAP[i], 0, (*data)->map_x);
		i++;
	}
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
				if (MAPNEW[y][x] == (*data)->my_figure)
					MAPNEW[y][x] = 126;
				if (MAPNEW[y][x] == (*data)->enemy_figure || MAPNEW[y][x] == ((*data)->enemy_figure + 32))
					MAPNEW[y][x] = v;
				if (MAPNEW[y][x] == v)
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
			res += MAPNEW[y + my][x + mx];
			// printf("%d\n", res);
			x++;
		}
		y++;
	}
	return (res);
}

int		check_last(t_game **data)
{
	int y;
	int x;

	y = (*data)->return_y - (*data)->last_y;
	x = (*data)->return_x - (*data)->last_x;
	// printf("%d\n", x + y);
	return (x + y);
}


int		check_free_space(t_game **data)
{
	int	x;
	int	y;
	int	distance;
	int	last;

	y = 0;
	last = 10000;
	distance = 10000;
	while(y < (*data)->map_y - (*data)->piece_y)
	{
		x = 0;
		while(x < (*data)->map_x - (*data)->piece_x)
		{
			// printf("%d %d\n", y, x);
			if (check_consilience(&*data, y, x) > 0)
			{

				if (get_distance(&*data, y, x) < distance)
				{
					distance = get_distance(&*data, y, x);
					(*data)->return_y = y;
					(*data)->return_x = x;
				}
			}
			x++;
		}
		y++;
	}
	(*data)->last_y = y;
	(*data)->last_x = x;
	return (1);
}
