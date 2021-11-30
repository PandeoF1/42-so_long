/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:39:52 by tnard             #+#    #+#             */
/*   Updated: 2021/11/29 03:06:17 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_open_map(so_long **game)
{
	(*game)->border = mlx_xpm_file_to_image((*game)->mlx, "./img/border.xpm", &(*game)->picture_size , &(*game)->picture_size );
	(*game)->player = mlx_xpm_file_to_image((*game)->mlx, "./img/player.xpm", &(*game)->picture_size , &(*game)->picture_size );
	(*game)->exit = mlx_xpm_file_to_image((*game)->mlx, "./img/exit.xpm", &(*game)->picture_size , &(*game)->picture_size );
	(*game)->coin = mlx_xpm_file_to_image((*game)->mlx, "./img/coin.xpm", &(*game)->picture_size , &(*game)->picture_size );
	ft_open_number(&(*game));
}

void	ft_open_number(so_long **game)
{
	(*game)->number[0] = mlx_xpm_file_to_image((*game)->mlx, "./img/number/0.xpm", &(*game)->picture_size , &(*game)->picture_size);
	(*game)->number[1] = mlx_xpm_file_to_image((*game)->mlx, "./img/number/1.xpm", &(*game)->picture_size , &(*game)->picture_size);
	(*game)->number[2] = mlx_xpm_file_to_image((*game)->mlx, "./img/number/2.xpm", &(*game)->picture_size , &(*game)->picture_size);
	(*game)->number[3] = mlx_xpm_file_to_image((*game)->mlx, "./img/number/3.xpm", &(*game)->picture_size , &(*game)->picture_size);
	(*game)->number[4] = mlx_xpm_file_to_image((*game)->mlx, "./img/number/4.xpm", &(*game)->picture_size , &(*game)->picture_size);
	(*game)->number[5] = mlx_xpm_file_to_image((*game)->mlx, "./img/number/5.xpm", &(*game)->picture_size , &(*game)->picture_size);
	(*game)->number[6] = mlx_xpm_file_to_image((*game)->mlx, "./img/number/6.xpm", &(*game)->picture_size , &(*game)->picture_size);
	(*game)->number[7] = mlx_xpm_file_to_image((*game)->mlx, "./img/number/7.xpm", &(*game)->picture_size , &(*game)->picture_size);
	(*game)->number[8] = mlx_xpm_file_to_image((*game)->mlx, "./img/number/8.xpm", &(*game)->picture_size , &(*game)->picture_size);
	(*game)->number[9] = mlx_xpm_file_to_image((*game)->mlx, "./img/number/9.xpm", &(*game)->picture_size , &(*game)->picture_size);
}

static int	ft_push_img(so_long **game, int x, int y)
{
	if ((*game)->str[y][x] == '1')
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->border, x * (*game)->mult, y * (*game)->mult);
	else if ((*game)->str[y][x] == 'E')
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->exit, x * (*game)->mult, y * (*game)->mult);
	else if ((*game)->str[y][x] == 'P')
	{
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player, x * (*game)->mult, y * (*game)->mult);
		if ((*game)->player_x != 0 || (*game)->player_y != 0)
			return (0);
		(*game)->player_x = x;
		(*game)->player_y = y;
	}
	else if ((*game)->str[y][x] == 'C')
	{
		(*game)->coin_count++;
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->coin, x * (*game)->mult, y * (*game)->mult);
	}
	else if ((*game)->str[y][x] == 'N')
		mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->border, x * (*game)->mult, y * (*game)->mult);
	//else
	return (1);
}

static int	ft_push_map(so_long **game)
{
	int	x;
	int	y;

	y = 0;
	(*game)->picture_size = (*game)->max_x;
	(*game)->coin_count = 0;
	(*game)->mlx = mlx_init();
	(*game)->mlx_win = mlx_new_window((*game)->mlx, (*game)->max_x * (*game)->mult, (*game)->max_y * (*game)->mult, "test");
	ft_open_map(&(*game));
	while (y * (*game)->mult < (*game)->max_y * (*game)->mult)
	{
		x = 0;
		while (x * (*game)->mult < (*game)->max_x * (*game)->mult)
		{
			if (!ft_push_img(&(*game), x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_init_map(so_long **game, char *path) // leak ici
{
	map_check	*check;
	int			fd;
	char		*str;

	check = malloc(sizeof(map_check));
	fd = open(path, O_RDONLY);
	ft_printf("fd : %i, 1\n", fd);
	str = ft_get_file(fd, 0 ,0);
	ft_printf("str : %s, path : %s, 2\n", str, path);
	(*game)->str = ft_split_ln(str, "\n", &check->max_y);
	free(str);
	close(fd);
	ft_printf("ln : %i, 3\n", check->max_y);
	//check->max_y = 5; //recup ca automatiquement
	/*
	(*game)->str = malloc(sizeof(char *) * 6);
	(*game)->str[0] = malloc(sizeof(char) * 11);
	(*game)->str[1] = malloc(sizeof(char) * 11);
	(*game)->str[2] = malloc(sizeof(char) * 11);
	(*game)->str[3] = malloc(sizeof(char) * 11);
	(*game)->str[4] = malloc(sizeof(char) * 11);
	if (!check)
		return (0);
	check->max_y = 5; //recup ca automatiquement
	ft_printf("\nmap :\n");
	ft_strlcpy((*game)->str[0], "1111111111", 11);
	ft_strlcpy((*game)->str[1], "1EC0000001", 11);
	ft_strlcpy((*game)->str[2], "1PCCCCCCC1", 11);
	ft_strlcpy((*game)->str[3], "1CCCCCC001", 11);
	ft_strlcpy((*game)->str[4], "1111111111", 11);
	//char	*str; //get_next_line ko in ubuntu
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);*/
	ft_printf("%s\n%s\n%s\n%s\n", (*game)->str[0], (*game)->str[1], (*game)->str[2], (*game)->str[3]);
	check->max_x = ft_strlen((*game)->str[0]);
	check->y = 0;
	while(check->y < check->max_y)
	{
		check->x = 0;
		check->count_x = 0;
		while (check->x < check->max_x && ((*game)->str[check->y][check->x] == '1' || (*game)->str[check->y][check->x] == 'E' || (*game)->str[check->y][check->x] == 'P' || (*game)->str[check->y][check->x] == 'C' || (*game)->str[check->y][check->x] == '0' || (*game)->str[check->y][check->x] == 'N'))
		{
			if ((check->y == 0 || check->y == check->max_y - 1) && (*game)->str[check->y][check->x] == '1')
				check->count_x++;
			check->x++;
		}
		//if ((*game)->str[0])
		if ((check->y == 0 || check->y == check->max_y - 1) && (check->x != check->count_x || check->max_x != check->x))
			return (0);
		if (check->x != check->max_x)
			return (0);
		check->y++;
	}
	(*game)->max_x = check->max_x;
	(*game)->max_y = check->max_y;
	free(check);
	return (ft_push_map(&(*game)));
}
