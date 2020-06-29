/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:03:43 by fmelda            #+#    #+#             */
/*   Updated: 2020/03/02 18:25:15 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			print(t_filler *fill)
{
	ft_putnbr(fill->x);
	ft_putchar(' ');
	ft_putnbr(fill->y);
	ft_putchar('\n');
	fill->x = 0;
	fill->y = 0;
}

int				main(void)
{
	t_filler	*fill;

	fill = init_filler();
	if (!(parse_fighter(fill)))
		exit(0);
	while (true)
	{
		fill->map = init_map();
		parse_map(fill);
		init_heatmap(fill);
		fill->piece = init_piece();
		parse_piece(fill);
		math_heatmap(fill);
		find_coords(fill);
		print(fill);
		free_map_and_piece(fill);
	}
	free(fill);
	return (0);
}
