/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:39:52 by tnard             #+#    #+#             */
/*   Updated: 2021/11/29 03:06:17 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_open_number(so_long **game)
{
	(*game)->number[0] = ft_open_xpm(&(*game), "./img/number/0.xpm");
	(*game)->number[1] = ft_open_xpm(&(*game), "./img/number/1.xpm");
	(*game)->number[2] = ft_open_xpm(&(*game), "./img/number/2.xpm");
	(*game)->number[3] = ft_open_xpm(&(*game), "./img/number/3.xpm");
	(*game)->number[4] = ft_open_xpm(&(*game), "./img/number/4.xpm");
	(*game)->number[5] = ft_open_xpm(&(*game), "./img/number/5.xpm");
	(*game)->number[6] = ft_open_xpm(&(*game), "./img/number/6.xpm");
	(*game)->number[7] = ft_open_xpm(&(*game), "./img/number/7.xpm");
	(*game)->number[8] = ft_open_xpm(&(*game), "./img/number/8.xpm");
	(*game)->number[9] = ft_open_xpm(&(*game), "./img/number/9.xpm");
}

static void	ft_open_map(so_long **game)
{
	(*game)->border = ft_open_xpm(&(*game), "./img/border.xpm");
	(*game)->player = ft_open_xpm(&(*game), "./img/player.xpm");
	(*game)->exit = ft_open_xpm(&(*game), "./img/exit.xpm");
	(*game)->coin = ft_open_xpm(&(*game), "./img/coin.xpm");
	ft_open_number(&(*game));
}

static int	ft_push_img(so_long **game, int x, int y)
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
			(*game)->player, x * (*game)->mult, y * (*game)->mult);
		if ((*game)->player_x != 0 || (*game)->player_y != 0)
			return (0);
		(*game)->player_x = x;
		(*game)->player_y = y;
	}
	else if ((*game)->str[y][x] == 'C')
	{
		(*game)->coin_count++;
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->coin, x * (*game)->mult, y * (*game)->mult);
	}
	else if ((*game)->str[y][x] == 'N')
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->border, x * (*game)->mult, y * (*game)->mult);
	return (1);
}

static int	ft_push_map(so_long **game)
{
	int	x;
	int	y;

	y = 0;
	(*game)->picture_size = (*game)->max_x;
	(*game)->coin_count = 0;
	(*game)->mlx = mlx_init();
	(*game)->mlx_win = mlx_new_window((*game)->mlx,
			(*game)->max_x * (*game)->mult,
			(*game)->max_y * (*game)->mult, "test");
	ft_open_map(&(*game));
	while (y * (*game)->mult < (*game)->max_y * (*game)->mult)
	{
		x = 0;
		while (x * (*game)->mult < (*game)->max_x * (*game)->mult)
		{
			if (!ft_push_img(&(*game), x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_init_map(so_long **game, char *path)
{
	map_check	*check;
	int			fd;
	char		*str;

	check = malloc(sizeof(map_check));
	fd = open(path, O_RDONLY);
	str = ft_get_file(fd, 0, 0);
	(*game)->str = ft_split_ln(str, "\n", &check->max_y);
	free(str);
	close(fd);
	check->max_x = ft_strlen((*game)->str[0]);
	check->y = 0;
	ft_init_while(&(*game), &check);
	(*game)->max_x = check->max_x;
	(*game)->max_y = check->max_y;
	free(check);
	return (ft_push_map(&(*game)));
}
