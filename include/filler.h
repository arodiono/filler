/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:28:37 by arodiono          #+#    #+#             */
/*   Updated: 2017/05/11 16:28:39 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define MAP (*data)->map
# define MAPN (*data)->new_map
# define MAPX (*data)->map_x
# define MAPY (*data)->map_y

# define PC (*data)->piece
# define PX (*data)->piece_x
# define PY (*data)->piece_y

# define MF (*data)->my_figure
# define MX (*data)->my_x
# define MY (*data)->my_y

# define EF (*data)->enemy_figure
# define EX (*data)->enemy_x
# define EY (*data)->enemy_y

# define RY (*data)->return_y
# define RX (*data)->return_x

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_game
{
	char		my_figure;
	int			my_x;
	int			my_y;
	char		enemy_figure;
	int			enemy_x;
	int			enemy_y;
	char		**map;
	int			map_x;
	int			map_y;
	char		**piece;
	int			piece_x;
	int			piece_y;
	int			return_y;
	int			return_x;
	char		**new_map;
}				t_game;

void	bzero_data(t_game **data);
void	free_struct(t_game **data);
int		check_free_space(t_game **data);
void	print_result(t_game *data);
void	get_piece(t_game **data);
void	get_piece_size(t_game **data);
void	map_copy(t_game **data);
int		count_dots(t_game **data);

void print_map(t_game **data);
void print_piece(t_game **data);

#endif
