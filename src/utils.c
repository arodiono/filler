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

void 	bzero_data(t_game **data)
{
	(*data)->my_x = -1;
	(*data)->my_y = -1;
	(*data)->enemy_x = -1;
	(*data)->enemy_y = -1;
	(*data)->map_x = 0;
	(*data)->map_y = 0;
	(*data)->piece_x = 0;
	(*data)->piece_y = 0;
	(*data)->return_y = 0;
	(*data)->return_x = 0;
}

void map_copy(t_game **data)
{
	int i;

	i = 0;
	MAPN = (char **)malloc(sizeof(char *) * (*data)->map_y);					//leak
	while (i < (*data)->map_y)
	{
		MAPN[i] = ft_strsub(MAP[i], 0, (*data)->map_x);
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
	while (y < (*data)->map_y)
	{
		x = 0;
		while(x < (*data)->map_x)
		{
			if (MAPN[y][x] == '.')
				res++;
			x++;
		}
		y++;
	}
	return (res);
}

void	free_struct(t_game **data)
{
	if ((*data)->piece != NULL)
		ft_memdel((void**)(*data)->piece);
	if ((*data)->map != NULL)
		ft_memdel((void**)(*data)->map);
}

void	print_result(t_game *data)
{
	ft_putnbr(data->return_y);
	write(1, " ", 1);
	ft_putnbr(data->return_x);
	write(1, "\n", 1);
}


// void print_map(t_game **data)
// {
// 	int y;
// 	y = 0;
// 	while(y < (*data)->map_y)
// 	{
// 		printf("%s\n", MAP[y]);
// 		y++;
// 	}
// }
// void print_piece(t_game **data)
// {
// 	int y;
// 	y = 0;
// 	while(y < (*data)->piece_y)
// 	{
// 		printf("%s\n", PC[y]);
// 		y++;
// 	}
// }
