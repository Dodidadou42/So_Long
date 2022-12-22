/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 08:56:31 by ddychus           #+#    #+#             */
/*   Updated: 2022/12/01 09:45:31 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *str, t_game *game)
{	
	if (game->map.data)
		free_map(game);
	free(game);
	ft_printf("Error\n%s", str);
	exit(-1);
}

int	victory(t_game *game)
{
	ft_printf("Moves : %d", game->moves);
	ft_printf("\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
");
	if (game->map.data)
		free_map(game);
	free(game);
	exit(1);
}

int	close_game(t_game *game)
{
	ft_printf("Moves : %d\n", game->moves);
	if (game->map.data)
		free_map(game);
	free(game);
	ft_printf("Game closed");
	exit(0);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
		free(game->map.data[i++]);
	i = 0;
	while (i < game->map.rows)
		free(game->map.path[i++]);
	free(game->map.data);
	free(game->map.path);
}
