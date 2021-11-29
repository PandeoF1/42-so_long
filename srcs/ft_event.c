/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:47:35 by aviscogl          #+#    #+#             */
/*   Updated: 2021/11/29 03:03:55 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void ft_print_moov(so_long **game)
{
	//int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
	mlx_string_put((*game)->mlx, (*game)->mlx_win, 10, 10, 0x00FF0000, "Moov : 10");
	ft_printf("string printed\n");
}

static void ft_moov(so_long **game, int y, int x)
{
	mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->border,((*game)->player_x) * (*game)->mult, ((*game)->player_y) * (*game)->mult);
	mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player,((*game)->player_x + x) * (*game)->mult, ((*game)->player_y + y) * (*game)->mult);
	(*game)->str[(*game)->player_y + y][(*game)->player_x + x] = 'P';
	(*game)->str[(*game)->player_y][(*game)->player_x] = 'P';
	(*game)->player_y += y;
	(*game)->player_x += x;
	(*game)->player_mouv++;
	ft_printf("%i\n", (*game)->player_mouv);
	ft_print_moov(&(*game));
}

static void	ft_go(so_long **game, int y, int x)
{
	int	moov;

	moov = 0;
	//ft_printf("go up %i\nx y = %c\n", (*game)->mult, (*game)->str[(*game)->player_y + y][(*game)->player_x + x]);
	if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == '0')
		moov = 1;
	else if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == 'C')
	{
		moov = 1;
		(*game)->coin_count--;
	}
	else if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == 'E')
	{
		if ((*game)->coin_count == 0)
		{
			mlx_loop_end((*game)->mlx);
			ft_printf("win\n");
			return (0);
		}
		else
			ft_printf("Il te manque des pieces\n");
	}
	if (moov)
		ft_moov(&(*game), y, x);
}

int	ft_win_event(int keycode, so_long **game) //Rajouter le close avec esc et la croix :)
{
	//ft_printf("keycode : %i\n", keycode);
	if (keycode == event_w)
		ft_go(&(*game), -1, 0);
	else if (keycode == event_a)
		ft_go(&(*game), 0, -1);
	else if (keycode == event_d)
		ft_go(&(*game), 0, 1);
	else if (keycode == event_s)
		ft_go(&(*game), 1, 0);
	else if (keycode == event_esc)
	{
		mlx_loop_end((*game)->mlx);
		ft_printf("close\n");
		return (0);
	}
	return (0);
}