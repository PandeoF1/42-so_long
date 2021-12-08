/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:38:27 by tnard             #+#    #+#             */
/*   Updated: 2021/12/08 11:20:30 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_so_long	*game;
	int			fd;

	game = malloc(sizeof(t_so_long));
	game->mult = 50;
	if (!game)
		return (0);
	if (argc == 2 && ft_check_file(argv[1]) && ft_init_map(&game, argv[1]))
	{
		game->player_mouv = 0;
		game->anim_count = 0;
		game->enemies_count = 0;
		mlx_key_hook(game->mlx_win, ft_win_event, &game);
		mlx_hook(game->mlx_win, 17, 1L << 17, ft_exit_hook, &game);
		mlx_loop_hook(game->mlx, ft_sprite, &game);
		mlx_loop(game->mlx);
		ft_close(&game, 0);
		ft_printf("You made : %i.\n", game->player_mouv);
	}
	else
		ft_printf("Error\n");
	free(game);
	return (1);
}
