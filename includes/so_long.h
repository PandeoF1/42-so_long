/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 02:38:07 by tnard             #+#    #+#             */
/*   Updated: 2021/12/10 22:01:47 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlbx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# define EVENT_W 119
# define EVENT_A 97
# define EVENT_S 115
# define EVENT_D 100
# define EVENT_ESC 65307

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct so_long
{
	char	**str;
	int		mult;
	int		max_x;
	int		max_y;
	int		player_x;
	int		player_y;
	int		coin_count;
	int		player_mouv;
	int		anim_count;
	int		enemies_count;
	int		anim_enemies;
	int		anim_coin;
	int		anim_player;
	void	*number[10];
	void	*border;
	void	*background;
	void	*player[6];
	void	*enemies[11];
	void	*exit;
	void	*coin[4];
	void	*mlx;
	void	*mlx_win;
}				t_so_long;

typedef struct map_check
{
	int		max_x;
	int		max_y;
	int		count_x;
	int		x;
	int		y;
}				t_map_check;

char			*ft_strrchr(const char *s, int c);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *str);

int				ft_check_file(char *path);
int				ft_win_event(int keycode, t_so_long **game);
int				ft_close(t_so_long **game, int x);
int				ft_exit_hook(t_so_long **game);
int				ft_init_map(t_so_long **game, char *path);
char			*ft_get_file(int fd, int size, int len);
char			**ft_split_ln(char *str, char *charset, int *ln);
int				ft_sprite(t_so_long **game);
void			*ft_open_xpm(t_so_long **game, char *str);
int				ft_init_while(t_so_long **game, t_map_check **check);
void			ft_init_xpm(t_so_long **game);
int				ft_push_img(t_so_long **game, int x, int y);

int				ft_printf(const char *str, ...);
int				ft_putnbr_base(unsigned int nbr, char *base);
int				ft_putnbr(int n);
int				ft_putstr(char *s);
int				ft_putchar(char c);
int				ft_putmemory(unsigned long long *t, char *table);
unsigned int	ft_putnbr_u(unsigned int n);

#endif