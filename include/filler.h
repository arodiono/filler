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
# define PIECE (*data)->piece

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

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
}				t_game;

typedef struct		s_var
{
	int				x;
	int				y;
	int				l;
	struct s_var	*next;
}					t_var;

void	get_figure_coorditates(t_game **data);
void	bzero_data(t_game **data);
void	free_struct(t_game **data);

#endif
