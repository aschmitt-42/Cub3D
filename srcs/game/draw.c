/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:58:44 by aschmitt          #+#    #+#             */
/*   Updated: 2024/07/16 11:07:53 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sidedist(t_game *game)
{
	if (game->ray.raydirx < 0)
	{
		game->ray.stepx = -1;
		game->ray.sidedistx = (game->player.posx - game->ray.mapx)
			* game->ray.deltadistx;
	}
	else
	{
		game->ray.stepx = 1;
		game->ray.sidedistx = (game->ray.mapx + 1.0 - game->player.posx)
			* game->ray.deltadistx;
	}
	if (game->ray.raydiry < 0)
	{
		game->ray.stepy = -1;
		game->ray.sidedisty = (game->player.posy - game->ray.mapy)
			* game->ray.deltadisty;
	}
	else
	{
		game->ray.stepy = 1;
		game->ray.sidedisty = (game->ray.mapy + 1.0 - game->player.posy)
			* game->ray.deltadisty;
	}
}

void	init_value(t_game *game)
{
	game->ray.camerax = 2 * game->ray.x / (double)(game->width) - 1;
	game->ray.raydirx = game->player.dirx + game->player.planex
		* game->ray.camerax;
	game->ray.raydiry = game->player.diry + game->player.planey
		* game->ray.camerax;
	game->ray.mapx = game->player.posx;
	game->ray.mapy = game->player.posy;
	if (game->ray.raydirx == 0)
		game->ray.deltadistx = 1e30;
	else
		game->ray.deltadistx = fabs(1 / game->ray.raydirx);
	if (game->ray.raydiry == 0)
		game->ray.deltadisty = 1e30;
	else
		game->ray.deltadisty = fabs(1 / game->ray.raydiry);
	game->ray.hit = 0;
	init_sidedist(game);
}

void	draw(t_game *game)
{
	game->ray.x = -1;
	while (++game->ray.x < game->width)
	{
		init_value(game);
		performe_dda(game);
		display(game);
	}
	mlx_put_image_to_window(game->mlibx.mlx_ptr,
		game->mlibx.win_ptr, game->img.img, 0, 0);
}
