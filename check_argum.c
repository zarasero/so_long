/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:36:11 by zserobia          #+#    #+#             */
/*   Updated: 2024/08/24 15:33:48 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_param_2(const char *str, t_game_map *z)
{
	int	coin_e;
	int	coin_p;
	int	i;

	coin_e = 0;
	coin_p = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			z->coin_count_tous++;
		else if (str[i] == 'P')
			coin_p++;
		else if (str[i] == 'E')
			coin_e++;
		i++;
	}
	if (z->coin_count_tous < 1)
		error_generat_1("Not enough C characters", z);
	if (coin_p != 1)
		error_generat_1("Invalid number of P characters", z);
	if (coin_e != 1)
		error_generat_1("Invalid number of E characters", z);
}

void	ft_check_param(const char *str, t_game_map *z)
{
	int	i;

	i = 0;
	if (str[0] != '1')
		error_generat_1("Premier character", z);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'P'
			&& str[i] != 'E' && str[i] != '\n')
			error_generat_1("Invalid character in map", z);
		if (i > 0 && str[i] == '\n'
			&& (str[i + 1] == '\n' || str[i + 1] == '\0'))
			error_generat_1("Empty row in map", z);
		i++;
	}
	if (str[i - 1] != '1')
		error_generat_1("Last character", z);
}

void	ft_first_check(char **argv, t_game_map *z)
{
	char	*temp;

	z->all_line = ft_calloc(1, 1);
	if (!z->all_line)
		error_generat_1("Memory allocation failed", z);
	z->fd = open(argv[1], O_RDONLY);
	if (z->fd < 0)
		error_generat_1("Failed to open file", z);
	z->line = get_next_line(z->fd);
	while (z->line)
	{
		temp = ft_strjoin(z->all_line, z->line);
		free(z->all_line);
		z->all_line = temp;
		free(z->line);
		z->line = get_next_line(z->fd);
	}
	close(z->fd);
	ft_check_param(z->all_line, z);
	ft_check_param_2(z->all_line, z);
	z->map = ft_split(z->all_line, '\n');
	if (!z->map)
		error_generat_1("Failed to split map into lines", z);
	ft_check_first_dernier(z->map, z);
	ft_check_x_y(z->map, z);
}
