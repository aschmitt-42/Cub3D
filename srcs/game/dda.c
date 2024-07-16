/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:34:01 by aschmitt          #+#    #+#             */
/*   Updated: 2024/07/16 11:52:17 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_dist(t_game *game)
{
	game->ray.h = game->height;
	game->ray.lineheight = (int)(game->ray.h / game->ray.perpwalldist);
	game->ray.drawstart = -game->ray.lineheight / 2 + game->ray.h / 2;
	if (game->ray.drawstart < 0)
		game->ray.drawstart = 0;
	game->ray.drawend = game->ray.lineheight / 2 + game->ray.h / 2;
	if (game->ray.drawend >= game->ray.h)
		game->ray.drawend = game->ray.h - 1;
}

void	performe_dda(t_game *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.sidedistx < game->ray.sidedisty)
		{
			game->ray.sidedistx += game->ray.deltadistx;
			game->ray.mapx += game->ray.stepx;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedisty += game->ray.deltadisty;
			game->ray.mapy += game->ray.stepy;
			game->ray.side = 1;
		}
		if (game->map[game->ray.mapx][game->ray.mapy] > '0')
			game->ray.hit = 1;
	}
	if (game->ray.side == 0)
		game->ray.perpwalldist = (game->ray.sidedistx - game->ray.deltadistx);
	else
		game->ray.perpwalldist = (game->ray.sidedisty - game->ray.deltadisty);
	draw_dist(game);
}
