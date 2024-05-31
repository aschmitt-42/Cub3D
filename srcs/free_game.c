/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:12:13 by eboumaza          #+#    #+#             */
/*   Updated: 2024/05/31 23:05:28 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_construct(t_game *game)
{
	game->minilib.mlx_ptr = NULL;
	game->minilib.win_ptr = NULL;
	game->map = NULL;
	game->width = 0;
	game->height = 0;
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void 	free_game(t_game *game, int error_code)
{
	free_map(game);
	if (error_code)
		exit (error_code);
}

