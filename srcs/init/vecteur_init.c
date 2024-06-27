/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:09:03 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/27 23:23:02 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pre_init(t_game *game)
{
	game->player.dirx = 0;
	game->player.diry = 0;
	game->player.planex = 0;
	game->player.planey = 0;
}

void	init_vecteur(t_game *game)
{
	pre_init(game);
	if (game->player.start == 'N')
	{
		game->player.dirx = -1;
		game->player.planey = 0.66;
	}
	if (game->player.start == 'S')
	{
		game->player.dirx = 1;
		game->player.planey = -0.66;
	}
	if (game->player.start == 'E')
	{
		game->player.diry = 1;
		game->player.planex = 0.66;
	}
	if (game->player.start == 'W')
	{
		game->player.diry = -1;
		game->player.planex = -0.66;
	}
	game->rotspeed = 0.03;
	game->movespeed = 0.05;
}
