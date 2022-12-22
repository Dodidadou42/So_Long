/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:55:44 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/01 12:20:25 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_game *game)
{
	game->map.items = 0;
	game->map.exit = 0;
	game->map.pj = 0;
	game->map.columns = ft_strlen(game->map.data[0]);
	game->moves = 0;
	game->map.player.dir = 0;
	game->portal_sprite = 0;
	game->portal_frame = 0;
	game->map.enemy = 0;
	game->foe_sprite = 0;
	game->foe_frame = 0;
	game->map.items_check = 0;
}

void	init_map(char *argv, t_game *game)
{
	char	*map;
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nCouldn't open map.");
		free(game);
		exit(-1);
	}
	map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = join_free(map, line);
		free(line);
		game->map.rows++;
	}
	close(fd);
	game->map.path = ft_split(map, '\n');
	game->map.data = ft_split(map, '\n');
	free(map);
}

void	check_arguments(int argc, char **argv, t_game *game)
{
	int	len;

	if (argc < 2)
	{
		ft_printf("Error\nMap file missing.");
		free(game);
		exit(-1);
	}
	if (argc > 2)
	{
		ft_printf("Error\nToo many arguments.");
		free(game);
		exit(-1);
	}
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e'
		|| argv[1][len - 3] != 'b' || argv[1][len - 4] != '.'
		|| len < 4)
	{
		ft_printf("Error\nMap format is wrong.");
		free(game);
		exit(-1);
	}
	game->map.rows = 0;
}
