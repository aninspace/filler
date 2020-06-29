/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fighter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:13:34 by fmelda            #+#    #+#             */
/*   Updated: 2020/02/25 18:34:20 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

bool		parse_fighter(t_filler *fill)
{
	char	*line;
	char	**split;

	if ((get_next_line(0, &line) == 1))
	{
		split = ft_strsplit(line, ' ');
		if (ft_strcmp(split[2], "p1") == 0)
		{
			fill->my_sy = 'O';
			fill->en_sy = 'X';
		}
		else if (ft_strcmp(split[2], "p2") == 0)
		{
			fill->my_sy = 'X';
			fill->en_sy = 'O';
		}
		ft_strdel(&line);
		ft_free_arr(split);
		return (true);
	}
	else
	{
		ft_strdel(&line);
		return (false);
	}
}
