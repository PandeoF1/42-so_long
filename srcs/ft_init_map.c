/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:39:52 by aviscogl          #+#    #+#             */
/*   Updated: 2021/11/26 17:39:52 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static void	ft_open_map(so_long **game)
{
	//check if file exist maybe
	(*game)->border = mlx_xpm_file_to_image((*game)->mlx, "./img/border.xpm", &(*game)->picture_size , &(*game)->picture_size );
	(*game)->player = mlx_xpm_file_to_image((*game)->mlx, "./img/player.xpm", &(*game)->picture_size , &(*game)->picture_size );
	(*game)->exit = mlx_xpm_file_to_image((*game)->mlx, "./img/exit.xpm", &(*game)->picture_size , &(*game)->picture_size );
	(*game)->coin = mlx_xpm_file_to_image((*game)->mlx, "./img/coin.xpm", &(*game)->picture_size , &(*game)->picture_size );
}

static int	ft_push_map(so_long **game, char **str) // TODO : peut etre fait une fonction put image pour baisser la taille de celle ci, check pour plusieur jouer / plusieur exit (si il faut check ca)
{
	int	x;
	int	y;

	y = -1;
	(*game)->picture_size = (*game)->max_x;
	(*game)->coin_count = 0;
	(*game)->mlx = mlx_init();
	(*game)->mlx_win = mlx_new_window((*game)->mlx, (*game)->max_x * (*game)->mult, (*game)->max_y * (*game)->mult, "test");
	ft_open_map(&(*game));
	while (++y * (*game)->mult < (*game)->max_y * (*game)->mult)
	{
		x = -1;
		while (++x * (*game)->mult < (*game)->max_x * (*game)->mult)
		{
			if ((*game)->str[y][x] == '1')
				mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->border, x * (*game)->mult, y * (*game)->mult);
			else if ((*game)->str[y][x] == 'E')
				mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->exit, x * (*game)->mult, y * (*game)->mult);
			else if ((*game)->str[y][x] == 'P')
			{
				mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->player, x * (*game)->mult, y * (*game)->mult);
				(*game)->player_x = x;
				(*game)->player_y = y;
			}
			else if ((*game)->str[y][x] == 'C') //25
			{
				(*game)->coin_count++;
				mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win, (*game)->coin, x * (*game)->mult, y * (*game)->mult);
			}
		}
	}
	return (1);
}

int	ft_init_map(so_long **game, char *path) // leak ici
{
	map_check	*check;

	check = malloc(sizeof(map_check));
	(*game)->str = malloc(sizeof(char *) * 6);
	(*game)->str[0] = malloc(sizeof(char) * 11);
	(*game)->str[1] = malloc(sizeof(char) * 11);
	(*game)->str[2] = malloc(sizeof(char) * 11);
	(*game)->str[3] = malloc(sizeof(char) * 11);
	(*game)->str[4] = malloc(sizeof(char) * 11);
	if (!check)
		return (0);
	check->max_y = 5; //recup ca automatiquement
	dprintf(1, "\nmap :\n");
	ft_strlcpy((*game)->str[0], "1111111111", 11);
	ft_strlcpy((*game)->str[1], "1EC0000001", 11);
	ft_strlcpy((*game)->str[2], "1PCCCCCCC1", 11);
	ft_strlcpy((*game)->str[3], "1CCCCCC001", 11);
	ft_strlcpy((*game)->str[4], "1111111101", 11);
	//char	*str; //get_next_line ko in ubuntu
	//fd = open(path, O_RDONLY);
	//str = get_next_line(fd);
	printf("%s\n%s\n%s\n%s\n\n", (*game)->str[0], (*game)->str[1], (*game)->str[2], (*game)->str[3]);
	check->max_x = ft_strlen((*game)->str[0]);
	check->y = 0;
	while(check->y < check->max_y)
	{
		check->x = 0;
		check->count_x = 0;
		while (check->x < check->max_x && ((*game)->str[check->y][check->x] == '1' || (*game)->str[check->y][check->x] == 'E' || (*game)->str[check->y][check->x] == 'P' || (*game)->str[check->y][check->x] == 'C' || (*game)->str[check->y][check->x] == '0'))
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
	return (ft_push_map(&(*game), (*game)->str));
}