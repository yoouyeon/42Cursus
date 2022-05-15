/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 03:30:09 by jeyoon            #+#    #+#             */
/*   Updated: 2022/05/15 16:05:29 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_open(t_game *game, char *filename)
{
	int	fd;
	int	len;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		exit_error(game, "Error\n: Failed to open file");
	len = ft_strlen(filename);
	if (len < 3)
		exit_error(game, "Error\n: Need a map in format *.ber");
	if (filename[len - 4] != '.' || filename[len - 3] != 'b' || \
			filename[len - 2] != 'e' || filename[len - 1] != 'r')
		exit_error(game, "Error\n: Need a map in format *.ber");
	return (fd);
}

static void	get_map_size(t_game *game, char *filename)
{
	int		fd;
	int		curr_width;
	char	c;

	fd = ft_open(game, filename);
	game->map.height = 1;
	game->map.width = 0;
	curr_width = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			game->map.height++;
			curr_width = 0;
		}
		else
			curr_width++;
		if (curr_width > game->map.width)
			game->map.width = curr_width;
	}
	close(fd);
}

static int	malloc_map(t_game *game, char *filename)
{
	int	i;

	get_map_size(game, filename);
	if (game->map.height == 0 || game->map.width == 0)
		exit_error(game, "Error\n: empty map.");
	game->map.map = (char **)malloc(sizeof(char *) * game->map.height);
	if (game->map.map == 0)
		return (FALSE);
	i = 0;
	while (i < game->map.height)
	{
		game->map.map[i] = (char *)malloc(sizeof(char) * game->map.width + 1);
		if (game->map.map[i] == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	load_map(t_game *game, char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	c;

	fd = ft_open(game, filename);
	i = 0;
	j = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			game->map.map[i][j] = '\0';
			i++;
			j = 0;
		}
		else
		{
			game->map.map[i][j] = c;
			j++;
		}
	}
	game->map.map[i][j] = '\0';
	close(fd);
}

void	read_map(t_game *game, char *filename)
{
	if (malloc_map(game, filename) == FALSE)
		exit_error(game, "Error\n: Memory allocation failed.");
	load_map(game, filename);
}
