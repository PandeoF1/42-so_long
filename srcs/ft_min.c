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

int	ft_check_in(char str, char *charset)
{
	int	j;
	int	check;

	j = 0;
	check = 0;
	while (charset[j])
	{
		if (str == charset[j])
			check = 1;
		else if (str != charset[j] && check != 1)
			check = 0;
		j++;
	}
	if (check == 0)
		return (0);
	j = 0;
	return (check);
}

int	ft_init_while(t_so_long **game, t_map_check **check)
{
	while (++(*check)->y < (*check)->max_y)
	{
		(*check)->x = -1;
		(*check)->count_x = 0;
		while (++(*check)->x < (*check)->max_x
			&& ft_check_in((*game)->str[(*check)->y][(*check)->x], "10EPCN"))
		{
			if ((*game)->str[(*check)->y][0] != '1' ||
				(*game)->str[(*check)->y][(*check)->max_x - 1] != '1')
				return (0);
			if (((*check)->y == 0 || (*check)->y == (*check)->max_y - 1)
				&& (*game)->str[(*check)->y][(*check)->x] == '1')
				(*check)->count_x++;
		}
		if (((*check)->y == 0 || (*check)->y == (*check)->max_y - 1)
			&& ((*check)->x != (*check)->count_x
				|| (*check)->max_x != (*check)->x))
			return (0);
		if ((*check)->x != (*check)->max_x)
			return (0);
	}
	return (1);
}
