/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:34:01 by aschmitt          #+#    #+#             */
/*   Updated: 2024/06/23 15:08:55 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_dist(t_game *game)
{
	game->ray.h = game->height ;
	game->ray.lineHeight = (int)(game->ray.h / game->ray.perpWallDist);
    game->ray.drawStart = -game->ray.lineHeight / 2 + game->ray.h / 2;
    if(game->ray.drawStart < 0)
		game->ray.drawStart = 0;
    game->ray.drawEnd = game->ray.lineHeight / 2 + game->ray.h / 2;
    if(game->ray.drawEnd >= game->ray.h)
		game->ray.drawEnd = game->ray.h - 1;
}

void	performe_dda(t_game *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.sideDistX < game->ray.sideDistY)
		{
			game->ray.sideDistX += game->ray.deltaDistX;
			game->ray.mapX += game->ray.stepX;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sideDistY += game->ray.deltaDistY;
			game->ray.mapY += game->ray.stepY;
			game->ray.side = 1;
		}
		if (game->map[game->ray.mapX][game->ray.mapY] > '0')
			game->ray.hit = 1;
	}
	if(game->ray.side == 0)
		game->ray.perpWallDist = (game->ray.sideDistX - game->ray.deltaDistX);
	else
		game->ray.perpWallDist = (game->ray.sideDistY - game->ray.deltaDistY);
	draw_dist(game);
}
