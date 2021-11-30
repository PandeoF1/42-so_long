/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:38:27 by tnard             #+#    #+#             */
/*   Updated: 2021/11/29 03:01:34 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	so_long	*game;
	int		fd;

	game = malloc(sizeof(so_long));
	game->mult = 50;
	if (!game)
		return (0);
	if (argc == 2)
	{
		if (ft_check_file(argv[1]) && ft_init_map(&game, argv[1]))
		{
			game->player_mouv = 0;
			mlx_key_hook(game->mlx_win, ft_win_event, &game);
			mlx_hook(game->mlx_win, 17, 1L << 17, ft_exit_hook, &game);
			mlx_loop_hook(game->mlx, ft_sprite, &game);
			mlx_loop(game->mlx);
			ft_close(&game);
			ft_printf("You made : %i.\n", game->player_mouv);
		}
		else
			ft_printf("Error\n");
	}
	else
		ft_printf("Error\n");
	free(game);
	return (1);
}

/*int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}*/