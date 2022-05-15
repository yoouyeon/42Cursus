/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 03:59:42 by jeyoon            #+#    #+#             */
/*   Updated: 2022/05/15 14:26:07 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"
#include <stdlib.h>

void	ft_mlx_distroy(t_game *game)
{
	if (game->imgs.blank != 0)
		mlx_destroy_image(game->mlx_ptr, game->imgs.blank);
	if (game->imgs.bunny_1 != 0)
		mlx_destroy_image(game->mlx_ptr, game->imgs.bunny_1);
	if (game->imgs.bunny_2 != 0)
		mlx_destroy_image(game->mlx_ptr, game->imgs.bunny_2);
	if (game->imgs.bunny_3 != 0)
		mlx_destroy_image(game->mlx_ptr, game->imgs.bunny_3);
	if (game->imgs.bunny_4 != 0)
		mlx_destroy_image(game->mlx_ptr, game->imgs.bunny_4);
	if (game->imgs.carrot != 0)
		mlx_destroy_image(game->mlx_ptr, game->imgs.carrot);
	if (game->imgs.house != 0)
		mlx_destroy_image(game->mlx_ptr, game->imgs.house);
	if (game->imgs.wall != 0)
		mlx_destroy_image(game->mlx_ptr, game->imgs.wall);
	if (game->win_ptr != 0)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
}

void	ft_mem_free(t_game *game)
{
	int	i;

	ft_mlx_distroy(game);
	i = 0;
	if (game->map.map != 0)
	{
		while (i < game->map.height)
		{
			if (game->map.map[i] != 0)
				free(game->map.map[i]);
			i++;
		}
		free(game->map.map);
	}
}
