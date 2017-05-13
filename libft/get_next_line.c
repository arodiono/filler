/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:00:37 by arodiono          #+#    #+#             */
/*   Updated: 2017/01/17 18:00:39 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_n(char **tmp, char **save, char **line)
{
	int i;

	i = 0;
	while ((*tmp)[i] != '\0')
	{
		if ((*tmp)[i] == '\n')
		{
			*line = ft_strsub(*tmp, 0, i);
			*save = ft_strsub(*tmp, i + 1, (ft_strlen(*tmp) - i));
			free(*tmp);
			return (1);
		}
		i++;
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	int			n;
	char		*buf;
	char		*tmp;
	static char	*save;

	tmp = "";
	n = 1;
	if (save != NULL)
		tmp = ft_strdup(save);
	if ((check_n(&tmp, &save, &*line)) == 1)
		return (1);
	while (n > 0)
	{
		buf = ft_memalloc(BUFF_SIZE + 1);
		n = read(fd, buf, BUFF_SIZE);
		tmp = ft_strjoin(tmp, buf);
		free(buf);
		if ((check_n(&tmp, &save, &*line)) == 1)
			return (1);
	}
	if (tmp[0] != 0 && n == 0 && (*line = ft_strdup(tmp)))
		return (1);
	if (n < 0 || fd < 0)
		return (-1);
	return (0);
}
