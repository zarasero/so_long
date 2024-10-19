/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:28:00 by zserobia          #+#    #+#             */
/*   Updated: 2024/08/24 18:59:17 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_map(t_game_map *z)
{
	z->all_line = NULL;
	z->fd = -1;
	z->line = NULL;
	z->map = NULL;
	z->coin_count_tous = 0;
	z->len.x = 0;
	z->len.y = 0;
	z->pl_x = 0;
	z->pl_y = 0;
	z->count_step = 0;
}

void	init_game_map_2(t_game_map *z)
{
	int	w;
	int	h;

	z->mlx = mlx_init();
	if (z->mlx == NULL)
		error_generat("Error initializing MinilibX\n", z);
	z->win = mlx_new_window(z->mlx, ((z->len.x) * 50),
			((z->len.y) * 50), "so_long");
	if (z->win == NULL)
		error_generat("Error creating window\n", z);
	z->pict_coin = mlx_xpm_file_to_image(z->mlx, "./textures/r.xpm", &w, &h);
	z->pict_player = mlx_xpm_file_to_image(z->mlx, "./textures/o.xpm", &w, &h);
	z->pict_exit = mlx_xpm_file_to_image(z->mlx, "./textures/a.xpm", &w, &h);
	z->pict_wall = mlx_xpm_file_to_image(z->mlx, "./textures/b.xpm", &w, &h);
	z->pict_space = mlx_xpm_file_to_image(z->mlx, "./textures/c.xpm", &w, &h);
	if (!z->pict_coin || !z->pict_player || !z->pict_exit || !z->pict_wall
		|| !z->pict_space)
	{
		error_generat("Error: One or more images failed to load", z);
	}
}

int	main(int argc, char **argv)
{
	t_game_map	*z;
	size_t		len;

	if (argc == 2)
	{
		z = malloc(sizeof(t_game_map));
		if (z == NULL)
			error_generat_simple("Memory allocation failed", z);
		len = ft_strlen(argv[1]);
		if (len <= 4 || ft_strcmp(&argv[1][len - 4], ".ber") != 0)
			error_generat_simple("Invalid file extension", z);
		init_game_map(z);
		ft_first_check(argv, z);
		ft_trouve_position_xy(z);
		position_flood_fill(z);
		init_game_map_2(z);
		ft_graphic(z->all_line, z);
		mlx_key_hook(z->win, move, z);
		mlx_hook(z->win, DestroyNotify, NoEventMask, mlx_loop_end, z->mlx);
		mlx_loop(z->mlx);
		cleanup(z);
	}
	else
		ft_putstr("Error\nInvalid count argc");
	return (0);
}
