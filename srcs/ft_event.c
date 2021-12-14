/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:47:35 by tnard             #+#    #+#             */
/*   Updated: 2021/12/14 11:28:45 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_int_len(int x)
{
	int	y;

	y = 0;
	if (x > 0)
	{
		if (x > 9)
			y += ft_int_len(x / 10);
		y++;
	}
	return (y);
}

void	ft_print_moov(t_so_long **game, int x, int y)
{
	if (x > 9)
		ft_print_moov(&(*game), x / 10, y - 1);
	mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
		(*game)->number[x % 10], (*game)->mult / 2 * y, 0);
}

static void	ft_moov(t_so_long **game, int y, int x)
{
	mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
		(*game)->background, ((*game)->player_x) * (*game)->mult,
		((*game)->player_y) * (*game)->mult);
	mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
		(*game)->player[(*game)->anim_player], ((*game)->player_x + x)
		* (*game)->mult, ((*game)->player_y + y) * (*game)->mult);
	(*game)->str[(*game)->player_y + y][(*game)->player_x + x] = 'P';
	(*game)->str[(*game)->player_y][(*game)->player_x] = '0';
	(*game)->player_y += y;
	(*game)->player_x += x;
	(*game)->player_mouv++;
	ft_print_moov(&(*game), (*game)->player_mouv,
		ft_int_len((*game)->player_mouv));
	ft_printf("\033[2K\r\033[0;32m%i\e[0m", (*game)->player_mouv);
}

static void	ft_go(t_so_long **game, int y, int x)
{
	if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == '0')
		ft_moov(&(*game), y, x);
	else if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == 'C')
	{
		ft_moov(&(*game), y, x);
		(*game)->coin_count--;
	}
	else if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == 'E')
	{
		if ((*game)->coin_count == 0)
			return ((void)mlx_loop_end((*game)->mlx));
		else
			ft_printf("\033[2K\r\033[0;32mIl te manque %i piece(s)\e[0m",
				(*game)->coin_count);
	}
	else if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == 'N')
		mlx_loop_end((*game)->mlx);
}

int	ft_win_event(int keycode, t_so_long **game)
{
	if (keycode == EVENT_W)
		ft_go(&(*game), -1, 0);
	else if (keycode == EVENT_A)
		ft_go(&(*game), 0, -1);
	else if (keycode == EVENT_D)
		ft_go(&(*game), 0, 1);
	else if (keycode == EVENT_S)
		ft_go(&(*game), 1, 0);
	else if (keycode == EVENT_ESC)
	{
		mlx_loop_end((*game)->mlx);
		return (0);
	}
	return (0);
}
