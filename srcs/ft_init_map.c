/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:39:52 by tnard             #+#    #+#             */
/*   Updated: 2021/12/14 11:08:27 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_push_img_min(t_so_long **game, int x, int y)
{
	if ((*game)->str[y][x] == 'N')
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->enemies[0], x * (*game)->mult, y * (*game)->mult);
	else
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->background, x * (*game)->mult, y * (*game)->mult);
}

static int	ft_push_img(t_so_long **game, int x, int y)
{
	if ((*game)->str[y][x] == '1')
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->border, x * (*game)->mult, y * (*game)->mult);
	else if ((*game)->str[y][x] == 'E')
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->exit, x * (*game)->mult, y * (*game)->mult);
	else if ((*game)->str[y][x] == 'P')
	{
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->player[0], x * (*game)->mult, y * (*game)->mult);
		if ((*game)->player_x != 0 || (*game)->player_y != 0)
			return (0);
		(*game)->player_x = x;
		(*game)->player_y = y;
	}
	else if ((*game)->str[y][x] == 'C')
	{
		(*game)->coin_count++;
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->coin[0], x * (*game)->mult, y * (*game)->mult);
	}
	else
		ft_push_img_min(&(*game), x, y);
	return (1);
}

static int	ft_check_map(t_so_long **game, int x, int y)
{
	char	charset[4];

	while (y <= 3)
		charset[y++] = 0;
	y = -1;
	while ((*game)->str[++y])
	{
		x = -1;
		while ((*game)->str[y][++x])
		{
			if ((*game)->str[y][x] == 'E')
				charset[0]++;
			else if ((*game)->str[y][x] == 'P')
				charset[1]++;
			else if ((*game)->str[y][x] == 'C')
				charset[2]++;
		}
	}
	if (charset[0] == 0 || charset[1] != 1
		|| charset[2] == 0)
		return (0);
	return (1);
}

static int	ft_push_map(t_so_long **game)
{
	int	x;
	int	y;

	y = -1;
	(*game)->picture_size = (*game)->max_x;
	(*game)->coin_count = 0;
	(*game)->mlx = mlx_init();
	(*game)->mlx_win = mlx_new_window((*game)->mlx,
			(*game)->max_x * (*game)->mult,
			(*game)->max_y * (*game)->mult, "so_long | v1.0");
	ft_init_xpm(&(*game));
	while (++y * (*game)->mult < (*game)->max_y * (*game)->mult)
	{
		x = -1;
		while (++x * (*game)->mult < (*game)->max_x * (*game)->mult)
			if (!ft_push_img(&(*game), x, y))
				return (0);
	}
	return (ft_check_map(&(*game), 0, 0));
}

int	ft_init_map(t_so_long **game, char *path)
{
	t_map_check	*check;
	int			fd;
	char		*str;

	check = malloc(sizeof(t_map_check));
	fd = open(path, O_RDONLY);
	str = ft_get_file(fd, 0, 0);
	(*game)->str = ft_split_ln(str, "\n", &check->max_y);
	free(str);
	close(fd);
	check->max_x = ft_strlen((*game)->str[0]);
	check->y = -1;
	if (ft_init_while(&(*game), &check) == 0)
		return (0);
	(*game)->max_x = check->max_x;
	(*game)->max_y = check->max_y;
	free(check);
	return (ft_push_map(&(*game)));
}
