/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                         ::      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:47:35 by tnard             #+#    #+#             */
/*   Updated: 2021/11/29 03:03:55 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_moov_enemies_min(t_so_long **game, int x, int y)
{
	int	a;

	if ((*game)->str[y][x + 1] == 'P' || (*game)->str[y][x - 1] == 'P')
		ft_printf("t'es mort mdr\n", mlx_loop_end((*game)->mlx));
	mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
		(*game)->background, (x) * (*game)->mult, y * (*game)->mult);
	if ((*game)->str[y][x + 1] == '0')
	{
		(*game)->str[y][x] = '0';
		(*game)->str[y][x + 1] = 'N';
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->enemies[0], (x + 1) * (*game)->mult, y * (*game)->mult);
		return (1);
	}
	else
	{
		a = 0;
		(*game)->str[y][x] = '0';
		while ((*game)->str[y][a] != '0' && a != (*game)->max_x)
			a++;
		(*game)->str[y][a] = 'N';
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->enemies[0], (a) * (*game)->mult, y * (*game)->mult);
	}
	return (0);
}

static void	ft_moov_enemies(t_so_long **game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*game)->max_y)
	{
		x = -1;
		while (++x < (*game)->max_x)
			if ((*game)->str[y][x] == 'N')
				x += ft_moov_enemies_min(&(*game), x, y);
		y++;
	}
}

static void	ft_anim_change(t_so_long **game, int x, int y, char type)
{
	if (type == 'N')
	{
		if ((*game)->anim_enemies == 11)
			(*game)->anim_enemies = 0;
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->enemies[(*game)->anim_enemies],
			x * (*game)->mult, y * (*game)->mult);
	}
	else if (type == 'P')
	{
		if ((*game)->anim_player == 6)
			(*game)->anim_player = 0;
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->player[(*game)->anim_player],
			x * (*game)->mult, y * (*game)->mult);
	}
	else if (type == 'C')
	{
		if ((*game)->anim_coin == 4)
			(*game)->anim_coin = 0;
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->coin[(*game)->anim_coin],
			x * (*game)->mult, y * (*game)->mult);
	}
}

static void	ft_anim(t_so_long **game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*game)->max_y)
	{
		x = -1;
		while (++x < (*game)->max_x)
		{
			if ((*game)->str[y][x] == 'N')
				ft_anim_change(&(*game), x, y, 'N');
			if ((*game)->str[y][x] == 'P')
				ft_anim_change(&(*game), x, y, 'P');
			if ((*game)->str[y][x] == 'C')
				ft_anim_change(&(*game), x, y, 'C');
		}
		y++;
	}
	(*game)->anim_coin++;
	(*game)->anim_player++;
	(*game)->anim_enemies++;
}

int	ft_sprite(t_so_long **game)
{
	(*game)->anim_count++;
	(*game)->enemies_count++;
	if ((*game)->anim_count == 0)
	{
		(*game)->anim_player = 0;
		(*game)->anim_count = 0;
		(*game)->anim_enemies = 0;
	}
	else if ((*game)->anim_count == 15000)
	{
		(*game)->anim_count = 1;
		ft_anim(&(*game));
	}
	if ((*game)->enemies_count == 100000)
	{
		(*game)->enemies_count = 0;
		ft_moov_enemies(&(*game));
	}
	return (0);
}
