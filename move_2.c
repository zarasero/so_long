/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:01:58 by zserobia          #+#    #+#             */
/*   Updated: 2024/08/27 15:37:44 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_trouve_position_xy(t_game_map *z)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < z->len.y)
	{
		while (x < z->len.x)
		{
			if (z->map[y][x] == 'P')
			{
				z->player_pos.x = x;
				z->player_pos.y = y;
				return ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	draw_map_2(char tile, t_game_map *z, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(z->mlx, z->win, z->pict_wall, x * 50, y * 50);
	else if (tile == '0')
		mlx_put_image_to_window(z->mlx, z->win, z->pict_space, x * 50, y * 50);
	else if (tile == 'C')
		mlx_put_image_to_window(z->mlx, z->win, z->pict_coin, x * 50, y * 50);
	else if (tile == 'E')
		mlx_put_image_to_window(z->mlx, z->win, z->pict_exit, x * 50, y * 50);
	else if (tile == 'P')
		mlx_put_image_to_window(z->mlx, z->win, z->pict_player, x * 50, y * 50);
}

void	draw_map(t_game_map *z)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < z->len.y)
	{
		x = 0;
		while (x < z->len.x)
		{
			tile = z->map[y][x];
			draw_map_2(tile, z, x, y);
			x++;
		}
		y++;
	}
}

void	redraw_map(t_game_map *z)
{
	mlx_clear_window(z->mlx, z->win);
	draw_map(z);
}

void	move_up(t_game_map *z)
{
	char	next_pos;

	if (z->player_pos.y > 0)
	{
		next_pos = z->map[z->player_pos.y - 1][z->player_pos.x];
		if (next_pos == '1')
			return ;
		if (next_pos == 'E' && (z->coin_count_tous != 0))
			return ;
		move_tous(z, z->player_pos.y - 1, z->player_pos.x, next_pos);
	}
}
