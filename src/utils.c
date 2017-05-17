/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:57:22 by arodiono          #+#    #+#             */
/*   Updated: 2017/05/12 16:57:24 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	bzero_data(t_game **data)
{
	MX = -1;
	MY = -1;
	EX = -1;
	EY = -1;
	MAPX = 0;
	MAPY = 0;
	PX = 0;
	PY = 0;
	RY = 0;
	RX = 0;
}

void	map_copy(t_game **data)
{
	int i;

	i = 0;
	MAPN = (char **)malloc(sizeof(char *) * MAPY);
	while (i < MAPY)
	{
		MAPN[i] = ft_strsub(MAP[i], 0, MAPX);
		i++;
	}
}

int		count_dots(t_game **data)
{
	int	y;
	int	x;
	int	res;

	res = 0;
	y = 0;
	while (y < MAPY)
	{
		x = 0;
		while (x < MAPX)
		{
			if (MAP[y][x] == '.')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	free_struct(t_game **data)
{
	if (PC != NULL)
		ft_memdel((void**)PC);
	if (MAP != NULL)
		ft_memdel((void**)MAP);
}

void	print_result(t_game **data)
{
	ft_putnbr(RY);
	write(1, " ", 1);
	ft_putnbr(RX);
	write(1, "\n", 1);
}
