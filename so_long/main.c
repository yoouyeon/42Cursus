/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:27:40 by jeyoon            #+#    #+#             */
/*   Updated: 2022/05/15 15:21:16 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	exit_error(t_game *game, char *msg)
{
	ft_mem_free(game);
	printf("%s\n", msg);
	exit(1);
}

void	exit_success(t_game *game)
{
	ft_mem_free(game);
	printf("Success!! Total number of movements: %d", game->bunny.mov_cnt);
	exit(0);
}

int	exit_game(t_game *game)
{
	ft_mem_free(game);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.mlx_ptr = 0;
	game.win_ptr = 0;
	game.map.map = 0;
	game.imgs.blank = 0;
	game.imgs.bunny_1 = 0;
	game.imgs.bunny_2 = 0;
	game.imgs.bunny_3 = 0;
	game.imgs.bunny_4 = 0;
	game.imgs.carrot = 0;
	game.imgs.house = 0;
	game.imgs.wall = 0;
	if (argc != 2)
		exit_error(&game, "Error\n: in the number of map files");
	read_map(&game, argv[1]);
	check_map(&game);
	draw_map(&game);
	mlx_hook(game.win_ptr, KEYPRESS, 0, &key_press, &game);
	mlx_hook(game.win_ptr, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
