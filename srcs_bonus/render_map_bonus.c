/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:32:14 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/01 09:39:31 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_sprite(t_game *game, t_image sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite.xpm,
		x * sprite.x, y * sprite.y);
}

void	identify_sprite(t_game *game, int x, int y)
{
	char	temp;

	temp = game->map.data[y][x];
	if (temp == WALL)
		render_sprite(game, game->wall, x, y);
	if (temp == EMPTY || temp == PLAYER || temp == FOE
		|| temp == ITEM || temp == MAP_EXIT)
		render_sprite(game, game->floor, x, y);
	if (temp == PLAYER)
		render_sprite(game, game->pj, x, y);
	if (temp == FOE)
		render_sprite(game, game->foe, x, y);
	if (temp == ITEM)
		render_sprite(game, game->item, x, y);
	if (temp == MAP_EXIT)
		render_sprite(game, game->exit, x, y);
}

void	render_moves(t_game *game)
{
	char	*str;
	char	*temp;

	temp = ft_itoa(game->moves);
	str = ft_strjoin("Moves : ", temp);
	mlx_string_put(game->mlx, game->win, 0, 0, 16711680, str);
	free(str);
	free(temp);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			identify_sprite(game, x, y);
			x++;
		}
		y++;
	}
	render_moves(game);
	return (0);
}
