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

#include "filler.h"

void 	bzero_data(t_game **data)
{
	(*data)->my_figure = 0;
	(*data)->my_x = -1;
	(*data)->my_y = -1;
	(*data)->enemy_figure = 0;
	(*data)->enemy_x = -1;
	(*data)->enemy_y = -1;
	(*data)->map_x = 0;
	(*data)->map_y = 0;
	(*data)->piece_x = 0;
	(*data)->piece_y = 0;
}

void	free_struct(t_game **data)
{
	// if ((*data)->piece != NULL)
	// 	ft_memdel((void**)(*data)->piece);
	if ((*data)->map != NULL)
		ft_memdel((void**)(*data)->map);
}
