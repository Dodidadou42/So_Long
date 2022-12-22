/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 08:56:23 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/01 12:55:13 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WALL				'1'
# define EMPTY 				'0'
# define ITEM   			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'
# define FOE				'F'

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define KEY_PRESS			02
# define KEY_RELEASE		03

# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_LEFT			123
# define KEY_W 				13
# define KEY_S 				2
# define KEY_D 				1
# define KEY_A 				0
# define KEY_ESCAPE 		53

# define IDLE_LEFT			"assets/sprites/pj/idle_left/"
# define IDLE_RIGHT			"assets/sprites/pj/idle_right/"
# define PJ_HURT			"assets/sprites/pj/hurt/"
# define OPEN_PORT			"assets/sprites/portal/open/"
# define IDLE_PORT			"assets/sprites/portal/idle/"
# define CLOSE_PORT			"assets/sprites/portal/close/"
# define IDLE_ITEM			"assets/sprites/item/"
# define SLIME_LEFT			"assets/sprites/foe/left/AnyConv.com__"
# define SLIME_RIGHT		"assets/sprites/foe/right/AnyConv.com__"

typedef struct s_position
{
	float	x;
	float	y;
	int		dir;
}	t_position;

typedef struct s_image
{
	int		x;
	int		y;
	void	*xpm;
}	t_image;

typedef struct s_map
{
	char		**data;
	char		**path;
	int			rows;
	int			columns;
	int			items;
	int			items_check;
	int			exit;
	int			pj;
	int			enemy;
	t_position	player;
	t_position	foe;

}	t_map;

typedef struct s_game
{
	t_map	map;
	void	*mlx;
	void	*win;

	t_image	wall;
	t_image	floor;
	t_image	item;
	t_image	exit;
	t_image	pj;
	t_image	foe;

	int		moves;
	int		portal_sprite;
	int		portal_frame;
	int		foe_sprite;
	int		foe_frame;
}	t_game;

void	check_arguments(int argc, char **argv, t_game *game);
int		error_msg(char *str, t_game *game);
void	init_map(char *argv, t_game *game);
void	init_vars(t_game *game);
void	check_map(t_game *game);
int		pathfinding(t_game *game);
char	**get_old(t_game *game);
void	free_old(char **old);
void	init_mlx(t_game *game);
void	init_images(t_game *game);
t_image	init_sprite(void *mlx, char *path, t_game *game);
int		render_map(t_game *game);
int		handle_input(int key, t_game *game);
int		update(t_game *game);
void	idle_player_right(t_game *game);
void	idle_player_left(t_game *game);
void	idle_portal(t_game *game);
void	open_portal(t_game *game);
void	close_portal(t_game *game);
void	handle_foe(t_game *game);
int		victory(t_game *game);
int		death(t_game *game);
void	player_hurt(t_game *game);
int		close_game(t_game *game);
void	free_map(t_game *game);
void	free_all(t_game *game);

int		ft_printf(const char *f, ...);
char	*get_next_line(int fd);
char	*join_free(char *s1, const char *s2);
int		ft_strcmp(char *str1, char *str2);

#endif
