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
#include <stdio.h>																//delete
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

void	free_struct(t_game **data)
{
	// if ((*data)->piece != NULL)
	// 	ft_memdel((void**)(*data)->piece);
	if ((*data)->map != NULL)
		ft_memdel((void**)(*data)->map);
}

void	print_result(t_game *data)
{
	// printf("%d %d\n", data->return_y, data->return_x	);
	ft_putnbr(data->return_y);
	write(1, " ", 1);
	ft_putnbr(data->return_x);
	write(1, "\n", 1);
}


void print_map(t_game **data)
{
	int y;
	y = 0;
	while(y < (*data)->map_y)
	{
		printf("%s\n", MAP[y]);
		y++;
	}
}
void print_piece(t_game **data)
{
	int y;
	y = 0;
	while(y < (*data)->piece_y)
	{
		printf("%s\n", PIECE[y]);
		y++;
	}
}
