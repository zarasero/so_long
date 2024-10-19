/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:57:10 by zserobia          #+#    #+#             */
/*   Updated: 2024/08/24 16:01:24 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_tous(t_game_map *z, int new_y, int new_x, char next_pos)
{
	z->count_step++;
	ft_putnbr(z->count_step);
	ft_putstr(" - current number of movements\n");
	z->map[z->player_pos.y][z->player_pos.x] = '0';
	z->player_pos.y = new_y;
	z->player_pos.x = new_x;
	z->map[z->player_pos.y][z->player_pos.x] = 'P';
	redraw_map(z);
	if (next_pos == 'C')
		z->coin_count_tous--;
	else if (next_pos == 'E')
	{
		if (z->coin_count_tous == 0)
		{
			ft_putstr("You win!\n");
			cleanup(z);
			exit(0);
		}
	}
}

void	move_down(t_game_map *z)
{
	char	next_pos;

	if (z->player_pos.y < z->len.y - 1)
	{
		next_pos = z->map[z->player_pos.y + 1][z->player_pos.x];
		if (next_pos == '1')
			return ;
		if (next_pos == 'E' && (z->coin_count_tous != 0))
			return ;
		move_tous(z, z->player_pos.y + 1, z->player_pos.x, next_pos);
	}
}

void	move_left(t_game_map *z)
{
	char	next_pos;

	if (z->player_pos.x > 0)
	{
		next_pos = z->map[z->player_pos.y][z->player_pos.x - 1];
		if (next_pos == '1')
			return ;
		if (next_pos == 'E' && (z->coin_count_tous != 0))
			return ;
		move_tous(z, z->player_pos.y, z->player_pos.x - 1, next_pos);
	}
}

void	move_right(t_game_map *z)
{
	char	next_pos;

	if (z->player_pos.x < z->len.x - 1)
	{
		next_pos = z->map[z->player_pos.y][z->player_pos.x + 1];
		if (next_pos == '1')
			return ;
		if (next_pos == 'E' && (z->coin_count_tous != 0))
			return ;
		move_tous(z, z->player_pos.y, z->player_pos.x + 1, next_pos);
	}
}

int	move(int key, t_game_map *z)
{
	if (key == 87 || key == 119)
		move_up(z);
	else if (key == 83 || key == 115)
		move_down(z);
	else if (key == 65 || key == 97)
		move_left(z);
	else if (key == 68 || key == 100)
		move_right(z);
	else if (key == 65307)
		mlx_loop_end(z->mlx);
	return (0);
}
