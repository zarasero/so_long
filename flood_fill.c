/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:29:33 by zserobia          #+#    #+#             */
/*   Updated: 2024/08/27 16:08:46 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (size == 0)
		return (0);
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

char	**copy_map(char **map, int width, int height, t_game_map *z)
{
	char	**new_map;
	int		y;

	y = 0;
	new_map = malloc(height * sizeof(char *));
	if (!new_map)
	{
		free_map1(new_map);
		error_generat_1("Error: Memory allocation failed", z);
	}
	while (y < height)
	{
		new_map[y] = malloc((width + 1) * sizeof(char));
		if (!new_map[y])
		{
			free_map1(new_map);
			error_generat_1("Error: Memory allocation failed", z);
		}
		ft_strlcpy(new_map[y], map[y], width + 1);
		y++;
	}
	return (new_map);
}

void	flood_fill(char **tab, t_position size, t_position cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	if (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'F'
		|| tab[cur.y][cur.x] == 'E')
		return ;
	tab[cur.y][cur.x] = 'F';
	flood_fill(tab, size, (t_position){cur.x - 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_position){cur.x + 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_position){cur.x, cur.y - 1}, to_fill);
	flood_fill(tab, size, (t_position){cur.x, cur.y + 1}, to_fill);
}

void	check_unreachable_elements(char **map_copy, t_game_map *z, int x, int y)
{
	if (map_copy[y][x] == 'C')
	{
		free_map(map_copy, z->len.y);
		error_generat_1("Error: Unreachable 'C' on the map", z);
	}
	else if ((map_copy[y][x] == 'E')
		&& (((map_copy[y][x + 1] == '1') || (map_copy[y][x + 1] == '0'))
		&& ((map_copy[y][x - 1] == '1') || (map_copy[y][x - 1] == '0'))
		&& ((map_copy[y + 1][x] == '1') || (map_copy[y + 1][x] == '0'))
		&& ((map_copy[y - 1][x] == '1') || (map_copy[y + 1][x] == '0'))))
	{
		free_map(map_copy, z->len.y);
		error_generat_1("Error: Unreachable 'E' on the map", z);
	}
}

void	position_flood_fill(t_game_map *z)
{
	char	**map_copy;
	int		x;
	int		y;

	y = 0;
	map_copy = copy_map(z->map, z->len.x, z->len.y, z);
	flood_fill(map_copy, z->len, z->player_pos,
		map_copy[z->player_pos.y][z->player_pos.x]);
	while (y < z->len.y)
	{
		x = 0;
		while (x < z->len.x)
		{
			check_unreachable_elements(map_copy, z, x, y);
			x++;
		}
		y++;
	}
	free_map(map_copy, z->len.y);
}
