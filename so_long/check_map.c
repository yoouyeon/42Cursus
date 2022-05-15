/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 03:25:20 by jeyoon            #+#    #+#             */
/*   Updated: 2022/05/15 14:55:09 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

static int	is_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		if (ft_strlen(game->map.map[i]) != game->map.width)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	is_closed(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		if (i == 0 || i == game->map.height - 1)
		{
			j = 0;
			while (j < game->map.width)
			{
				if (game->map.map[i][j] != '1')
					return (FALSE);
				j++;
			}
		}
		else
		{
			if (game->map.map[i][0] != '1' || \
			game->map.map[i][game->map.width - 1] != '1')
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static int	check_characters(t_game *game, t_cnt *cnts)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'P')
				init_bunny(game, cnts, j, i);
			else if (game->map.map[i][j] == 'E')
				cnts->cnt_e++;
			else if (game->map.map[i][j] == 'C')
				cnts->cnt_c++;
			else if (game->map.map[i][j] != '0' && game->map.map[i][j] != '1')
				return (FALSE);
			j++;
		}
		i++;
	}
	if (cnts->cnt_p == 0 || cnts->cnt_e == 0 || cnts->cnt_c == 0)
		return (FALSE);
	return (TRUE);
}

void	check_map(t_game *game)
{
	t_cnt	cnts;

	cnts.cnt_e = 0;
	cnts.cnt_c = 0;
	cnts.cnt_p = 0;
	if (is_rectangular(game) == FALSE)
		exit_error(game, "Error\n: The map must be rectangular.");
	if (is_closed(game) == FALSE)
		exit_error(game, "Error\n: The map must be closed/surrounded by walls.");
	if (check_characters(game, &cnts) == FALSE)
		exit_error(game, "Error\n: In map contents");
	game->map.carrot = cnts.cnt_c;
}
