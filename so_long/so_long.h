/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:24:07 by jeyoon            #+#    #+#             */
/*   Updated: 2022/05/15 14:31:01 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TRUE 0
# define FALSE 1

# define KEYPRESS 2
# define X_EVENT_KEY_EXIT   17
# define KEY_ESCAPE			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2

typedef struct s_game	t_game;
typedef struct s_map	t_map;
typedef struct s_bunny	t_bunny;
typedef struct s_imgs	t_imgs;
typedef struct s_cnt	t_cnt;

struct s_map
{
	int		height;
	int		width;
	char	**map;
	int		carrot;
};

struct s_bunny
{
	int		dir;
	int		x;
	int		y;
	int		carrot;
	int		mov_cnt;
};

struct s_imgs
{
	void	*bunny_1;
	void	*bunny_2;
	void	*bunny_3;
	void	*bunny_4;
	void	*blank;
	void	*wall;
	void	*carrot;
	void	*house;
};

struct s_game
{
	t_map	map;
	t_bunny	bunny;
	t_imgs	imgs;
	void	*mlx_ptr;
	void	*win_ptr;
};

struct s_cnt
{
	int	cnt_e;
	int	cnt_c;
	int	cnt_p;
};

void	ft_mem_free(t_game *game);
void	read_map(t_game *game, char *filename);
void	check_map(t_game *game);
void	draw_map(t_game *game);
int		key_press(int keycode, t_game *game);

int		ft_strlen(char *str);

void	exit_error(t_game *game, char *msg);
void	exit_success(t_game *game);
int		exit_game(t_game *game);

void	init_bunny(t_game *game, t_cnt *cnts, int x, int y);
void	put_bunny(t_game *game, int dir, int x, int y);
void	put_imgs(t_game *game);

#endif