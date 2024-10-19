/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:34:16 by zserobia          #+#    #+#             */
/*   Updated: 2024/08/27 15:37:14 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <mlx.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_game_map
{
	char		*line;
	char		*all_line;
	char		**map;
	void		*pict_wall;
	int			coin_count_tous;
	int			fd;
	int			pl_x;
	int			pl_y;
	int			count_step;
	t_position	len;
	t_position	player_pos;
	void		*pict_player;
	void		*pict_coin;
	void		*pict_space;
	void		*pict_exit;
	void		*mlx;
	void		*win;
}	t_game_map;

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);
char	*read_tous_line(int fd, char *rest);
char	*read_line(char *rest);
char	*new_rest(char *rest, char *line);
char	*word_zap(const char *str, int start, int finish);
int		count_words(const char *str, char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);

void	init_game_map(t_game_map *z);
void	init_game_map_2(t_game_map *z);
void	ft_first_check(char **argv, t_game_map *z);
void	ft_check_param(const char *str, t_game_map *z);
void	ft_check_param_2(const char *str, t_game_map *z);
void	ft_check_first_dernier(char **str, t_game_map *z);
void	ft_check_x_y(char **str, t_game_map *z);
void	ft_check_first_dernier_x_y(char **str, int x, int y, t_game_map *z);
void	error_generat(const char *message, t_game_map *z);
void	error_generat_simple(const char *message, t_game_map *z);
void	error_generat_1(const char *message, t_game_map *z);

void	position_flood_fill(t_game_map *z);
void	flood_fill(char **tab, t_position size, t_position cur, char to_fill);
void	check_unreachable_elements(char **map_copy, t_game_map *z,
			int x, int y);
void	free_map(char **map, int height);
char	**copy_map(char **map, int width, int height, t_game_map *z);

void	ft_graphic(const char *str, t_game_map *z);
void	ft_graphic_space(t_game_map *z, int place_x, int place_y);
void	ft_graphic_wall(t_game_map *z, int place_x, int place_y);
void	ft_graphic_exit(t_game_map *z, int place_x, int place_y);
void	ft_graphic_player(t_game_map *z, int place_x, int place_y);
void	ft_graphic_coin(t_game_map *z, int place_x, int place_y);

int		move(int key, t_game_map *z);
void	draw_map(t_game_map *z);
void	draw_map_2(char tile, t_game_map *z, int x, int y);
void	redraw_map(t_game_map *z);
void	move_up(t_game_map *z);
void	move_tous(t_game_map *z, int new_y, int new_x, char next_pos);
void	move_right(t_game_map *z);
void	move_left(t_game_map *z);
void	move_down(t_game_map *z);
void	move_up(t_game_map *z);
void	cleanup(t_game_map *z);
void	ft_trouve_position_xy(t_game_map *z);
void	free_map1(char **str);

#endif
