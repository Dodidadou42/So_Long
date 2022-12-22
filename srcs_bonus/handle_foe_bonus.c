/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_foe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:43:51 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/30 20:03:22 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_foe_left(t_game *game)
{
	static int	frame = 0;

	if (frame == 0)
		game->foe = init_sprite(game->mlx, SLIME_LEFT"Slime1.xpm", game);
	if (frame == 5)
		game->foe = init_sprite(game->mlx, SLIME_LEFT"Slime2.xpm", game);
	if (frame == 10)
		game->foe = init_sprite(game->mlx, SLIME_LEFT"Slime3.xpm", game);
	if (frame == 15)
		game->foe = init_sprite(game->mlx, SLIME_LEFT"Slime4.xpm", game);
	if (frame == 20)
		game->foe = init_sprite(game->mlx, SLIME_LEFT"Slime5.xpm", game);
	if (frame == 25)
		game->foe = init_sprite(game->mlx, SLIME_LEFT"Slime6.xpm", game);
	if (frame == 30)
		game->foe = init_sprite(game->mlx, SLIME_LEFT"Slime7.xpm", game);
	if (frame == 35)
		game->foe = init_sprite(game->mlx, SLIME_LEFT"Slime8.xpm", game);
	if (frame == 40)
		game->foe = init_sprite(game->mlx, SLIME_LEFT"Slime9.xpm", game);
	if (frame == 45)
		frame = 0;
	frame++;
}

void	animate_foe_right(t_game *game)
{
	static int	frame = 0;

	if (frame == 0)
		game->foe = init_sprite(game->mlx, SLIME_RIGHT"m_Slime1.xpm", game);
	if (frame == 5)
		game->foe = init_sprite(game->mlx, SLIME_RIGHT"m_Slime2.xpm", game);
	if (frame == 10)
		game->foe = init_sprite(game->mlx, SLIME_RIGHT"m_Slime3.xpm", game);
	if (frame == 15)
		game->foe = init_sprite(game->mlx, SLIME_RIGHT"m_Slime4.xpm", game);
	if (frame == 20)
		game->foe = init_sprite(game->mlx, SLIME_RIGHT"m_Slime5.xpm", game);
	if (frame == 25)
		game->foe = init_sprite(game->mlx, SLIME_RIGHT"m_Slime6.xpm", game);
	if (frame == 30)
		game->foe = init_sprite(game->mlx, SLIME_RIGHT"m_Slime7.xpm", game);
	if (frame == 35)
		game->foe = init_sprite(game->mlx, SLIME_RIGHT"m_Slime8.xpm", game);
	if (frame == 40)
		game->foe = init_sprite(game->mlx, SLIME_RIGHT"m_Slime9.xpm", game);
	if (frame == 45)
		frame = 0;
	frame++;
}

void	move_foe_left(t_game *game)
{
	int	x;
	int	y;

	x = game->map.foe.x;
	y = game->map.foe.y;
	if (game->foe_frame % 15 == 0)
	{
		if (game->foe_sprite == 0 && game->map.data[y][x + 1] != WALL)
		{
			if (game->map.data[y][x + 1] == PLAYER)
			{
				game->map.foe.x++;
				return ;
			}
			game->map.data[y][x] = EMPTY;
			game->map.foe.x++;
			game->map.data[y][x + 1] = FOE;
			if (game->map.data[y][x + 2] == WALL
				|| game->map.data[y][x + 2] == ITEM
					|| game->map.data[y][x + 2] == MAP_EXIT)
				game->foe_sprite = 1;
		}
	}
}

void	move_foe_right(t_game *game)
{
	int	x;
	int	y;

	x = game->map.foe.x;
	y = game->map.foe.y;
	if (game->foe_frame % 15 == 0)
	{
		if (game->foe_sprite == 1 && game->map.data[y][x - 1] != WALL)
		{
			if (game->map.data[y][x - 1] == PLAYER)
			{
				game->map.foe.x--;
				return ;
			}
			game->map.data[y][x] = EMPTY;
			game->map.foe.x--;
			game->map.data[y][x - 1] = FOE;
			if (game->map.data[y][x - 2] == WALL
				|| game->map.data[y][x - 2] == ITEM
					|| game->map.data[y][x - 2] == MAP_EXIT)
				game->foe_sprite = 0;
		}
	}
}

void	handle_foe(t_game *game)
{
	if (game->foe_sprite == 0)
		animate_foe_right(game);
	if (game->foe_sprite == 1)
		animate_foe_left(game);
	if (game->foe_sprite == 0)
		move_foe_left(game);
	else
		move_foe_right(game);
	if (game->map.foe.x == game->map.player.x
		&& game->map.foe.y == game->map.player.y)
	{
		mlx_loop_hook(game->mlx, death, game);
	}
	game->foe_frame++;
}
