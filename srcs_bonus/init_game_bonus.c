/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 08:55:58 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/01 08:55:33 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	init_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (!sprite.xpm)
		error_msg("Couldn't find sprite.", game);
	return (sprite);
}

void	init_images(t_game *game)
{
	game->wall = init_sprite(game->mlx, "assets/sprites/wall.xpm", game);
	game->floor = init_sprite(game->mlx, "assets/sprites/floor.xpm", game);
	game->pj = init_sprite(game->mlx, IDLE_LEFT"PJ_Idle1.xpm", game);
	game->item = init_sprite(game->mlx, "assets/sprites/item/item.xpm", game);
	game->exit = init_sprite(game->mlx, OPEN_PORT"portal_open0.xpm", game);
	game->foe = init_sprite(game->mlx, SLIME_RIGHT"m_Slime1.xpm", game);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_msg("Couldn't find mlx pointer.", game);
	game->win = mlx_new_window(game->mlx, game->map.columns * IMG_WIDTH,
			game->map.rows * IMG_HEIGHT, "So Long Bonus");
	if (!game->win)
	{
		free(game->mlx);
		error_msg("Couldn't load window.", game);
	}
}
