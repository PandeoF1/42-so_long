/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:49:08 by aviscogl          #+#    #+#             */
/*   Updated: 2021/11/26 17:49:08 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	ft_close(so_long **game)
{
	int	x;

	dprintf(1, "win\n");
	mlx_destroy_image((*game)->mlx, (*game)->player);
	mlx_destroy_image((*game)->mlx, (*game)->border);
	mlx_destroy_image((*game)->mlx, (*game)->coin);
	mlx_destroy_image((*game)->mlx, (*game)->exit);
	mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
	//mlx_destroy_display((*game)->mlx);
	mlx_loop_end((*game)->mlx);
	x = 0;
	while (x < (*game)->max_y)
		free((*game)->str[x++]);
	free((*game)->str);
	free((*game)->mlx);
	return (0);
}
