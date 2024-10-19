/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:09:16 by zserobia          #+#    #+#             */
/*   Updated: 2024/08/24 13:43:27 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_graphic(const char *str, t_game_map *z)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			ft_graphic_coin(z, z->pl_x, z->pl_y);
		else if (str[i] == 'P')
			ft_graphic_player(z, z->pl_x, z->pl_y);
		else if (str[i] == 'E')
			ft_graphic_exit(z, z->pl_x, z->pl_y);
		else if (str[i] == '1')
			ft_graphic_wall(z, z->pl_x, z->pl_y);
		else if (str[i] == '0')
			ft_graphic_space(z, z->pl_x, z->pl_y);
		z->pl_x = z->pl_x + 50;
		i++;
		if (str[i] == '\n')
		{
			z->pl_y = z->pl_y + 50;
			z->pl_x = 0;
			i++;
		}
	}
}
