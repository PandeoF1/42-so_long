/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:39:52 by tnard             #+#    #+#             */
/*   Updated: 2021/12/07 10:24:44 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_open_number(t_so_long **game)
{
	(*game)->number[0] = ft_open_xpm(&(*game), "./img/number/0.xpm");
	(*game)->number[1] = ft_open_xpm(&(*game), "./img/number/1.xpm");
	(*game)->number[2] = ft_open_xpm(&(*game), "./img/number/2.xpm");
	(*game)->number[3] = ft_open_xpm(&(*game), "./img/number/3.xpm");
	(*game)->number[4] = ft_open_xpm(&(*game), "./img/number/4.xpm");
	(*game)->number[5] = ft_open_xpm(&(*game), "./img/number/5.xpm");
	(*game)->number[6] = ft_open_xpm(&(*game), "./img/number/6.xpm");
	(*game)->number[7] = ft_open_xpm(&(*game), "./img/number/7.xpm");
	(*game)->number[8] = ft_open_xpm(&(*game), "./img/number/8.xpm");
	(*game)->number[9] = ft_open_xpm(&(*game), "./img/number/9.xpm");
}

static void	ft_open_player(t_so_long **game)
{
	(*game)->player[0] = ft_open_xpm(&(*game), "./img/player/0.xpm");
	(*game)->player[1] = ft_open_xpm(&(*game), "./img/player/1.xpm");
	(*game)->player[2] = ft_open_xpm(&(*game), "./img/player/2.xpm");
	(*game)->player[3] = ft_open_xpm(&(*game), "./img/player/3.xpm");
	(*game)->player[4] = ft_open_xpm(&(*game), "./img/player/4.xpm");
	(*game)->player[5] = ft_open_xpm(&(*game), "./img/player/5.xpm");
}

static void	ft_open_enemies(t_so_long **game)
{
	(*game)->enemies[0] = ft_open_xpm(&(*game), "./img/enemies/0.xpm");
	(*game)->enemies[1] = ft_open_xpm(&(*game), "./img/enemies/1.xpm");
	(*game)->enemies[2] = ft_open_xpm(&(*game), "./img/enemies/2.xpm");
	(*game)->enemies[3] = ft_open_xpm(&(*game), "./img/enemies/3.xpm");
	(*game)->enemies[4] = ft_open_xpm(&(*game), "./img/enemies/4.xpm");
	(*game)->enemies[5] = ft_open_xpm(&(*game), "./img/enemies/5.xpm");
	(*game)->enemies[6] = ft_open_xpm(&(*game), "./img/enemies/6.xpm");
	(*game)->enemies[7] = ft_open_xpm(&(*game), "./img/enemies/7.xpm");
	(*game)->enemies[8] = ft_open_xpm(&(*game), "./img/enemies/8.xpm");
	(*game)->enemies[9] = ft_open_xpm(&(*game), "./img/enemies/9.xpm");
	(*game)->enemies[10] = ft_open_xpm(&(*game), "./img/enemies/10.xpm");
}

static void	ft_open_coin(t_so_long **game)
{
	(*game)->coin[0] = ft_open_xpm(&(*game), "./img/coin/0.xpm");
	(*game)->coin[1] = ft_open_xpm(&(*game), "./img/coin/1.xpm");
	(*game)->coin[2] = ft_open_xpm(&(*game), "./img/coin/2.xpm");
	(*game)->coin[3] = ft_open_xpm(&(*game), "./img/coin/3.xpm");
}

void	ft_init_xpm(t_so_long **game)
{
	(*game)->border = ft_open_xpm(&(*game), "./img/border.xpm");
	(*game)->exit = ft_open_xpm(&(*game), "./img/exit.xpm");
	(*game)->background = ft_open_xpm(&(*game), "./img/background.xpm");
	ft_open_enemies(&(*game));
	ft_open_coin(&(*game));
	ft_open_number(&(*game));
	ft_open_player(&(*game));
}
