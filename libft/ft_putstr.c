/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:39:20 by arodiono          #+#    #+#             */
/*   Updated: 2016/11/22 13:42:21 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
			ft_putchar(s[i++]);
}
