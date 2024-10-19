/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:02:26 by zserobia          #+#    #+#             */
/*   Updated: 2024/08/24 19:56:25 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map1(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	error_generat_1(const char *message, t_game_map *z)
{
	ft_putstr("Error\n");
	ft_putstr((char *)message);
	if (z->all_line)
		free(z->all_line);
	if (z->map)
		free_map1(z->map);
	free(z);
	exit(1);
}

void	error_generat_simple(const char *message, t_game_map *z)
{
	ft_putstr("Error\n");
	ft_putstr((char *)message);
	free(z);
	exit(1);
}

void	error_generat(const char *message, t_game_map *z)
{
	ft_putstr("Error\n");
	ft_putstr((char *) message);
	cleanup(z);
	exit(1);
}

void	cleanup(t_game_map *z)
{
	mlx_clear_window(z->mlx, z->win);
	if (z->pict_coin)
		mlx_destroy_image(z->mlx, z->pict_coin);
	if (z->pict_player)
		mlx_destroy_image(z->mlx, z->pict_player);
	if (z->pict_exit)
		mlx_destroy_image(z->mlx, z->pict_exit);
	if (z->pict_wall)
		mlx_destroy_image(z->mlx, z->pict_wall);
	if (z->pict_space)
		mlx_destroy_image(z->mlx, z->pict_space);
	if (z->win)
		mlx_destroy_window(z->mlx, z->win);
	if (z->mlx)
	{
		mlx_destroy_display(z->mlx);
		free(z->mlx);
	}
	if (z->all_line)
		free(z->all_line);
	if (z->map)
		free_map1(z->map);
	free(z);
}
