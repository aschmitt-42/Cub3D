/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:09:03 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/25 16:06:19 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vecteur(t_game *game)
{
	
	game->player.posX = 1 + 0.5;
	game->player.posY = 16 + 0.5;
	game->player.dirX = 1;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0.66;
	game->rotSpeed = 0.03;
	game->moveSpeed = 0.05;
}