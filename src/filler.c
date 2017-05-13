/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:28:44 by arodiono          #+#    #+#             */
/*   Updated: 2017/05/11 16:28:45 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>																//delete

void	get_piece(t_game **data)
{
	int		i;
	char	*line;

	i = 0;
	(*data)->piece = (char **)malloc(sizeof(char *) * (*data)->piece_y);		//leak
	while (i < (*data)->piece_y && get_next_line(0, &line) > 0)
	{
		(*data)->piece[i] = line;
		free(line);
		i++;
	}
}

void	get_piece_size(t_game **data)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Piece"))
		{
			while (line[i] != ' ' && line[i] != '\0')
				i++;
			(*data)->piece_y = ft_atoi(&line[i++]);
			while (line[i] != ' ' && line[i] != '\0')
				i++;
			(*data)->piece_x = ft_atoi(&line[i++]);
			break ;
		}
		free(line);
	}
}

void	get_map(t_game **data)
{
	int		i;
	char	*line;

	i = 0;
	(*data)->map = (char **)malloc(sizeof(char *) * (*data)->map_y);			//leak
	get_next_line(0, &line);
	while (i < (*data)->map_y && get_next_line(0, &line) > 0)
	{
		(*data)->map[i] = ft_strsub(line, 4, (*data)->map_x);
		free(line);
		i++;
	}
}

void	get_map_size(t_game **data)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			while (line[i] != ' ' && line[i] != '\0')
				i++;
			(*data)->map_y = ft_atoi(&line[i++]);
			while (line[i] != ' ' && line[i] != '\0')
				i++;
			(*data)->map_x = ft_atoi(&line[i++]);
			break ;
		}
		free(line);
	}
}

void	get_data(t_game **data)
{
	char	*line;

	if ((*data)->my_figure == 0)
		if (get_next_line(0, &line) > 0)
		{
			(*data)->my_figure = (line[10] == '1') ? 'O' : 'X';
			(*data)->enemy_figure = (*data)->my_figure == 'O' ? 'X' : 'O';
			// printf("my\t%c\nri\t%c\n", (*data)->my_figure, (*data)->enemy_figure);
			free(line);
		}
	get_map_size(&*data);
	get_map(&*data);
	get_piece_size(&*data);
	get_piece(&*data);
	if ((*data)->my_x == -1 && (*data)->my_y == -1 && \
		(*data)->enemy_x == -1 && (*data)->enemy_y == -1)						//fix it
		get_figure_coorditates(&*data);
}

int		main(void)
{
	t_game	*data;

	data = (t_game *)malloc(sizeof(t_game));
	bzero_data(&data);
	get_data(&data);
	free_struct(&data);
	free(data);
	return (0);
}
