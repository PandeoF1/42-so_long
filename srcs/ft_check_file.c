/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:38:27 by aviscogl          #+#    #+#             */
/*   Updated: 2021/11/29 03:01:34 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_print_err(char	*str)
{
	ft_printf("Error.\n%s\n", str);
	return (0);
}

int	ft_check_file(char *path) //Check si il faut bien des message de return et rajouter des check pour le directory et tout le tralalala
{
	char	*ext;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	ext = ft_strrchr(path, '.');
	if (ext == NULL || ft_strcmp(".ber", ext) != 0)
		return(0);
	return (1);
}