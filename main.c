#include "includes/main.h"

int	ft_print_err(char	*str)
{
	printf("Error.\n%s\n", str);
	return (0);
}

int	ft_check_file(char *path) //Check si il faut bien des message de return
{
	char	*ext;
	int		a;

	ext = ft_strrchr(path, '.');
	if (ext == NULL || ft_strcmp(".ber", ext) != 0)
		return(ft_print_err("File not valid !"));
	return (1);
}

int	ft_push_map(so_long **game, char **str)
{
	int	x;
	int	y;
	int	mult;
	int a;
	int b;

	a = 10;
	b = 10;
	
	mult = mult;
	dprintf(1, "test : y = %i, x = %i, px = %i, str[0] = %s\n", (*game)->max_y * mult, (*game)->max_x * mult, (*game)->max_x, str[0]);
	(*game)->picture_size = (*game)->max_x;
	(*game)->mlx = mlx_init();
	(*game)->mlx_win = mlx_new_window((*game)->mlx, (*game)->max_x * mult, (*game)->max_y * mult, "Hello world!");
	(*game)->border = mlx_xpm_file_to_image((*game)->mlx, "./img/border.xpm", &a, &b);
	(*game)->player = mlx_xpm_file_to_image((*game)->mlx, "./img/player.xpm", &a, &b);
	(*game)->exit = mlx_xpm_file_to_image((*game)->mlx, "./img/exit.xpm", &a, &b);
	(*game)->coin = mlx_xpm_file_to_image((*game)->mlx, "./img/exit.xpm", &a, &b);
	y = 0;
	while (y * mult < (*game)->max_y * mult)
	{
		x = 0;
		while (x * mult < (*game)->max_x * mult)
		{
			if (str[y][x] == '1')
				mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->border, x * mult, y * mult);
			x++;
		}
		y++;
	}
	//mlx_put_image_to_window(test->mlx, test->mlx_win, test->border, x, y);
	return (1);
}

int	ft_init_map(so_long **game, char *path) // leak ici
{
	map_check	*check;
	char		**str;

	check = malloc(sizeof(map_check));
	str = malloc(sizeof(char *) * 4);
	str[0] = malloc(sizeof(char) * 11);
	str[1] = malloc(sizeof(char) * 11);
	str[2] = malloc(sizeof(char) * 11);
	str[3] = malloc(sizeof(char) * 11);
	if (!check)
		return (NULL);
	check->max_y = 4; //recup ca automatiquement

	dprintf(1, "\nmap :\n");
	ft_strlcpy(str[0], "1111111111", 11);
	ft_strlcpy(str[1], "1E00000001", 11);
	ft_strlcpy(str[2], "1PCCCCCCC1", 11);
	ft_strlcpy(str[3], "1111111111", 11);
	//char	*str; //get_next_line ko in ubuntu
	//fd = open(path, O_RDONLY);
	//str = get_next_line(fd);
	printf("%s\n%s\n%s\n%s\n\n", str[0], str[1], str[2], str[3]);
	check->max_x = ft_strlen(str[0]);
	check->y = 0;
	while(check->y < check->max_y)
	{
		check->x = 0;
		check->count_x = 0;
		while (check->x < check->max_x && (str[check->y][check->x] == '1' || str[check->y][check->x] == 'E' || str[check->y][check->x] == 'P' || str[check->y][check->x] == 'C' || str[check->y][check->x] == '0'))
		{
			if ((check->y == 0 || check->y == check->max_y - 1) && str[check->y][check->x] == '1')
				check->count_x++;
			check->x++;
		}
		if (str[0])
		if ((check->y == 0 || check->y == check->max_y - 1) && (check->x != check->count_x || check->max_x != check->x))
			return (0);
		if (check->x != check->max_x)
			return (0);
		check->y++;
	}
	(*game)->max_x = check->max_x;
	(*game)->max_y = check->max_y;
	return (ft_push_map(&(*game), str));
}

int	main(int argc, char **argv)
{
	so_long	*game;
	int		fd;

	game = malloc(sizeof(so_long));
	if (!game)
		return (NULL);
	if (argc == 2)
	{
		if (ft_check_file(argv[1]) && ft_init_map(&game, argv[1]))
		{
			printf("\n\ngg\n\n");
			mlx_loop(game->mlx);
		}
	}
	else
		printf("Error\n");
	return (1);
}

int test(int a)
{
    return (a);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
/*
void	ft_init_map(so_long *test)
{
	int	x;
	int	y;

	y = 0;
	while (y < test->max_y)
	{
		x = 0;
		while (x < test->max_x)
			mlx_pixel_put(test->mlx, test->mlx_win, x++, y, 0x000000FF);
		y++;
	}
	y = 0;
	while (y < test->max_y)
	{
		x = 0;
		while (x < test->max_x)
		{
			if (x == 0 || y == 0)
				mlx_put_image_to_window(test->mlx, test->mlx_win, test->border, x, y);
			x += test->picture_size;
		}
		y += test->picture_size;
	}
}

void	ft_getmap(so_long **test)
{
	(*test)->max_x = mult0;
	(*test)->max_y = mult0;
}

int	main(void)
{
	so_long	*test;
	void	*mlx;

	ft_getmap(&test);
	test->player_x = 0;
	test->player_y = 0;
	test->picture_size = 5;

	test->mlx = mlx_init();
	test->mlx_win = mlx_new_window(test->mlx, test->max_x, test->max_y, "Hello world!");
	test->border = mlx_xpm_file_to_image(test->mlx, "./img/border.xpm", &test->picture_size, &test->picture_size);
	test->player = mlx_xpm_file_to_image(test->mlx, "./img/player.xpm", &test->picture_size, &test->picture_size);
	test->exit = mlx_xpm_file_to_image(test->mlx, "./img/exit.xpm", &test->picture_size, &test->picture_size);
	//mlx_put_image_to_window(test->mlx, test->mlx_win, img, 0, 0);
	mlx = test->mlx;
	dprintf(1, "fill map started\n");
	ft_init_map(test);
	dprintf(1, "fill map finish\n");
	mlx_loop(mlx);
	return (0);
}
*/