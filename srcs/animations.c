/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:29:12 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/30 19:34:35 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	idle_item(t_game *game)
{
	static int	frame = 0;

	if (frame == 0)
		game->item = init_sprite(game->mlx, IDLE_ITEM"item.xpm", game);
	if (frame == 5)
		game->item = init_sprite(game->mlx, IDLE_ITEM"item2.xpm", game);
	if (frame == 10)
		game->item = init_sprite(game->mlx, IDLE_ITEM"item3.xpm", game);
	if (frame == 15)
		game->item = init_sprite(game->mlx, IDLE_ITEM"item2.xpm", game);
	if (frame == 20)
		game->item = init_sprite(game->mlx, IDLE_ITEM"item.xpm", game);
	if (frame == 25)
		game->item = init_sprite(game->mlx, IDLE_ITEM"item4.xpm", game);
	if (frame == 30)
		game->item = init_sprite(game->mlx, IDLE_ITEM"item5.xpm", game);
	if (frame == 35)
		game->item = init_sprite(game->mlx, IDLE_ITEM"item6.xpm", game);
	if (frame == 40)
		game->item = init_sprite(game->mlx, IDLE_ITEM"item5.xpm", game);
	if (frame == 45)
		game->item = init_sprite(game->mlx, IDLE_ITEM"item4.xpm", game);
	if (frame == 50)
		frame = 0;
	frame++;
}

int	update(t_game *game)
{
	if (game->map.player.dir == 0)
		idle_player_left(game);
	else if (game->map.player.dir == 1)
		idle_player_right(game);
	if (game->portal_sprite == 0)
		open_portal(game);
	else if (game->portal_sprite == 1)
		idle_portal(game);
	else if (game->portal_sprite == 2)
		close_portal(game);
	idle_item(game);
	handle_foe(game);
	render_map(game);
	return (0);
}
