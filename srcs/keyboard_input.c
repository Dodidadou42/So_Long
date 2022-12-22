/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:14:58 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/01 09:17:15 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_cell(t_game *game, int x, int y)
{
	if (game->map.data[y][x] == ITEM)
		game->map.items--;
	game->map.player.x = x;
	game->map.player.y = y;
	game->map.data[y][x] = PLAYER;
	game->moves++;
}

void	player_move(t_game *game, int x, int y)
{
	if (game->map.data[y][x] == 'E' && game->map.items == 0)
		victory(game);
	else if (game->map.data[y][x] == EMPTY
			|| game->map.data[y][x] == ITEM)
	{
		game->map.data[(int)game->map.player.y][(int)game->map.player.x] = '0';
		move_cell(game, x, y);
		if ((game->map.data[y][x - 1] == 'E' || game->map.data[y][x + 1] == 'E'
					|| game->map.data[y - 1][x] == 'E'
					|| game->map.data[y + 1][x] == 'E') && game->map.items != 0)
			game->portal_sprite = 2;
		if (game->portal_sprite == 2 && game->map.data[y][x - 1] != 'E'
				&& game->map.data[y][x + 1] != 'E'
				&& game->map.data[y - 1][x] != 'E'
				&& game->map.data[y + 1][x] != 'E')
		{
			game->portal_sprite = 0;
			game->portal_frame = 0;
		}
		render_map(game);
	}
}

int	handle_input(int key, t_game *game)
{
	if (key == KEY_ESCAPE)
		close_game(game);
	if (key == KEY_W || key == KEY_UP)
		player_move(game, game->map.player.x, game->map.player.y - 1);
	if (key == KEY_S || key == KEY_DOWN)
		player_move(game, game->map.player.x, game->map.player.y + 1);
	if (key == KEY_D || key == KEY_RIGHT)
	{
		game->map.player.dir = 1;
		player_move(game, game->map.player.x + 1, game->map.player.y);
	}
	if (key == KEY_A || key == KEY_LEFT)
	{
		game->map.player.dir = 0;
		player_move(game, game->map.player.x - 1, game->map.player.y);
	}
	return (0);
}
