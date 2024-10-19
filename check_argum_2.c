/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argum_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:06:12 by zserobia          #+#    #+#             */
/*   Updated: 2024/08/24 15:06:14 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_first_dernier_x_y(char **str, int x, int y, t_game_map *z)
{
	int	i;
	int	t;

	i = 0;
	t = x - 1;
	while (str[i] && i < y)
	{
		if (str[i][0] != '1')
			error_generat_1("First column check failed", z);
		if (str[i][t] != '1')
			error_generat_1("Last column check failed", z);
		i++;
	}
}

void	ft_check_x_y(char **str, t_game_map *z)
{
	int	len_x;
	int	len_y;
	int	temp_x;

	len_x = 0;
	len_y = 0;
	temp_x = 0;
	while (str[0][len_x])
		len_x++;
	while (str[len_y])
	{
		temp_x = 0;
		while (str[len_y][temp_x])
			temp_x++;
		if (temp_x != len_x)
			error_generat_1("Inconsistent row lengths", z);
		len_y++;
	}
	z->len.x = len_x;
	z->len.y = len_y;
	if (len_x == len_y)
		error_generat_1("Map cannot be square", z);
	ft_check_first_dernier_x_y(str, len_x, len_y, z);
}

void	ft_check_first_dernier(char **str, t_game_map *z)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (str == NULL || str[0] == NULL)
		error_generat_1("Invalid map structure", z);
	while (str[y])
		y++;
	if (y == 0)
		error_generat_1("Empty map", z);
	while (str[0][x])
	{
		if (str[0][x] != '1')
			error_generat_1("First row check failed", z);
		x++;
	}
	x = 0;
	while (str[y - 1][x])
	{
		if (str[y - 1][x] != '1')
			error_generat_1("Last row check failed", z);
		x++;
	}
}
