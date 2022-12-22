/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_portal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:27:31 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/30 19:28:11 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_portal(t_game *game)
{
	static int	frame = 0;

	if (frame == 0)
		game->exit = init_sprite(game->mlx, OPEN_PORT"portal_open0.xpm", game);
	else if (frame == 5)
		game->exit = init_sprite(game->mlx, OPEN_PORT"portal_open1.xpm", game);
	else if (frame == 10)
		game->exit = init_sprite(game->mlx, OPEN_PORT"portal_open2.xpm", game);
	else if (frame == 15)
		game->exit = init_sprite(game->mlx, OPEN_PORT"portal_open3.xpm", game);
	else if (frame == 20)
		game->exit = init_sprite(game->mlx, OPEN_PORT"portal_open4.xpm", game);
	else if (frame == 25)
		game->exit = init_sprite(game->mlx, OPEN_PORT"portal_open5.xpm", game);
	else if (frame == 30)
		game->exit = init_sprite(game->mlx, OPEN_PORT"portal_open6.xpm", game);
	else if (frame == 35)
	{
		game->portal_sprite = 1;
		frame = -1;
	}
	frame++;
}

void	idle_portal(t_game *game)
{
	static int	frame = 0;

	if (frame == 0)
		game->exit = init_sprite(game->mlx, IDLE_PORT"portal_idle1.xpm", game);
	else if (frame == 5)
		game->exit = init_sprite(game->mlx, IDLE_PORT"portal_idle2.xpm", game);
	else if (frame == 10)
		game->exit = init_sprite(game->mlx, IDLE_PORT"portal_idle3.xpm", game);
	else if (frame == 15)
		game->exit = init_sprite(game->mlx, IDLE_PORT"portal_idle4.xpm", game);
	else if (frame == 20)
		game->exit = init_sprite(game->mlx, IDLE_PORT"portal_idle5.xpm", game);
	else if (frame == 25)
		game->exit = init_sprite(game->mlx, IDLE_PORT"portal_idle6.xpm", game);
	else if (frame == 30)
		game->exit = init_sprite(game->mlx, IDLE_PORT"portal_idle7.xpm", game);
	else if (frame == 35)
		game->exit = init_sprite(game->mlx, IDLE_PORT"portal_idle8.xpm", game);
	else if (frame == 40)
		frame = -1;
	frame++;
}

void	close_portal(t_game *game)
{
	if (game->portal_frame == 0)
		game->exit = init_sprite(game->mlx, CLOSE_PORT"close1.xpm", game);
	else if (game->portal_frame == 5)
		game->exit = init_sprite(game->mlx, CLOSE_PORT"close2.xpm", game);
	else if (game->portal_frame == 10)
		game->exit = init_sprite(game->mlx, CLOSE_PORT"close3.xpm", game);
	else if (game->portal_frame == 15)
		game->exit = init_sprite(game->mlx, CLOSE_PORT"close4.xpm", game);
	else if (game->portal_frame == 20)
		game->exit = init_sprite(game->mlx, CLOSE_PORT"close5.xpm", game);
	else if (game->portal_frame == 25)
		game->exit = init_sprite(game->mlx, CLOSE_PORT"close6.xpm", game);
	else if (game->portal_frame == 30)
		game->exit = init_sprite(game->mlx, CLOSE_PORT"close7.xpm", game);
	else if (game->portal_frame == 35)
	{
		game->exit = init_sprite(game->mlx, OPEN_PORT"portal_open0.xpm", game);
		return ;
	}
	game->portal_frame++;
}
