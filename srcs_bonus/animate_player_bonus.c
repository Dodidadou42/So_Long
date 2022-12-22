/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:49:56 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/01 12:21:35 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	idle_player_left(t_game *game)
{
	static int	frame = 0;

	if (frame == 0)
		game->pj = init_sprite(game->mlx, IDLE_LEFT"PJ_Idle1.xpm", game);
	else if (frame == 5)
		game->pj = init_sprite(game->mlx, IDLE_LEFT"PJ_Idle2.xpm", game);
	else if (frame == 10)
		game->pj = init_sprite(game->mlx, IDLE_LEFT"PJ_Idle3.xpm", game);
	else if (frame == 15)
		game->pj = init_sprite(game->mlx, IDLE_LEFT"PJ_Idle4.xpm", game);
	else if (frame == 20)
		game->pj = init_sprite(game->mlx, IDLE_LEFT"PJ_Idle5.xpm", game);
	else if (frame == 25)
		game->pj = init_sprite(game->mlx, IDLE_LEFT"PJ_Idle6.xpm", game);
	else if (frame == 30)
		game->pj = init_sprite(game->mlx, IDLE_LEFT"PJ_Idle7.xpm", game);
	else if (frame == 35)
		game->pj = init_sprite(game->mlx, IDLE_LEFT"PJ_Idle8.xpm", game);
	else if (frame == 40)
		game->pj = init_sprite(game->mlx, IDLE_LEFT"PJ_Idle9.xpm", game);
	else if (frame == 45)
		game->pj = init_sprite(game->mlx, IDLE_LEFT"PJ_Idle10.xpm", game);
	else if (frame == 50)
		frame = 0;
	frame++;
}

void	idle_player_right(t_game *game)
{
	static int	frame = 0;

	if (frame == 0)
		game->pj = init_sprite(game->mlx, IDLE_RIGHT"PJ_Idle1.xpm", game);
	else if (frame == 5)
		game->pj = init_sprite(game->mlx, IDLE_RIGHT"PJ_Idle2.xpm", game);
	else if (frame == 10)
		game->pj = init_sprite(game->mlx, IDLE_RIGHT"PJ_Idle3.xpm", game);
	else if (frame == 15)
		game->pj = init_sprite(game->mlx, IDLE_RIGHT"PJ_Idle4.xpm", game);
	else if (frame == 20)
		game->pj = init_sprite(game->mlx, IDLE_RIGHT"PJ_Idle5.xpm", game);
	else if (frame == 25)
		game->pj = init_sprite(game->mlx, IDLE_RIGHT"PJ_Idle6.xpm", game);
	else if (frame == 30)
		game->pj = init_sprite(game->mlx, IDLE_RIGHT"PJ_Idle7.xpm", game);
	else if (frame == 35)
		game->pj = init_sprite(game->mlx, IDLE_RIGHT"PJ_Idle8.xpm", game);
	else if (frame == 40)
		game->pj = init_sprite(game->mlx, IDLE_RIGHT"PJ_Idle9.xpm", game);
	else if (frame == 45)
		game->pj = init_sprite(game->mlx, IDLE_RIGHT"PJ_Idle10.xpm", game);
	else if (frame == 50)
		frame = 0;
	frame++;
}

void	player_hurt(t_game *game)
{
	static int	frame = 0;

	if (frame == 0)
		game->pj = init_sprite(game->mlx, PJ_HURT"Hurt1.xpm", game);
	else if (frame == 10)
		game->pj = init_sprite(game->mlx, PJ_HURT"Hurt2.xpm", game);
	else if (frame == 20)
		game->pj = init_sprite(game->mlx, PJ_HURT"Hurt3.xpm", game);
	else if (frame == 30)
		game->pj = init_sprite(game->mlx, PJ_HURT"Hurt4.xpm", game);
	frame++;
}

int	death(t_game *game)
{
	static int	i = 0;

	if (i < 50)
	{
		player_hurt(game);
		render_map(game);
	}
	else
	{
		ft_printf("Moves : %d\n", game->moves);
		if (game->map.data)
			free_map(game);
		free(game);
		ft_printf("You lost.");
		exit (0);
	}
	i++;
	return (0);
}
