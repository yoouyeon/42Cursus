/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 03:33:32 by jeyoon            #+#    #+#             */
/*   Updated: 2022/05/15 14:55:09 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

void	put_img_32(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		img_ptr, 32 * x, 32 * y);
}

void	put_imgs(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == '1')
				put_img_32(game, game->imgs.wall, j, i);
			else if (game->map.map[i][j] == 'C')
				put_img_32(game, game->imgs.carrot, j, i);
			else if (game->map.map[i][j] == 'E')
				put_img_32(game, game->imgs.house, j, i);
			else if (game->map.map[i][j] == 'P')
				put_bunny(game, game->bunny.dir, j, i);
			else
				put_img_32(game, game->imgs.blank, j, i);
			j++;
		}
		i++;
	}
}

void	get_img_ptr(t_game *game)
{
	int	img_width;
	int	img_height;

	game->imgs.bunny_1 = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./with_bg/bunny_1.xpm", &img_width, &img_height);
	game->imgs.bunny_2 = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./with_bg/bunny_2.xpm", &img_width, &img_height);
	game->imgs.bunny_3 = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./with_bg/bunny_3.xpm", &img_width, &img_height);
	game->imgs.bunny_4 = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./with_bg/bunny_4.xpm", &img_width, &img_height);
	game->imgs.blank = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./with_bg/blank.xpm", &img_width, &img_height);
	game->imgs.wall = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./with_bg/wall.xpm", &img_width, &img_height);
	game->imgs.carrot = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./with_bg/carrot.xpm", &img_width, &img_height);
	game->imgs.house = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./with_bg/house.xpm", &img_width, &img_height);
}

void	init_mlx(t_game *game)
{	
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == 0)
		exit_error(game, "Error\n: Error in mlx.");
	get_img_ptr(game);
	if (game->imgs.bunny_1 == 0 || game->imgs.bunny_2 == 0 || \
			game->imgs.bunny_3 == 0 || game->imgs.bunny_4 == 0)
		exit_error(game, "Error\n: Error in mlx.");
	if (game->imgs.blank == 0 || game->imgs.wall == 0 || \
			game->imgs.carrot == 0 || game->imgs.house == 0)
		exit_error(game, "Error\n: Error in mlx.");
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
		game->map.width * 32, game->map.height * 32, "so_long");
	if (game->win_ptr == 0)
		exit_error(game, "Error\n: Error in mlx.");
}

void	draw_map(t_game *game)
{
	init_mlx(game);
	put_imgs(game);
}
