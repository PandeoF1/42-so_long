#include "includes/main.h"
#include "libft/libft.h"

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

int	ft_init_map(so_long *game, char *path) // leak ici
{
	char	*str;
	int		fd;
	int		ln;

	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	close(fd);
	//free(str);
	return (1);
}

int	main(int argc, char **argv)
{
	so_long *game;
	int		fd;

	if (argc == 2)
	{
		if (ft_check_file(argv[1]) && ft_init_map(game, argv[1]))
		{
			printf("\n\ngg\n\n");
		}
	}
	else
		printf("Error\n");
	return(1);
}

/*
int test(int a)
{
    return (a);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

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
			mlx_put_image_to_window(test->mlx, test->mlx_win, test->border, x, y);
			x += test->picture_size;
		}
		y += test->picture_size;
	}
}

void	ft_getmap(so_long *test)
{
	test->max_x = 500;
	test->max_y = 500;
}

int	main(void)
{
	so_long *test;
	void	*mlx;

	ft_getmap(test);
	test->player_x = 0;
	test->player_y = 0;
	test->picture_size = 5;

	test->mlx = mlx_init();
	test->mlx_win = mlx_new_window(test->mlx, test->max_x, test->max_y, "Hello world!");
	test->border = mlx_xpm_file_to_image(test->mlx, "./img/border.xpm", &test->picture_size, &test->picture_size);
	test->player = mlx_xpm_file_to_image(test->mlx, "./img/player.xpm", &test->picture_size, &test->picture_size);
	test->exit = mlx_xpm_file_to_image(test->mlx, "./img/exit.xpm", &test->picture_size, &test->picture_size);
	//mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx = test->mlx;
	dprintf(1, "fill map started\n");
	ft_init_map(test);
	dprintf(1, "fill map finish\n");
	mlx_loop(mlx);
}*/