/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 08:56:15 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/01 09:44:56 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	check_arguments(argc, argv, game);
	init_map(argv[1], game);
	init_vars(game);
	check_map(game);
	pathfinding(game);
	init_mlx(game);
	init_images(game);
	render_map(game);
	mlx_hook(game->win, KEY_PRESS, (1L << 0), handle_input, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
}

char	**get_old(t_game *game)
{
	int		i;
	char	**ret;

	i = 0;
	while (game->map.path[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (game->map.path[i])
	{
		ret[i] = ft_strdup(game->map.path[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

void	free_old(char **old)
{
	int	i;

	i = -1;
	while (old[++i])
		free(old[i]);
	free(old);
}
