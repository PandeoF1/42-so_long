/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reload.c                                         ::      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:47:35 by tnard             #+#    #+#             */
/*   Updated: 2021/11/29 03:03:55 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_reload(t_so_long **game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*game)->max_y)
	{
		x = 0;
		while (x < (*game)->max_x)
		{
			if ((*game)->str[y][x] == '1')
				mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
					(*game)->border, x * (*game)->mult, y * (*game)->mult);
			else if ((*game)->str[y][x] == '0')
				mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
					(*game)->background, x * (*game)->mult, y * (*game)->mult);
			else if ((*game)->str[y][x] == 'E')
				mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
					(*game)->exit, x * (*game)->mult, y * (*game)->mult);
			x++;
		}
		y++;
	}
	if ((*game)->player_mouv > 0)
		ft_print_moov(&(*game), (*game)->player_mouv,
			ft_int_len((*game)->player_mouv));
}
