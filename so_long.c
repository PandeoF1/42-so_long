/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:38:27 by tnard             #+#    #+#             */
/*   Updated: 2021/12/14 11:22:46 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	ft_usage(void)
{
	ft_printf("\033[0;31mError\nusage: ./so_long [map.ber]\e[0m\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_so_long	*game;

	game = malloc(sizeof(t_so_long));
	game->mult = 50;
	if (!game)
		return (0);
	if (argc != 2)
		return (ft_usage());
	if (ft_check_file(argv[1]) && ft_init_map(&game, argv[1]))
	{
		game->player_mouv = 0;
		game->anim_count = -1;
		game->enemies_count = 0;
		mlx_key_hook(game->mlx_win, ft_win_event, &game);
		mlx_hook(game->mlx_win, 17, 1L << 17, ft_exit_hook, &game);
		mlx_loop_hook(game->mlx, ft_sprite, &game);
		mlx_loop(game->mlx);
		ft_close(&game, 0);
		ft_printf("\033[2K\r\033[0;34mYou made : %i.\e[0m", game->player_mouv);
	}
	else
		ft_printf("\033[2K\r\033[0;31mError\e[0m");
	free(game);
	ft_printf("\n");
	return (1);
}
