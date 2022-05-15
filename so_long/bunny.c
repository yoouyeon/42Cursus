/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bunny.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 03:37:59 by jeyoon            #+#    #+#             */
/*   Updated: 2022/05/15 12:38:25 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"
#include <stdio.h>

void	init_bunny(t_game *game, t_cnt *cnts, int x, int y)
{
	if (cnts->cnt_p != 0)
		game->map.map[y][x] = '0';
	else
	{
		cnts->cnt_p++;
		game->bunny.y = y;
		game->bunny.x = x;
		game->bunny.mov_cnt = 0;
		game->bunny.dir = 4;
		game->bunny.carrot = 0;
	}
}

void	put_bunny(t_game *game, int dir, int x, int y)
{
	if (dir == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->imgs.bunny_1, 32 * x, 32 * y);
	else if (dir == 2)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->imgs.bunny_2, 32 * x, 32 * y);
	else if (dir == 3)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->imgs.bunny_3, 32 * x, 32 * y);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->imgs.bunny_4, 32 * x, 32 * y);
}

void	move_bunny(t_game *game, int new_x, int new_y)
{
	game->bunny.mov_cnt++;
	printf("number of movements : %d\n", game->bunny.mov_cnt);
	game->map.map[game->bunny.y][game->bunny.x] = '0';
	game->bunny.x = new_x;
	game->bunny.y = new_y;
	if (game->map.map[game->bunny.y][game->bunny.x] == 'E')
		exit_success(game);
	if (game->map.map[game->bunny.y][game->bunny.x] == 'C')
		game->bunny.carrot++;
	game->map.map[game->bunny.y][game->bunny.x] = 'P';
}

void	check_bunny(t_game *game, int dir, int x_gap, int y_gap)
{
	int	new_x;
	int	new_y;

	new_x = game->bunny.x + x_gap;
	new_y = game->bunny.y + y_gap;
	game->bunny.dir = dir;
	if (new_x < 0 || new_x >= game->map.width || new_y < 0 || \
		new_y >= game->map.height)
		put_imgs(game);
	else if (game->map.map[new_y][new_x] == '1')
		put_imgs(game);
	else if (game->map.map[new_y][new_x] == 'E' && \
		game->map.carrot != game->bunny.carrot)
		put_imgs(game);
	else
		move_bunny(game, new_x, new_y);
	put_imgs(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESCAPE)
		exit_game(game);
	else if (keycode == KEY_W)
		check_bunny(game, 1, 0, -1);
	else if (keycode == KEY_A)
		check_bunny(game, 2, -1, 0);
	else if (keycode == KEY_S)
		check_bunny(game, 3, 0, 1);
	else if (keycode == KEY_D)
		check_bunny(game, 4, 1, 0);
	return (0);
}
