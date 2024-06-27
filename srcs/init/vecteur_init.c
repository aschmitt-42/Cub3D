/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:09:03 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/27 19:32:32 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pre_init(t_game *game)
{
	game->player.dirX = 0;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0;
}

void	init_vecteur(t_game *game)
{
	pre_init(game);
	if (game->player.start == 'N')
	{
		game->player.dirX = -1;
		game->player.planeY = 0.66;
	}
	if (game->player.start == 'S')
	{
		game->player.dirX = 1;
		game->player.planeY = -0.66;
	}
	if (game->player.start == 'E')
	{
		game->player.dirY = 1;
		game->player.planeX = 0.66;
	}
	if (game->player.start == 'W')
	{
		game->player.dirY = -1;
		game->player.planeX = -0.66;
	}
	game->rotSpeed = 0.03;
	game->moveSpeed = 0.05;
}
