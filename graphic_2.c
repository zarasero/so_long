/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:05:01 by zserobia          #+#    #+#             */
/*   Updated: 2024/08/27 16:05:04 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_graphic_coin(t_game_map *z, int place_x, int place_y)
{
	mlx_put_image_to_window(z->mlx, z->win, z->pict_coin, place_x, place_y);
}

void	ft_graphic_player(t_game_map *z, int place_x, int place_y)
{
	mlx_put_image_to_window(z->mlx, z->win, z->pict_player, place_x, place_y);
}

void	ft_graphic_exit(t_game_map *z, int place_x, int place_y)
{
	mlx_put_image_to_window(z->mlx, z->win, z->pict_exit, place_x, place_y);
}

void	ft_graphic_wall(t_game_map *z, int place_x, int place_y)
{
	mlx_put_image_to_window(z->mlx, z->win, z->pict_wall, place_x, place_y);
}

void	ft_graphic_space(t_game_map *z, int place_x, int place_y)
{
	mlx_put_image_to_window(z->mlx, z->win, z->pict_space, place_x, place_y);
}
