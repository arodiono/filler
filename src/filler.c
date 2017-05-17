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

#include "../include/filler.h"

void	get_piece(t_game **data)
{
	int		i;
	char	*line;

	i = 0;
	PC = (char **)malloc(sizeof(char *) * PY);
	while (i < PY && get_next_line(0, &line) > 0)
	{
		PC[i] = ft_strsub(line, 0, PX);
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
			PY = ft_atoi(&line[i++]);
			while (line[i] != ' ' && line[i] != '\0')
				i++;
			PX = ft_atoi(&line[i++]);
			return ;
		}
		free(line);
	}
}

void	get_map(t_game **data)
{
	int		i;
	char	*line;

	i = 0;
	MAP = (char **)malloc(sizeof(char *) * MAPY);
	get_next_line(0, &line);
	while (i < MAPY && get_next_line(0, &line) > 0)
	{
		MAP[i] = ft_strsub(line, 4, MAPX);
		free(line);
		i++;
	}
}

void	get_map_size(t_game **data, char *line)
{
	int	i;

	i = 0;
	if (ft_strstr(line, "Plateau"))
	{
		while (line[i] != ' ' && line[i] != '\0')
			i++;
		MAPY = ft_atoi(&line[i]);
		i++;
		while (line[i] != ' ' && line[i] != '\0')
			i++;
		MAPX = ft_atoi(&line[i]);
	}
	free(line);
}

int		main(void)
{
	t_game	*data;
	char	*line;

	data = (t_game *)malloc(sizeof(t_game));
	data->my_figure = 0;
	data->enemy_figure = 0;
	if (get_next_line(0, &line) > 0 && data->my_figure == 0)
	{
		data->my_figure = (line[10] == '1') ? 'O' : 'X';
		data->enemy_figure = data->my_figure == 'O' ? 'X' : 'O';
		free(line);
	}
	while (get_next_line(0, &line) > 0)
	{
		get_map_size(&data, line);
		get_map(&data);
		get_piece_size(&data);
		get_piece(&data);
		check_free_space(&data);
		print_result(&data);
		bzero_data(&data);
		free_struct(&data);
	}
	free(data);
	return (0);
}
