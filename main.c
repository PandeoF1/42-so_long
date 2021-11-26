#include "includes/main.h"

int	ft_print_err(char	*str)
{
	printf("Error.\n%s\n", str);
	return (0);
}

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
			printf("\n\ngg\n\n");
			mlx_key_hook(game->mlx_win, ft_win_event, &game);
			mlx_loop(game->mlx);
		}
		else
			printf("Error\n");
	}
	else
		printf("Error\n");
	fd = 0;
	while (fd < (game)->max_y) //ici il faut recup le max_y meme avec un return 0
		free((game)->str[fd++]);
	free(game);
	return (1);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}