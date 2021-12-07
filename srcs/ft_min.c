/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:39:52 by tnard             #+#    #+#             */
/*   Updated: 2021/11/29 03:06:17 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_open_xpm(t_so_long **game, char *str)
{
	return (mlx_xpm_file_to_image(
			(*game)->mlx, str, &(*game)->picture_size,
			&(*game)->picture_size));
}

int	ft_init_while(t_so_long **game, t_map_check **check)
{
	while ((*check)->y < (*check)->max_y)
	{
		(*check)->x = 0;
		(*check)->count_x = 0;
		while ((*check)->x < (*check)->max_x
			&& ((*game)->str[(*check)->y][(*check)->x] == '1'
			|| (*game)->str[(*check)->y][(*check)->x] == 'E'
			|| (*game)->str[(*check)->y][(*check)->x] == 'P'
			|| (*game)->str[(*check)->y][(*check)->x] == 'C'
			|| (*game)->str[(*check)->y][(*check)->x] == '0'
			|| (*game)->str[(*check)->y][(*check)->x] == 'N'))
		{
			if (((*check)->y == 0 || (*check)->y == (*check)->max_y - 1)
				&& (*game)->str[(*check)->y][(*check)->x] == '1')
				(*check)->count_x++;
			(*check)->x++;
		}
		if (((*check)->y == 0 || (*check)->y == (*check)->max_y - 1)
			&& ((*check)->x != (*check)->count_x
				|| (*check)->max_x != (*check)->x))
			return (0);
		if ((*check)->x != (*check)->max_x)
			return (0);
		(*check)->y++;
	}
}
