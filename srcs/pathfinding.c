/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:17:40 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/01 09:32:02 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_left_right(t_game *game, int x, int y)
{
	if (x > 0)
	{
		if (game->map.path[y][x - 1] != WALL
				&& game->map.path[y][x - 1] != PLAYER)
		{
			if (game->map.path[y][x - 1] == ITEM)
				game->map.items_check++;
			game->map.path[y][x - 1] = PLAYER;
		}
	}
	if (x < game->map.columns - 1)
	{
		if (game->map.path[y][x + 1] != WALL
				&& game->map.path[y][x + 1] != PLAYER)
		{
			if (game->map.path[y][x + 1] == ITEM)
				game->map.items_check++;
			game->map.path[y][x + 1] = PLAYER;
		}
	}
}

void	check_up_down(t_game *game, int x, int y)
{
	if (y > 0)
	{
		if (game->map.path[y - 1][x] != WALL
				&& game->map.path[y - 1][x] != PLAYER)
		{
			if (game->map.path[y - 1][x] == ITEM)
				game->map.items_check++;
			game->map.path[y - 1][x] = PLAYER;
		}
	}
	if (y < game->map.rows - 1)
	{
		if (game->map.path[y + 1][x] != WALL
				&& game->map.path[y + 1][x] != PLAYER)
		{
			if (game->map.path[y + 1][x] == ITEM)
				game->map.items_check++;
			game->map.path[y + 1][x] = PLAYER;
		}
	}
	check_left_right(game, x, y);
}

void	check_path(t_game *game)
{
	char	*temp;
	int		i;

	temp = malloc(sizeof(char *));
	i = 0;
	while (game->map.path[i])
	{
		temp = join_free(temp, game->map.path[i]);
		i++;
	}
	if (ft_strchr(temp, MAP_EXIT)
		|| game->map.items_check != game->map.items)
	{
		free(temp);
		error_msg("Map cannot be beaten.", game);
	}
	free(temp);
}

int	compare_maps(t_game *game, char **old)
{
	char	*map;
	char	*olds;
	int		i;

	i = 0;
	map = malloc(sizeof(char *));
	olds = malloc(sizeof(char *));
	while (game->map.path[i])
	{
		map = join_free(map, game->map.path[i]);
		i++;
	}
	i = 0;
	while (old[i])
	{
		olds = join_free(olds, old[i]);
		i++;
	}
	i = ft_strcmp(map, olds);
	free(map);
	free(olds);
	return (i);
}

int	pathfinding(t_game *game)
{
	char	**old;
	int		x;
	int		y;

	old = get_old(game);
	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.columns)
			if (game->map.path[y][x] == PLAYER)
				check_up_down(game, x, y);
	}
	if (compare_maps(game, old))
	{
		free_old(old);
		pathfinding(game);
	}
	else
	{
		free_old(old);
		check_path(game);
	}
	return (0);
}
