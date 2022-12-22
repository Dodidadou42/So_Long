/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 08:55:47 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/30 19:38:32 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_vars2(t_game *game);

void	check_columns_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (ft_strlen(game->map.data[i]) != (unsigned int)game->map.columns)
			error_msg("Map is not rectangle", game);
		else if (game->map.data[i][0] != WALL)
			error_msg("Left wall is not complete.", game);
		else if (game->map.data[i][game->map.columns - 1] != WALL)
			error_msg("Right wall is not complete.", game);
		i++;
	}
	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.data[0][i] != WALL)
			error_msg("Up wall is not complete.", game);
		else if (game->map.data[game->map.rows - 1][i] != WALL)
			error_msg("Down wall is not complete.", game);
		i++;
	}
}

void	count_vars(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.columns)
		{
			if (!ft_strchr("01PCE", game->map.data[y][x]))
				error_msg("Map contains forbidden characters.", game);
			if (game->map.data[y][x] == PLAYER)
			{
				game->map.pj++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
		}
	}
	count_vars2(game);
}

void	count_vars2(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.columns)
		{
			if (game->map.data[y][x] == FOE)
			{
				game->map.enemy++;
				game->map.foe.x = x;
				game->map.foe.y = y;
			}
			if (game->map.data[y][x] == ITEM)
				game->map.items++;
			if (game->map.data[y][x] == MAP_EXIT)
				game->map.exit++;
		}
	}
}

void	check_vars(t_game *game)
{
	if (game->map.items < 1)
		error_msg("Invalid item quantity.", game);
	if (game->map.exit != 1)
		error_msg("Invalid exit quantity.", game);
	if (game->map.pj != 1)
		error_msg("Invalid player quantity.", game);
	if (game->map.enemy > 1)
		error_msg("Invalid foe quantity.", game);
}

void	check_map(t_game *game)
{
	check_columns_rows(game);
	count_vars(game);
	check_vars(game);
}
