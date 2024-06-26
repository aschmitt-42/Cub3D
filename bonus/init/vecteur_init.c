/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:09:03 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/26 17:56:35 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vecteur(t_game *game)
{
	game->player.dirX = 0;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0;
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
