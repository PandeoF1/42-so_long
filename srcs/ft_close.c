/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:49:08 by tnard             #+#    #+#             */
/*   Updated: 2021/12/14 11:55:13 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_exit_hook(t_so_long **game)
{
	mlx_loop_end((*game)->mlx);
	return (0);
}

int	ft_close(t_so_long **game, int x)
{
	mlx_destroy_image((*game)->mlx, (*game)->border);
	mlx_destroy_image((*game)->mlx, (*game)->background);
	mlx_destroy_image((*game)->mlx, (*game)->exit);
	while (x < 10)
		mlx_destroy_image((*game)->mlx, (*game)->number[x++]);
	x = 0;
	while (x < 11)
		mlx_destroy_image((*game)->mlx, (*game)->enemies[x++]);
	x = 0;
	while (x < 4)
		mlx_destroy_image((*game)->mlx, (*game)->coin[x++]);
	x = 0;
	while (x < 6)
		mlx_destroy_image((*game)->mlx, (*game)->player[x++]);
	mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
	mlx_destroy_display((*game)->mlx);
	x = 0;
	while (x < (*game)->max_y)
		free((*game)->str[x++]);
	free((*game)->str);
	free((*game)->mlx);
	return (0);
}
