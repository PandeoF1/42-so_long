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

static void	ft_moov_enemies_min(so_long **game, int x, int y)
{
	if ((*game)->str[y][x + 1] == 'P' || (*game)->str[y][x - 1] == 'P')
	{
		ft_printf("t mort mdr\n");
		mlx_loop_end((*game)->mlx);
	}
	if ((*game)->str[y][x - 1] == '0')
	{
		(*game)->str[y][x] = '0';
		(*game)->str[y][x - 1] = 'N';
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->border, (x - 1) * (*game)->mult, y * (*game)->mult);
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->coin, (x) * (*game)->mult, y * (*game)->mult);
	}
	else if ((*game)->str[y][x + 1] == '0')
	{
		(*game)->str[y][x] = '0';
		(*game)->str[y][x + 1] = 'N';
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->border, (x + 1) * (*game)->mult, y * (*game)->mult);
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
			(*game)->coin, (x) * (*game)->mult, y * (*game)->mult);
		x++;
	}
}

static void	ft_moov_enemies(so_long **game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*game)->max_y)
	{
		x = 0;
		while (x < (*game)->max_x)
		{
			if ((*game)->str[y][x] == 'N')
			{
				ft_moov_enemies_min(&(*game), x, y);
			}
			x++;
		}
		y++;
	}
}

int	ft_sprite(so_long **game)
{
	(*game)->anim_count++;
	(*game)->enemies_count++;
	if ((*game)->anim_count == 20000)
	{
		(*game)->anim_count = 0;
		//ft_printf("change l'anim\n");
	}
	if ((*game)->enemies_count == 100000)
	{
		(*game)->enemies_count = 0;
		ft_moov_enemies(&(*game));
		//ft_printf("attaque\n");
	}
	return (0);
}
